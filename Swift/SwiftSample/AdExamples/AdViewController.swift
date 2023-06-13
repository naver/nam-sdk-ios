//
//  AdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class AdViewController: UIViewController {

    let vm: AdControlVC.ViewModel = .shared

    var unitId: String? { vm.unitId }

    func addLog(_ text: String) {
        vm.addLog(text)
    }

    init() {
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        if #available(iOS 13.0, *) {
            self.view.backgroundColor = .systemBackground
        }
    }

    func loadAd() {
    }
}

