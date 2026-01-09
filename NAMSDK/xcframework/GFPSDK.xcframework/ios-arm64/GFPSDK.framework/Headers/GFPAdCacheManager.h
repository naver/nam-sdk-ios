//
//  GFPAdCacheManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

@class GFPAdCacheManager;
@class GFPNativeAdBase;
@class GFPNativeAd;
@class GFPNativeSimpleAd;
@class GFPInterstitialAdManager;
@class GFPRewardedAdManager;
@class GFPLoadResponseInfo;
@class GFPError;

@class GFPAdCacheNativeOptions;
@class GFPAdCacheInterstitialOptions;
@class GFPAdCacheRewardOptions;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPAdCacheManagerDelegate <NSObject>

- (void)cacheManager:(NSString *)adUnitId didCacheNativeAd:(GFPNativeAd *)nativeAd;
- (void)cacheManager:(NSString *)adUnitId didCacheNativeSimpleAd:(GFPNativeSimpleAd *)nativeSimpleAd;

- (void)cacheManager:(NSString *)adUnitId didFailWithError:(GFPError *)error responseInfo:(GFPLoadResponseInfo * _Nullable)responseInfo;

@end

@interface GFPAdCacheManager : NSObject

@property (class, readonly, nonatomic) GFPAdCacheManager *sharedInstance;

/**
 * Native, NativeSimple
 */
- (void)prefetchNativeAd:(GFPAdCacheNativeOptions *)options;

- (void)loadNativeAdFromDisk:(GFPAdCacheNativeOptions *)options
                    delegate:(id <GFPAdCacheManagerDelegate> _Nonnull)delegate;

- (void)loadNativeAdFromDisk:(GFPAdCacheNativeOptions *)options
                    delegate:(id <GFPAdCacheManagerDelegate> _Nonnull)delegate
              isAutoPrefetch:(BOOL)isAutoPrefetch;

/**
 * Utils
 */
- (void)clearWith:(NSString *)adUnitId;
- (void)clearAll;

@end

NS_ASSUME_NONNULL_END
