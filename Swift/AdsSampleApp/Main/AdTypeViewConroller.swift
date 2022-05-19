//
//  AdTypeViewConroller.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

final class AdTypeViewController: UIViewController {
    
    private var tableView: UITableView!
    private var adTypeList = [AdType]()
    private var isStartup = true
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "Select an Ad Type"
        
        setupViews()
        setupLayout()
        setupData()
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        showMainViewOnStartup()
    }
    
    func setupViews() {
        self.tableView = UITableView()
        self.view.addSubview(self.tableView!)
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.isScrollEnabled = false
        self.tableView.register(AdTypeTableViewCell.self, forCellReuseIdentifier: "AdTypeTableViewCell")
    }
    
    func setupLayout() {
        self.tableView.translatesAutoresizingMaskIntoConstraints = false
        
        let safeArea = self.view.safeAreaLayoutGuide
        
        self.tableView.topAnchor.constraint(equalTo: safeArea.topAnchor).isActive = true
        self.tableView.leftAnchor.constraint(equalTo: safeArea.leftAnchor).isActive = true
        self.tableView.rightAnchor.constraint(equalTo: safeArea.rightAnchor).isActive = true
        self.tableView.bottomAnchor.constraint(equalTo: safeArea.bottomAnchor).isActive = true
    }
    
    func setupData() {
        self.adTypeList = AdType.allCases
    }
    
    private func showMainViewOnStartup() {
        if self.isStartup && MainViewManager.shared.adType != nil {
            performSegue(withIdentifier: "ShowMainViewController", sender: self)
        }
        self.isStartup = false
    }
    
}

final class AdTypeTableViewCell: UITableViewCell {
    var adType: AdType?
    
    func setup(adType aAdType:AdType) {
        self.adType = aAdType
        self.textLabel?.text = aAdType.title
        self.textLabel?.textAlignment = .center
    }
}

extension AdTypeViewController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if UIDevice.current.orientation == .portrait {
            return 65
        } else {
            return 50
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.adTypeList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "AdTypeTableViewCell", for: indexPath) as! AdTypeTableViewCell
        
        let adType = self.adTypeList[indexPath.row]
        
        cell.setup(adType: adType)
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let cell = tableView.cellForRow(at: indexPath) as? AdTypeTableViewCell else { return }
        guard let adType = cell.adType else { return }
        
        MainViewManager.shared.adType = adType
        
        tableView.deselectRow(at: indexPath, animated: false)
        self.navigationController?.popViewController(animated: true)
        self.navigationController?.dismiss(animated: true)
        
        performSegue(withIdentifier: "ShowMainViewController", sender: self)
    }
}
