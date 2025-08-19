//
//  SettingsHelper.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import AppTrackingTransparency
import AdSupport
import GFPSDK
//import PrebidMobile
//import DTBiOSSDK


fileprivate extension String {
    static let darkMode = "SettingsManager.darkMode"
    static let language = "SettingsManager.language"
    static let testModeDFP = "SettingsManager.testModeDFP"
    static let testModeFAN = "SettingsManager.testModeFAN"
    static let testModeGFP = "SettingsManager.testModeGFP"
    static let testModeUnity = "SettingsManager.testModeUnity"
    static let timeoutDisplayAd = "SettingsManager.timeoutDisplayAd"
    static let timeoutVideoAd = "SettingsManager.timeoutVideoAd"
    static let timeoutRewardedAd = "SettingsManager.timeoutRewardedAd"
    static let timeoutInterstitialAd = "SettingsManager.timeoutInterstitialAd"
    static let useLoudness = "SettingsManager.useLoudness"
    static let displayType = "SettingsManager.displayType"
    static let logLevel = "SettingsManager.logLevel"
    static let phase = "SettingsManager.phase"
    static let gender = "SettingsManager.gender"
    static let yearOfBirth = "SettingsManager.yearOfBirth"
    static let userCountryCode = "SettingsManager.userCountryCode"
    static let userID = "SettingsManager.userID"
    static let displayAgent = "SettingsManager.displayAgent"
    static let dedupEnabled = "SettingsManager.dedupEnabled"
    static let dedupNumber = "SettingsManager.dedupNumber"
    static let deviceIp = "SettingsManager.deviceIp"
    static let prebidEnabled = "SettingsManager.prebidEnabled"
    static let prebidAcountId = "SettingsManager.prebidAccountId"
    static let prebidConfig = "SettingsManager.prebidConfig"
    static let prebidPrice = "SettingsManager.prebidPrice"
    static let prebidPriceAppNexus = "SettingsManager.prebidPriceAppNexus"
    static let apsEnabled = "SettingsManager.apsEnabled"
    static let apsTestMode = "SettingsManager.apsTestMode"
    static let apsAppKey = "SettingsManager.apsAppKey"
    static let apsSlotInfo = "SettingsManager.apsSlotInfo"
    static let apsAppKeys = "SettingsManager.apsAppKeys"
    static let useImageCache = "SettingManager.useImageCache"
    static let useNativeTemplate = "SettingManager.useNativeTemplate"
}

extension Notification.Name {
    static let settingManagerValuesChanged: Self = .init("settingsManagerValuesChanged")
}

class SettingsManager: NSObject {

    static let shared = SettingsManager()

    override init() {
        super.init()
        initializeSDK { error in
            if error == nil {return}

            let alert = UIAlertController(title: "Swift Sample Failed to Initialize SDK", message: error?.localizedDescription, preferredStyle: .alert)

            let closeAction = UIAlertAction(title: "Confirm", style: UIAlertAction.Style.cancel, handler: nil)

            alert.addAction(closeAction)

            UIApplication.shared.keyWindow?.rootViewController?.present(alert, animated: true)
        }
        darkMode = darkMode
        useLoudness = useLoudness
        displayAgent = displayAgent
        logLevel = logLevel
        phase = phase
        useImageCache = useImageCache
        useNativeTemplate = useNativeTemplate
        timeoutDisplayAd = timeoutDisplayAd
        timeoutVideoAd = timeoutVideoAd
        timeoutRewardedAd = timeoutRewardedAd
        timeoutInterstitialAd = timeoutInterstitialAd
        testModeDFP = testModeDFP
        testModeFAN = testModeFAN
        testModeGFP = testModeGFP
        testModeUnity = testModeUnity
        gender = gender
        yearOfBirth = yearOfBirth
        userCountryCode = userCountryCode
        userID = userID
    }

