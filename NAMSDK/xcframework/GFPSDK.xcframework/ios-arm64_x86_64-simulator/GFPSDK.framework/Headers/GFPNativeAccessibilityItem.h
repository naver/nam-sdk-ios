//
//  GFPNativeAccessibilityItem.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

/**
 * 광고 단위 단일 포커스 접근성 문구의 항목 종류.
 * 템플릿(렌더러)은 "무엇을 읽을지"만 순서대로 선언하고, 단위 문구("판매가", "할인", "별점" 등)·alt 치환·SDK 가 그리는 텍스트(기본 고지, 혜택 티켓)는 SDK 가 채운다.
 */
typedef NS_ENUM(NSInteger, GFPNativeAccessibilityItemKind) {
    GFPNativeAccessibilityItemKindText = 0,          // 표시 텍스트 그대로 (비어 있으면 제외)
    GFPNativeAccessibilityItemKindMainImage,         // 메인 이미지 자리. alt, 없으면 "광고 이미지". 미디어가 없거나 동영상이면 제외 (text 무시)
    GFPNativeAccessibilityItemKindPriceDiscount,     // 할인율 — "{text}할인"
    GFPNativeAccessibilityItemKindDeliveryFee,       // 배송비 — "배송비 {text}"
    GFPNativeAccessibilityItemKindAIReviewSummary,   // AI 리뷰 칩들 앞에 한 번 읽는 "AI 리뷰" (text 무시)
    GFPNativeAccessibilityItemKindStar,              // 별점 — "별점 {text}"
    GFPNativeAccessibilityItemKindCallToAction,      // CTA 표시 텍스트. 비어 있으면 응답 cta 텍스트
    GFPNativeAccessibilityItemKindNotice,            // 고지. 비어 있으면 SDK 가 그린 고지(응답 notice 또는 기본 고지)
    GFPNativeAccessibilityItemKindPriceSummary,      // SDK(POC 레이아웃)가 그린 가격 영역 — 판매가·할인율·즉시할인가·최대할인가 (text 무시)
    GFPNativeAccessibilityItemKindBenefitTicket,     // (신) 쇼핑 소식 혜택 티켓 — SDK 레이아웃이 그린 텍스트 (text 무시)
    GFPNativeAccessibilityItemKindExtraImage,        // 엑스트라 이미지 — text 는 extraImage 키. 응답 원본 alt 가 있을 때만 읽고 없으면 제외
};

/**
 * 접근성 문구 항목 한 개. kind 에 따라 SDK 가 text 를 치환·포맷한다.
 */
@interface GFPNativeAccessibilityItem : NSObject

@property (nonatomic, readonly) GFPNativeAccessibilityItemKind kind;
@property (nonatomic, readonly, copy, nullable) NSString *text;

+ (instancetype _Nonnull)itemWithKind:(GFPNativeAccessibilityItemKind)kind text:(NSString * _Nullable)text;
+ (instancetype _Nonnull)text:(NSString * _Nullable)text;      // Text
+ (instancetype _Nonnull)mainImage;                             // MainImage
+ (instancetype _Nonnull)extraImageWithKey:(NSString * _Nonnull)key;  // ExtraImage

@end
