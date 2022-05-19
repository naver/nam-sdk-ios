//
//  DisplayAdViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

import GFPSDK

//import DTBiOSSDK

class DisplayAdViewController : UIViewController, AdViewController {
    
    private(set) var adType : AdType = .display
    private(set) var unitId : String = ""
    
    private var hasMediaView : Bool = true
    
    //common loader
    private var dedupeManager : GFPAdDedupeManager?
    private var adLoader : GFPAdLoader?
    
    //ad views
    private var bannerView : GFPBannerView?
    private var nativeAdView : GFPNativeAdView?
    private var nativeSimpleAdView : GFPNativeSimpleAdView?
    private var nativeBannerAdView : NativeBannerAdView?
    
    //for HeaderBidding
//    private var prebidBannerAdUnit : BannerAdUnit?
//    private var dtbAdSize : DTBAdSize?
//    private var tempAdParam : GFPAdParam?
    
    private var defaultSimpleAdSize : CGSize {
        let screenRect = UIScreen.main.bounds
        let defaultWidth = screenRect.size.width < screenRect.size.height ? screenRect.size.width : screenRect.size.height
        
        let width : CGFloat = defaultWidth > 0 ? defaultWidth : 320.0
        let height : CGFloat = 200.0
        
        return CGSize.init(width: width, height: height)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    required init() {
        super.init(nibName: nil, bundle: nil)
    }
    
    func loadAd() {
        MainViewManager.shared.addHistory("Loading Ad ...")
        
        self.adType = MainViewManager.shared.adType ?? .display
        self.unitId = MainViewManager.shared.unitID ?? ""
        
        setupDedupeManager()
        
        let adParam = GFPAdParam()
        adParam.gender = AdGFPSDKManger.gender()
        adParam.yearOfBirth = AdGFPSDKManger.yearOfBirth()
        adParam.keywords = ["KWD_1", "KWD_2"]
        adParam.currentPageUrl = "https://naver.com"
        
        let customUserParam = ["customValue1":"customValue1", "language": UserDefaults.language, "Country":Locale.countryCode]
        adParam.customUserParam = customUserParam
        
        self.requestLoadAd(adParam: adParam)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.backgroundColor = UIColor.white
        
        self.setupView()
        
        MainViewManager.shared.addHistory("Loaded Display Ad View")
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        updateLayout()
    }
    
    //MARK: - Private Setup
    private func setupDedupeManager() {
        let numAdsDeduped = UserDefaults.adConfig()?.numAdsDeduped ?? 3
        self.dedupeManager = GFPAdDedupeManager.init(numAdsDeduped: numAdsDeduped)
    }
    
    private func setupView() {
        self.view.autoresizesSubviews = false;
        
        self.title = self.unitId
        
        self.nativeAdView = UIView.loadView(name: "GFPNativeAdView") as? GFPNativeAdView
        self.nativeAdView?.showDebugBorder(withColor: .blue)
        
        self.nativeSimpleAdView = UIView.loadView(name: "GFPNativeSimpleAdView") as? GFPNativeSimpleAdView
        self.nativeSimpleAdView?.showDebugBorder(withColor: .green)
        self.updateSimpleAdViewSize(size : self.defaultSimpleAdSize)
        
        self.nativeBannerAdView = UIView.loadView(name: "NativeBannerAdView") as? NativeBannerAdView
        self.nativeBannerAdView?.showDebugBorder(withColor: .red)
    }
    
    private func resetSubViews() {
        self.bannerView?.removeFromSuperview()
        self.nativeAdView?.removeFromSuperview()
        self.nativeSimpleAdView?.removeFromSuperview()
        self.nativeBannerAdView?.removeFromSuperview()
        
        self.nativeBannerAdView?.reset()
        
        self.updateSimpleAdViewSize(size : self.defaultSimpleAdSize)
    }
    
    private func updateSimpleAdViewSize(size : CGSize) {
        self.nativeSimpleAdView?.updateSize(size: size)
        self.nativeSimpleAdView?.mediaView?.updateSize(size: size)
    }
    
    //MARK: - View Position & frame
    
    private func updateLayout() {
        self.bannerView?.move(to: .top, margin: 10.0)
        self.bannerView?.move(to: .horizontalCenter)
        
        self.nativeAdView?.move(to: .top, margin: 10.0)
        self.nativeAdView?.move(to: .horizontalCenter)
        
        self.nativeSimpleAdView?.move(to: .top, margin: 10.0)
        self.nativeSimpleAdView?.move(to: .horizontalCenter)
        
        self.nativeBannerAdView?.move(to: .top, margin: 10.0)
        self.nativeBannerAdView?.move(to: .horizontalCenter)
    }
    
    private func updateBannerViewSize (bannerSize : GFPBannerAdSize) {
        if bannerSize.type.rawValue == 0 { //fixed
            self.bannerView?.updateSize(size: bannerSize.size)
        } else { //fluid
            updateBannerViewFluid()
        }
    }
    
    private let MaxFluidBannerWidth = 414
    private let MaxFluidBannerHeight = 300

    private func updateBannerViewFluid() {
        if self.bannerView?.layoutType == .fluidWidth {
            let width = min(CGFloat(self.view.bounds.size.width - self.view.sideSafeAreaInsets), CGFloat(MaxFluidBannerWidth))
            self.bannerView?.updateSize(type: .width, value: width)
        }

        if self.bannerView?.layoutType == .fluidHeight {
            let height = min(CGFloat(self.view.bounds.size.height - self.view.topBottomSafeAreaInsets), CGFloat(MaxFluidBannerHeight))
            self.bannerView?.updateSize(type: .height, value: height)
        }

        if self.bannerView?.layoutType == .fluid {
            let width = min(CGFloat(self.view.bounds.size.width - self.view.sideSafeAreaInsets), CGFloat(MaxFluidBannerWidth))
            let height = min(CGFloat(self.view.bounds.size.height - self.view.topBottomSafeAreaInsets), CGFloat(MaxFluidBannerHeight))
            self.bannerView?.updateSize(size: CGSize.init(width: width, height: height))
        }
    }
    
    //MARK: - load
    private func requestLoadAd(adParam : GFPAdParam) {
        if self.adLoader == nil {
            self.adLoader = GFPAdLoader.init(unitID: self.unitId, rootViewController: self, adParam: adParam)
        }
        
        //for banner
        let bannerOption = GFPAdBannerOptions()
        bannerOption.layoutType = .fixed

        self.adLoader?.setBannerDelegate(self, bannerOptions: bannerOption)
        
        //for native
        let nativeOption = GFPAdNativeOptions()
        
        let renderingSetting = GFPNativeAdRenderingSetting()
        //        renderingSetting.preferredAdChoicesViewPosition = // TOD: preferredAdChoicesViewPosition
        renderingSetting.hasMediaView = self.hasMediaView
        
        nativeOption.renderingSetting = renderingSetting
        //        nativeOption.viewableImpThresholdType = .type50p1s // TODO: viewableImpThresholdType
        
        self.adLoader?.setNativeDelegate(self, nativeOptions: nativeOption)
        
        //for nativeSimple
        let nativeSimpleOption = GFPAdNativeSimpleOptions()
        
        let simpleRenderingSetting = GFPNativeSimpleAdRenderingSetting()
        nativeSimpleOption.simpleAdRenderingSetting = simpleRenderingSetting
        
        self.adLoader?.setNativeSimpleDelegate(self, nativeSimpleOptions: nativeSimpleOption)
        
        //        self.adLoader = adLoader
        self.adLoader?.delegate = self
        
        if let isDeduplication = UserDefaults.adConfig()?.isDeduplication, isDeduplication == true {
            self.dedupeManager?.loadAd(with: self.adLoader!)
        } else {
            self.adLoader?.loadAd()
        }
    }
    
}


//MARK: - GFPAdLoaderDelegate
extension DisplayAdViewController : GFPAdLoaderDelegate {
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceiveBannerAd bannerView: GFPBannerView!) {
        self.resetSubViews()

        self.bannerView = bannerView
        self.bannerView?.delegate = self
        self.view.addSubview(bannerView)

        self.updateBannerViewFluid()
        self.bannerView?.showDebugBorder(withColor: .red)

        let message = "GFPAdLoader didReceiveBannerAd - \(bannerView.adProviderName!)"
        MainViewManager.shared.addHistory(message)
    }
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeAd: GFPNativeAd!) {
        self.resetSubViews()
        
        nativeAd.delegate = self
        
        if self.adType == .display {
            self.view.addSubview(self.nativeAdView!)
            
            self.nativeAdView?.nativeAd = nativeAd
            
            self.nativeAdView?.titleLabel?.text = nativeAd.title
            self.nativeAdView?.bodyLabel?.text = nativeAd.body
            self.nativeAdView?.advertiserLabel?.text = nativeAd.advertiser
            self.nativeAdView?.callToActionLabel?.text = nativeAd.callToAction
            
            self.nativeAdView?.showDebugBorder(withColor: .blue)
        } else {
            //.nativeBanner
            self.view.addSubview(self.nativeBannerAdView!)
            self.nativeBannerAdView?.updateNativeBanner(nativeAd: nativeAd)
        }
        
        let message = "GFPAdLoader didReceive NativeAd - \(nativeAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeSimpleAd: GFPNativeSimpleAd!) {
        self.resetSubViews()
        
        nativeSimpleAd.delegate = self
        self.view.addSubview(self.nativeSimpleAdView!)
        
        self.nativeSimpleAdView?.nativeAd = nativeSimpleAd
        self.nativeSimpleAdView?.showDebugBorder(withColor: .green)
        
        let message = "GFPAdLoader didReceive nativeSimpleAd - \(nativeSimpleAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didFailWithError error: GFPError!, responseInfo: GFPLoadResponseInfo!) {
        self.resetSubViews()
        
        let message = "GFPAdLoader didFailWithError - \(error.localizedDescription), responseInfo - \(String(describing: responseInfo))"
        MainViewManager.shared.addHistory(message)
    }
}


