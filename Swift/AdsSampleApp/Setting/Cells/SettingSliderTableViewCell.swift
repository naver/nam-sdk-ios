//
//  SettingSliderTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

protocol SettingSliderPresentable {
    
    var title: String { get }
    var value: Int { get }
    var min: Int { get }
    var max: Int { get }
    var configType: ConfigType { get }
    
}

protocol SettingSliderTableViewCellDelegate : AnyObject {
    
    func changeValue(cell : UITableViewCell, changeValue : Float, presentable : SettingSliderPresentable?)
    
}

class SettingSliderTableViewCell: UITableViewCell, NibLoadable {
    
    @IBOutlet weak var title : UILabel?
    @IBOutlet weak var slider : UISlider?
    
    var sliderValue : UILabel?
    var presentable : SettingSliderPresentable?
    
    weak var delegate : SettingSliderTableViewCellDelegate?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        setupSliderValue()
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        self.title?.move(to: .verticalCenter)
        self.title?.move(to: .left, margin: 20.0)
    }
    
    func updatePresentable(presentable : SettingSliderPresentable) {
        self.presentable = presentable
        
        self.title?.text = self.presentable?.title
        self.title?.sizeToFit()
        
        self.slider?.maximumValue = Float(self.presentable?.max ?? 0)
        self.slider?.minimumValue = Float(self.presentable?.min ?? 0)
        
        self.slider?.value = Float(self.presentable?.value ?? 0)
        self.updateSlider(value: self.presentable?.value ?? 0)
    }
    
    @IBAction func valueChanged(_ sender: Any) {
        self.updateSlider(value: Int(self.slider?.value ?? 0))
        
        self.delegate?.changeValue(cell: self, changeValue: self.slider?.value ?? 0, presentable: self.presentable)
    }
    
    //MARK: - Private
    private func setupSliderValue() {
        self.sliderValue = UILabel.init(frame: .zero)
        self.sliderValue?.backgroundColor = .clear
        self.sliderValue?.textAlignment = .center
        self.sliderValue?.textColor = .black
        self.sliderValue?.font = .systemFont(ofSize: 15.0)
        self.addSubview(self.sliderValue!)
    }
    
    private func updateSlider(value : Int) {
        self.sliderValue?.text = "\(value)"
        self.sliderValue?.sizeToFit()
        
        let bounds = self.slider?.bounds ?? .zero
        let track = self.slider?.trackRect(forBounds: bounds) ?? .zero
        let frame = self.slider?.thumbRect(forBounds: bounds, trackRect: track, value: self.slider?.value ?? 0) ?? .zero
        
        let origin = self.slider?.frame.origin ?? .zero
        
        let position = CGPoint(x: frame.origin.x + origin.x + 10, y: origin.y + 28)
        self.sliderValue?.updateOrigin(origin: position)
    }

}
