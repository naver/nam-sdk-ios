//
//  GFPBannerMediator.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPMediator.h"

@protocol GFPBannerProviding;
@protocol GFPBannerAdapting;
@protocol GFPNativeAdapting;
@protocol GFPCombinedAdapting;
@protocol GFPEventReportDelegate;

@class GFPBannerMediator;
@class GFPAdParam;
@class GFPProvider;
@class GFPBannerContext;
@class GFPAdAdaptor;
@class GFPError;
@class GFPNativeContext;
@class GFPCombinedContext;
@class GFPNativeAd;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPBannerMediatorDelegate <NSObject>

- (void)bannerMediator:(GFPBannerMediator *)mediator didLoadBannerAdaptor:(GFPAdAdaptor <GFPBannerAdapting> *)adaptor;
- (void)bannerMediator:(GFPBannerMediator *)mediator didLoadNativeAd:(GFPNativeAd *)nativeAd;
- (void)bannerMediator:(GFPBannerMediator *)mediator didFailToLoadBannerAdaptorWithError:(GFPError *)error;

@end


@interface GFPBannerMediator : GFPMediator

@property (nonatomic, weak) id <GFPEventReportDelegate> reportDelegate;

@property (readwrite, nonatomic, weak) id <GFPBannerMediatorDelegate> delegate;

- (void)loadBannerAdaptorWithAdUnitID:(NSString *)adUnitID
                        bannerContext:(GFPBannerContext *)bannerContext
                              adParam:(nullable GFPAdParam *)adParam
                      timeoutInterval:(NSTimeInterval)timeoutInterval;

- (void)loadBannerAdaptorWithAdUnitID:(NSString *)adUnitID
                        bannerContext:(GFPBannerContext *)bannerContext
                        nativeContext:(GFPNativeContext *)nativeContext
                              adParam:(nullable GFPAdParam *)adParam
                      timeoutInterval:(NSTimeInterval)timeoutInterval;
@end

NS_ASSUME_NONNULL_END
