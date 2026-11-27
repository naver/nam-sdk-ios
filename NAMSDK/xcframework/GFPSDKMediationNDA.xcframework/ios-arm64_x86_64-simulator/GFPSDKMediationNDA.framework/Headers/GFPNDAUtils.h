//
//  GFPNDAUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPLanguageType.h"
#import "GFPNativeProtocol.h"

NS_ASSUME_NONNULL_BEGIN

//접근성 문구 키 (GFPNDANativeLocalizable.strings)
static NSString * const kGFPNDAAccessibilityDeliveryFeeKey = @"accessibility_deliveryfee";

//POC 가격 레이블 접근성 문구 포맷 키 (%@에 레이블 값이 들어간다, ko.lproj 전용)
static NSString * const kGFPNDAAccessibilityOriginPriceFormatKey        = @"accessibility_price_origin_format";
static NSString * const kGFPNDAAccessibilityDiscountRateFormatKey       = @"accessibility_price_discount_format";
static NSString * const kGFPNDAAccessibilityDiscountedPriceFormatKey    = @"accessibility_price_discounted_format";
static NSString * const kGFPNDAAccessibilityMaxDiscountedPriceFormatKey = @"accessibility_price_max_discounted_format";

@protocol GFPNativeAdInfoLinkPresentable;
@class GFPNativeAdData;
@class GFPNativeLinkInfo;

@interface GFPNDAUtils : NSObject


@property (readonly, nonatomic, strong) NSBundle *mraidBundle;
@property (readonly, nonatomic, strong) NSBundle *nativeBundle;


+ (GFPNDAUtils *)sharedInstance;


/**
 * GFPNDAMraidResource
 */
- (NSString *)mraidFileContentsPath:(NSString *)name extension:(NSString *)extension;
- (NSString *)mraidFileContentsByPath:(NSString *)name extension:(NSString *)extension;

+ (NSString *)mraidJavascript;

/**
 * GFPNDANativeResource
 */
- (UIImage *)nativeImageWith:(NSString *)aName;

- (NSString *)nativeResourceStringWith:(NSString *)aMessageKey;
- (NSString *)nativeResourceStringWith:(NSString *)aMessageKey languageType:(GFPLanguageType)languageType;
- (NSString *)nativeResourceKoreanStringWith:(NSString *)aMessageKey;

- (UIView * _Nullable)nativeLoadNibWithName:(NSString *)aName index:(NSInteger)index;

+ (NSAttributedString * _Nullable)ctaChangedText:(NSString *)originText fontSize:(CGFloat)fontSize;


/**
 * for customAsset utils
 */
+ (UIImage *)customImageWith:(NSString *)name inBundle:(NSBundle * _Nullable)bundle;

/**
 * for Link info
 */
+ (void)applyLinkWith:(id<GFPNativeAdInfoLinkPresentable>)linkInfo target:(id)target view:(UIView *)aView action:(SEL)action;
+ (void)removeLinkWith:(UIView *)aView;

/**
 * for accessibility summary (광고 단위 단일 포커스 문구)
 */
+ (NSString *)accessibilityAdPrefix;                                   // "광고"
+ (NSString *)accessibilityAIUsagePrefix;                              // "AI 활용"
+ (NSString *)accessibilityElectionPrefix;                             // "선거광고" (accessibility_election_prefix)
+ (NSString *)accessibilityImageTextWithAlt:(nullable NSString *)alt;  // alt 가 있으면 alt, 없으면 "광고 이미지"(accessibility_ad)
+ (NSString *)accessibilitySummaryWithItems:(NSArray<NSString *> *)items; // 빈 항목 제거 후 ", " 로 연결
+ (nullable NSString *)accessibilityTextWithKind:(GFPNativeAccessibilityItemKind)kind text:(nullable NSString *)text; // kind 별 단위 문구 적용 ("%@할인", "배송비 %@", "별점 %@", "AI 리뷰"). 값이 비면 nil

/**
 * 광고 단위 단일 포커스 문구를 만든다 (NS 템플릿·NN 공용).
 * - items 가 nil 이면 기본 순서(광고주 → 제목 → 본문 → 메인 이미지 → CTA → 고지).
 * - MainImage 는 미디어 alt(없으면 "광고 이미지"), 미디어가 없거나 동영상이면 제거. 할인율·배송비·별점은 단위 문구를 붙인다.
 * - PriceSummary·BenefitTicket·Notice(텍스트 없음) 는 textProvider 로 SDK 가 그린 텍스트를 받는다 (nil 이면 응답 값으로 대체 가능한 것만).
 * - ExtraImage 는 응답 원본 alt 가 있을 때만 읽는다.
 * - hasAIBadge 면 "AI 활용" 접두어, 그 뒤 항상 "광고". 항목 사이는 ", ".
 */
+ (NSString *)accessibilitySummaryWithNativeData:(GFPNativeAdData *)nativeData
                                           items:(nullable NSArray<GFPNativeAccessibilityItem *> *)items
                                      hasAIBadge:(BOOL)hasAIBadge
                                    textProvider:(nullable NSString * _Nullable (^)(GFPNativeAccessibilityItemKind kind))textProvider;
