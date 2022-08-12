//
//  SettingViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

final class SettingViewController: UITableViewController, SettingSwitchTableViewCellDelegate {

    private let manager = SettingManager.shared
    
    required init?(coder: NSCoder) {        
        super.init(coder: coder)
    }
    
    init() {
        super.init(nibName: nil, bundle: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.setupSettings()
    }
    
    @IBAction func close(_ sender: Any) {
        self.navigationController?.dismiss(animated: true, completion: nil)
    }
    
    //MARK: - Private
    
    func setupSettings() {
        self.title = "Settings";
        
        self.tableView.separatorInset = .zero
        
        self.tableView.registerNib(SettingTableViewCell.self)
        self.tableView.registerNib(SettingSwitchTableViewCell.self)
        self.tableView.register(SettingDarkModeSelectorTableViewCell.self, forCellReuseIdentifier: "SettingDarkModeSelectorTableViewCell")
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return self.manager.settingCount()
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return "   \(self.manager.settingTitleTypeInSection(section: section))"
    }
    
    override func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 44.0
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.manager.settingsSubCountInSection(section: section)
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60.0
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if self.manager.isDarkMode(indexPath: indexPath) {
            let cell = self.tableView.dequeueReusableCell(withIdentifier: "SettingDarkModeSelectorTableViewCell", for: indexPath) as! SettingDarkModeSelectorTableViewCell
            cell.setupViews()
            return cell
        }
        else if self.manager.isSwitchType(indexPath: indexPath) {
            let cell = tableView.dequeReusableCell(SettingSwitchTableViewCell.self, for: indexPath)
            
            cell.delegate = self
            if let data = self.manager.settingSwitchsAtIndexPath(indexPath: indexPath) {
                cell.updateAdsData(data: data)
            }
            
            return cell
        } else {
            let cell = tableView.dequeReusableCell(SettingTableViewCell.self, for: indexPath)
            
            if let data = self.manager.settingsAtIndexPath(indexPath: indexPath) {
                cell.updateData(data: data)
            }
            
            return cell
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: false)
        
        let type = self.manager.settingTypeInSection(section: indexPath.section)
        
        switch type {
        case .adParam:
            let viewController = SettingAdParamViewController()
            self.navigationController?.pushViewController(viewController, animated: true)
        case .language:
            if let data = self.manager.settingsAtIndexPath(indexPath: indexPath) {
                let viewController = SettingLanguageViewController.init(data: data)
                self.navigationController?.pushViewController(viewController, animated: true)
            }
        case .deduplication:
            let viewController = SettingDedupeViewController()
            self.navigationController?.pushViewController(viewController, animated: true)
        case .timeout:
            let viewController = SettingTimeoutViewController()
            self.navigationController?.pushViewController(viewController, animated: true)
        default:
            print("nothing")
        }
    }
    
    //MARK: - SettingSwitchTableViewCellDelegate
    func changeData(cell: UITableViewCell, data: SettingSwitchData) {
        if data is SettingTestModeSwitchData, let testModeData = data as? SettingTestModeSwitchData {
            self.manager.updateTestMode(mode: testModeData.mode)
        }
    }
}
