//
//  GFPAdLoader+Common.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

#import "GFPAdLoader.h"
#import "GFPAdBannerOptions.h"
#import "GFPNativeAdDelegate.h"
#import "GFPBannerViewDelegate.h"
#import "GFPAdAdaptor.h"

@protocol GFPEventReportDelegate;
@protocol GFPAdCallDelegate;

@class GFPAdNativeSimpleOptions;
@class GFPAdNativeOptions;

@class GFPUnifiedMediator;
@class GFPNativeContext;
@class GFPBannerContext;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdLoader ()

@property (nonatomic, weak) id <GFPEventReportDelegate> reportDelegate;

//Common
@property (nonatomic, strong) GFPAdParam *adParam;
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, strong) NSString *adUnitID;

//Banner
@property (nonatomic, weak) id<GFPBannerViewDelegate> bannerDelegate;
@property (nonatomic, strong) GFPAdBannerOptions *bannerOptions;

//Simple Native
@property (nonatomic, weak) id<GFPNativeSimpleAdDelegate> nativeSimpleDelegate;
@property (nonatomic, strong) GFPAdNativeSimpleOptions *nativeSimpleOptions;

//Native
@property (nonatomic, weak) id<GFPNativeAdDelegate> nativeDelegate;
@property (nonatomic, strong) GFPAdNativeOptions *nativeOptions;

//DeDuplication
@property (nonatomic, weak) id <GFPAdCallDelegate> adCallDelegate;

- (void)adLoaderDidFailWithError:(GFPError *)error responseInfo:(GFPLoadResponseInfo *)responseInfo;
- (void)loadAdInternal:(GFPUnifiedMediator *)unifiedMediator;

@end

NS_ASSUME_NONNULL_END
