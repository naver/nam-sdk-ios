//
//  MainViewController+Actions.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

extension MainViewController {
    func setupActions() {
        
        self.settingsButton = UIBarButtonItem(title: "Settings", style: .plain, target: self, action: #selector(settingsTapped))
        self.navigationItem.rightBarButtonItem = self.settingsButton
        
//        let adTypeOptionsTap = UITapGestureRecognizer(target: self, action: #selector(adTypeOptionsTapped(_:)))
//        self.adTypeOptionsButton.addGestureRecognizer(adTypeOptionsTap)
        
        let unitIDTap = UITapGestureRecognizer(target: self, action: #selector(adUnitIDTapped(_:)))
        self.unitIDButton.addGestureRecognizer(unitIDTap)
        
        let loadTap = UITapGestureRecognizer(target: self, action: #selector(loadTapped(_:)))
        self.loadButton.addGestureRecognizer(loadTap)
        
        let loadWithoutImpressionTap = UITapGestureRecognizer(target: self, action: #selector(loadWithoutImpressionTapped(_:)))
        self.loadWithoutImpressionButton.addGestureRecognizer(loadWithoutImpressionTap)
        
        let resetTap = UITapGestureRecognizer(target: self, action: #selector(unloadTapped(_:)))
        self.unloadButton.addGestureRecognizer(resetTap)
        
    }
    
    @IBAction private func settingsTapped() {
        if UIDevice.current.userInterfaceIdiom == .phone {
            performSegue(withIdentifier: "ShowSettingViewController", sender: nil)
        } else {
            self.controlPanelDetailView?.present(self.settingVC?.view ?? nil)
        }
    }
    
    @IBAction private func adTypeOptionsTapped(_ sender: UITapGestureRecognizer) {
        // TODO: remove debug print()s
        print("adTypeOptionsTapped")
    }
    
    @IBAction private func adUnitIDTapped(_ sender: UITapGestureRecognizer) {
        if (UIDevice.current.userInterfaceIdiom == .pad) {
            self.controlPanelDetailView?.present(self.unitIdVC?.view ?? nil)
        } else {
            performSegue(withIdentifier: "ShowUnitIDViewController", sender: nil)
        }
    }
    
    @IBAction private func loadTapped(_ sender: UITapGestureRecognizer) {
        setAdViewScrollHeight()
        loadAd()
        adViewScrollTop()
    }
    
    @IBAction private func loadWithoutImpressionTapped(_ sender: UITapGestureRecognizer) {
        setAdViewScrollHeight()
        adViewScrollBottom()
        loadAd()
    }
    
    @IBAction func unloadTapped(_ sender: UITapGestureRecognizer) {
        removeAdViewController()
    }
    
    private func loadAd() {
        MainViewManager.shared.resetHistory()
        guard let adType = MainViewManager.shared.adType else {
            MainViewManager.shared.addHistory("AdType not specified")
            return
        }
        guard let unitID = MainViewManager.shared.unitID else { return }
        if unitID == "" {
            MainViewManager.shared.addHistory("UnitID not specified")
            return
        }
        
        let vc: AdViewController?
        
        switch adType {
        case .display:
            vc = DisplayAdViewController()
        case .rewarded:
            vc = RewardedAdViewController()
        case .interstitial:
            vc = InterstitialAdViewController()
//        default:
//            print("MainViewController: No AdType Selected.")
//            return
        }
        
        setNewAdViewController(vc!)
        
        vc!.loadAd()
        
        self.view.layoutSubviews()
    }
    
    private func setNewAdViewController(_ vc:UIViewController) {
        
        if (self.adViewController != nil) {
            removeAdViewController()
        }
        
        self.adViewController = vc
        self.addChild(vc)
        self.adView.addSubview(vc.view)
        self.adViewController!.didMove(toParent: self)
        
        let view = vc.view!
        view.backgroundColor = UIColor.Background.secondary
        
        view.translatesAutoresizingMaskIntoConstraints = false
        view.topAnchor.constraint(equalTo: self.adView.contentLayoutGuide.topAnchor).isActive = true
        view.centerXAnchor.constraint(equalTo: self.adView.contentLayoutGuide.centerXAnchor).isActive = true
        view.widthAnchor.constraint(equalTo: self.adView.contentLayoutGuide.widthAnchor).isActive = true
        view.heightAnchor.constraint(equalTo: self.adView.contentLayoutGuide.heightAnchor).isActive = true
        
        addScrollToTopButton()
    }
    
    private func removeAdViewController() {
        guard let vc = self.adViewController else { return }
        
        vc.willMove(toParent: nil)
        vc.view.removeFromSuperview()
        vc.removeFromParent()
        self.adViewController = nil
        
        self.callHistoryTextView.reset()
    }
    
    private func setAdViewScrollHeight() {
        let height:CGFloat
        
        switch MainViewManager.shared.adType {
        case .display:
            if UIDevice.current.userInterfaceIdiom == .pad {
                height = 1300
            } else {
                height = 850
            }
        case .rewarded, .interstitial:
            height = 0
        case .none:
            height = 0
        }
        
        self.adView.removeConstraints(self.adView.contentLayoutGuide.constraintsAffectingLayout(for: .horizontal))
        self.adView.removeConstraints(self.adView.contentLayoutGuide.constraintsAffectingLayout(for: .vertical))
        
        self.adView.contentLayoutGuide.widthAnchor.constraint(equalTo: self.adView.widthAnchor).isActive = true
        self.adView.contentLayoutGuide.heightAnchor.constraint(equalToConstant: height).isActive = true
        
        self.adView.layoutSubviews()
    }
    
    private func addScrollToTopButton() {
        switch MainViewManager.shared.adType {
        case .display:
            break
        case .rewarded, .interstitial:
            return
        default:
            return
        }
        
        let scrollTopButton = UIButton.gray2
        self.adViewController!.view.addSubview(scrollTopButton)
        
        scrollTopButton.setTitle("Scroll Top to View Ad", for: .normal)
        scrollTopButton.fitSizeTo(fontSize: FontSize)
        scrollTopButton.translatesAutoresizingMaskIntoConstraints = false
        scrollTopButton.widthAnchor.constraint(equalToConstant: scrollTopButton.frame.width + 15).isActive = true
        scrollTopButton.bottomAnchor.constraint(equalTo: self.adViewController!.view.bottomAnchor, constant: -20).isActive = true
        scrollTopButton.centerXAnchor.constraint(equalTo: self.adViewController!.view.centerXAnchor).isActive = true
        
        let scrollTopButtonTapped = UITapGestureRecognizer(target: self, action: #selector(scrollTopButtonTapped(_:)))
        scrollTopButton.addGestureRecognizer(scrollTopButtonTapped)
    }
    
    @IBAction func scrollTopButtonTapped(_ sender:UITapGestureRecognizer) {
        adViewScrollTop()
    }
    
    private func adViewScrollTop() {
        let scrollTopOffset = CGPoint(x: 0, y: 0)
        self.adView.setContentOffset(scrollTopOffset, animated: true)
    }
    
    private func adViewScrollBottom() {
        let scrollBottomOffset = CGPoint(x: 0, y: self.adView.contentSize.height - self.adView.bounds.height)
        self.adView.setContentOffset(scrollBottomOffset, animated: false)
    }
}
