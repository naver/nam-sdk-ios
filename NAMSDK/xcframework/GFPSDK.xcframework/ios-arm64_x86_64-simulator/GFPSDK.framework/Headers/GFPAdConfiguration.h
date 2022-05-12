//
//  GFPAdConfiguration.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPAdProviderSetting.h"
#import "GFPRenderDisplayAgent.h"
#import "GFPLogLevel.h"
#import "GFPAdInterfaceStyle.h"

// CHECK: Remove header reference when public open.
#import "GFPSDKPhase.h"



@interface GFPAdConfiguration : NSObject


@property (nonatomic, assign) GFPPhaseType phase;

/**
 * 배너광고 요청 타임아웃 (기본값 60초, kGFPDefaultBannerAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval bannerAdRequestTimeout;

/**
 * 비디오광고 요청 타임아웃 (기본값 60초, kGFPDefaultVideoAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval videoAdRequestTimeout;

/**
 * 네이티브광고 요청 타임아웃 (기본값 60초, kGFPDefaultNativeAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval nativeAdRequestTimeout;

/**
 * 통합광고 요청 타임아웃 (기본값 60초, kGFPDefaultUnifiedAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval unifiedAdRequestTimeout;

/**
 * 리워드광고 요청 타임아웃 (기본값 60초, kGFPDefaultRewardedAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval rewardedAdRequestTimeout;

/**
 * 전면형광고 요청 타임아웃 (기본값 60초, kGFPDefaultInterstitialAdRequestTimeout)
 */
@property (nonatomic, assign) NSTimeInterval interstitialAdRequestTimeout;


/**
 * 광고 클릭 후 렌더링 타입
 */
@property (nonatomic, strong) GFPRenderDisplayAgent *displayAgent;


/**
 * 비디오 광고 재생 시, Loudness (볼륨 자동 조절) 사용 여부. (기본값 NO)
*/
@property (nonatomic, assign) BOOL useLoudness;


/**
 *  SDK내에서 정의한 Default UA로 광고 요청하도록 세팅. (기본값 NO)
*/
@property (nonatomic, assign) BOOL useDefaultUA;

/**
 *  SDK에 UA주입되어 사용할 수 있도록
*/
@property (nonatomic, strong) NSString *externalUserAgent;

/**
 * GFPSDK 로그레벨 설정. 설정한 로그레벨 이상의 로그만 콘솔에 출력됩니다. (기본값: GFPSDKLogLevelNone, 로그를 출력하지 않음)
 */
@property (nonatomic, assign) GFPLogLevel logLevel;

/**
 * GFP 에서 렌더링 하는 광고의 style. (기본값 Light)
 */
@property (nonatomic, assign) GFPAdInterfaceStyle adInterfaceStyle;


/**
 * AdProvider 별 테스트 모드 설정.
 */
@property (nonatomic, strong) NSArray <GFPAdProviderSetting *> *adProviderConfigList;

/**
 * 식별 가능한 Cookie 세팅.
 */
@property (nonatomic, readonly, strong) NSDictionary <NSString *, NSString *> *cookie;


- (GFPAdProviderSetting *)adProviderConfigWith:(GFPAdProviderSettingType)aType;


@end
