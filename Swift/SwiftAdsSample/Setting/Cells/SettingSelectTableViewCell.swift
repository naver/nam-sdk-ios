//
//  SettingSelectTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class SettingSelectTableViewCell: UITableViewCell, NibLoadable {

    var data : SettingSelectBaseData?
    @IBOutlet weak var titleLabel : UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    //MARK: - Public
    
    func updateAdsData() {
        self.titleLabel.text = self.data?.title
        updateAccessoryType()
    }
    
    //MARK: - Private
    private func updateAccessoryType() {
        if let isSelected = self.data?.isSelected {
            self.accessoryType = isSelected ? AccessoryType.checkmark : AccessoryType.none
        } else {
            self.accessoryType = AccessoryType.none
        }
    }


}
