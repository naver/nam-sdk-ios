//
//  GFPProvider.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAdAdaptorParam;

/**
 *  이 클래스는 각 광고 제공자를 어댑팅 하기 위한 최상위 타입 클래스로 사용됨.
 *  obj-c 특성상 추상 클래스가 불가능하므로, 공통으로 사용할 기능만 구현하고 기능명세는 프로토콜에 하도록 하자.
 */
NS_ASSUME_NONNULL_BEGIN

typedef NSString *GFPProviderType NS_STRING_ENUM;
FOUNDATION_EXPORT NSString *const GFPProviderTypeNDA;
FOUNDATION_EXPORT NSString *const GFPProviderTypeNDAVideo;
FOUNDATION_EXPORT NSString *const GFPProviderTypeDFP;
FOUNDATION_EXPORT NSString *const GFPProviderTypeIMA;
FOUNDATION_EXPORT NSString *const GFPProviderTypeFAN;
FOUNDATION_EXPORT NSString *const GFPProviderTypeINMOBI;
FOUNDATION_EXPORT NSString *const GFPProviderTypeUNITY;
FOUNDATION_EXPORT NSString *const GFPProviderTypeAppLovin;
FOUNDATION_EXPORT NSString *const GFPProviderTypeVungle;
FOUNDATION_EXPORT NSString *const GFPProviderTypeDT;
FOUNDATION_EXPORT NSString *const GFPProviderTypeIS;
FOUNDATION_EXPORT NSString *const GFPProviderTypeAPS;
FOUNDATION_EXPORT NSString *const GFPProviderTypeLAN;
FOUNDATION_EXPORT NSString *const GFPProviderTypeChartBoost;
FOUNDATION_EXPORT NSString *const GFPProviderTypeBidMachine;

typedef NSString *GFPProviderRenderType NS_STRING_ENUM;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeNDP;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeSF;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeDFP;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeIMA;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeEMPTY;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeGV;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeFAN;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeINMOBI;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeUNITY;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeAppLovin;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeVungle;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeDT;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeIS;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeAPS;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeLAN;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeChartBoost;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeBidMachine;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeSIMPLE;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeNORMAL;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeCOMPOSITE;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeJSTAG;
FOUNDATION_EXPORT NSString *const GFPProviderRenderTypeRewarded;

typedef NSString *GFPProviderCreativeType NS_STRING_ENUM;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeBanner;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeVideo;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeNative;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeCombined;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeRewardedAd;
FOUNDATION_EXPORT NSString *const GFPProviderCreativeTypeInterstitialAd;

typedef NSString *GFPProviderProductType NS_STRING_ENUM;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeBanner;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeNative;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeCombined;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeRewarded;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeInstreamVideo;
FOUNDATION_EXPORT NSString *const GFPProviderProductTypeInterstitial;



@interface GFPProvider : NSObject

@property (nonatomic, assign) BOOL isBlacklisted;

@end

NS_ASSUME_NONNULL_END