    func resetAllSettings() {
        darkMode = .system
        language = .kr
        useLoudness = false
        logLevel = .debug
        phase = .real
        displayAgent = .displayAgentTypeInApp
        useImageCache = false
        useNativeTemplate = false
        setTimeout(60.0, forType: .displayAd)
        setTimeout(60.0, forType: .videoAd)
        setTimeout(60.0, forType: .rewardedAd)
        setTimeout(60.0, forType: .interstitialAd)
        setTestMode(false, forType: .DFP)
        setTestMode(false, forType: .FAN)
        setTestMode(false, forType: .GFP)
        setTestMode(false, forType: .unity)
        gender = .female
        yearOfBirth = 1980
        userCountryCode = "KR"
        userID = ""
        dedupEnabled = false
        dedupNumber = 2
        deviceIp = "0.0.0.0"
        prebidEnabled = false
        prebidAccountId = "bfa84af2-bd16-4d35-96ad-31c6bb888df0"
        prebidConfig = PrebidConfigInfo(configId: "6ace8c7d-88c0-4623-8117-75bc3f0a2e45", size: .init(width: 300, height: 250))
        prebidPrice = 0
        apsEnabled = false
        apsTestMode = false
        apsAppKey = "83a5710e-5e87-486b-a765-e42d1ec6b940"
        apsSlotInfo = APSSlotInfo(slotUUID: "c5f20fe6e37146b08749d09bb2b6a4dd",
                                  width: 300,
                                  height: 250,
                                  desc: "ios_Discover-Viewerend_300x250")


        Self.postSettingsChanged(self)
    }

    static func postSettingsChanged(_ manager: SettingsManager) {
        NotificationCenter.default.post(name: .settingManagerValuesChanged, object: manager, userInfo: nil)
    }

    static func observeSettingsChanged(using: @escaping (SettingsManager) -> Void) {
        let closure = { (_ notification: Notification) -> Void in
            using(notification.object as! SettingsManager)
        }
        NotificationCenter.default.addObserver(forName: .settingManagerValuesChanged, object: nil, queue: nil, using: closure)
    }

