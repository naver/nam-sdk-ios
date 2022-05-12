//
//  GFPImpression.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPImpressionType) {
    GFPImpressionTypeRender = 1 << 0,
    GFPImpressionTypeViewable = 1 << 1,
    GFPImpressionTypeCustom = 1 << 2,
};

typedef NS_OPTIONS(NSInteger, GFPImpressionThresholdType) {
    GFPImpressionThresholdTypeDefault = 1 << 0,
    GFPImpressionThresholdType50p1s = 1 << 1,
    GFPImpressionThresholdType50p2s = 1 << 2,
    GFPImpressionThresholdType100p0s = 1 << 3,
    GFPImpressionThresholdType100p1s = 1 << 4,
} DEPRECATED_ATTRIBUTE;


/**
 * 해당 interface는 deprecate 되었으며, 서버 응답에 의해 imp를 설정합니다.
 */
@interface GFPImpressionSetting : NSObject


@property (readonly, nonatomic, assign) GFPImpressionThresholdType viewableImpThresholdType DEPRECATED_ATTRIBUTE;

- (instancetype)initWith:(GFPImpressionThresholdType)viewableImpThresholdType DEPRECATED_MSG_ATTRIBUTE("GFPImpressionSetting is deprecated.");


@end

NS_ASSUME_NONNULL_END
