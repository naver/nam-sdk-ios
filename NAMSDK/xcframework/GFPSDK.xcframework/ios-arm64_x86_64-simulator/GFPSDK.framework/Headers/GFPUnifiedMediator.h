//
//  GFPUnifiedMediator.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPMediator.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GFPBannerAdapting;
@protocol GFPEventReportDelegate;

@class GFPUnifiedMediator;
@class GFPAdAdaptor;
@class GFPNativeAd;
@class GFPNativeSimpleAd;
@class GFPError;
@class GFPBannerContext;
@class GFPNativeContext;
@class GFPAdParam;
@class GFPWaterfallExtra;

@protocol GFPUnifiedMediatorDelegate <NSObject>

- (void)unifiedMediator:(GFPUnifiedMediator *)mediator didLoadBannerAdaptor:(GFPAdAdaptor <GFPBannerAdapting> *)adaptor;
- (void)unifiedMediator:(GFPUnifiedMediator *)mediator didLoadNativeAd:(GFPNativeAd *)nativeAd;
- (void)unifiedMediator:(GFPUnifiedMediator *)mediator didLoadNativeSimpleAd:(GFPNativeSimpleAd *)nativeAd;
- (void)unifiedMediator:(GFPUnifiedMediator *)mediator didFailToLoadAdaptorWithError:(GFPError *)error;

- (void)unifiedMediator:(GFPUnifiedMediator *)mediator didReceivedWaterfallResponse:(GFPWaterfallExtra *)waterfallList;

@end

@interface GFPUnifiedMediator : GFPMediator

// For Event Logging.
@property (nonatomic, weak) id <GFPEventReportDelegate> reportDelegate;

@property (nonatomic, weak) id <GFPUnifiedMediatorDelegate> delegate;

- (void)loadAdaptorWithAdUnitID:(NSString *)adUnitID
                  bannerContext:(nullable GFPBannerContext *)bannerContext
                  nativeContext:(nullable GFPNativeContext *)nativeContext
                        adParam:(nullable GFPAdParam *)adParam
                timeoutInterval:(NSTimeInterval)timeoutInterval;

@end

NS_ASSUME_NONNULL_END
