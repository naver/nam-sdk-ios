//
//  InterstitialAdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


import GFPSDK

class InterstitialAdExample: AdViewController {

    private var adManager : GFPInterstitialAdManager?
    
    override func loadAd() {
        super.loadAd()

        addLog("Loading Ad ...")

        let adManager = configureSDKBySwiftSample()

//        let adManager = configureSDKOnYourOwn()

        self.adManager = adManager

        adManager.delegate = self

        adManager.load()

    }

    private func configureSDKOnYourOwn() -> GFPInterstitialAdManager {
        let adParam = GFPAdParam()
        adParam.keywords = ["KWD_1", "KWD_2"]
        adParam.currentPageUrl = "https://naver.com"

        let adManager = GFPInterstitialAdManager(unitID: self.unitId ?? "", adParam: adParam)

        adManager.requestTimeoutInterval = 60.0

        return adManager
    }

    private func configureSDKBySwiftSample() -> GFPInterstitialAdManager {
        let adParam = SettingsManager.shared.adParam

        let adManager = GFPInterstitialAdManager(unitID: self.unitId ?? "", adParam: adParam)
        adManager.requestTimeoutInterval = SettingsManager.shared.timeout(forType: .rewardedAd)

        return adManager
    }
    
}


//MARK: - GFPAdLoaderDelegate
extension InterstitialAdExample: GFPInterstitialAdManagerDelegate {
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didLoad interstitialAd: GFPInterstitialAd) {
        addLog("Interstitial Ad Did Load")
        self.adManager?.show(self)
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didStart interstitialAd: GFPInterstitialAd) {
        addLog("Interstitial Ad Started")
        
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, wasClickedAd interstitialAd: GFPInterstitialAd) {
        addLog("Interstitial Ad WasClicked")

    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didClose interstitialAd: GFPInterstitialAd) {
        addLog("Interstitial Ad Did Closed : %@" + interstitialAd.description)

    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didComplete interstitialAd: GFPInterstitialAd) {
        addLog("Interstitial Ad Did Complete With InterstitialAd : " + interstitialAd.description )
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didFailWithError error: GFPError, responseInfo: GFPLoadResponseInfo?) {
        addLog("Interstitial Ad DidFailed With : \(error.code) ResponseInfo : \(String(describing: responseInfo ?? nil))")
    }
}
