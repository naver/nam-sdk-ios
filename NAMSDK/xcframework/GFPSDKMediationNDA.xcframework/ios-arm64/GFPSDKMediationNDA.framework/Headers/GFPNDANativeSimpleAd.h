//
//  GFPNDANativeSimpleAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPNDANativeAd.h"
#import "GFPNativeAdRenderingSetting.h"

#import "GFPNativeAccessibilityItem.h"

@class GFPNativeAdInfo;
@class GFPNDANativeSimpleAd;
@class GFPNativeTemplateOptions;
@class GFPNativeBaseView;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeSimpleAd : GFPNDANativeAd

@property (nonatomic, strong) GFPNativeTemplateOptions *templateOptions;
@property (nonatomic, readonly, assign) BOOL isImageSizePreferred;
@property (nonatomic, strong, nullable) NSNumber *videoLoadTimeout;

// MARK: - 접근성: 광고 단위 단일 포커스 (NS 전 상품 — 플레인 이미지/동영상·렌더러 템플릿·플리킹·스플래시·리치)

/**
 * 광고 뷰(GFPNativeSimpleAdView) 전체를 VoiceOver 요소 하나로 묶는다. registerViewWith: 끝에서 호출(플레인·렌더러는 이 클래스가, 리치는 자기 register 끝에서).
 * - 활성화(이중 탭) = root link 랜딩. root link 가 없으면(링크 없음·unclickable 정책·`#`) 요소는 있되 "버튼"이 아니고 활성화해도 아무 일 없다 (AOS 정합 2026-11-06).
 * - 문구는 읽는 시점에 계산(labelProvider): 서브클래스 훅 accessibilitySummaryItems / accessibilitySummaryTextProvider / accessibilitySummaryHasAIBadge / accessibilitySummaryHasElectionBadge.
 * - 광고 요소 다음 별도 포커스 = accessibilityTrailingViews. 뮤트 UI 토글은 GFPNDAAdChoiceView → GFPNativeBaseView+Accessibility 공통.
 */
- (void)applyAccessibilitySummaryWith:(GFPNativeBaseView *)nativeAdView;
/// 별도 포커스 뷰 목록만 다시 만든다(렌더러 바인딩·POC 로드·리치 확장/축소 뒤). 문구는 읽는 시점에 계산되므로 따로 갱신하지 않는다.
- (void)refreshAccessibilitySummaryTrailingViews;
/// 현재 단일 포커스 문구 (테스트·디버그용. 실제 요소는 labelProvider 로 같은 값을 읽는다).
- (NSString *)currentAccessibilitySummary;
/// 광고 요소 다음에 각자 포커스를 받는 뷰 — 미디어의 accessibilitySeparateFocusViews(붙어 있고 보이는 것) + 미디어의 accessibilityAdChoiceView(앞 뷰의 자손이면 제외: 컨테이너 순회로 이미 닿는다).
/// 종류와 무관하게 화면 순(위→아래, 왼→오른)으로 정렬해 돌려준다 (AOS 정합 2026-11-11).
- (NSArray<UIView *> *)accessibilityTrailingViews;

// 서브클래스 훅
/// 문구 항목. 기본(플레인 NS) = 메인 이미지만(동영상·없음이면 빌더가 제거 → "광고"). 렌더러 템플릿은 렌더러 항목, 리치는 nil(기본 구성: 광고주 → 제목 → 본문 → 이미지 → CTA → 고지).
- (nullable NSArray<GFPNativeAccessibilityItem *> *)accessibilitySummaryItems;
/// SDK 가 그린 텍스트(POC 가격·혜택 티켓·고지) 제공자. 기본 nil.
- (nullable NSString * _Nullable (^)(GFPNativeAccessibilityItemKind kind))accessibilitySummaryTextProvider;
/// "AI 활용" 접두어 여부. 기본 = 미디어뷰 hasVisibleAIUsageBadge.
- (BOOL)accessibilitySummaryHasAIBadge;
/// "선거광고" 접두어 여부. 기본 = 미디어뷰 hasVisibleElectionBadge (플레인 이미지 NS·리치의 미디어뷰가 배지를 그리면 YES).
- (BOOL)accessibilitySummaryHasElectionBadge;

@end

NS_ASSUME_NONNULL_END
