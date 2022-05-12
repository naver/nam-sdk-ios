//
//  GFPAdNativeOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPImpression.h"

@class GFPNativeAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdNativeOptions : NSObject

/**
 * 광고 렌터링 세팅 (Optional)
 */
@property(readwrite, nonatomic, strong, nullable) GFPNativeAdRenderingSetting *renderingSetting;

/**
 * 광고 유효 노출 설정 정보
 * 해당 기능은 deprecate 되었으며, 서버 응답에 의해 imp를 설정합니다.
 */
@property (readwrite, nonatomic, strong) GFPImpressionSetting *impressionSetting DEPRECATED_ATTRIBUTE;


@end

NS_ASSUME_NONNULL_END
