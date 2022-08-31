//
//  InputTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

protocol InputPresentable {
    
    var title: String { get }
    var value: Double { get }
    var timeoutType: SettingTimeoutType { get }
    
}

protocol InputTableViewCellDelegate : AnyObject {
    
    func enter(tableViewCell : UITableViewCell, text : String, presentable : InputPresentable?)
    
}


class InputTableViewCell: UITableViewCell, UITextFieldDelegate, NibLoadable {
    
    var presentable : InputPresentable?
    weak var delegate : InputTableViewCellDelegate?
    
    @IBOutlet weak var titleLabel : UILabel?
    @IBOutlet weak var inputTextField : UITextField?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        self.inputTextField?.delegate = self
        self.inputTextField?.borderStyle = .roundedRect
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }
    
    override func layoutSubviews() {
        if self.presentable != nil {
            self.inputTextField?.updateSize(type: .width, value: 150)
            self.inputTextField?.move(to: .right, margin: 20.0)
        }
    }
    
    override func resignFirstResponder() -> Bool {
        super.resignFirstResponder()
        
        return self.inputTextField?.resignFirstResponder() ?? false
    }
    
    //MARK: - Public
    func updateInputUnitId() {
        self.inputTextField?.placeholder = "Input Unit Id"
        self.inputTextField?.keyboardType = .default
        self.inputTextField?.textAlignment = .left
        self.titleLabel?.isHidden = true
    }
    
    func updatePresentable() {
        self.titleLabel?.isHidden = false
        
        if let presentable = self.presentable {
            self.titleLabel?.text = presentable.title

            self.inputTextField?.placeholder = "Input timeout"
            self.inputTextField?.keyboardType = .decimalPad
            self.inputTextField?.textAlignment = .right
            self.inputTextField?.text = "\(String(describing: presentable.value))"
        }
    }
    
    //MARK: - Private
    private func isInvalidNum(text : String, index : NSInteger) -> Bool {
        let regex = try? NSRegularExpression.init(pattern: "^[0-9]*(\\.[0-9]{0,\(index)})?$", options: NSRegularExpression.Options(rawValue: 0))
        let textRange = NSMakeRange(0, text.count)
        return regex != nil ? regex?.numberOfMatches(in: text, options: NSRegularExpression.MatchingOptions(rawValue: 0), range: textRange) == 0 : true
    }

    
    //MARK: - UITextFieldDelegate
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        
        if let presentable = self.presentable {
            let input = (textField.text! as NSString).replacingCharacters(in: range, with: string)
            if self.isInvalidNum(text: input, index: 3) {
                return false
            }
            
            self.delegate?.enter(tableViewCell: self, text: input, presentable: presentable)
        }
        
        return true
    }
    
    func textFieldShouldClear(_ textField: UITextField) -> Bool {
        if let presentable = self.presentable {
            self.delegate?.enter(tableViewCell: self, text: "", presentable: presentable)
        }
        return true
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        if let count = textField.text?.count, count > 0 {
            self.delegate?.enter(tableViewCell: self, text: textField.text!, presentable: self.presentable)
            self.inputTextField?.text = ""
        }
        
        return true
    }
}