//MARK: - GFPNativeAdDelegate
extension DisplayAdViewController: GFPNativeAdDelegate {
    
    func nativeAdWasSeen(_ nativeAd: GFPNativeAd) {
        let message = "Native Ad Was Seen \(nativeAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func nativeAdWasClicked(_ nativeAd: GFPNativeAd) {
        let message = "Native Ad Was Clicked \(nativeAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func nativeAd(_ nativeAd: GFPNativeAd, didFailWithError error: GFPError) {
        let message = "Native Ad Error \(error)"
        MainViewManager.shared.addHistory(message)
    }
    
}

//MARK: - GFPBannerViewDelegate
extension DisplayAdViewController: GFPBannerViewDelegate {

    func bannerAdWasSeen(_ bannerView: GFPBannerView) {
        let message = "Banner Ad Was Seen \(bannerView.adProviderName!)"
        MainViewManager.shared.addHistory(message)
    }

    func bannerAdWasClicked(_ bannerView: GFPBannerView) {
        let message = "Banner Ad Was Clicked \(bannerView.adProviderName!)"
        MainViewManager.shared.addHistory(message)
    }

    func bannerView(_ bannerView: GFPBannerView, didChangeWith size: GFPBannerAdSize) {
        updateBannerViewSize(bannerSize: size)

        let message = "Banner Ad Size Did Change \(size)"
        MainViewManager.shared.addHistory(message)
    }

