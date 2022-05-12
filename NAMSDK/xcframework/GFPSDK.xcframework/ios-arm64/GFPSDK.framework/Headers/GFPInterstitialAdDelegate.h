//
//  GFPInterstitialAdDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


@class GFPInterstitialAd;
@class GFPError;

@protocol GFPInterstitialAdDelegate <NSObject>

- (void)interstitialAdDidStarted:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdWasClicked:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdClosed:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdDidComplete:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAd:(GFPInterstitialAd *)interstitialAd didFailedWithError:(GFPError *)error;
- (void)interstitialAdRecieveImpression:(GFPInterstitialAd *)interstitialAd;

@end
 
