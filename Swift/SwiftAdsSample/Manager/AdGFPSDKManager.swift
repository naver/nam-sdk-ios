//
//  AdGFPSDKManager.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import GFPSDK


class AdGFPSDKManger : NSObject, GFPAdManagerDelegate {
    
    static let shared = AdGFPSDKManger()
    
    override init() {
        super.init()
        self.setupNotification()
        
        self.turnOnDebug()
        self.updateTestMode()
        self.updateTimeOutAll()
        self.updateLoudness()
    }
    
    private func setupNotification() {
        NotificationCenter.default.addObserver(self, selector: #selector(timeOutUpdateNotification), name: NotificationConstant.timeOutUpdate, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(testModeUpdateNotification), name: NotificationConstant.testModeUpdate, object: nil)
    }
    
    private func turnOnDebug() {
//        GFPAdManager.perform(Selector("turnOnDebugMode"))
        GFPAdManager.adConfiguration().logLevel = .trace
    }
    
    private func updateTestMode() {
        let dfpConfig = GFPAdProviderSetting.type(.DFP, testMode: UserDefaults.testModeGoogle)!
        let fanConfig = GFPAdProviderSetting.type(.FAN, testMode: UserDefaults.testModeFacebook)!
        let mopubConfig = GFPAdProviderSetting.type(.moPub, testMode: UserDefaults.testModeMopub)!
        
        GFPAdManager.adConfiguration().adProviderConfigList = [dfpConfig, fanConfig, mopubConfig]
    }
    
    private func updateTimeOutAll() {
        if let adTimeoutInfo = UserDefaults.adTimeoutInfo() {
            let displayTimeout = adTimeoutInfo.displayAdTimeout
//            let videoTimeout = adTimeoutInfo.videoAdTimeout
            let rewardTimeout = adTimeoutInfo.rewardedAdTimeout
            let interstitialTimeout = adTimeoutInfo.interstitialAdTimeout
            
            GFPAdManager.adConfiguration().unifiedAdRequestTimeout = displayTimeout
//            GFPAdManager.adConfiguration().videoAdRequestTimeout = videoTimeout
            GFPAdManager.adConfiguration().rewardedAdRequestTimeout = rewardTimeout
            GFPAdManager.adConfiguration().interstitialAdRequestTimeout = interstitialTimeout
        }
    }
    
    private func updateLoudness() {
        GFPAdManager.adConfiguration().useLoudness = true
    }
    
    private func updateDisplayType() {
        let displayAgent : GFPRenderDisplayAgent = GFPRenderDisplayAgent(type: .displayAgentTypeNativeSafari)
        GFPAdManager.adConfiguration().displayAgent = displayAgent
    }
    
    private func updateLogTrace() {
        GFPAdManager.adConfiguration().logLevel = .trace
    }
        
    private func updateRealPhase() {
        GFPAdManager.adConfiguration().phase = .real
        
    }
    
    //MARK: - Notification
    @objc private func timeOutUpdateNotification() {
        self.updateTimeOutAll()
    }
    
    @objc private func testModeUpdateNotification() {
        self.updateTestMode()
    }
    
    //MARK: - Public
    
    static func gender() -> GFPAdParamGenderType {
        if let type = UserDefaults.adConfig()?.gender {
            switch type {
            case .male:
                return GFPAdParamGenderType.male
            case .female:
                return GFPAdParamGenderType.female
            case .other:
                return GFPAdParamGenderType.other
            }
        }
        
        return .other
    }
    
    static func yearOfBirth() -> UInt {
        if let config = UserDefaults.adConfig() {
            return UInt(Calendar.currentYear - config.age)
        }
        
        return 0
    }
    
    func setupGFPSDK() {
        self.updateRealPhase()

        GFPAdManager.setup(withPublisherCd: nil, target:self, completionHandler: { (error: GFPError?) in
            print("Setup Eror: \(String(describing: error?.description))")
        })
        
        self.updateDisplayType()
        self.updateLogTrace()
    }
    
    func sdkVersion() -> String {
        return GFPAdManager.sdkVersion()
    }
    
    @objc func attStatus() -> GFPATTAuthorizationStatus {
        return .authorizeNotDetermined
    }
}
