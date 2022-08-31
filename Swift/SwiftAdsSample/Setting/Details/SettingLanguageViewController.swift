//
//  SettingLanguageViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class SettingLanguageViewController: UITableViewController, SettingLanguageManagerDelegate {
    
    private let data : SettingData
    private let manager : SettingLanguageManager
    
    init(data : SettingData) {
        self.data = data
        self.manager = SettingLanguageManager.init(type: self.data.type)
        
        super.init(style: .plain)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setup()
    }
    
    //MARK: - Private
    private func setup() {
        self.title = self.data.title
        
        self.manager.delegate = self
        
        self.tableView.separatorInset = .zero
        self.tableView.registerNib(SettingSelectTableViewCell.self)
    }
    
    //MARK: - SettingLanguageManagerDelegate
    func updateData(manager: SettingLanguageManager) {
        self.tableView.reloadData()
    }

    // MARK: - Table view data source

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.manager.count
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60.0
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeReusableCell(SettingSelectTableViewCell.self, for: indexPath)
        
        cell.data = self.manager.languageData(indexPath: indexPath)
        cell.updateAdsData()
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: false)
        self.manager.updateSelected(indexPath: indexPath)
    }
    
}
