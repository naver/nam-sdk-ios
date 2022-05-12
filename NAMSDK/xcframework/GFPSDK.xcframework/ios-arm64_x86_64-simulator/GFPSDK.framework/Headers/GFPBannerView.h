//
//  GFPBannerView.h
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

@protocol GFPBannerAdapting;

@class GFPAdParam;
@class GFPNativeAdRenderingSetting;
@class GFPNativeSimpleAdRenderingSetting;
@class GFPBannerAdSize;
@class GFPAdAdaptor;
@class GFPLoadResponseInfo;

NS_ASSUME_NONNULL_BEGIN


@interface GFPBannerView : UIView


/**
 * 광고 요청에 사용할 파라미터
*/
@property (readwrite, nonatomic, strong, nullable) GFPAdParam *adParam;

/**
 * 로드 타임아웃(초) (기본값: 10 초)
 */
@property (readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

/**
 * 네이티브 광고 로드 허용 여부
 */
@property (readwrite, nonatomic, assign, getter=isNativeAdLoadable) BOOL nativeAdLoadable;

/**
 * 네이티브 광고 렌터링 세팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) GFPNativeAdRenderingSetting *nativeAdRenderingSetting;

/**
 * 네이티브 Simple 형(=단일 이미지) 광고 렌더링 세팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) GFPNativeSimpleAdRenderingSetting *nativeSimpleAdRenderingSetting;

/**
 * 광고 로드 및 이벤트 리스너
 */
@property (readwrite, nonatomic, weak) id <GFPBannerViewDelegate> delegate;

/**
 * 배너 레이아웃 타입. (기본값: GFPBannerViewLayoutTypeFixed)
 */
@property (readwrite, nonatomic, assign) GFPBannerViewLayoutType layoutType;

/**
 * 배너 광고 MetaData 셋팅 (Optional)
 *
 * (example) 광고의 InterfaceStyle 설정 시
 * key: @"theme"
 * value: @"system" or @"light" or @"dark"
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

/**
 * 광고 응답 객체
 */
@property (readonly, nonatomic, strong) GFPLoadResponseInfo *responseInfo;


/**
 * 배너 광고를 생성합니다.
 * @param adUnitID              배너 광고 유닛 아이디
 * @param rootViewController    최상단 뷰 컨트롤러
 * @param adParam               광고 요청에 사용할 파라미터
 */
- (instancetype)initWithAdUnitID:(NSString *)adUnitID
              rootViewController:(nullable UIViewController *)rootViewController
                         adParam:(nullable GFPAdParam *)adParam;

/**
 * 광고를 요청합니다.
 * 응답결과는 GFPBannerViewDelegate 를 통해 받으실 수 있습니다.
 * GFPAdLoader를 사용해서 로드하는 경우에 해당 메서드를 호출하면 Exception이 발생합니다.
 */
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
