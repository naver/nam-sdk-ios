//
//  GFPNDABannerViewDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPBannerAdaptorDelegate.h"
#import "GFPEventReporter.h"

@class GFPError;

@protocol GFPNDABannerViewDelegate <NSObject>

- (void)ndaBannerViewDidLoadAd:(GFPNDABannerView *)bannerView;

- (void)ndaBannerView:(GFPNDABannerView *)bannerView didFailToLoadAdWithError:(GFPError *)error;

- (void)ndaBannerViewWasClicked:(GFPNDABannerView *)bannerView;

- (void)ndaBannerView:(GFPNDABannerView *)bannerView didRequestLandingWithUrl:(NSString *)landingUrl;

- (void)ndaBannerViewShouldUnload:(GFPNDABannerView *)bannerView;

- (void)ndaBannerViewWasMuted:(GFPNDABannerView *)bannerView;

@optional

- (void)ndaBannerView:(GFPNDABannerView *)bannerView didChangeWith:(GFPBannerAdSize *)size type:(GFPBannerSizeChangeType)changeType;

- (void)ndaBannerView:(GFPNDABannerView *)bannerView didChangeWith:(NSDictionary *)adMeta;

@end
