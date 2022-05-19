//
//  SettingManager.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import UIKit


enum UnitIdSection : Int {
    case idInput
    case idReal
}

class SettingManager {
    public static var shared = SettingManager()
    
    private var settingDicts : [SettingType : [Any]]
    private var settingSections : [SettingType]
    
    init() {
        self.settingDicts = [:]
        self.settingSections = [SettingType.adParam, SettingType.language, /*SettingType.deduplication,*/ SettingType.timeout, SettingType.darkMode, SettingType.testMode, SettingType.version]
        
        fetchSettingList()
        loadFromMemory()
    }
    
    //MARK: - Private
    private func settingsData(type: SettingType) -> [Any] {
        switch type {
        case .darkMode, .adParam, .language, .deduplication, .timeout, .version:
            return [SettingData.init(type: type)]
        case .testMode:
            let facebook = SettingTestModeSwitchData.init(mode: .facebook)
            let google = SettingTestModeSwitchData.init(mode: .google)
            return [facebook, google]
        }
    }
    
    private func testModeData(mode : SettingTestModeType) -> SettingTestModeSwitchData? {
        let testModes = self.settingDicts[.testMode] as? [SettingTestModeSwitchData]
        let filter = testModes?.filter{ $0.mode == mode }
        return filter?.first
    }
    
    //MARK: - Public
    
    func fetchSettingList() {
        self.settingDicts = [:]
        for type in self.settingSections {
            self.settingDicts[type] = settingsData(type: type)
        }
    }
    
    func settingCount() -> Int {
        return self.settingSections.count
    }
    
    func settingsSubCountInSection(section : Int) -> Int {
        let type = settingTypeInSection(section: section)!

        if let settings = settingDicts[type] {
            return settings.count
        } else {
            return 0
        }
    }
    
    func settingTitleTypeInSection(section : Int) -> String {
        let type = settingTypeInSection(section: section)!
        
        if let settings = settingDicts[type] {
            if let data = settings.first as? SettingData {
                return data.type.title
            } else if let data = settings.first as? SettingTestModeSwitchData {
                return data.title
            } else {
                return ""
            }
        } else {
            return ""
        }
    }
    
    func isSwitchType(indexPath : IndexPath) -> Bool {
        return settingTypeInSection(section: indexPath.section) == .testMode
    }
    
    func isDarkMode(indexPath: IndexPath) -> Bool {
        return settingTypeInSection(section: indexPath.section) == .darkMode
    }
    
    func updateTestMode(mode : SettingTestModeType) {
        if let testMode = testModeData(mode: mode) {
            testMode.updateSwitch()
            
            NotificationCenter.default.post(name: NotificationConstant.testModeUpdate, object: self)
        }
    }
    
    func settingTypeInSection(section : Int) -> SettingType? {
        return self.settingSections[section]
    }
    
    func settingsAtIndexPath(indexPath : IndexPath) -> SettingData? {
        let type = settingTypeInSection(section: indexPath.section)!
        
        if self.isSwitchType(indexPath: indexPath) {
            return nil
        }
        
        let datas = self.settingDicts[type] as? [SettingData]
        return datas?[indexPath.row]
    }
    
    func settingSwitchsAtIndexPath(indexPath : IndexPath) -> SettingTestModeSwitchData? {
        let type = self.settingTypeInSection(section: indexPath.section)!
        
        if !self.isSwitchType(indexPath: indexPath) {
            return nil
        }
        
        let datas = self.settingDicts[type] as? [SettingTestModeSwitchData]
        return datas?[indexPath.row]
    }
    
    func setDarkMode(to darkMode: DarkModeType) {
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
            
            UserDefaults.darkMode = darkMode
        }
    }
    
    func getDarkMode() -> DarkModeType {
        return UserDefaults.darkMode
    }
    
    // MARK: - private
    
    private func loadFromMemory() {
        setDarkMode(to: getDarkMode())
    }
}


class SettingConfigManager {
    
    private let configTypes: [ConfigType] = [ConfigType.gender, ConfigType.age]
    private let config: AdConfig? = UserDefaults.adConfig()
    
    private var configList: [Any] = []
    
