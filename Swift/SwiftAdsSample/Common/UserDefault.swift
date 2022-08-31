//
//  UserDefault.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation


private enum UserDefaultsKey {
    
    static let darkMode = "SettingDarkMode"
    
    static let language = "SettingLanguage"

    static let testModeFacebook = "SettingTestModeFacebook"
    static let testModeGoogle = "SettingTestModeGoogle"
    static let testModeMopub = "SettingTestModeMopub"
    
    static let debugRepeatCount = "SettingDebugRepeatCount"
    
    static let adConfig = "SettingAdConfig"
    static let adTimeOut = "SettingAdTimeOut"
}

extension UserDefaults {
    static var darkMode : DarkModeType {
        get {
            return DarkModeType(rawValue: UserDefaults.standard.integer(forKey: UserDefaultsKey.darkMode)) ?? .system
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: UserDefaultsKey.darkMode)
            UserDefaults.standard.synchronize()
        }
    }
    
    static var language : String {
        get {
            return (UserDefaults.standard.object(forKey: UserDefaultsKey.language) as? String) ?? "en"
        }
        set {
            UserDefaults.standard.set(newValue, forKey: UserDefaultsKey.language)
            UserDefaults.standard.synchronize()
        }
    }
    
    static var testModeFacebook : Bool {
        get {
            return (UserDefaults.standard.object(forKey: UserDefaultsKey.testModeFacebook) as? Bool == true)
        }
        set {
            UserDefaults.standard.set(newValue, forKey: UserDefaultsKey.testModeFacebook)
            UserDefaults.standard.synchronize()
        }
    }
    
    static var testModeGoogle : Bool {
        get {
            return (UserDefaults.standard.object(forKey: UserDefaultsKey.testModeGoogle) as? Bool == true)
        }
        set {
            UserDefaults.standard.set(newValue, forKey: UserDefaultsKey.testModeGoogle)
            UserDefaults.standard.synchronize()
        }
    }
    
    static var testModeMopub : Bool {
        get {
            return (UserDefaults.standard.object(forKey: UserDefaultsKey.testModeMopub) as? Bool == true)
        }
        set {
            UserDefaults.standard.set(newValue, forKey: UserDefaultsKey.testModeMopub)
            UserDefaults.standard.synchronize()
        }
    }
    
    static func adConfig() -> AdConfig? {
        let object = UserDefaults.standard.object(forKey: UserDefaultsKey.adConfig)
        
        if let data = object as? Data {
            return NSKeyedUnarchiver.unarchiveObject(with: data) as! AdConfig?
        } else {
            return nil
        }
    }
    
    static func updateAdConfig(adConfig : AdConfig) -> Bool {
        let data : Data = NSKeyedArchiver.archivedData(withRootObject: adConfig)
        UserDefaults.standard.setValue(data, forKey: UserDefaultsKey.adConfig)
        return UserDefaults.standard.synchronize()
    }
    
    static func adTimeoutInfo() -> AdTimeoutInfo? {
        let object = UserDefaults.standard.object(forKey: UserDefaultsKey.adTimeOut)
        
        if let data = object as? Data {
            return NSKeyedUnarchiver.unarchiveObject(with: data) as! AdTimeoutInfo?
        } else {
            return nil
        }
    }
    
    static func updateTimeout(info : AdTimeoutInfo) -> Bool {
        let data : Data = NSKeyedArchiver.archivedData(withRootObject: info)
        UserDefaults.standard.setValue(data, forKey: UserDefaultsKey.adTimeOut)
        return UserDefaults.standard.synchronize()
    }
    
}
