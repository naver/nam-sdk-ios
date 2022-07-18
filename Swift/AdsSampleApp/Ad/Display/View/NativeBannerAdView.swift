//
//  NativeBannerAdView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

import GFPSDK

class NativeBannerAdView: GFPNativeAdView {
    
    override class func awakeFromNib() {
        super.awakeFromNib()
    }
    
    //MARK: - Public
    
    func updateNativeBanner(nativeAd : GFPNativeAd) {
        self.nativeAd = nativeAd
        
        self.titleLabel?.text = nativeAd.title
        self.bodyLabel?.text = nativeAd.body
        self.advertiserLabel?.text = nativeAd.advertiser
        self.callToActionLabel?.text = nativeAd.callToAction
    }
    
    func reset() {
        self.nativeAd = nil
        
        self.titleLabel?.text = ""
        self.bodyLabel?.text = ""
        self.advertiserLabel?.text = ""
        self.callToActionLabel?.text = ""
    }
}
