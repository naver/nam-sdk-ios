//
//  AdTypeViewConroller.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

final class AdTypeViewController: UIViewController {

    private var tableView = UITableView()
    private var adTypeList = [AdType]()

    @Persisted(key: "AdTypeViewController.lastAdType", defaultValue: nil)
    private var lastAdType: AdType?
    private var didPushVC: Bool = false

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "Select an Ad Type"
        
        setupViews()
        setupLayout()
        setupData()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        // Shows MainView on startup
        if let adType = lastAdType, !didPushVC {
            didPushVC = true
            self.navigationController?.pushViewController(AdControlVC(adType: adType), animated: true)
        } else {
            lastAdType = nil
        }
    }
    
    func setupViews() {
        self.view.addSubview(self.tableView)
        self.tableView.delegate = self
        self.tableView.dataSource = self
        self.tableView.isScrollEnabled = false
        self.tableView.register(AdTypeCell.self, forCellReuseIdentifier: AdTypeCell.identifier)
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
}

final class AdTypeCell: UITableViewCell {

    static let identifier = UUID().uuidString

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
        let cell = tableView.dequeueReusableCell(withIdentifier: AdTypeCell.identifier, for: indexPath) as! AdTypeCell
        
        let adType = self.adTypeList[indexPath.row]
        
        cell.setup(adType: adType)
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let cell = tableView.cellForRow(at: indexPath) as? AdTypeCell else { return }
        guard let adType = cell.adType else { return }
        
        tableView.deselectRow(at: indexPath, animated: false)
        self.navigationController?.popViewController(animated: true)
        self.navigationController?.dismiss(animated: true)

        self.didPushVC = true
        self.lastAdType = adType
        self.navigationController?.pushViewController(AdControlVC(adType: adType), animated: true)
    }
}
