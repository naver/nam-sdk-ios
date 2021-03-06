//
//  GFPAdAdaptorParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

#import "GFPProvider.h"

@class GFPAdInfoSize;
@class GFPAd;
@class GFPAdEvent;
@class GFPEventReporter;
@class GFPAdParam;
@class GFPAdHTML;
@class GFPContext;
@class GFPNativeAdInfo;
@class GFPAdInfoStyle;
@class GFPWaterfallDedup;
@class GFPWaterfallExtra;
@class GFPSKAdNetworkInfo;
@class GFPAdChoiceInfo;

NS_ASSUME_NONNULL_BEGIN


@interface GFPAdAdaptorParam : NSObject


@property (readonly, nonatomic, strong) GFPAdInfoSize *responseSize;
@property (readonly, nonatomic, strong) NSArray<GFPAdInfoSize *> *requestSizes;

@property (readonly, nonatomic, strong) NSDictionary<NSString *, NSString *> *sdkRequestInfo;

@property (readonly, nonatomic, strong) GFPAdParam *adParam;
@property (readonly, nonatomic, strong) GFPEventReporter *eventReporter;

@property (readonly, nonatomic, strong) NSString *responseCreativeType;


/**
 * 각 광고별 정보 Context
 */
@property (readonly, nonatomic, strong) GFPContext *context;


/**
 * IMA vastLoadTimeout
*/
@property (readonly, nonatomic, strong, nullable) NSNumber *loadTimeoutSec;


/**
 * NDA 관련 Banner, Video ADM
*/
@property (readonly, nonatomic, strong, nullable) GFPAdHTML *adHTML;
@property (readonly, nonatomic, strong, nullable) GFPNativeAdInfo *nativeInfo;


/**
 * HeaderBidding 관련 bidding price
*/
@property(readonly, nonatomic, strong, nullable) NSString *bidPrice;
@property(readonly, nonatomic, strong, nullable) NSNumber *randomNumber;

/**
 * 선택된 adProvider.
*/
@property(readonly, nonatomic, strong, nullable) NSString *adProviderName;

/**
 * 선택된 RenderType
 */
@property(readonly, nonatomic, strong, nullable) GFPProviderRenderType renderType;

/**
 * 중복 제어 관련 객체
 */
@property(readonly, nonatomic, strong, nullable) GFPWaterfallDedup *dedup;


/**
 * SKAdNetowrk 정보 객체
 */
@property (readonly, nonatomic, strong, nullable) GFPSKAdNetworkInfo *skAdNetworkInfo;

/**
 * Vast 관련 정보.
 */
@property (readonly, nonatomic, strong, nullable) NSNumber *vastMaxRedirect;

/**
 * AdChoice 정보 객체
 */
@property (readonly, nonatomic, strong, nullable) GFPAdChoiceInfo *adChoiceInfo;

- (instancetype)initWithAd:(GFPAd *)ad
             eventReporter:(GFPEventReporter *)eventReporter
                   context:(GFPContext *)context
                renderType:(GFPProviderRenderType)renderType
                   adParam:(nullable GFPAdParam *)adParam
                     extra:(nullable GFPWaterfallExtra *)extra;

@end

NS_ASSUME_NONNULL_END
