//
//  GFPAdProviderSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#include <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, GFPAdProviderSettingType) {
    GFPAdProviderSettingTypeNone = 0,
    GFPAdProviderSettingTypeDFP,
    GFPAdProviderSettingTypeFAN,
    GFPAdProviderSettingTypeMoPub,
    GFPAdProviderSettingTypeUnity,
};


@interface GFPAdProviderSetting : NSObject


@property (readonly, nonatomic, assign) GFPAdProviderSettingType type;


/**
 * 테스트 광고 송출 여부 설정 (기본값: NO)
 */
@property (nonatomic, getter=isTestMode) BOOL testMode;


+ (instancetype)type:(GFPAdProviderSettingType)type testMode:(BOOL)testMode;
- (instancetype)initWithType:(GFPAdProviderSettingType)type testMode:(BOOL)testMode;


@end
