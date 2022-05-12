//
//  GFPAdBannerOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <UIKit/UIKit.h>
#import "GFPBannerViewDelegate.h"
#import "GFPMRAIDSupportSetting.h"
#import "GFPImpression.h"
#import "GFPBannerViewLayoutType.h"

@class GFPNativeAdRenderingSetting;
@class GFPNativeSimpleAdRenderingSetting;
@class GFPBannerAdSize;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdBannerOptions : NSObject

/**
 * 배너 레이아웃 타입. (기본값: GFPBannerViewLayoutTypeFixed)
 */
@property (readwrite, nonatomic, assign) GFPBannerViewLayoutType layoutType;

/**
 * 배너 광고 MetaData 셋팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) NSDictionary <NSString *, NSString *> *hostMeta;

/**
 * 로드된 배너 광고 제공자 명 (없으면 nil)
 */
@property (readonly, nonatomic, strong, nullable) NSString *adProviderName;

/**
 * 로드된 배너 광고 사이즈 정보 (없으면 nil)
 */
@property (readonly, nonatomic, strong) GFPBannerAdSize *adSize;


/**
 * Mraid 추가 feature Support 세팅 정보 ( 0 -> default )
 */
@property (readwrite, nonatomic, setter=setMraidSupportType:) GFPMraidSupportType mraidSupportType;

/**
 * 광고 유효 노출 설정 정보
 * 해당 기능은 deprecate 되었으며, 서버 응답에 의해 imp를 설정합니다.
 */
@property (readwrite, nonatomic, strong) GFPImpressionSetting *impressionSetting DEPRECATED_ATTRIBUTE;


@end

NS_ASSUME_NONNULL_END
