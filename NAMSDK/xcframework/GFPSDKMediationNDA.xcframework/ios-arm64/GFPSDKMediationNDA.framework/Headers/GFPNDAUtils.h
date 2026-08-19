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

NS_ASSUME_NONNULL_BEGIN

//접근성 문구 키 (GFPNDANativeLocalizable.strings)
static NSString * const kGFPNDAAccessibilityDeliveryFeeKey = @"accessibility_deliveryfee";

//POC 가격 레이블 접근성 문구 포맷 키 (%@에 레이블 값이 들어간다, ko.lproj 전용)
static NSString * const kGFPNDAAccessibilityOriginPriceFormatKey        = @"accessibility_price_origin_format";
static NSString * const kGFPNDAAccessibilityDiscountRateFormatKey       = @"accessibility_price_discount_format";
static NSString * const kGFPNDAAccessibilityDiscountedPriceFormatKey    = @"accessibility_price_discounted_format";
static NSString * const kGFPNDAAccessibilityMaxDiscountedPriceFormatKey = @"accessibility_price_max_discounted_format";

@protocol GFPNativeAdInfoLinkPresentable;

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