/// 위와 같고, hasElectionBadge 면 "AI 활용" 뒤·"광고" 앞에 "선거광고" 접두어를 넣는다 (리치 선거광고 소재, 2026-11).
+ (NSString *)accessibilitySummaryWithNativeData:(GFPNativeAdData *)nativeData
                                           items:(nullable NSArray<GFPNativeAccessibilityItem *> *)items
                                      hasAIBadge:(BOOL)hasAIBadge
                                hasElectionBadge:(BOOL)hasElectionBadge
                                    textProvider:(nullable NSString * _Nullable (^)(GFPNativeAccessibilityItemKind kind))textProvider;

/// 뷰들을 container 좌표 기준 화면 순(위→아래, 같은 줄이면 왼→오른)으로 정렬한다. 같은 위치는 원래 순서 유지.
/// 단일 포커스의 별도 포커스 뷰는 종류(배지·매체 버튼·AdChoices)와 무관하게 이 순서로 읽는다 (AOS 정합 2026-11-11).
+ (NSArray<UIView *> *)accessibilityViewsSortedByScreenPosition:(NSArray<UIView *> *)views in:(nullable UIView *)container;
/// 뷰에 SDK 랜딩 제스처가 아닌 탭 제스처(UITapGestureRecognizer 계열)가 붙어 있는지 — 매체가 직접 클릭을 처리하는 뷰 판정 (단일 포커스에서 별도 포커스로 보존).
+ (BOOL)hasPublisherTapGestureOnView:(nullable UIView *)view;

/// 뷰가 화면에 보여 주는 텍스트 — 매체가 지정한 accessibilityLabel 이 있으면 그것, 없고 UILabel 이면 attributedText/text. 그 외 nil.
/// 단일 포커스 문구는 응답 값이 아니라 이 화면 값을 읽는다 (AOS 정합 2026-11-06; 접근성은 그려진 것을 읽어 주는 기능).
+ (nullable NSString *)accessibilityDisplayedTextOfView:(nullable UIView *)view;

/// candidate 자신과 boundary 직전까지의 조상 중 숨김(hidden)이 하나도 없으면 YES. candidate 가 nil 이면 NO. boundary 가 nil 이면 window 까지 본다.
+ (BOOL)isAccessibilityVisibleView:(nullable UIView *)candidate within:(nullable UIView *)boundary;

/// 랜딩 링크를 가진 단일 포커스 요소의 trait. 트래킹 전용(`#`) cURL 이면 랜딩하지 않으므로 None(버튼으로 알리지 않음), 아니면 Button.
+ (UIAccessibilityTraits)accessibilitySummaryTraitsForLink:(nullable GFPNativeLinkInfo *)link;

/**
 * For truncate
 */
+ (NSAttributedString *)truncateToTwoLinesCharWrap:(NSAttributedString *)attr
                                              font:(UIFont *)font
                                             width:(CGFloat)width;

/**
 * 콤마·통화 표기("10,000원")가 섞인 문자열에서 숫자만 추출
 */
+ (NSInteger)numericValueWith:(nullable NSString *)text;


+ (void)setCornerRadiusForView:(UIView *)view radius:(CGFloat)radius corners:(UIRectCorner)corners;

@end


typedef NS_OPTIONS(NSUInteger, LMBorderSegment) {
    LMBorderSegmentNone              = 0,
    LMBorderSegmentEdgeTop           = 1 << 0,
    LMBorderSegmentEdgeRight         = 1 << 1,
    LMBorderSegmentEdgeBottom        = 1 << 2,
    LMBorderSegmentEdgeLeft          = 1 << 3,
    LMBorderSegmentCornerTopLeft     = 1 << 4,
    LMBorderSegmentCornerTopRight    = 1 << 5,
    LMBorderSegmentCornerBottomRight = 1 << 6,
    LMBorderSegmentCornerBottomLeft  = 1 << 7,
    LMBorderSegmentAllEdges   = LMBorderSegmentEdgeTop | LMBorderSegmentEdgeRight |
                                LMBorderSegmentEdgeBottom | LMBorderSegmentEdgeLeft,
    LMBorderSegmentAllCorners = LMBorderSegmentCornerTopLeft | LMBorderSegmentCornerTopRight |
                                LMBorderSegmentCornerBottomRight | LMBorderSegmentCornerBottomLeft,
    LMBorderSegmentAll        = LMBorderSegmentAllEdges | LMBorderSegmentAllCorners,
};

@interface UIView (CornerRadii)
- (void)lm_applyCornerRadiiTopLeft:(CGFloat)tl
                          topRight:(CGFloat)tr
                       bottomRight:(CGFloat)br
                        bottomLeft:(CGFloat)bl
                       borderWidth:(CGFloat)borderWidth
                       borderColor:(UIColor *)borderColor
                          segments:(LMBorderSegment)segments;
@end

NS_ASSUME_NONNULL_END
