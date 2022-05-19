//
//  SettingData.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

enum SettingType : Int {
    case adParam
    case language
    case deduplication
    case timeout
    case testMode
    case darkMode
    case version
    
    var title : String {
        switch self {
        case .darkMode:
            return "Setting_Dark_Mode".localized
        case .adParam:
            return "Setting_Ad_Param".localized
        case .language:
            return "Setting_Language".localized
        case .deduplication:
            return "Setting_Deduplication".localized
        case .timeout:
            return "Setting_TimeOut".localized
        case .testMode:
            return "Setting_TestMode".localized
        case .version:
            return "App : \(Bundle.currentVersion) - GFPSDK version : \(AdGFPSDKManger.shared.sdkVersion())"
        }
    }
}

enum SettingSectionType : Int, CaseIterable {
    case appConfigs
    case SDKConfigs
    
    var title : String {
        switch self {
        case .appConfigs:
            return "App_Configs".localized
        case .SDKConfigs:
            return "SDK_Configs".localized
        }
    }
    
    var settings: [SettingType] {
        switch self {
        case .appConfigs:
            return [.darkMode, .language]
        case .SDKConfigs:
            return [.adParam, .deduplication, .timeout, .testMode, .version]
        }
    }
}

enum SettingLanguageType : String {
    
    case kr
    case en
    case jp
    case id
    case zh
    case th
    
    var languageID: String {
        switch self {
        case .kr, .en, .jp, .id, .th:
            return self.rawValue
        case .zh :
            return "zh-hans"
        }
    }
    
    var title: String {
        switch self {
        case .kr:
            return "Setting_Lang_KR".localized(param: self.languageID)
        case .en:
            return "Setting_Lang_EN".localized(param: self.languageID)
        case .jp:
            return "Setting_Lang_JP".localized(param: self.languageID)
        case .id:
            return "Setting_Lang_ID".localized(param: self.languageID)
        case .zh:
            return "Setting_Lang_ZH".localized(param: self.languageID)
        case .th:
            return "Setting_Lang_TH".localized(param: self.languageID)
        }
    }
    
}


enum SettingSwitchType : Int {
    
    case bannerNativeUnified = 0
    
}

enum SettingTestModeType : Int {
    case facebook
    case google
    case mopub
}



class SettingData {
    
    private(set) var type : SettingType
    
    init(type : SettingType) {
        self.type = type
    }
    
    var title: String {
        return self.type.title
    }
}



class SettingBaseData {
    
    var title : String
    var desc : String
    
    init(title : String, desc : String) {
        self.title = title
        self.desc = desc
    }
}



class SettingSwitchData : SettingBaseData {
    
    var switchOn : Bool
    
    override init(title: String, desc: String) {
        self.switchOn = false
        
        super.init(title: title, desc: desc)
    }
    
    func updateSwitch() {
        self.switchOn = !self.switchOn
    }
}




class SettingTestModeSwitchData : SettingSwitchData {
    
    private var modeType : SettingTestModeType
    
    init(mode : SettingTestModeType) {
        self.modeType = mode
        
        super.init(title: "", desc: "")
        
        self.title = testModeTitle(mode: mode)
        self.desc = testModeSubTitle(mode: mode)
        self.switchOn = selectedTestMode(mode: mode)
    }
    
    var mode : SettingTestModeType {
        get {
            return self.modeType
        }
    }
    
    override func updateSwitch() {
        super.updateSwitch()
        
        updateTestModeOn(testModeOn: self.switchOn)
    }
    
    //MARK: - Private
    private func updateTestModeOn(testModeOn : Bool) {
        switch self.mode {
        case .facebook:
            UserDefaults.testModeFacebook = testModeOn
        case .google:
            UserDefaults.testModeGoogle = testModeOn
        case .mopub:
            UserDefaults.testModeMopub = testModeOn
        }
    }
    
    private func testModeTitle(mode : SettingTestModeType) -> String {
        return NSLocalizedString("Setting_TestMode", comment: "")
    }
    
    private func testModeSubTitle(mode : SettingTestModeType) -> String {
        switch self.mode {
        case .facebook:
            return NSLocalizedString("Setting_Test_Facebook", comment: "")
        case .google:
            return NSLocalizedString("Setting_Test_Google", comment: "")
        case .mopub:
            return NSLocalizedString("Setting_Test_Mopub", comment: "")
        }
    }
    