    func bannerView(_ bannerView: GFPBannerView, didChangeAdMeta adMeta: [String : String]) {
        let message = "Banner Ad AdMeta Did Change \(adMeta)"
        MainViewManager.shared.addHistory(message)
    }

}


//MARK: - GFPNativeSimpleAdDelegate
extension DisplayAdViewController : GFPNativeSimpleAdDelegate {
    
    func nativeSimpleAdWasSeen(_ nativeSimpleAd: GFPNativeSimpleAd) {
        let message = "NativeSimple Ad Was Seen \(nativeSimpleAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func nativeSimpleAdWasClicked(_ nativeSimpleAd: GFPNativeSimpleAd) {
        let message = "NativeSimple Ad Was Clicked \(nativeSimpleAd.adProviderName)"
        MainViewManager.shared.addHistory(message)
    }
    
    func nativeSimpleAd(_ nativeSimpleAd: GFPNativeSimpleAd, didChangeMediaViewSizeWith size: CGSize) {
        self.updateSimpleAdViewSize(size: size)
        
        let message = "NativeSimple MediaView did Change Size \n- (w: \(size.width), h: \(size.height), w/h: \(size.width/size.height)"
        MainViewManager.shared.addHistory(message)
    }
    
    func nativeSimpleAd(_ nativeSimpleAd: GFPNativeSimpleAd, didFailWithError error: GFPError) {
        self.resetSubViews()
        
        let message = "NativeSimple Ad Was Error \(error)"
        MainViewManager.shared.addHistory(message)
    }
}