    init() {
        guard let config = self.config else {
            return;
        }
        
        self.configList = self.configTypes.map {
            if $0 == .age {
                return SettingConfigData.init(type: $0, adConfig: config)
            } else {
                return SettingAdParamSwitchData.init(configType: $0, config: config)
            }
        }
    }
    
    
    //MARK: - Public
    static func reviseConfig() {
        guard let _ = UserDefaults.adConfig() else {
            let config = AdConfig.init(darkMode: .system, gender: .other, age: 25, isDeduplication: false, numAdsDeduped: 3)
            let _ = UserDefaults.updateAdConfig(adConfig: config)
            return;
        }
    }
    
    func save() {
        let _ = UserDefaults.updateAdConfig(adConfig: self.config!)
    }
    
    var configCount: Int {
        return 1
    }
    
    func configRowCount(section : Int) -> Int {
        return self.configList.count
    }
    
    func isSwitchData(indexPath : IndexPath) -> Bool {
        let type = self.configTypes[indexPath.row]
        return type == .gender
    }
    
    func configData(indexPath : IndexPath) -> SettingConfigData? {
        if isSwitchData(indexPath: indexPath) {
           return nil
        }
        
        return self.configList[indexPath.row] as? SettingConfigData
    }
    
    func configSwitchData(indexPath : IndexPath) -> SettingAdParamSwitchData? {
        if !isSwitchData(indexPath: indexPath) {
            return nil
        }
        
        return self.configList[indexPath.row] as? SettingAdParamSwitchData
    }
    
    func updateValue(type : ConfigType, value : Float) {
        if type == .age {
            self.config?.age = Int(value)
        } else {
            print("do nothing")
        }
    }
    
    func updateSwitchData(data : SettingSwitchData) {
        if data is SettingAdParamSwitchData, let switchData = data as? SettingAdParamSwitchData {
            let type = switchData.type
            if type == ConfigType.gender {
                let genderType = (switchData.switchOn == true) ? GenderType.female : GenderType.male
                self.config?.gender = genderType
                
                switchData.updateSwitch()
            }
        }
    }
    
}



protocol SettingLanguageManagerDelegate : AnyObject {
    
    func updateData(manager : SettingLanguageManager)
    
}

class SettingLanguageManager {
    
    private var type : SettingType
    private var settingDetails: [SettingLanguageData] = []
    private var selectedDatas: [SettingLanguageData] = []
    
    weak var delegate : SettingLanguageManagerDelegate?
    
    init(type : SettingType) {
        self.type = type
        
        setup()
    }
    
    //MARK: - Private
    private func setup() {
        switch self.type {
        case .language:
            self.settingDetails = [SettingLanguageType.kr, .en, .jp, .id, .zh, .th].map { SettingLanguageData.init(type: $0) }
            updateSelectedDatas()
        default:
            print("do nothing")
        }
    }
    
    private func updateSelectedDatas() {
        self.selectedDatas = []
        
        let filter = self.settingDetails.filter { $0.isSelected }
        self.selectedDatas.append(contentsOf: filter)
    }
    
    //MARK: - Public
    var count: Int {
        return self.settingDetails.count
    }
    
    func languageData(indexPath : IndexPath) -> SettingLanguageData {
        return self.settingDetails[indexPath.row]
    }
    
    func isSelected(indexPath : IndexPath) -> Bool {
        let data = languageData(indexPath: indexPath)
        return self.selectedDatas.contains { data.type == $0.type }
    }
    
    func updateSelected(indexPath : IndexPath) {
        let selcted = self.languageData(indexPath: indexPath)
        
        for (index, data) in self.settingDetails.enumerated() {
            data.updateSelected(isSelected: (index == indexPath.row))
            
            if data === selcted {
                data.save()
            }
        }
        
        if !self.isSelected(indexPath: indexPath) {
            self.updateSelectedDatas()
        }
        
        self.delegate?.updateData(manager: self)
    }
}




enum SettingTimeoutType : Int {
    case displayAd
//    case videoAd
    case rewardedAd
    case interstitialAd
}

class SettingTimeoutManager {
    
    private var timeouts : [InputPresentable] = []
    private let timeoutInfo : AdTimeoutInfo? = UserDefaults.adTimeoutInfo()
    
