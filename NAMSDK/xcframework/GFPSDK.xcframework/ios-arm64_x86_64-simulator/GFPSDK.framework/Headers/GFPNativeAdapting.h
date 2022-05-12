//
//  GFPNativeAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdAdapting.h"
#import "GFPNativeAd.h"

@protocol GFPNativeAdaptorDelegate;

@class GFPNativeAd;
@class GFPNativeBaseView;

@class GFPWaterfallDedup;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeAdapting <GFPAdAdapting>

@property(readwrite, nonatomic, weak) id <GFPNativeAdaptorDelegate> delegate;

- (GFPNativeAdProviderType)adProviderType;

- (id)adProviderNativeAd;

- (BOOL)hasIconImage;

- (NSString *)title;

- (NSString *)body;

- (NSString *)advertiser;

- (NSString *)badge;

- (NSString *)callToAction;

- (NSString *)socialContext;

- (void)registerView:(GFPNativeBaseView *)nativeAdView;

- (void)unregisterView;

- (BOOL)isRegistered;

@optional
- (void)updateMediaViewLayout;

- (GFPAdStyleType)adStyleType;

- (BOOL)isInvalid;

- (UIImage * _Nullable)image;

- (GFPWaterfallDedup * _Nullable)dedup;

@end

NS_ASSUME_NONNULL_END
