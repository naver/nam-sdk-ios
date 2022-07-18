//
//  InterstitialAdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


import UIKit
import GFPSDK
class InterstitialAdViewController: UIViewController, AdViewController {

    private(set) var adType : AdType = .interstitial
    private(set) var unitId : String = ""
    
    private var adManager : GFPInterstitialAdManager?
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    required init() {
        super.init(nibName: nil, bundle: nil)
    }

    func loadAd() {
        MainViewManager.shared.addHistory("Loading Ad ...")
        
        self.adType = MainViewManager.shared.adType ?? .interstitial
        self.unitId = MainViewManager.shared.unitID ?? ""
        
        self.loadInterstitial()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.view.backgroundColor = UIColor.white
        
        setupView()
        
        MainViewManager.shared.addHistory("Loaded Interstitial Ad View")
    }
    
    //MARK: - Private Setup
    private func setupView() {
        self.view.autoresizesSubviews = false;
        
        self.title = self.unitId
    }
    
    private func updateTextViewText(log : String) {
        MainViewManager.shared.addHistory(log)
    }
    
    //MARK: - InterstitialLoad
    
    private func loadInterstitial() {
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
        self.adManager = GFPInterstitialAdManager(unitID: self.unitId, adParam: adParam)
        self.adManager?.delegate = self
        self.adManager?.requestTimeoutInterval = 60
        self.adManager?.load()
    }
    
}


//MARK: - GFPAdLoaderDelegate
extension InterstitialAdViewController: GFPInterstitialAdManagerDelegate {
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didLoad interstitialAd: GFPInterstitialAd) {
        MainViewManager.shared.addHistory("Interstitial Ad Did Load")
        self.adManager?.show(self)
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didStart interstitialAd: GFPInterstitialAd) {
        MainViewManager.shared.addHistory("Interstitial Ad Started")
        
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, wasClickedAd interstitialAd: GFPInterstitialAd) {
        MainViewManager.shared.addHistory("Interstitial Ad WasClicked")

    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didClose interstitialAd: GFPInterstitialAd) {
        MainViewManager.shared.addHistory("Interstitial Ad Did Closed : %@" + interstitialAd.description)

    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didComplete interstitialAd: GFPInterstitialAd) {
        MainViewManager.shared.addHistory("Interstitial Ad Did Complete With InterstitialAd : " + interstitialAd.description )
    }
    
    func interstitialAdManager(_ manager: GFPInterstitialAdManager, didFailWithError error: GFPError, responseInfo: GFPLoadResponseInfo?) {
        MainViewManager.shared.addHistory("Interstitial Ad DidFailed With : \(error.code) ResponseInfo : \(responseInfo ?? nil)")
    }
}
