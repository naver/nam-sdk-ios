//
//  SettingsData.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import GFPSDK
import UIKit

// MARK: - Common Protocols

protocol SettingsEnumProtocol: Codable, Equatable, CaseIterable, RawRepresentable {
    var title: String {get}
}

// MARK: - Enums

enum DarkModeType: Int, SettingsEnumProtocol {

    case system = 1
    case light = 2
    case dark = 3

    var title: String {
        switch self {
        case .system:
            return "System"
        case .light:
            return "Light"
        case .dark:
            return "Dark"
        }
    }

}

enum SettingsLanguageType: String, SettingsEnumProtocol {
    case kr
    case en
    case jp
    case id
    case zh
    case th

    var languageId: String {
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
            return "Setting_Lang_KR".localized(param: self.languageId)
        case .en:
            return "Setting_Lang_EN".localized(param: self.languageId)
        case .jp:
            return "Setting_Lang_JP".localized(param: self.languageId)
        case .id:
            return "Setting_Lang_ID".localized(param: self.languageId)
        case .zh:
            return "Setting_Lang_ZH".localized(param: self.languageId)
        case .th:
            return "Setting_Lang_TH".localized(param: self.languageId)
        }
    }

}

enum RequestTimeoutType {
    case displayAd
    case videoAd
    case rewardedAd
    case interstitialAd
}

// MARK: - Structs

struct PrebidConfigInfo: Codable, Equatable {
    var configId: String
    var size: CGSize
    var desc: String = ""
}

struct APSSlotInfo: Codable, Equatable {
    var slotUUID: String
    var width: Int
    var height: Int
    var desc: String = ""
}

// MARK: - GFPSDK Extensions

extension GFPPhaseType: SettingsEnumProtocol {
    public static var allCases: [GFPPhaseType] {
        [.alpha, .dev, .test, .real]
    }

    var title: String {
        switch self {
        case .alpha: return "alpha"
        case .dev: return "dev"
        case .test: return "test"
        case .real: return "real"
        default: return ""
        }
    }
}

extension GFPUserParamGenderType: SettingsEnumProtocol {
    public static var allCases: [GFPUserParamGenderType] {
        [.male, .female, .other]
    }
    
    var title: String {
        switch self {
        case .male: return "Male"
        case .female: return "Female"
        case .other: return "Other"
        default: return ""
        }
    }
}

enum PublisherCode: String, SettingsEnumProtocol {
    case swiftSample = "2209163917" // @"2785576236" @"1257889546" @"1056835215" @"5819764626" @"4597058926"
    case naverSample = "5819764626"
    case lineWebtoonDev = "8080714807"
    case vapp = "2447629606"
    case zepeto = "9891874316"
    case snow = "2108381715"

    var title: String {
        switch self {
        case .swiftSample: return "Swift Sample"
        case .naverSample: return "NAVER Sample"
        case .lineWebtoonDev: return "LineWebtoon Dev"
        case .vapp: return "Vapp"
        case .zepeto: return "Zepeto"
        case .snow: return "Snow"
        }
    }
}

extension GFPRenderDisplayAgentType: SettingsEnumProtocol {
    public static var allCases: [GFPRenderDisplayAgentType] {
        [.displayAgentTypeInApp, .displayAgentTypeNativeSafari, .displayAgentTypeScheme]
    }

    var title: String {
        switch self {
        case .displayAgentTypeInApp: return "In-App"
        case .displayAgentTypeNativeSafari: return "Safari"
        case .displayAgentTypeScheme: return "Scheme"
        default: return ""
        }
    }
}

extension GFPATTAuthorizationStatus: Codable {
    var title: String {
        switch self {
        case .notDetermined: return "Not Determined"
        case .restricted: return "Restricted"
        case .denied: return "Denied"
        case .authorized: return "Authorized"
        @unknown default: return "Unknown Status"
        }
    }
}

extension GFPUserParamGenderType: Codable {}

extension GFPLogLevel: Codable {}
