//
//  MainViewManager.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import GFPSDK

class WfMatcher: Codable {
    var text: String
    var isRegex: Bool
}

extension AdControlVC {
    class ViewModel {
        static let shared = ViewModel()

        weak var vc: AdControlVC?

        var adType: AdType? = nil

        var unitIdText: String? = nil {
            didSet {
                self.vc?.unitIdLabel.text = unitIdText ?? "⇦ Select An Unit ID"
            }
        }

        private weak var callHistory: CallHistoryTextView?

        func configure(withViewController vc: AdControlVC, adType: AdType) {
            self.vc = vc
            self.adType = adType
            self.callHistory = vc.callHistoryTextView
            self.unitIdText = self.unitId

            loadUnitID()
            configure()
        }

        var unitId: String? {
            get {
                let text: String? = UserDefaults.standard.load(forKey: adType?.unitIdListName ?? "noAdTypeSpecified" + ".unitId")
                unitIdText = text
                return text
            }
            set {
                UserDefaults.standard.persist(newValue, forKey: adType?.unitIdListName ?? "noAdTypeSpecified" + ".unitId")
                unitIdText = newValue
            }
        }

        @Persisted(key: .wfMatcher, defaultValue: nil)
        public var wfMatcher: WfMatcher? {
            didSet {
//                self.vc?.wfMatcherLabel.text = wfMatcher?.text
            }
        }

        @Persisted(key: .previousDefaultUnitIDList, defaultValue: [:])
        private var previousDefaultUnitIDList: UnitIDList

        @Persisted(key: .defaultUnitIDList, defaultValue: [:])
        private var defaultUnitIDList: UnitIDList

        @Persisted(key: .currentUnitIDList, defaultValue: [:])
        var currentUnitIDList: UnitIDList
        
        func addLog(_ aText:String) {
            self.callHistory?.append(content: aText)
        }

        func resetLog() {
            self.callHistory?.reset()
        }

        func loadUnitID() {
            self.defaultUnitIDList = loadDefaultUnitIDListFromFile() ?? [:]

            if !self.previousDefaultUnitIDList.isEmpty && self.defaultUnitIDList.isEqual(to: self.previousDefaultUnitIDList) {
                if self.currentUnitIDList.isEmpty {
                    self.currentUnitIDList = self.defaultUnitIDList
                }
            } else { // Replaces UnitIdList on AdUnitList.plist file update
                self.currentUnitIDList = self.defaultUnitIDList
                self.previousDefaultUnitIDList = self.defaultUnitIDList

                guard let adType = self.adType else { return }
                guard let unitId = self.unitId else { return }
                if self.currentUnitIDList[adType.unitIdListName]?.contains(unitId) == false {
                    self.unitId = nil
                }
            }
        }

        private func loadDefaultUnitIDListFromFile() -> UnitIDList? {
            guard let path = Bundle.main.path(forResource: "AdUnitIDList", ofType: "plist") else { print("MainViewManager: plist for default Ad Unit IDs not found"); return nil }

            let url = URL(fileURLWithPath: path)
            guard let data = try? Data(contentsOf: url) else { print("MainViewManager - Failed to load default Ad Unit ID data:"); return nil }

            return try? PropertyListSerialization.propertyList(from: data, options: [], format: nil) as? [String:[String]]
        }

    }
}

