//
//  UnitIDViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import SnapKit

let NewIDRowHeight:CGFloat = 47
let NewIDRowHorizontalMargin:CGFloat = 20

final class UnitIDViewController: UIViewController {

    let vm: AdControlVC.ViewModel

    var controlStack = UIStackView()

    var newIDTextField = UITextField.sampleAppTextField()
    var addButton = UIButton.gray1(withTitle: "Add")
    var editButton = UIButton.edit()
    var tableView = UITableView()
    
    var unitIdList: [String]! = [String]()

    var lastSelectedRow: IndexPath? = nil

    init(adControlViewModel: AdControlVC.ViewModel) {
        self.vm = adControlViewModel
        super.init(nibName: nil, bundle: nil)
        if #available(iOS 13.0, *) {
            self.view.backgroundColor = .systemBackground
        }
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupViews()
        setupLayouts()
        setupActions()
        loadUnitIDList()

        self.tableView.register(CheckCell.self, forCellReuseIdentifier: CheckCell.identifier)
    }
    
    // MARK: - Setup Functions
    private func setupViews() {
        self.title = "Ad Unit IDs";

        self.view.addSubview(self.controlStack)
        self.controlStack.axis = .horizontal
        self.controlStack.alignment = .center
        self.controlStack.spacing = 8
        self.controlStack.isLayoutMarginsRelativeArrangement = true
        self.controlStack.layoutMargins = .init(top: 0, left: 10, bottom: 0, right: 10)
        [self.newIDTextField,
         self.addButton,
         self.editButton
        ].forEach {
            self.controlStack.addArrangedSubview($0)
        }

        self.view.addSubview(self.tableView)
        
        self.newIDTextField.placeholder = "New Ad Unit ID"
        self.newIDTextField.font = UIFont.systemFont(ofSize: .Styles.FontSize)
        
        self.tableView.delegate = self
        self.tableView.dataSource = self

        if UIDevice.current.userInterfaceIdiom == .phone {
            self.configureNavBarDoneButton()
        }
    }
    
    private func setupLayouts() {
        self.controlStack.snp.makeConstraints { make in
            make.top.left.right.equalTo(self.view.safeAreaLayoutGuide)
        }

        self.editButton.snp.makeConstraints { make in
            make.width.equalTo(50)
        }

        self.tableView.snp.makeConstraints { make in
            make.left.right.bottom.equalTo(self.view.safeAreaLayoutGuide)
            make.top.equalTo(self.controlStack.snp.bottom)
        }
    }
    
    private func loadUnitIDList() {
        // TODO: phase 타입 구분해서 불러오도록
        guard let adType = vm.adType else {return}
        let list = vm.currentUnitIDList[adType.unitIdListName]
        self.unitIdList = list ?? [String]()
    }
    
    private func saveUnitIDs() {
        guard let adType = vm.adType else {return}
        vm.currentUnitIDList[adType.unitIdListName] = self.unitIdList
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
        
        vm.unitId = newID

        newIDTextField.text = nil
        self.tableView.setContentOffset(CGPoint.zero, animated: true)

        loadUnitIDList()

        self.tableView.beginUpdates()

        if let lastSelectedRow = lastSelectedRow, let lastSelectedCell = tableView.cellForRow(at: lastSelectedRow) as? CheckCell {
            lastSelectedCell.isSelected = false
        }

        if self.unitIdList.contains(newID) == false {
            self.unitIdList.insert(newID, at: 0)
            self.tableView.insertRows(at: [IndexPath(row: 0, section: 0)], with: .automatic)
            saveUnitIDs()
        } else {
            if let row = self.unitIdList.firstIndex(of: newID), let cell = tableView.cellForRow(at: .init(row: row, section: 0)) {
                cell.isSelected = true
                lastSelectedRow = .init(row: row, section: 0)
            }
        }

        self.tableView.endUpdates()
    }
    
    @IBAction func editTapped(_ sender: UITapGestureRecognizer) {
        let toggled = !self.tableView.isEditing
        self.editButton.isSelected = toggled
        self.tableView.setEditing(toggled, animated: true)
    }
}

extension UnitIDViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if self.unitIdList == nil || self.unitIdList.count == 0 {
            return 0
        }
        
        return self.unitIdList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: CheckCell.identifier, for: indexPath) as? CheckCell ?? CheckCell()
        let adUnitID = self.unitIdList[indexPath.row]


        cell.textLabel?.text = adUnitID

        if vm.unitId == adUnitID {
            cell.isSelected = true
            lastSelectedRow = indexPath
        } else {
            cell.isSelected = false
        }

        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let cell = tableView.cellForRow(at: indexPath) as? CheckCell else {return}
        
        vm.unitId = cell.textLabel?.text
        
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
                    
            weak.unitIdList?.remove(at: indexPath.row)
            weak.tableView.deleteRows(at: [indexPath], with: .automatic)
            weak.saveUnitIDs()
            completionHandler(true)
        }
        deleteAction.backgroundColor = .systemRed
        
        let editAction = UIContextualAction(style: .normal, title: "Edit") { (action, view, completionHandler) in
            weak var weakSelf = self
            guard let weak = weakSelf else { return }
            
            let editPopup = UIAlertController(title: "Edit Ad Unit ID", message: nil, preferredStyle: .alert)
            
            let originalUnitID = weak.unitIdList[indexPath.row]
            editPopup.addTextField { (textField: UITextField) in
                textField.text = originalUnitID
            }
            
            let editAction = UIAlertAction(title: "Save", style: .default) { alert -> Void in
                let newUnitID = editPopup.textFields![0].text!
                if newUnitID == "" { return }
                
                weak.unitIdList?[indexPath.row] = newUnitID
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
        let movedObject = self.unitIdList[sourceIndexPath.row]
        self.unitIdList.remove(at: sourceIndexPath.row)
        self.unitIdList.insert(movedObject, at: destinationIndexPath.row)
        saveUnitIDs()
    }
}
