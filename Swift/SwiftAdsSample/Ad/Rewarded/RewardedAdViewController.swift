//
//  RewardedAdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


import UIKit

import GFPSDK

class RewardedAdViewController: UIViewController, AdViewController {

    private(set) var unitId : String = ""
    private(set) var adType : AdType = .rewarded
        
    private var adManager : GFPRewardedAdManager?
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    required init() {
        super.init(nibName: nil, bundle: nil)
    }
    
    internal func loadAd() {
        MainViewManager.shared.addHistory("Loading Ad ...")
        
        self.adType = MainViewManager.shared.adType ?? .rewarded
        self.unitId = MainViewManager.shared.unitID ?? ""
        
        self.loadRewarded()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.view.backgroundColor = UIColor.white
        
        setupView()
        
        MainViewManager.shared.addHistory("Loaded Rewarded Ad View")
    }
    
    //MARK: - Private Setup
    private func setupView() {
        self.view.autoresizesSubviews = false;
        
        self.title = self.unitId
    }
    
    //MARK: - RewardedLoad
    
    private func loadRewarded() {
        let adParam = GFPAdParam()
        adParam.gender = AdGFPSDKManger.gender()
        adParam.yearOfBirth = AdGFPSDKManger.yearOfBirth()
        adParam.keywords = ["KWD_1", "KWD_2"]
        adParam.currentPageUrl = "https://naver.com"
        
        let customUserParam = ["customValue1":"customValue1", "language": UserDefaults.language, "Country":Locale.countryCode]
        adParam.customUserParam = customUserParam
        
        self.requestLoadAd(adParam: adParam)
    }
    
    private func requestLoadAd(adParam : GFPAdParam) {
        self.adManager = GFPRewardedAdManager(unitID: self.unitId, adParam: adParam)
        self.adManager?.delegate = self
        self.adManager?.requestTimeoutInterval = 60
        self.adManager?.load()
    }
    
}


//MARK: - GFPAdLoaderDelegate
extension RewardedAdViewController: GFPRewardedAdManagerDelegate {
   
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didClose rewardedAd: GFPRewardedAd) {
        MainViewManager.shared.addHistory("Rewarded Ad Did Closed : " + rewardedAd.description)
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didComplete rewardedAd: GFPRewardedAd, with reward: GFPReward?) {
        let rewardInfo = reward?.description ?? "EMPTY";
        MainViewManager.shared.addHistory("Rewarded Ad Did Complete With RewardedAd : " + rewardedAd.description + ", Reward : " + rewardInfo)

    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didFailWithError error: GFPError, responseInfo: GFPLoadResponseInfo?) {
        MainViewManager.shared.addHistory("Rewarded Ad DidFailed With : \(error.code) ResponseInfo : \(responseInfo ?? nil)")
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didLoad rewardedAd: GFPRewardedAd) {
        MainViewManager.shared.addHistory("Rewarded Ad Did Load")
        self.adManager?.show(self)
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didStart rewardedAd: GFPRewardedAd) {
        MainViewManager.shared.addHistory("Rewarded Ad Started")

    }
    

    func rewardedAdManager(_ manager: GFPRewardedAdManager, wasClickedAd rewardedAd: GFPRewardedAd) {
        MainViewManager.shared.addHistory("Rewarded Ad WasClicked")

    }
}

