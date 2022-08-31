//
//  UnitIDViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

let NewIDRowHeight:CGFloat = 47 * GlobalLayoutScale
let NewIDRowHorizontalMargin:CGFloat = 20 * GlobalLayoutScale

final class UnitIDViewController: UIViewController {
    
    var newIDTextField: UITextField!
    var addButton: UIButton!
    var editButton: UIButton!
    var tableView: UITableView!
    
    var unitIDList: [String]! = [String]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupViews()
        setupLayouts()
        setupActions()
        loadUnitIDList()
        
        self.tableView.register(UnitIDTableViewCell.self, forCellReuseIdentifier: "UnitIDTableViewCell")
    }
    
    // MARK: - Setup Functions
    private func setupViews() {
        addNavBarDoneItemOnModalView()
        
        self.newIDTextField = SampleAppTextField()
        self.addButton = UIButton.gray1
        self.editButton = UIButton.edit
        self.tableView = UITableView()
        
        self.view.addSubview(self.newIDTextField)
        self.view.addSubview(self.addButton)
        self.view.addSubview(self.editButton)
        self.view.addSubview(self.tableView)
        
        self.newIDTextField.placeholder = "New Ad Unit ID"
        self.newIDTextField.font = UIFont.systemFont(ofSize: FontSize)
        
        self.addButton.setTitle("Add", for: .normal)
        self.addButton.fitSizeTo(fontSize: FontSize)
        
        self.tableView.delegate = self
        self.tableView.dataSource = self
    }
    
    private func setupLayouts() {
        self.newIDTextField.translatesAutoresizingMaskIntoConstraints = false
        self.addButton.translatesAutoresizingMaskIntoConstraints = false
        self.editButton.translatesAutoresizingMaskIntoConstraints = false
        self.tableView.translatesAutoresizingMaskIntoConstraints = false
        
        let safeArea = self.view.safeAreaLayoutGuide
        
        let controlPanel = UILayoutGuide()
        self.view.addLayoutGuide(controlPanel)
        controlPanel.topAnchor.constraint(equalTo: safeArea.topAnchor).isActive = true
        controlPanel.leftAnchor.constraint(equalTo: safeArea.leftAnchor).isActive = true
        controlPanel.rightAnchor.constraint(equalTo: safeArea.rightAnchor).isActive = true
        controlPanel.heightAnchor.constraint(equalToConstant: NewIDRowHeight * GlobalLayoutScale).isActive = true
        
        self.editButton.rightAnchor.constraint(equalTo: safeArea.rightAnchor, constant: -7 * GlobalLayoutScale).isActive = true
        self.editButton.widthAnchor.constraint(equalToConstant: self.editButton.frame.width).isActive = true
        self.editButton.heightAnchor.constraint(equalToConstant: self.editButton.frame.height).isActive = true
        self.editButton.centerYAnchor.constraint(equalTo: controlPanel.centerYAnchor).isActive = true
        
        self.addButton.leftAnchor.constraint(equalTo: self.newIDTextField.rightAnchor, constant: 5 * GlobalLayoutScale).isActive = true
        self.addButton.widthAnchor.constraint(equalToConstant: self.addButton.frame.width).isActive = true
        self.addButton.heightAnchor.constraint(equalToConstant: self.addButton.frame.height).isActive = true
        self.addButton.centerYAnchor.constraint(equalTo: controlPanel.centerYAnchor).isActive = true
        
        self.newIDTextField.leftAnchor.constraint(equalTo: controlPanel.leftAnchor, constant: NewIDRowHorizontalMargin).isActive = true
        self.newIDTextField.heightAnchor.constraint(equalTo: self.addButton.heightAnchor, constant: 5 * GlobalLayoutScale).isActive = true
        self.newIDTextField.centerYAnchor.constraint(equalTo: self.addButton.centerYAnchor).isActive = true
        self.newIDTextField.widthAnchor.constraint(equalTo: controlPanel.widthAnchor, multiplier: 0.62).isActive = true
        
        self.tableView.leftAnchor.constraint(equalTo: safeArea.leftAnchor).isActive = true
        self.tableView.rightAnchor.constraint(equalTo: safeArea.rightAnchor).isActive = true
        self.tableView.bottomAnchor.constraint(equalTo: safeArea.bottomAnchor).isActive = true
        self.tableView.topAnchor.constraint(equalTo: controlPanel.bottomAnchor).isActive = true
    }
    
    private func loadUnitIDList() {
        // TODO: phase 타입 구분해서 불러오도록
        guard let adType = MainViewManager.shared.adType else { return }
        let list = MainViewManager.shared.unitIDList[adType.title]
        self.unitIDList = list ?? [String]()
    }
    
    private func saveUnitIDs() {
        guard let adType = MainViewManager.shared.adType else { return }
        MainViewManager.shared.unitIDList[adType.title] = self.unitIDList
    }
}

