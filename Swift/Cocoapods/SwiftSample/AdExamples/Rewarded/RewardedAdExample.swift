//
//  RewardedAdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


import GFPSDK

class RewardedAdExample: AdViewController {

    private var adManager : GFPRewardedAdManager?

    override func loadAd() {
        super.loadAd()

        addLog("Loading Ad ...")

        self.loadRewarded()
    }
    
    private func loadRewarded() {

        let adManager = configureSDKBySwiftSample()

//        let adManager = configureSDKOnYourOwn()

        self.adManager = adManager

        adManager.delegate = self

        adManager.load()
    }

    private func configureSDKOnYourOwn() -> GFPRewardedAdManager {
        let adParam = GFPAdParam()
        adParam.keywords = ["KWD_1", "KWD_2"]
        adParam.currentPageUrl = "https://naver.com"

        let adManager = GFPRewardedAdManager(unitID: self.unitId ?? "", adParam: adParam)

        adManager.requestTimeoutInterval = 60.0

        return adManager
    }

    private func configureSDKBySwiftSample() -> GFPRewardedAdManager {
        let adParam = SettingsManager.shared.adParam

        let adManager = GFPRewardedAdManager(unitID: self.unitId ?? "", adParam: adParam)
        adManager.requestTimeoutInterval = SettingsManager.shared.timeout(forType: .rewardedAd)

        return adManager
    }
}



//MARK: - GFPAdLoaderDelegate
extension RewardedAdExample: GFPRewardedAdManagerDelegate {
   
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didClose rewardedAd: GFPRewardedAd) {
        addLog("Rewarded Ad Did Closed : " + rewardedAd.description)
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didComplete rewardedAd: GFPRewardedAd, with reward: GFPReward?) {
        let rewardInfo = reward?.description ?? "EMPTY";
        addLog("Rewarded Ad Did Complete With RewardedAd : " + rewardedAd.description + ", Reward : " + rewardInfo)

    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didFailWithError error: GFPError, responseInfo: GFPLoadResponseInfo?) {
        addLog("Rewarded Ad DidFailed With : \(error.code) ResponseInfo : \(String(describing: responseInfo ?? nil))")
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didLoad rewardedAd: GFPRewardedAd) {
        addLog("Rewarded Ad Did Load")
        self.adManager?.show(self)
    }
    
    func rewardedAdManager(_ manager: GFPRewardedAdManager, didStart rewardedAd: GFPRewardedAd) {
        addLog("Rewarded Ad Started")

    }
    

    func rewardedAdManager(_ manager: GFPRewardedAdManager, wasClickedAd rewardedAd: GFPRewardedAd) {
        addLog("Rewarded Ad WasClicked")

    }
}

