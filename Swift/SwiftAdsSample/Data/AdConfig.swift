//
//  AdConfig.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

enum ConfigType : String {
    
    case darkMode
    case gender
    case age
    case deduplication
    case numAdsDeduped
    
    var title: String {
        switch self {
        case .darkMode:
            return "Setting_Dark_Mode".localized
        case .age:
            return "Setting_Age".localized
        case .gender:
            return "Setting_Gender".localized
        case .deduplication:
            return "Setting_Ad_Param_Deduplication".localized
        case .numAdsDeduped:
            return "Setting_Ad_Param_NumAdsDeduped".localized
        }
    }
        
    var min: Int {
        switch self {
        case .darkMode:
            return 0
        case .age:
            return 1
        case .gender:
            return 0
        case .deduplication:
            return 0
        case .numAdsDeduped:
            return 2
        }
    }
    
    var max: Int {
        switch self {
        case .darkMode:
            return 2
        case .age:
            return 100
        case .gender:
            return 12
        case .deduplication:
            return 0
        case .numAdsDeduped:
            return 5
        }
    }
    
}

enum DarkModeType : Int, CaseIterable {
    case system
    case light
    case dark
    
    var title: String {
        switch self {
        case .system:
            return "Follow System"
        case .light:
            return "Light"
        case .dark:
            return "Dark"
        }
    }
}

enum GenderType : Int {
    
    case female
    case male
    case other
    
    var description: String {
        switch self {
        case .female:
            return NSLocalizedString("Setting_Female", comment: "")
        case .male:
            return NSLocalizedString("Setting_Male", comment: "")
        case .other:
            return ""
        }
    }
}

class AdConfig : NSObject, NSCoding {
    
    var darkMode : DarkModeType
    
    var gender : GenderType
    var age : Int
    
    var isDeduplication : Bool
    var numAdsDeduped : Int
    
    init(darkMode : DarkModeType, gender : GenderType, age : Int, isDeduplication : Bool, numAdsDeduped : Int) {
        self.darkMode = darkMode
        
        self.gender = gender
        self.age = age
        
        self.isDeduplication = isDeduplication
        self.numAdsDeduped = numAdsDeduped
        
        super.init()
    }
    
    func description() -> String {
        let ageDesc = String(format: "%@ : %d", NSLocalizedString("Setting_Age", comment: ""), self.age)
        return "\(self.gender.description)\n\(ageDesc)"
    }
    
    //MARK: - NSCopying
    
    func encode(with coder: NSCoder) {
        coder.encodeCInt(Int32(self.darkMode.rawValue), forKey: ConfigType.darkMode.rawValue)
        
        coder.encodeCInt(Int32(self.gender.rawValue), forKey: ConfigType.gender.rawValue)
        coder.encodeCInt(Int32(self.age), forKey: ConfigType.age.rawValue)
        
        coder.encode(self.isDeduplication, forKey: ConfigType.deduplication.rawValue)
        coder.encodeCInt(Int32(self.numAdsDeduped), forKey: ConfigType.numAdsDeduped.rawValue)
    }
    
    required init?(coder: NSCoder) {
        let darkModeValue = Int(coder.decodeInt32(forKey: ConfigType.darkMode.rawValue))
        self.darkMode = DarkModeType(rawValue: darkModeValue) ?? .system
        
        let genderValue = Int(coder.decodeInt32(forKey: ConfigType.gender.rawValue))
        self.gender = GenderType.init(rawValue: genderValue)!
        self.age = Int(coder.decodeInt32(forKey: ConfigType.age.rawValue))
        
        self.isDeduplication = coder.decodeBool(forKey: ConfigType.deduplication.rawValue)
        self.numAdsDeduped = Int(coder.decodeInt32(forKey: ConfigType.numAdsDeduped.rawValue))
    }
}