    // MARK: ------ App Settings. ------
    @Persisted(key: .darkMode, defaultValue: .system)
    var darkMode: DarkModeType {
        didSet {
            // https://naver.github.io/nam-sdk-guide/ios/common/get_started#스타일-설정
            GFPAdManager.adConfiguration().adInterfaceStyle = .init(rawValue: darkMode.rawValue)

            if #available(iOS 13.0, *) {
                guard let appDelegate = UIApplication.shared.delegate else { return }
                guard let window = appDelegate.window else { return }

                switch darkMode {
                case .system:
                    window?.overrideUserInterfaceStyle = .unspecified
                case .light:
                    window?.overrideUserInterfaceStyle = .light
                case .dark:
                    window?.overrideUserInterfaceStyle = .dark
                }
            }
        }
    }

    @Persisted(key: .language, defaultValue: .kr)
    var language: SettingsLanguageType // TODO: language settings?


    // MARK: ------ GFPAdManager Settings. ------

    @Persisted(key: .useLoudness, defaultValue: false)
    var useLoudness: Bool {
        didSet {
            GFPAdManager.adConfiguration().useLoudness = useLoudness
        }
    }

    @Persisted(key: .displayType, defaultValue: .displayAgentTypeInApp)
    var displayAgent: GFPRenderDisplayAgentType {
        didSet {
            GFPAdManager.adConfiguration().displayAgent = GFPRenderDisplayAgent(type: displayAgent)
        }
    }

    @Persisted(key: .logLevel, defaultValue: .debug)
    var logLevel: GFPLogLevel {
        didSet {
            // TODO: Swift Enum 이슈 https://oss.navercorp.com/da-ssp-app-sdk/gfp-sdk-ios/issues/1153
//            GFPAdManager.adConfiguration().logLevel = logLevel
            GFPAdManager.adConfiguration().logLevel = .debug
        }
    }

    @Persisted(key: .phase, defaultValue: .test)
    var phase: GFPPhaseType {
        didSet {
            GFPAdManager.adConfiguration().phase = phase
        }
    }

    // MARK: - Timeout settings.

    @Persisted(key: .timeoutDisplayAd, defaultValue: 60.0)
    private var timeoutDisplayAd: TimeInterval

    @Persisted(key: .timeoutVideoAd, defaultValue: 60.0)
    private var timeoutVideoAd: TimeInterval

    @Persisted(key: .timeoutRewardedAd, defaultValue: 60.0)
    private var timeoutRewardedAd: TimeInterval

    @Persisted(key: .timeoutInterstitialAd, defaultValue: 60.0)
    private var timeoutInterstitialAd: TimeInterval

    func setTimeout(_ value: TimeInterval, forType type: RequestTimeoutType) {
        switch type {
        case .displayAd:
            GFPAdManager.adConfiguration().unifiedAdRequestTimeout = value
            timeoutDisplayAd = value
        case .videoAd:
            GFPAdManager.adConfiguration().videoAdRequestTimeout = value
            timeoutVideoAd = value
        case .rewardedAd:
            GFPAdManager.adConfiguration().rewardedAdRequestTimeout = value
            timeoutRewardedAd = value
        case .interstitialAd:
            GFPAdManager.adConfiguration().interstitialAdRequestTimeout = value
            timeoutInterstitialAd = value
        }
    }

    func timeout(forType type: RequestTimeoutType) -> TimeInterval {
        switch type {
        case .displayAd: return timeoutDisplayAd
        case .videoAd: return timeoutVideoAd
        case .rewardedAd: return timeoutRewardedAd
        case .interstitialAd: return timeoutInterstitialAd
        }
    }


    // MARK: - Test Modes

    @PersistedProviderSetting(key: .testModeDFP, defaultValue: .type(.DFP, testMode: false))
    private(set) var testModeDFP: GFPAdProviderSetting

    @PersistedProviderSetting(key: .testModeFAN, defaultValue: .type(.FAN, testMode: false))
    private(set) var testModeFAN: GFPAdProviderSetting

    @PersistedProviderSetting(key: .testModeGFP, defaultValue: .type(.GFP, testMode: false))
    private(set) var testModeGFP: GFPAdProviderSetting

    @PersistedProviderSetting(key: .testModeUnity, defaultValue: .type(.unity, testMode: false))
    private(set) var testModeUnity: GFPAdProviderSetting

    func setTestMode(_ testMode: GFPAdProviderSetting) {
        var configList = [
            GFPAdProviderSetting.type(.DFP, testMode: false),
            GFPAdProviderSetting.type(.FAN, testMode: false),
            GFPAdProviderSetting.type(.GFP, testMode: false),
            GFPAdProviderSetting.type(.unity, testMode: false)
        ].filter { $0.type != testMode.type }

        configList.append(testMode)
        GFPAdManager.adConfiguration().adProviderConfigList = configList
        
        switch testMode.type {
        case .DFP: testModeDFP = testMode
        case .FAN: testModeFAN = testMode
        case .GFP: testModeGFP = testMode
        case .unity: testModeUnity = testMode
        default: break
        }
    }

    func setTestMode(_ testMode: Bool, forType type: GFPAdProviderSettingType) {
        let testMode = GFPAdProviderSetting.type(type, testMode: testMode)
        setTestMode(testMode)
    }

    func isTestMode(forType type: GFPAdProviderSettingType) -> Bool {
        switch type {
        case .DFP: return testModeDFP.isTestMode
        case .FAN: return testModeFAN.isTestMode
        case .GFP: return testModeGFP.isTestMode
        case .unity: return testModeUnity.isTestMode
        default: return false
        }
    }


    // MARK: - UserParams
    @Persisted(key: .gender, defaultValue: .female)
    var gender: GFPUserParamGenderType {
        didSet {
            let userParam = getUserParam()
            userParam.gender = gender
            GFPAdManager.setUserParam(userParam)
        }
    }
    

    @Persisted(key: .yearOfBirth, defaultValue: 1980)
    var yearOfBirth: UInt {
        didSet {
            let userParam = getUserParam()
            userParam.yearOfBirth = yearOfBirth
            GFPAdManager.setUserParam(userParam)
        }
    }

    @Persisted(key: .userCountryCode, defaultValue: "KR")
    var userCountryCode: String {
        didSet {
            let userParam = getUserParam()
            userParam.userCountryCode = userCountryCode
            GFPAdManager.setUserParam(userParam)
        }
    }

    @Persisted(key: .userID, defaultValue: "")
    var userID: String {
        didSet {
            let userParam = getUserParam()
            userParam.userID = userID
            GFPAdManager.setUserParam(userParam)
        }
    }

    private func getUserParam() -> GFPUserParam {
        if let ret = GFPAdManager.userParam() {
            return ret
        } else {
            return GFPUserParam()
        }
    }

    // MARK: - Initialize SDK

    var isSdkInitialized: Bool {
        GFPAdManager.isSdkInitialized()
    }

    func initializeSDK(withPublisherCd cd: PublisherCode = .swiftSample, completion: @escaping (GFPError?) -> Void) {
        GFPAdManager.setup(withPublisherCd: cd.rawValue, target: self) { [weak self] error in
            guard let self = self else {return}
            self.initializeErrorDesc = error.debugDescription
            DispatchQueue.main.async {
                completion(error)
            }
        }
    }

    var initializeErrorDesc: String = ""

    // MARK: - DedupeManager

    @Persisted(key: .dedupEnabled, defaultValue: false)
    var dedupEnabled: Bool

    @Persisted(key: .dedupNumber, defaultValue: 2)
    var dedupNumber: Int


    // MARK: ------ AdParams ------

    var adParam: GFPAdParam {
        let adParam = GFPAdParam()

        // MARK: Not supported in NAM SDK
//        if prebidEnabled {
//            var prebidParam = requestPrebidParam()
//            prebidParam["hb_pb"] = String(describing: prebidPrice)
//            prebidParam["hb_pb_appnexus"] = String(describing: prebidPriceAppNexus)
//            adParam.prebidHBParam = prebidParam
//        }

//        if apsEnabled {
//            let apsParam = requestApsParam()
//            adParam.apsParam = apsParam
//        }

        return adParam
    }

    @Persisted(key: .deviceIp, defaultValue: "0.0.0.0")
    var deviceIp: String

    // MARK: - Header Bidding

