//
//  SettingSwitchTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

protocol SettingSwitchTableViewCellDelegate : AnyObject {
    
    func changeData(cell : UITableViewCell, data : SettingSwitchData)
    
}

class SettingSwitchTableViewCell: UITableViewCell, NibLoadable {
    
    @IBOutlet weak var titleLabel : UILabel?
    @IBOutlet weak var modeSwitch : UISwitch?
    
    weak var delegate : SettingSwitchTableViewCellDelegate?
    var data : SettingSwitchData?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    func updateAdsData(data : SettingSwitchData) {
        self.data = data
        
        if let count = self.data?.desc.count, count > 0 {
            self.titleLabel?.text = self.data?.desc
        } else {
            self.titleLabel?.text = self.data?.title
        }
        
        self.modeSwitch?.isOn = (self.data?.switchOn == true)
    }
    
    @IBAction func settingChanged(_ sender: Any) {
        if self.data != nil && self.delegate != nil {
            self.delegate?.changeData(cell: self, data: self.data!)
        }
    }


}
