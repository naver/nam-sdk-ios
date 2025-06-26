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

class DisplayAdExample: AdViewController {

    // Unified Ad Loader
    // https://naver.github.io/nam-sdk-guide/ios/banner/guide#뷰-컨트롤러-작성
    private var adLoader: GFPAdLoader?

    // Ad Views
    private var bannerView: GFPBannerView?
    private var nativeAdView: GFPNativeAdView?
    private var nativeSimpleAdView: GFPNativeSimpleAdView?

    // For Native Ad
    private var hasMediaView: Bool = true

    private var dedupeManager: GFPAdDedupeManager?

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.configureViews()
    }
    
    override func loadAd() {
        super.loadAd()

        addLog("Loading Ad ...")

        let adLoader = self.configureSDKBySwiftSample()

//        let adLoader = self.configureSDKOnYourOwn()

        self.adLoader = adLoader

        adLoader.delegate = self

        adLoader.loadAd()
    }

    private func configureSDKOnYourOwn() -> GFPAdLoader {
        // https://naver.github.io/nam-sdk-guide/ios/banner/guide#gfpadloader-생성-및-광고-요청

        // https://naver.github.io/nam-sdk-guide/ios/common/get_started#namsdk-광고매니저-설정
        // Sets GFPAdConfiguration before setup.
        let configuration = GFPAdConfiguration()
        configuration.displayAgent = GFPRenderDisplayAgent(type: .displayAgentTypeScheme, scheme: "MyAppScheme")

        // We recommend doing this setup process only once at your app's startup.
        GFPAdManager.setup(withPublisherCd: "YourPublisherCd", target:self, configuration: configuration) { (error : GFPError?) in
            print("Setup Error: \(String(describing: error?.description))")
        }

        // You can set GFPAdConfiguration also after setup.
        // https://naver.github.io/nam-sdk-guide/ios/common/get_started#스타일-설정
        GFPAdManager.adConfiguration().adInterfaceStyle = .light


        // https://naver.github.io/nam-sdk-guide/ios/banner/guide#광고-렌더링-타입-기본값-gfpdisplayagenttypeinapp
        GFPAdManager.adConfiguration().displayAgent = GFPRenderDisplayAgent(type: .displayAgentTypeInApp)

        let adParam = GFPAdParam()
        adParam.keywords = ["MyKeyword1", "MyKeyword2"]
        adParam.currentPageUrl = "www.naver.com"
        adParam.referrerPageUrl = "www.referrer.com"
//        adParam.apsParam
//        adParam.prebidHBParam

        // https://naver.github.io/nam-sdk-guide/ios/banner/guide#광고-요청-타임아웃-기본값-60초
        let adLoader = GFPAdLoader.init(unitID: self.unitId ?? "", rootViewController: self, adParam: adParam)
        adLoader.requestTimeoutInterval = 60

        // https://naver.github.io/nam-sdk-guide/ios/banner/guide#네이티브-광고-동시-로드
        // Banner Ad
        let bannerOption = GFPAdBannerOptions()
        bannerOption.layoutType = .fluidWidth // https://naver.github.io/nam-sdk-guide/ios/banner/guide#배너-레이아웃-타입-설정
        adLoader.setBannerDelegate(self, bannerOptions: bannerOption)

        // Native Ad
        let renderingSetting = GFPNativeAdRenderingSetting()
        renderingSetting.preferredAdChoicesViewPosition = .topRightCorner
        renderingSetting.hasMediaView = self.hasMediaView
        renderingSetting.useInternalCache = true
        let nativeOption = GFPAdNativeOptions()
        nativeOption.renderingSetting = renderingSetting
        adLoader.setNativeDelegate(self, nativeOptions: nativeOption)

        // NativeSimple Ad
        let simpleRenderingSetting = GFPNativeSimpleAdRenderingSetting()
        simpleRenderingSetting.preferredAdChoicesViewPosition = .topRightCorner
        let nativeSimpleOption = GFPAdNativeSimpleOptions()
        nativeSimpleOption.simpleAdRenderingSetting = simpleRenderingSetting
        adLoader.setNativeSimpleDelegate(self, nativeSimpleOptions: nativeSimpleOption)

        return adLoader
    }

    private func configureSDKBySwiftSample() -> GFPAdLoader {

        let adParam = SettingsManager.shared.adParam

        let adLoader = GFPAdLoader.init(unitID: self.unitId ?? "", rootViewController: self, adParam: adParam)

        adLoader.setBannerDelegate(self, bannerOptions: SettingsManager.shared.bannerOptions)

        adLoader.setNativeDelegate(self, nativeOptions: SettingsManager.shared.nativeOptions)

        adLoader.setNativeSimpleDelegate(self, nativeSimpleOptions: SettingsManager.shared.nativeSimpleOptions)

        return adLoader
    }
    
    //MARK: - Private Setup

    private func configureViews() {
        self.nativeAdView = UIView.loadWithBundle(aBundle: .main, nibName: "GFPNativeAdView") as? GFPNativeAdView
        self.nativeAdView?.showDebugBorder(withColor: .blue)
        
        self.nativeSimpleAdView = UIView.loadWithBundle(aBundle: .main, nibName: "GFPNativeSimpleAdView") as? GFPNativeSimpleAdView
        self.nativeSimpleAdView?.showDebugBorder(withColor: .green)
    }
    
    private func resetViews() {
        self.bannerView?.removeFromSuperview()
        self.nativeAdView?.removeFromSuperview()
        self.nativeSimpleAdView?.removeFromSuperview()
    }

    private func updateSimpleAdViewSize(size : CGSize) {
        self.nativeSimpleAdView?.updateSizeWith(type: .height, value: size.height)
        self.nativeSimpleAdView?.mediaView?.updateSizeWith(type: .height, value: size.height)
    }
    
    //MARK: - View Position & frame

    private let MaxFluidBannerWidth: CGFloat = 414
    private let MaxFluidBannerHeight: CGFloat = 300

    private func updateBannerViewLayout(adSize : GFPBannerAdSize) {
        self.bannerView?.snp.remakeConstraints { make in
            make.centerX.top.equalToSuperview()
        }

        switch adSize.type {
        case .fixed:
            self.bannerView?.snp.makeConstraints { make in
                make.size.equalTo(adSize.size)
            }

        case .fluid:
            self.bannerView?.snp.makeConstraints { make in
                make.width.equalTo(min(self.bannerView?.superview?.safeAreaLayoutGuide.layoutFrame.width ?? .infinity, MaxFluidBannerWidth))
                make.height.equalTo(min(self.bannerView?.superview?.safeAreaLayoutGuide.layoutFrame.height ?? .infinity, MaxFluidBannerHeight))
            }

        case .fluidWidth:
            self.bannerView?.snp.makeConstraints { make in
                make.width.equalTo(min(self.bannerView?.superview?.safeAreaLayoutGuide.layoutFrame.width ?? .infinity, MaxFluidBannerWidth))
                make.height.equalTo(adSize.size.height)
            }

        case .fluidHeight:
            self.bannerView?.snp.makeConstraints { make in
                make.width.equalTo(adSize.size.width)
                make.height.equalTo(min(self.bannerView?.superview?.safeAreaLayoutGuide.layoutFrame.height ?? .infinity, MaxFluidBannerHeight))
            }

        default:
            break
        }

    }
}