    private func selectedTestMode(mode : SettingTestModeType) -> Bool {
        switch self.mode {
        case .facebook:
            return UserDefaults.testModeFacebook
        case .google:
            return UserDefaults.testModeGoogle
        case .mopub:
            return UserDefaults.testModeMopub
        }
    }
}



class SettingAdParamSwitchData : SettingSwitchData {
    
    private var configType : ConfigType
    
    var type : ConfigType {
        get {
            return self.configType
        }
    }
    
    init(configType : ConfigType, config : AdConfig) {
        self.configType = configType
        
        super.init(title: "", desc: "")
        
        self.switchOn = isSwitchOn(config: config)
        self.title = configTitle()
    }
    
    override func updateSwitch() {
        super.updateSwitch()
        
        self.title = configTitle()
    }
    
    //MARK: - Private
    private func configTitle() -> String {
        switch self.configType {
        case .darkMode:
            return "Setting_Dark_Mode".localized
        case .gender:
            let gender = (self.switchOn == true) ? "Setting_Male".localized : "Setting_Female".localized
            return String(format: NSLocalizedString("Setting_Gender", comment: ""), gender)
        case .age:
            return ""
        case .deduplication:
            return NSLocalizedString("Setting_Ad_Param_Deduplication", comment: "")
        case .numAdsDeduped:
            return ""
        }
    }
    
    private func isSwitchOn(config : AdConfig) -> Bool {
        switch self.configType {
        case .darkMode:
            return false
        case .gender:
            return config.gender == .male ? true : false
        case .age:
            return false
        case .deduplication:
            return config.isDeduplication
        case .numAdsDeduped:
            return false
        }
    }
}



class SettingSelectBaseData {
    
    private var settingId : String
    private var isSelectedVal : Bool
    
    var title : String {
        return self.settingId
    }
    
    var id: String {
        return self.settingId
    }
    
    var isSelected: Bool {
        return self.isSelectedVal
    }
    
    init(settingId : String, isSelected : Bool) {
        self.settingId = settingId
        self.isSelectedVal = isSelected
    }

    func updateSelected(isSelected : Bool) {
        self.isSelectedVal = isSelected
    }
}



class SettingLanguageData : SettingSelectBaseData {
    
    private(set) var type : SettingLanguageType
    
    override var title: String {
        return self.type.title
    }
    
    init(type : SettingLanguageType) {
        self.type = type
        
        super.init(settingId: "", isSelected: false)
    }
    
    override var isSelected: Bool {
        return (UserDefaults.language == self.type.rawValue)
    }
    
    override func updateSelected(isSelected: Bool) {
        super.updateSelected(isSelected: isSelected)
    }
    
    func save() {
        UserDefaults.language = self.type.rawValue
    }
}



class SettingConfigData : SettingSliderPresentable {
    
    var type : ConfigType
    private var adConfig : AdConfig
    
    init(type : ConfigType, adConfig : AdConfig) {
        self.type = type
        self.adConfig = adConfig
    }
    
    //MARK: - SettingSliderPresentable
    
    var title: String {
        return self.type.title
    }
    
    
    var value: Int {
        switch self.type {
        case .darkMode:
            return self.adConfig.darkMode.rawValue
        case .age:
            return self.adConfig.age
        case .gender:
            return 0
        case .deduplication:
            return 0
        case .numAdsDeduped:
            return self.adConfig.numAdsDeduped
        }
    }
    
    var min: Int {
        return self.type.min
    }
    
    var max: Int {
        return self.type.max
    }
    
    var configType: ConfigType {
        return self.type
    }
    
}


class SettingTimeoutBase : NSObject, InputPresentable {
    
    
    private var type : SettingTimeoutType
    private(set) var value : Double
    
    //MARK: - Public
    
    init(type : SettingTimeoutType, val : Double) {
        self.type = type
        self.value = val
    }
    
    var title: String {
        let info = AdTimeoutInfo.defaultTimeout
        switch self.type {
        case .displayAd:
            return String(format: NSLocalizedString("Setting_TimeOut_DisplayAd", comment: ""), String(info.displayAdTimeout))
//        case .videoAd:
//            return String(format: NSLocalizedString("Setting_TimeOut_Video", comment: ""), String(info.videoAdTimeout))
        case .rewardedAd:
            return String(format: NSLocalizedString("Setting_TimeOut_RewardedAd", comment: ""), String(info.rewardedAdTimeout))
        case .interstitialAd:
            return String(format: NSLocalizedString("Setting_TimeOut_InterstitialAd", comment: ""), String(info.interstitialAdTimeout))
        }
    }
    
    var timeoutType: SettingTimeoutType {
        return self.type
    }
}