//    func requestPrebidParam() -> [String: String] {
//        Prebid.shared.prebidServerAccountId = prebidAccountId
//        Prebid.shared.prebidServerHost = .Appnexus
//        Prebid.shared.shareGeoLocation = true
//
//        let bannerAdUnit = BannerAdUnit.init(configId: prebidConfig.configId, size: prebidConfig.size)
//        let params = NSMutableDictionary()
//
//        var ret: [String: String] = [:]
//
//        bannerAdUnit.fetchDemand(adObject: params) { resultCode in
//            if resultCode == ResultCode.prebidDemandFetchSuccess {
//                ret = params as? [String : String] ?? [:]
//            }
//        }
//
//        return ret
//    }

    var apsDispatchGroup: DispatchGroup = .init()
    // MARK: Not supported in NAM SDK
//    var apsParam: GFPAPSAdParam? = nil
//    func requestApsParam() -> GFPAPSAdParam? {
//        DTBAds.sharedInstance().setAppKey(apsAppKey)
//        DTBAds.sharedInstance().mraidPolicy = CUSTOM_MRAID
//        DTBAds.sharedInstance().mraidCustomVersions = ["1.0", "2.0", "3.0"]
//        DTBAds.sharedInstance().testMode = apsTestMode
//        DTBAds.sharedInstance().setLogLevel(DTBLogLevelAll)
//
//        let slotInfo = apsSlotInfo
//        let dtbAdSize = DTBAdSize(bannerAdSizeWithWidth: slotInfo.width, height: slotInfo.height, andSlotUUID: slotInfo.slotUUID)
//        let dtbAdLoader = DTBAdLoader()
//        dtbAdLoader.setAdSizes([dtbAdSize as Any])
//        apsParam = nil
//        apsDispatchGroup.enter()
//        dtbAdLoader.loadAd(self)
//        _ = apsDispatchGroup.wait(timeout: .now() + 1)
//        if apsParam == nil {
//            AdControlVC.ViewModel.shared.addLog("Failed to fetch APS bidding info.")
//        }
//        return apsParam
//    }

    // --- Prebid ---

    @Persisted(key: .prebidEnabled, defaultValue: false)
    var prebidEnabled: Bool

    @Persisted(key: .prebidAcountId, defaultValue: "bfa84af2-bd16-4d35-96ad-31c6bb888df0")
    var prebidAccountId: String

    @Persisted(key: .prebidConfig, defaultValue: PrebidConfigInfo(configId: "6ace8c7d-88c0-4623-8117-75bc3f0a2e45", size: .init(width: 300, height: 250)))
    var prebidConfig: PrebidConfigInfo

    var prebidAccountIdList: [String] = [
        "bfa84af2-bd16-4d35-96ad-31c6bb888df0"
    ]

    var prebidConfigList: [PrebidConfigInfo] = [
        PrebidConfigInfo(configId: "6ace8c7d-88c0-4623-8117-75bc3f0a2e45", size: .init(width: 300, height: 250)),
PrebidConfigInfo(configId: "6ace8c7d-88c0-4623-8117-75bc3f0a2e45", size: .init(width: 320, height: 100)),
        PrebidConfigInfo(configId: "6ace8c7d-88c0-4623-8117-75bc3f0a2e45", size: .init(width: 320, height: 50)),
    ]

    @Persisted(key: .prebidPrice, defaultValue: 0.0)
    var prebidPrice: Float

    @Persisted(key: .prebidPriceAppNexus, defaultValue: 0.0)
    var prebidPriceAppNexus: Float

    // --- Amazon Publisher Services ---

    @Persisted(key: .apsEnabled, defaultValue: false)
    var apsEnabled: Bool

    @Persisted(key: .apsTestMode, defaultValue: false)
    var apsTestMode: Bool

    @Persisted(key: .apsAppKey, defaultValue: "83a5710e-5e87-486b-a765-e42d1ec6b940")
    var apsAppKey: String

    @Persisted(
        key: .apsSlotInfo,
        defaultValue: APSSlotInfo(slotUUID: "c5f20fe6e37146b08749d09bb2b6a4dd",
                                  width: 300,
                                  height: 250,
                                  desc: "ios_Discover-Viewerend_300x250")
    )
    var apsSlotInfo: APSSlotInfo

    var apsAppKeyList: [String] = [
        "83a5710e-5e87-486b-a765-e42d1ec6b940",
        "c5f20fe6e37146b08749d09bb2b6a4dd"
    ]

    var apsSlotInfoList: [APSSlotInfo] = [
        APSSlotInfo(slotUUID: "c5f20fe6e37146b08749d09bb2b6a4dd",
                    width: 300,
                    height: 250,
                    desc: "ios_Discover-Viewerend_300x250"),

        APSSlotInfo(slotUUID: "196eb8e7-bf6f-49c3-a44d-0571ef874630",
                    width: 300,
                    height: 250,
                    desc: "ios_Viewerend_300x250"),

        APSSlotInfo(slotUUID: "cabf9958-84e9-4a00-a36d-50534a784079",
                    width: 300,
                    height: 250,
                    desc: "webtoon: Rewarded Video"),

        APSSlotInfo(slotUUID: "88e6293b-0bf0-43fc-947b-925babe7bf3f",
                    width: 320,
                    height: 50,
                    desc: "testSlotUUID")
    ]

    // MARK: ------ Ad Options -------

    @Persisted(key: .useImageCache, defaultValue: false)
    var useImageCache: Bool

    @Persisted(key: .useNativeTemplate, defaultValue: false)
    var useNativeTemplate: Bool

    func clearImageCache() {
        GFPAdManager.clearMemoryCache()
    }

    var bannerOptions: GFPAdBannerOptions {
        let bannerOption = GFPAdBannerOptions()
        return bannerOption
    }

    var nativeOptions: GFPAdNativeOptions {
        let nativeRenderingSetting = GFPNativeAdRenderingSetting()
        nativeRenderingSetting.adInterfaceStyle = .init(rawValue: darkMode.rawValue)
        nativeRenderingSetting.useInternalCache = useImageCache
        let nativeOptions = GFPAdNativeOptions()
        nativeOptions.renderingSetting = nativeRenderingSetting
        return nativeOptions
    }

    var nativeSimpleOptions: GFPAdNativeSimpleOptions {
        let simpleRenderingSetting = GFPNativeSimpleAdRenderingSetting()
        simpleRenderingSetting.adInterfaceStyle = .init(rawValue: darkMode.rawValue)
        let nativeSimpleOptions = GFPAdNativeSimpleOptions()
        nativeSimpleOptions.simpleAdRenderingSetting = simpleRenderingSetting
        nativeSimpleOptions.templateOptions = self.nativeTemplateOptions
        return nativeSimpleOptions
    }

    var nativeTemplateOptions: GFPNativeTemplateOptions {
        let templateOptions = GFPNativeTemplateOptions(useNativeTemplate: useNativeTemplate, nativeOptions: self.nativeOptions)

//        let customTemplateView = CustomTemplateView.createView()
//        
//        if let customTemplateView = customTemplateView as? UIView & GFPNativeTemplateViewProtocol {
//            templateOptions.addTemplate(with: kGFPTemplateVisualKey.defaultVisualKey, templateView: customTemplateView)
//        }

        return templateOptions
    }

    var videoRenderingSetting: GFPVideoAdRenderingSetting {
        let renderingSetting = GFPVideoAdRenderingSetting()
        // TODO: add video options
        return renderingSetting
    }

    var videoPlayerSetting: GFPVideoAdPlayerSetting {
        let playerSetting = GFPVideoAdPlayerSetting()
        // TODO: add video options
        return playerSetting
    }

    // MARK: ------ Other ------

    var sdkVersion: String {
        GFPAdManager.sdkVersion()
    }

    var skAdNetworkAvailability: String {
        if #available(iOS 14.0, *), !skAdNetworkIdList.isEmpty {
            return "Supported"
        } else {
            return "Unsupported (needs iOS 14.0, SKAN 2.0)"
        }
    }

    var skAdNetworkVersion: String {
        if #available(iOS 14.6, *) {
            return "3.0"
        } else if #available(iOS 14.5, *) {
            return "2.2"
        } else if #available(iOS 14.1, *) {
            return "2.1"
        } else if #available(iOS 14.0, *) {
            return "2.0"
        } else if #available(iOS 11.3, *) {
            return "1.0"
        } else {
            return "SKAN unsupports this iOS Version"
        }
    }

    var skAdNetworkIdList: [String] {
        guard let list = Bundle.main.infoDictionary?["SKAdNetworkItems"] as? [Any] else { return [] }

        var ret = [String]()

        for item in list {
            if let dict = item as? [String : String], let identifier = dict["SKAdNetworkIdentifier"] {
                ret.append(identifier)
            }
        }

        return ret
    }

    var idfv: String {
        UIDevice.current.identifierForVendor?.uuidString ?? "Unknown"
    }

    var idfa: String {
        ASIdentifierManager.shared().advertisingIdentifier.uuidString
    }
}

