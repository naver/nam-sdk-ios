//
//  SettingTimeoutViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class SettingTimeoutViewController: UITableViewController, InputTableViewCellDelegate {
    
    private let manager : SettingTimeoutManager
    
    init() {
        self.manager = SettingTimeoutManager()
        
        super.init(style: .plain)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        setup()
    }
    
    private func setup() {
        self.title = NSLocalizedString("", comment: "")
        
        self.tableView.registerNib(InputTableViewCell.self)
        self.navigationItem.rightBarButtonItem = UIBarButtonItem.init(title: "Save", style: .plain, target: self, action: #selector(save(_:)))
    }
    
    @IBAction func save(_ sender: Any) {
        self.manager.save()
        self.navigationController?.popViewController(animated: true)
    }
    
    // MARK: - Table view data source

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.manager.numberTimeouts
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60.0
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeReusableCell(InputTableViewCell.self, for: indexPath)
        cell.presentable = self.manager.presentable(indexPath: indexPath)
        cell.updatePresentable()
        cell.delegate = self
        
        return cell
    }
    
    //MARK: - InputTableViewCellDelegate
    
    func enter(tableViewCell: UITableViewCell, text: String, presentable: InputPresentable?) {
        if let inputPresentable = presentable, let value = Double(text) {
            self.manager.updateTimeout(type: inputPresentable.timeoutType, value: value)
        }
    }

}