extension UnitIDViewController {
    private func setupActions() {
        let addTap = UITapGestureRecognizer(target: self, action: #selector(addTapped(_:)))
        self.addButton.addGestureRecognizer(addTap)
        
        let editTap = UITapGestureRecognizer(target: self, action: #selector(editTapped(_:)))
        self.editButton.addGestureRecognizer(editTap)
        
        self.newIDTextField.addTarget(self, action:#selector(addTapped(_:)), for: .editingDidEndOnExit)
    }
    
    @IBAction private func addTapped(_ sender: UITapGestureRecognizer) {
        guard let newID = self.newIDTextField.text else { return }
        if newID == "" { return }
        
        MainViewManager.shared.unitID = newID
        
        newIDTextField.text = nil
        self.tableView.setContentOffset(CGPoint.zero, animated: true)

        loadUnitIDList()
        
        self.unitIDList.insert(newID, at: 0)
        self.tableView.beginUpdates()
        self.tableView.insertRows(at: [IndexPath(row: 0, section: 0)], with: .automatic)
        self.tableView.endUpdates()
        saveUnitIDs()
    }
    
    @IBAction func editTapped(_ sender: UITapGestureRecognizer) {
        let toggled = !self.tableView.isEditing
        self.editButton.isSelected = toggled
        self.tableView.setEditing(toggled, animated: true)
    }
}

final class UnitIDTableViewCell: UITableViewCell {
    var unitID: String?
}

extension UnitIDViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if self.unitIDList == nil || self.unitIDList.count == 0 {
            return 0
        }
        
        return self.unitIDList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "UnitIDTableViewCell", for: indexPath) as! UnitIDTableViewCell
        let adUnitID = self.unitIDList[indexPath.row]
        
        cell.unitID = adUnitID
        cell.textLabel?.text = adUnitID
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let cell = tableView.cellForRow(at: indexPath) as! UnitIDTableViewCell
        
        MainViewManager.shared.unitID = cell.unitID
        
        tableView.deselectRow(at: indexPath, animated: false)
        
        if UIDevice.current.userInterfaceIdiom != .pad {
            self.navigationController?.popViewController(animated: true)
            self.navigationController?.dismiss(animated: true)            
        }
    }
    
    func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath)
    -> UISwipeActionsConfiguration? {
        
        let deleteAction = UIContextualAction(style: .destructive, title: "Delete") { (action, view, completionHandler) in
            weak var weakSelf = self
            guard let weak = weakSelf else { return }
                    
            weak.unitIDList?.remove(at: indexPath.row)
            weak.tableView.deleteRows(at: [indexPath], with: .automatic)
            weak.saveUnitIDs()
            completionHandler(true)
        }
        deleteAction.backgroundColor = .systemRed
        
        let editAction = UIContextualAction(style: .normal, title: "Edit") { (action, view, completionHandler) in
            weak var weakSelf = self
            guard let weak = weakSelf else { return }
            
            let editPopup = UIAlertController(title: "Edit Ad Unit ID", message: nil, preferredStyle: .alert)
            
            let originalUnitID = weak.unitIDList[indexPath.row]
            editPopup.addTextField { (textField: UITextField) in
                textField.text = originalUnitID
            }
            
            let editAction = UIAlertAction(title: "Save", style: .default) { alert -> Void in
                let newUnitID = editPopup.textFields![0].text!
                if newUnitID == "" { return }
                
                weak.unitIDList?[indexPath.row] = newUnitID
                weak.tableView.reloadData()
                weak.saveUnitIDs()
            }
            
            let cancelAction = UIAlertAction(title: "Cancel", style: .cancel)
            
            editPopup.addAction(editAction)
            editPopup.addAction(cancelAction)
            
            weak.present(editPopup, animated: true)
            
            completionHandler(true)
        }
        editAction.backgroundColor = .systemGray
        
        let configuration = UISwipeActionsConfiguration(actions: [deleteAction, editAction])
        return configuration
    }
    
    func tableView(_ tableView: UITableView, moveRowAt sourceIndexPath: IndexPath, to destinationIndexPath: IndexPath) {
        let movedObject = self.unitIDList[sourceIndexPath.row]
        self.unitIDList.remove(at: sourceIndexPath.row)
        self.unitIDList.insert(movedObject, at: destinationIndexPath.row)
        saveUnitIDs()
    }
}
