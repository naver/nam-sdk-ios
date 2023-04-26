//
//  UIView+GFPCommon.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GFPAlignmentCenter) {
    GFPAlignmentVerticalCenter = 0,
    GFPAlignmentHorizontalCenter,
};


typedef NS_ENUM(NSUInteger, GFPAlignment) {
    GFPAlignmentLeft = 0,
    GFPAlignmentTop,
    GFPAlignmentRight,
    GFPAlignmentBottom
};


typedef NS_ENUM(NSUInteger, GFPSizeType) {
    GFPSizeHeight = 0,
    GFPSizeWidth
};


typedef NS_ENUM(NSUInteger, GFPOriginType) {
    GFPOriginX = 0,
    GFPOriginY
};


@interface UIColor (GFPCommon)

+ (UIColor *)colorFromHexString:(NSString *)hexString;
+ (instancetype)colorWithRGBIntWith:(NSInteger)rgb;
+ (instancetype)colorWithRGBIntWith:(NSInteger)rgb alpha:(CGFloat)alpha;
+ (instancetype)colorWithRedWith:(CGFloat)aRed green:(CGFloat)aGreen blue:(CGFloat)aBlue alpha:(CGFloat)alpha;


@end


@interface UIView (GFPCommon)

+ (NSString *)frameWith:(CGRect)frame;

- (void)printSizeWith:(const char *)functionName;
- (void)printOriginWith:(const char *)functionName;

- (CGFloat)sizeWidth;
- (CGFloat)sizeHeight;

- (CGFloat)topSafeInsets;

- (CGFloat)sideSafeAreaInsets;
- (CGFloat)topBottomSafeAreaInsets;

- (CGFloat)leftSafeInsets;
- (CGFloat)rightSafeInsets;

- (CGFloat)maxY;
- (CGFloat)maxX;

- (void)showDebugBorderWithColorWith:(UIColor *)color;

- (void)addConstraintCenterWith:(UIView *)aItem toItem:(UIView *)toItem attribute:(NSLayoutAttribute)attribute;

- (void)moveWith:(GFPAlignmentCenter)type;
- (void)moveWith:(GFPAlignmentCenter)type margin:(CGFloat)margin;
- (void)moveToTypeWith:(GFPAlignment)type margin:(CGFloat)margin;
- (void)moveToTypeWith:(GFPAlignment)type withView:(UIView *)view gap:(CGFloat)gap;

- (void)alignWith:(GFPAlignment)type withView:(UIView *)view;
- (void)alignWith:(GFPAlignment)type withView:(UIView *)view gap:(CGFloat)gap;

- (void)alignCenterWith:(GFPAlignmentCenter)type withView:(UIView *)view;
- (void)alignCenterWith:(GFPAlignmentCenter)type withView:(UIView *)view gap:(CGFloat)gap;

- (void)updateSizeWith:(GFPSizeType)type value:(CGFloat)value;
- (void)updateSizeWith:(CGSize)aSize;

- (void)updateOriginWith:(CGPoint)aOrigin;
- (void)updateOriginTypeWith:(GFPOriginType)aType value:(CGFloat)aValue;

- (void)disableAccessibilityForSubviews;

+ (UIView *)loadWithBundle:(NSBundle *)aBundle Name:(NSString *)nibName;


@end


@interface UIImageView (GFPCommon)

- (void)startSpinningWith:(double)duration;
- (void)stopSpinning;

@end


NS_ASSUME_NONNULL_END
