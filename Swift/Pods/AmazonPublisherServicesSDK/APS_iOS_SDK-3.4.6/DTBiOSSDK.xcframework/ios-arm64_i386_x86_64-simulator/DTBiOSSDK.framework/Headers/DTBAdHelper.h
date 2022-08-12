//
//  DTBAdHelper.h
//  DTBiOSSDK
//
//  Created by Krivopaltsev, Eugene on 7/11/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTBExpectedSize.h"


NS_ASSUME_NONNULL_BEGIN
@class DTBAdResponse;

@protocol MopubObj <NSObject>
@property(nonatomic)NSString *keywords;
@property (nonatomic)NSDictionary *localExtras;
@end

@interface DTBAdHelper : NSObject

+(NSError * _Nonnull) createAmazonErrorWithCode:(NSInteger)code;
+(NSError * _Nonnull) createAmazonErrorWithCode:(NSInteger)code withMessage:(NSString *)msg;

// ADMOB

+(BOOL) validateAdMobBannerCustomEventWithExpectedSizeHandler:(id<DTBExpectedSize>)expectedSizeHandler  serverParameter: (NSString *)serverParameter parameters:(NSDictionary * _Nullable)params;

+(BOOL) validateAdMobInterstitialCustomEvent:(NSString *)serverParameter parameters:(NSDictionary * _Nullable)params;

+(UIView * _Nonnull) viewForAdView:(UIView * _Nonnull)adView expectedSizeHandler:(id<DTBExpectedSize> _Nonnull)expectedSizeHandler
                     requestedSize:(CGSize) requestedSize;

+ (BOOL)handleBannerBidsWith:(id<DTBExpectedSize> _Nonnull)expectedSizeHandler withParams:(NSDictionary * _Nullable)params;

+ (BOOL) validateMopubBannerCustomEventWithLocalInfo:(NSDictionary * _Nullable)localParameters  serverInfo: (NSDictionary * _Nullable) serverInfo;

+ (BOOL) validateMopubInterstitialCustomEventWithLocalInfo:(NSDictionary * _Nullable)localParameters  serverInfo: (NSDictionary * _Nullable) serverInfo;

+ (BOOL) isFetchManagerPresentForSmartBanner;

+(void)skadnHelper:(NSString *)label withInfo:(NSString *)info;

@end

NS_ASSUME_NONNULL_END
