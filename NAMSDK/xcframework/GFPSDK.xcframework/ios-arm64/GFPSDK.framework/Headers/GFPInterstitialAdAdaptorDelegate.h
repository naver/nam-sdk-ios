//
//  GFPInterstitialAdAdaptorDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GFPInterstitialAdAdapting;
@class GFPAdAdaptor;

@protocol GFPInterstitialAdAdaptorDelegate <NSObject>

- (void)interstitialAdDidStart:(GFPAdAdaptor <GFPInterstitialAdAdapting> *)interstitialAdAdaptor;
- (void)interstitialAdDidComplete:(GFPAdAdaptor<GFPInterstitialAdAdapting> *)interstitialAdAdaptor;
- (void)interstitialAdDidClose:(GFPAdAdaptor<GFPInterstitialAdAdapting> *)interstitialAdAdaptor;
- (void)interstitialAdAdaptor:(GFPAdAdaptor<GFPInterstitialAdAdapting> *)interstitialAdAdaptor didFailWithError:(GFPError *)error;

- (void)interstitialAdWasClicked:(GFPAdAdaptor <GFPInterstitialAdAdapting> *)interstitialAdAdaptor;
- (void)interstitialAdAdaptorRecieveImpression:(GFPAdAdaptor <GFPInterstitialAdAdapting> *)interstitialAdAdaptor;


@end

NS_ASSUME_NONNULL_END
