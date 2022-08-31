//
//  SettingDarkModeSelectorTableViewCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

final class SettingDarkModeSelectorTableViewCell: UITableViewCell, NibLoadable {
    private let manager = SettingManager.shared

    private let titleLabel = UILabel()
    private var modeSelector = UISegmentedControl(items: ["system", "light", "dark"])
    
    override func awakeFromNib() {
        super.awakeFromNib()
    }
    
    public func setupViews() {
        
        self.textLabel?.text = "Setting_Dark_Mode".localized
        
        self.accessoryView = self.modeSelector
        self.modeSelector.selectedSegmentIndex = manager.getDarkMode().rawValue
        self.modeSelector.addTarget(self, action: #selector(darkModeValueChanged(_:)), for: .valueChanged)
    }
    
    @IBAction private func darkModeValueChanged(_ sender:UISegmentedControl) {
        manager.setDarkMode(to: DarkModeType(rawValue: sender.selectedSegmentIndex) ?? .system)
    }
    
}
