//
//  SettingDedupeViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class SettingDedupeViewController: UITableViewController, SettingSliderTableViewCellDelegate, SettingSwitchTableViewCellDelegate {
    
    private let manager : SettingDedupeManager
    
    init() {
        self.manager = SettingDedupeManager()
        
        super.init(style: .plain)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        setupView()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        self.manager.save()
    }
    
    //MARK: - Private
    private func setupView() {
        self.title = NSLocalizedString("Setting_Deduplication", comment: "")
        
        self.view.backgroundColor = .white
        
        self.tableView.separatorInset = .zero
        
        self.tableView.registerNib(SettingSliderTableViewCell.self)
        self.tableView.registerNib(SettingSwitchTableViewCell.self)
    }
    
    //MARK: - SettingSliderTableViewCellDelegate
    func changeValue(cell: UITableViewCell, changeValue: Float, presentable: SettingSliderPresentable?) {
        self.manager.updateValue(type: presentable!.configType, value: changeValue)
    }
    
    //MARK: - SettingSwitchTableViewCellDelegate
    func changeData(cell: UITableViewCell, data: SettingSwitchData) {
        self.manager.updateSwitchData(data: data)
        self.tableView.reloadData()
    }

    // MARK: - Table view data source
    override func numberOfSections(in tableView: UITableView) -> Int {
        return self.manager.configCount
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.manager.configRowCount(section: section)
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60.0
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if self.manager.isSwitchData(indexPath: indexPath) {
            let cell = tableView.dequeReusableCell(SettingSwitchTableViewCell.self, for: indexPath)
            cell.delegate = self
            
            if let data = self.manager.configSwitchData(indexPath: indexPath) {
                cell.updateAdsData(data: data)
            }
            
            return cell
        }
        
        let cell = tableView.dequeReusableCell(SettingSliderTableViewCell.self, for: indexPath)
        cell.delegate = self
        
        if let presentable = self.manager.configData(indexPath: indexPath) {
            cell.updatePresentable(presentable: presentable)
        }
        
        return cell
    }
}