//MARK: - GFPAdLoaderDelegate
// https://naver.github.io/nam-sdk-guide/ios/banner/guide#gfpadloaderdelegate-구현

extension DisplayAdExample : GFPAdLoaderDelegate {
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceiveBannerAd bannerView: GFPBannerView!) {
        addLog("GFPAdLoader didReceiveBannerAd - \(bannerView.adProviderName!)")

        self.resetViews()

        self.bannerView = bannerView
        self.bannerView?.delegate = self
        self.view.addSubview(bannerView)

        updateBannerViewLayout(adSize: bannerView.adSize)

        self.bannerView?.showDebugBorder(withColor: .red)
    }


    // https://naver.github.io/nam-sdk-guide/ios/native/guide_nn#네이티브-광고-뷰-생성
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeAd: GFPNativeAd!) {
        addLog("GFPAdLoader didReceive NativeAd - \(nativeAd.adProviderName)")

        self.resetViews()

        nativeAd.delegate = self

        guard let nativeAdView = self.nativeAdView else { return }

        self.view.addSubview(nativeAdView)

        nativeAdView.updateSizeWith(type: .width, value: self.view.bounds.size.width)
        nativeAdView.mediaView?.updateSizeWith(type: .width, value: self.view.bounds.size.width)

        nativeAdView.nativeAd = nativeAd

        nativeAdView.titleLabel?.text = nativeAd.title
        nativeAdView.bodyLabel?.text = nativeAd.body
        nativeAdView.advertiserLabel?.text = nativeAd.advertiser
        nativeAdView.callToActionLabel?.text = nativeAd.callToAction
        nativeAdView.noticeLabel?.text = nativeAd.notice

        nativeAdView.showDebugBorder(withColor: .blue)
    }

    // https://naver.github.io/nam-sdk-guide/ios/native/guide_ns#네이티브-이미지형-광고-뷰-생성
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeSimpleAd: GFPNativeSimpleAd!) {
        addLog("GFPAdLoader didReceive nativeSimpleAd - \(nativeSimpleAd.adProviderName)")

        self.resetViews()

        nativeSimpleAd.delegate = self
        self.view.addSubview(self.nativeSimpleAdView!)

        self.nativeSimpleAdView?.updateSizeWith(type: .width, value: self.view.bounds.size.width)
        self.nativeSimpleAdView?.mediaView?.updateSizeWith(type: .width, value: self.view.bounds.size.width)

        self.nativeSimpleAdView?.nativeAd = nativeSimpleAd
        self.nativeSimpleAdView?.showDebugBorder(withColor: .green)
    }
    
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didFailWithError error: GFPError!, responseInfo: GFPLoadResponseInfo!) {
        addLog("GFPAdLoader didFailWithError - \(error.localizedDescription), responseInfo - \(String(describing: responseInfo))")

        self.resetViews()
    }
}

