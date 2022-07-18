//
//  Styles.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

let GlobalLayoutScale = UIScreen.main.bounds.size.width < 375 ? UIScreen.main.bounds.size.width / 375 : 1

let FontSize: CGFloat = 15 * GlobalLayoutScale
let ButtonCornerRadius: CGFloat = 8 * GlobalLayoutScale

extension UIColor {
    struct Button {
        static let gray1 = UIColor(white: 0.6, alpha: 1)
        static let gray2 = UIColor(white: 0.75, alpha: 1)
        static let load = UIColor(red: 0, green: 0.7, blue: 0, alpha: 0.8)
        static let unload = UIColor(red: 0.8, green: 0.15, blue: 0.15, alpha: 0.8)
    }

    struct Title {
        static let gray1 = UIColor(white: 0.99, alpha: 1)
        static let gray2 = UIColor(white: 0.99, alpha: 1)
        static let load = UIColor(white: 0.99, alpha: 1)
        static let unload = UIColor(white: 0.99, alpha: 1)
    }
    
    struct Background {
        static var primary: UIColor {
            if #available(iOS 13.0, *) {
                return UIColor.systemBackground
            } else {
                return UIColor.white
            }
        }
        static var secondary: UIColor {
            if #available(iOS 13.0, *) {
                if UITraitCollection.current.userInterfaceStyle == .dark {
                    return UIColor.systemGray3
                } else {
                    return UIColor.systemGray5
                }
            } else {
                return UIColor(white: 0.96, alpha: 1)
            }
        }
        static var tertiary: UIColor {
            if #available(iOS 13.0, *) {
                if UITraitCollection.current.userInterfaceStyle == .dark {
                    return UIColor.systemGray5
                } else {
                    return UIColor.systemGray3
                }
            } else {
                return UIColor(white: 0.8, alpha: 1)
            }
        }
    }
}

extension UIButton {
    static var load: UIButton {
        let button = UIButton()
        button.layer.cornerRadius = ButtonCornerRadius
        button.setTitleColor(.Title.load, for: .normal)
        button.backgroundColor = .Button.load
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static var unload: UIButton {
        let button = UIButton()
        button.layer.cornerRadius = ButtonCornerRadius
        button.setTitleColor(.Title.unload, for: .normal)
        button.backgroundColor = .Button.unload
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static var gray1: UIButton {
        let button = UIButton()
        button.layer.cornerRadius = ButtonCornerRadius
        button.setTitleColor(.Title.gray1, for: .normal)
        button.backgroundColor = .Button.gray1
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static var gray2: UIButton {
        let button = UIButton()
        button.layer.cornerRadius = ButtonCornerRadius
        button.setTitleColor(.Title.gray2, for: .normal)
        button.backgroundColor = .Button.gray2
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static var edit: UIButton {
        let button = UIButton()
        button.setTitle("Edit", for: .normal)
        button.setTitle("Done", for: .selected)
        
        button.setTitleColor(.systemBlue, for: .normal)
        button.setTitleColor(.systemBlue.withAlphaComponent(0.6), for: .highlighted)
        button.setTitleColor(.systemGray, for: .disabled)
        
        button.fitSizeTo(fontSize: FontSize*1.25)
        button.frame.size = CGSize(width: button.frame.size.width + 5, height: button.frame.height)
        
        UIButton.addTapHighlightActions(button)
        return button
    }
    
    private static func addTapHighlightActions(_ target:UIButton) {
        target.addTarget(target, action: #selector(buttonHighlight), for: .touchDown)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchCancel)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchUpInside)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchUpOutside)
    }
    
    @IBAction private func buttonHighlight() {
        var alpha: CGFloat = 0
        
        self.backgroundColor?.getRed(nil, green: nil, blue: nil, alpha: &alpha)
        self.backgroundColor = self.backgroundColor?.withAlphaComponent(alpha / 1.75)
    }
    
    @IBAction private func buttonNormal() {
        var alpha: CGFloat = 0
        
        self.backgroundColor?.getRed(nil, green: nil, blue: nil, alpha: &alpha)
        self.backgroundColor = self.backgroundColor?.withAlphaComponent(alpha * 1.75)
    }
    
    func fitSizeTo(fontSize:CGFloat) {
        self.titleLabel?.font = self.titleLabel?.font.withSize(fontSize)
        self.titleLabel?.numberOfLines = 1
        let size = self.sizeThatFits(CGSize(width: 10000, height: 10000))
        self.frame = CGRect(x: 0, y: 0, width: size.width + 15 * GlobalLayoutScale, height: size.height + 4 * GlobalLayoutScale)
    }
}

extension UILabel {
    func fitSizeTo(fontSize:CGFloat) {
        self.font = self.font.withSize(fontSize)
        let size = self.sizeThatFits(CGSize(width: 10000, height: 10000))
        self.frame = CGRect(x: 0, y: 0, width: size.width + 8 * GlobalLayoutScale, height: size.height)
    }
}

class SampleAppTextField: UITextField {
    let insets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        self.borderStyle = .roundedRect
        self.layer.cornerRadius = 6
    }
    
    convenience init() {
        self.init(frame: CGRect.zero)
    }
    
    override func textRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.inset(by: self.insets)
    }
    
    override func editingRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.inset(by: self.insets)
    }
}

extension UIViewController {
    func addNavBarDoneItemOnModalView() {
        let doneButton = UIBarButtonItem(barButtonSystemItem: UIBarButtonItem.SystemItem.done, target: nil, action: #selector(done))
        self.navigationItem.leftBarButtonItem = doneButton
    }
    
    @IBAction private func done() {
        self.dismiss(animated: true, completion: nil)
    }
}
