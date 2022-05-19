//
//  AdType.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

enum AdType: Int, Hashable, CaseIterable {
    
    case display
    case rewarded
    case interstitial
    
    var title : String {
        switch self {
        case .display:
            return NSLocalizedString("Display_Ad", comment: "")
        case .rewarded:
            return NSLocalizedString("Rewarded_Ad", comment: "")
        case .interstitial:
            return NSLocalizedString("Interstitial_Ad", comment: "")
        }
    }
}
