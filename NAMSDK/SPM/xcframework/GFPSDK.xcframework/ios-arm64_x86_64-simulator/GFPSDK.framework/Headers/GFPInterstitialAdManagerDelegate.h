//
//  GFPInterstitialAdManagerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol GFPInterstitialAdAdapting;

@class GFPInterstitialAdManager;
@class GFPInterstitialAd;
@class GFPLoadResponseInfo;
@class GFPAdAdaptor;
@class GFPError;

@protocol GFPInterstitialAdManagerDelegate <NSObject>

- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager didLoadAd:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager didStartAd:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager wasClickedAd:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager didCloseAd:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager didCompleteAd:(GFPInterstitialAd *)interstitialAd;
- (void)interstitialAdManager:(GFPInterstitialAdManager *)manager didFailWithError:(GFPError *)error responseInfo:(nullable GFPLoadResponseInfo *)responseInfo;

@optional
-(void)interstitialAdManagerDidPresentDefaultInAppBrowser:(GFPInterstitialAdManager *)manager;
-(void)interstitialAdManagerDidDismissDefaultInAppBrowser:(GFPInterstitialAdManager *)manager;


@end

NS_ASSUME_NONNULL_END
