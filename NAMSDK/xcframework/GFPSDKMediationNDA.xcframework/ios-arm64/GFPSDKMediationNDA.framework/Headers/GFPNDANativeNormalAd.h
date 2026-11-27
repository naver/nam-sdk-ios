//
//  GFPNDANativeNormalAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPNDANativeAd.h"

@import NaverAdsServices;
@class GFPNativeAdInfo;
@class GFPNativeAdRenderingSetting;
@class GFPAdImpressionInfo;
@class GFPAutoPlayInfo;
@class GFPVideoOptions;
@class GFPAdInfoID;
@class GFPNativeAdView;
@class GFPNativeAccessibilityItem;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeNormalAd : GFPNDANativeAd

@property (nonatomic, strong) GFPNDAMediaView *iconView;
@property (nonatomic, strong, readonly) GFPNativeAdRenderingSetting *nativeRenderingSetting;
@property (nonatomic, strong, nullable) NSNumber *videoLoadTimeout;

- (instancetype)initWithNativeAdInfo:(GFPNativeAdInfo *)nativeAdInfo
                     skAdNetworkInfo:(GFPSKAdNetworkInfo *)skNetworkInfo
                         nasSkipInfo:(GFPVastAdSkipInfo *)nasSkipInfo
                        adChoiceInfo:(GFPAdChoiceInfo *)adChoiceInfo
                     vastMaxRedirect:(NSNumber *)vastMaxRedirect
                             context:(GFPNativeContext *)nativeContext
                            adInfoId:(GFPAdInfoID *)adInfoId;

// MARK: - 접근성: 광고 단위 단일 포커스 (NN, 2단계)

/**
 * 광고 요소 다음에 각자 포커스를 받는 뷰(미디어의 AI 활용 배지·선거광고 배지·동영상 컨트롤러·캐러셀 → AdChoices)를 다시 계산해 반영한다.
 * 서브클래스(동영상·캐러셀·컴플렉스)가 super registerViewWith: 뒤에 미디어를 붙인 다음 호출한다. 단일 포커스가 적용되지 않았으면 아무것도 하지 않는다.
 */
- (void)refreshAccessibilitySummaryTrailingViews;

/**
 * 단일 포커스 문구 항목 (테스트용 공개). 매체가 outlet 을 연결했고 화면에 보이며 텍스트가 있는 에셋만.
 * 순서(위키 기본 구성 고정): 광고주 → 제목 → 본문 → extraText(화면 위치 순) → 메인 이미지 → extraImage(alt 있는 것만, 화면 위치 순) → CTA → 고지.
 * 텍스트는 응답 값(nativeData)을 읽는다.
 */
- (NSArray<GFPNativeAccessibilityItem *> *)accessibilitySummaryItemsWith:(GFPNativeAdView *)nativeAdView;

/// 현재 단일 포커스 문구 (테스트용 공개). "[AI 활용, ]광고, 항목, …"
- (NSString *)currentAccessibilitySummaryWith:(GFPNativeAdView *)nativeAdView;

@end

NS_ASSUME_NONNULL_END