    init() {
        let types = [SettingTimeoutType.displayAd, /*.videoAd,*/ .rewardedAd, .interstitialAd]
        
        guard let timeoutInfo = self.timeoutInfo else {
            return;
        }
        
        self.timeouts = types.map {
            switch $0 {
            case .displayAd:
                return SettingTimeoutBase.init(type: $0, val: timeoutInfo.displayAdTimeout)
//            case .videoAd:
//                return SettingTimeoutBase.init(type: $0, val: timeoutInfo.videoAdTimeout)
            case .rewardedAd:
                return SettingTimeoutBase.init(type: $0, val: timeoutInfo.rewardedAdTimeout)
            case .interstitialAd:
                return SettingTimeoutBase.init(type: $0, val: timeoutInfo.interstitialAdTimeout)
            }
        }
    }
    
    //MARK: - Public
    var numberTimeouts: Int {
        return self.timeouts.count
    }
    
    func presentable(indexPath : IndexPath) -> InputPresentable {
        return self.timeouts[indexPath.row]
    }
    
    func updateTimeout(type : SettingTimeoutType, value : Double) {
        let defaultTimeout = AdTimeoutInfo.defaultTimeout
        
        switch type {
        case .displayAd:
            self.timeoutInfo?.displayAdTimeout = value > 0 ? value : defaultTimeout.displayAdTimeout
//        case .videoAd:
//            self.timeoutInfo?.videoAdTimeout = value > 0 ? value : defaultTimeout.videoAdTimeout
        case .rewardedAd:
            self.timeoutInfo?.rewardedAdTimeout = value > 0 ? value : defaultTimeout.rewardedAdTimeout
        case .interstitialAd:
            self.timeoutInfo?.interstitialAdTimeout = value > 0 ? value : defaultTimeout.interstitialAdTimeout
        }
    }
    
    func save() {
        self.timeoutInfo?.save()
        
        NotificationCenter.default.post(name: NotificationConstant.timeOutUpdate, object: self, userInfo: nil)
    }
    
    static func reviseTimeout() {
        guard let _ = UserDefaults.adTimeoutInfo() else  {
            let _ = UserDefaults.updateTimeout(info: AdTimeoutInfo.defaultTimeout)
            return;
        }
    }
}




class SettingDedupeManager {
    
    private let configTypes: [ConfigType] = [ConfigType.deduplication, ConfigType.numAdsDeduped]
    private let config: AdConfig? = UserDefaults.adConfig()
    
    private var configList: [Any] = []
    
    init() {
        guard let config = self.config else {
            return;
        }
        
        self.configList = self.configTypes.map {
            if $0 == .numAdsDeduped {
                return SettingConfigData.init(type: $0, adConfig: config)
            } else {
                return SettingAdParamSwitchData.init(configType: $0, config: config)
            }
        }
    }
    
    
    //MARK: - Public
    
    func save() {
        let _ = UserDefaults.updateAdConfig(adConfig: self.config!)
    }
    
    var configCount: Int {
        return 1
    }
    
    func configRowCount(section : Int) -> Int {
        return self.configList.count
    }
    
    func isSwitchData(indexPath : IndexPath) -> Bool {
        let type = self.configTypes[indexPath.row]
        return type == .deduplication
    }
    
    func configData(indexPath : IndexPath) -> SettingConfigData? {
        if isSwitchData(indexPath: indexPath) {
           return nil
        }
        
        return self.configList[indexPath.row] as? SettingConfigData
    }
    
    func configSwitchData(indexPath : IndexPath) -> SettingAdParamSwitchData? {
        if !isSwitchData(indexPath: indexPath) {
            return nil
        }
        
        return self.configList[indexPath.row] as? SettingAdParamSwitchData
    }
    
    func updateValue(type : ConfigType, value : Float) {
        if type == .numAdsDeduped {
            self.config?.numAdsDeduped = Int(value)
        } else {
            print("do nothing")
        }
    }
    
    func updateSwitchData(data : SettingSwitchData) {
        if data is SettingAdParamSwitchData, let switchData = data as? SettingAdParamSwitchData {
            let type = switchData.type
            if type == ConfigType.deduplication {
                self.config?.isDeduplication = !data.switchOn
                switchData.updateSwitch()
            }
        }
    }
    
}