extension SettingsManager: GFPAdManagerDelegate {
    func attStatus() -> GFPATTAuthorizationStatus {
        if #available(iOS 14, *) {
            switch ATTrackingManager.trackingAuthorizationStatus {
            case .notDetermined: return .notDetermined
            case .restricted: return .restricted
            case .denied: return .denied
            case .authorized: return .authorized

            default: print("value is invalid."); return .notDetermined
            }
        } else {
            if ASIdentifierManager.shared().isAdvertisingTrackingEnabled {
                return .authorized
            }

            return .notDetermined
        }
    }
}

//extension SettingsManager: DTBAdCallback {
//    func onFailure(_ error: DTBAdError) {
//        /**Please implement the logic to send ad request without our parameters if you want to
//         show ads from other ad networks when Amazon ad request fails**/
//        // MARK: Not supported in NAM SDK
////        apsParam = nil
//        apsDispatchGroup.leave()
//    }
//
//    func onSuccess(_ adResponse: DTBAdResponse!) {
//        /**Build the ad request to your ad server. This portion will differ depending on your
//         ad server**/
//
//        // MARK: Not supported in NAM SDK
////        let apsParam = GFPAPSAdParam()
////        apsParam.crid = adResponse.crid()
////        apsParam.size = CGSizeMake(CGFloat(adResponse.adSize().width), CGFloat(adResponse.adSize().height));
////        apsParam.apsHBParam = adResponse.customTargeting() as? [String : NSObject]
////        apsParam.skAdNetworkParams = adResponse.skAdNetworkParams
////        self.apsParam = apsParam
//        apsDispatchGroup.leave()
//    }
//}
