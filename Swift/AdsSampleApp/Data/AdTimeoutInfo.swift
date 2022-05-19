//
//  AdTimeoutInfo.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

enum AdTimeoutInfoKey {
    static let displayAd = "displayAd"
//    static let videoAd = "videoAd"
    static let rewarededAd = "rewardedAd"
    static let interstitialAd = "interstitialAd"
}

class AdTimeoutInfo : NSObject, NSCoding {
    
    var displayAdTimeout : TimeInterval
//    var videoAdTimeout : TimeInterval
    var rewardedAdTimeout : TimeInterval
    var interstitialAdTimeout : TimeInterval
    
    init(displayAdTimeout : TimeInterval, /*videoAdTimeout : TimeInterval,*/ rewardedAdTimeout : TimeInterval, interstitialAdTimeout : TimeInterval) {
        self.displayAdTimeout = displayAdTimeout
//        self.videoAdTimeout = videoAdTimeout
        self.rewardedAdTimeout = rewardedAdTimeout
        self.interstitialAdTimeout = interstitialAdTimeout
    }
    
    func encode(with coder: NSCoder) {
        coder.encode(self.displayAdTimeout, forKey: AdTimeoutInfoKey.displayAd)
//        coder.encode(self.videoAdTimeout, forKey: AdTimeoutInfoKey.videoAd)
        coder.encode(self.rewardedAdTimeout, forKey: AdTimeoutInfoKey.rewarededAd)
        coder.encode(self.interstitialAdTimeout, forKey: AdTimeoutInfoKey.interstitialAd)
    }
    
    required init?(coder: NSCoder) {
        self.displayAdTimeout = TimeInterval(coder.decodeDouble(forKey: AdTimeoutInfoKey.displayAd))
//        self.videoAdTimeout = TimeInterval(coder.decodeDouble(forKey: AdTimeoutInfoKey.videoAd))
        self.rewardedAdTimeout = TimeInterval(coder.decodeDouble(forKey: AdTimeoutInfoKey.rewarededAd))
        self.interstitialAdTimeout = TimeInterval(coder.decodeDouble(forKey: AdTimeoutInfoKey.interstitialAd))
    }
    
    func save() {
        let _ = UserDefaults.updateTimeout(info: self)
    }
    
    static var defaultTimeout: AdTimeoutInfo {
        return AdTimeoutInfo.init(displayAdTimeout: 60.0, rewardedAdTimeout: 60.0, interstitialAdTimeout: 60.0)
    }
}
