//
//  SettingTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class SettingTableViewCell: UITableViewCell, NibLoadable {

    var data : SettingData?
    
    @IBOutlet weak var titleLabel : UILabel?
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    func updateData(data : SettingData) {
        self.data = data
        self.titleLabel?.text = data.type.title
    }

}