extension AdControlVC.ViewModel {
    private func configure() {
//        let adTypeOptionsTap = UITapGestureRecognizer(target: self, action: #selector(adTypeOptionsTapped(_:)))
//        self.adTypeSpecificOptionsButton.addGestureRecognizer(adTypeOptionsTap)

        self.vc?.settingsButton = UIBarButtonItem(title: "Settings", style: .plain, target: self, action: #selector(settingsTapped))

        let unitIdTap = UITapGestureRecognizer(target: self, action: #selector(adUnitIDTapped(_:)))
        self.vc?.unitIdButton.addGestureRecognizer(unitIdTap)

        let loadTap = UITapGestureRecognizer(target: self, action: #selector(loadTapped(_:)))
        self.vc?.loadButton.addGestureRecognizer(loadTap)

        let loadWithoutImpressionTap = UITapGestureRecognizer(target: self, action: #selector(loadWithoutImpressionTapped(_:)))
        self.vc?.loadWithoutImpressionButton.addGestureRecognizer(loadWithoutImpressionTap)

        let resetTap = UITapGestureRecognizer(target: self, action: #selector(unloadTapped(_:)))
        self.vc?.resetButton.addGestureRecognizer(resetTap)

    }

    @IBAction func settingsTapped() {
        if UIDevice.current.userInterfaceIdiom == .phone {
            let settingsVc = UINavigationController(rootViewController: SettingsViewController())
            self.vc?.present(settingsVc, animated: true)
        } else if UIDevice.current.userInterfaceIdiom == .pad {
            guard let settingsVc = self.vc?.settingsVC else { return }
            self.vc?.splitVC.show(settingsVc, sender: self)
        }
    }

    @IBAction func adTypeOptionsTapped(_ sender: UITapGestureRecognizer) {
        // TODO: remove debug print()s
        print("adTypeOptionsTapped")
    }

    @IBAction func adUnitIDTapped(_ sender: UITapGestureRecognizer) {
        if UIDevice.current.userInterfaceIdiom == .phone {
            let unitIdVc = UINavigationController(rootViewController: UnitIDViewController(adControlViewModel: self))
            self.vc?.present(unitIdVc, animated: true)
        } else if UIDevice.current.userInterfaceIdiom == .pad {
            guard let unitIdVc = self.vc?.unitIdVC else { return }
            self.vc?.splitVC.show(unitIdVc, sender: self)
        }
    }

    @IBAction func loadTapped(_ sender: UITapGestureRecognizer) {
        setAdViewScrollHeight()
        loadAd()
        adViewScrollTop()
    }

    @IBAction func loadWithoutImpressionTapped(_ sender: UITapGestureRecognizer) {
        setAdViewScrollHeight()
        adViewScrollBottom()
        loadAd()
    }

    @IBAction func unloadTapped(_ sender: UITapGestureRecognizer) {
        removeAdViewController()
    }

    private func loadAd() {
        self.resetLog()

        guard let unitId = self.unitId else { return }
        if unitId == "" {
            self.addLog("UnitID not specified")
            return
        }

        guard let adType = adType else {return}
        let vc: AdViewController = adType.adViewController

        removeAdViewController()

        self.vc?.addChild(vc)
        self.vc?.adViewController = vc

        if let view = vc.view {
            self.vc?.adContainerScrollView.addSubview(view)

            view.backgroundColor = UIColor.Background.primary

            view.snp.makeConstraints { make in
                make.top.bottom.left.right.equalToSuperview()
            }

            addScrollToTopButton()
        }

        vc.loadAd()

        vc.view.layoutSubviews()
    }

    private func removeAdViewController() {
        guard let vc = self.vc?.adViewController else { return }

        vc.removeFromParent()
        vc.view.removeFromSuperview()
        self.vc?.adViewController = nil

        self.vc?.callHistoryTextView.reset()
    }

    private func setAdViewScrollHeight() {
        var height: CGFloat? = nil

        switch self.adType {
        case .display, .scheduled:
            if UIDevice.current.userInterfaceIdiom == .pad {
                height = 1300
            } else {
                height = 850
            }
        case .rewarded, .interstitial:
            height = 0
        case .tableViewAd:
            height = 1000
        case nil:
            break
        }

        guard let view = self.vc?.adContainerScrollView else {return}
        view.contentLayoutGuide.snp.remakeConstraints { make in
            make.width.centerX.equalToSuperview()
            if let height = height {
                make.height.greaterThanOrEqualTo(height)
            }
        }

        view.layoutIfNeeded()
    }

    private func addScrollToTopButton() {
        switch self.adType {
        case .display:
            break
        case .rewarded, .interstitial:
            return
        default:
            return
        }

        let scrollTopButton = UIButton.gray2(withTitle: "Scroll Top to Show Ad")
        self.vc?.adViewController!.view.addSubview(scrollTopButton)

        scrollTopButton.snp.makeConstraints { make in
            make.bottom.equalToSuperview().inset(10)
            make.centerX.equalToSuperview()
        }

        let scrollTopButtonTapped = UITapGestureRecognizer(target: self, action: #selector(scrollTopButtonTapped(_:)))
        scrollTopButton.addGestureRecognizer(scrollTopButtonTapped)
    }

    @IBAction func scrollTopButtonTapped(_ sender:UITapGestureRecognizer) {
        adViewScrollTop()
    }

    private func adViewScrollTop() {
        let scrollTopOffset = CGPoint(x: 0, y: 0)
        self.vc?.adContainerScrollView.setContentOffset(scrollTopOffset, animated: true)
    }

    private func adViewScrollBottom() {
        guard let vc = vc else {return}
        let scrollBottomOffset = CGPoint(x: 0, y: vc.adContainerScrollView.contentSize.height - vc.adContainerScrollView.bounds.height)
        vc.adContainerScrollView.setContentOffset(scrollBottomOffset, animated: false)
    }
}


fileprivate extension String {
    static let adType = "MainViewModel.adType"
    static let wfMatcher = "MainViewModel.wfMatcher"
    static let previousDefaultUnitIDList = "MainViewModel.previousDefaultUnitIDList"
    static let defaultUnitIDList = "MainViewModel.defaultUnitIDList"
    static let currentUnitIDList = "MainViewModel.currentUnitIDList"
}
