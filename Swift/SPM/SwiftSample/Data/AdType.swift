//
//  AdType.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

enum AdType: String, Hashable, CaseIterable, Codable {
    case display
    case rewarded
    case interstitial
    case tableViewAd
    case scheduled

    var title : String {
        switch self {
        case .display: return "Display Ad"
        case .rewarded: return "Rewarded Ad"
        case .interstitial: return "Interstitial Ad"
        case .tableViewAd: return "Ads in TableView"
        case .scheduled: return "Scheduled Video Ad"
        }
    }

    // Root Key to take ad unit ids in AdUnitIDList.plist
    var unitIdListName: String {
        switch self {
        case .display: return "Display Ad"
        case .rewarded: return "Rewarded Ad"
        case .interstitial: return "Interstitial Ad"
        case .tableViewAd: return "Display Ad"
        case .scheduled: return "Scheduled Video Ad"
        }
    }

    var adViewController: AdViewController {
        switch self {
        case .display: return DisplayAdExample()
        case .rewarded: return RewardedAdExample()
        case .interstitial: return InterstitialAdExample()
        case .tableViewAd: return TableViewAdExample()
        case .scheduled: return ScheduledVideoAdExample()
        }
    }
}
