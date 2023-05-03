//
//  GFPBannerView+Common.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPBannerView.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPUnifiedMediator;

@protocol GFPBannerByLoaderDelegate <NSObject>

- (void)bannerAdLoaderDidReceiveAd:(GFPBannerView *)bannerView;
- (void)bannerAdLoader:(GFPBannerView *)bannerView didFailToSizeAdWithError:(GFPError *)error mediator:(GFPUnifiedMediator *)mediator;

@end


@protocol GFPEventReportDelegate;
@class GFPBannerMediator;
@class GFPLoadResponseInfo;

@interface GFPBannerView ()


@property (nonatomic, weak) id <GFPEventReportDelegate> reportDelegate;
@property (nonatomic, weak, nullable) id <GFPBannerByLoaderDelegate> delegateByLoader;


@property (readwrite, nonatomic, copy) NSString *adUnitID;
@property (readwrite, nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, assign) BOOL isLoadedByLoader;

@property (readwrite, nullable, nonatomic, strong) NSString *adProviderName;
@property (readwrite, nullable, nonatomic, strong) GFPBannerAdSize *adSize;

@property (readwrite, nonatomic, strong, nullable) GFPAdAdaptor <GFPBannerAdapting> *adaptor;
@property (readwrite, nonatomic, assign) CGRect updateFrame;


- (void)sendReportErrorWith:(NSString *)message;
- (GFPError *)adViewSizeError:(UIView *)adView;

- (void)updateBannerLayoutWith:(UIView *)aAdView;
- (void)loadAdInternal:(GFPBannerMediator *)bannerMediator;

- (void)updateResponseInfo:(GFPLoadResponseInfo *)responseInfo;

@end

NS_ASSUME_NONNULL_END