//MARK: - GFPBannerViewDelegate
extension DisplayAdExample: GFPBannerViewDelegate {

    func bannerAdWasSeen(_ bannerView: GFPBannerView) {
        addLog("Banner Ad Was Seen \(bannerView.adProviderName!)")
    }

    func bannerAdWasClicked(_ bannerView: GFPBannerView) {
        addLog("Banner Ad Was Clicked \(bannerView.adProviderName!)")
    }

    func bannerView(_ bannerView: GFPBannerView, didChangeWith size: GFPBannerAdSize) {
        addLog("Banner Ad Size Did Change \(size)")

        updateBannerViewLayout(adSize: size)
    }

    func bannerView(_ bannerView: GFPBannerView, didChangeAdMeta adMeta: [String : String]) {
        addLog("Banner Ad AdMeta Did Change \(adMeta)")
    }

}


//MARK: - GFPNativeAdDelegate
extension DisplayAdExample: GFPNativeAdDelegate {
    
    func nativeAdWasSeen(_ nativeAd: GFPNativeAd) {
        addLog("Native Ad Was Seen \(nativeAd.adProviderName)")
    }
    
    func nativeAdWasClicked(_ nativeAd: GFPNativeAd) {
        addLog("Native Ad Was Clicked \(nativeAd.adProviderName)")
    }
    
    func nativeAd(_ nativeAd: GFPNativeAd, didFailWithError error: GFPError) {
        addLog("Native Ad Error \(error)")
    }
    
}


//MARK: - GFPNativeSimpleAdDelegate
extension DisplayAdExample : GFPNativeSimpleAdDelegate {
    
    func nativeSimpleAdWasSeen(_ nativeSimpleAd: GFPNativeSimpleAd) {
        addLog("NativeSimple Ad Was Seen \(nativeSimpleAd.adProviderName)")
    }
    
    func nativeSimpleAdWasClicked(_ nativeSimpleAd: GFPNativeSimpleAd) {
        addLog("NativeSimple Ad Was Clicked \(nativeSimpleAd.adProviderName)")
    }
    
    func nativeSimpleAd(_ nativeSimpleAd: GFPNativeSimpleAd, didChangeMediaViewSizeWith size: CGSize) {
        addLog("NativeSimple MediaView did Change Size \n- (w: \(size.width), h: \(size.height), w/h: \(size.width/size.height)")

        self.updateSimpleAdViewSize(size: size)
    }
    
    func nativeSimpleAd(_ nativeSimpleAd: GFPNativeSimpleAd, didFailWithError error: GFPError) {
        addLog("NativeSimple Ad Was Error \(error)")

        self.resetViews()
    }
}


// https://naver.github.io/nam-sdk-guide/ios/common/get_started#gfpadmanagerdelegate-설정-및-example
import AdSupport
import AppTrackingTransparency

extension DisplayAdExample: GFPAdManagerDelegate {
    func attStatus() -> GFPATTAuthorizationStatus {
        if #available(iOS 14.5, *) {
            return GFPATTAuthorizationStatus(rawValue:  Int(ATTrackingManager.trackingAuthorizationStatus.rawValue)) ?? .notDetermined
        } else {
            if ASIdentifierManager.shared().isAdvertisingTrackingEnabled {
                return .authorized
            }
            return .notDetermined
        }
    }
}
