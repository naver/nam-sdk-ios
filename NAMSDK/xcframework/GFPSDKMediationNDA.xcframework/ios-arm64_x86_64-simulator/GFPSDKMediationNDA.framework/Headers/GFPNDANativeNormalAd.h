//
//  GFPNDANativeNormalAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPNDANativeAd.h"

@class GFPNativeAdInfo;
@class GFPNativeAdRenderingSetting;
@class GFPAdSkipInfo;
@class GFPAdImpressionInfo;
@class GFPAutoPlayInfo;
@class GFPVideoOptions;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeNormalAd : GFPNDANativeAd

@property (nonatomic, strong) GFPNDAMediaView *iconView;
@property (nonatomic, strong, readonly) GFPNativeAdRenderingSetting *nativeRenderingSetting;
@property (nonatomic, strong) NSNumber *videoLoadTimeout;

- (instancetype)initWithNativeAdInfo:(GFPNativeAdInfo *)nativeAdInfo
                     skAdNetworkInfo:(GFPSKAdNetworkInfo *)skNetworkInfo
                            skipInfo:(GFPAdSkipInfo *)skipInfo
                        adChoiceInfo:(GFPAdChoiceInfo *)adChoiceInfo
                     vastMaxRedirect:(NSNumber *)vastMaxRedirect
                             context:(GFPNativeContext *)nativeContext;

@end

NS_ASSUME_NONNULL_END
