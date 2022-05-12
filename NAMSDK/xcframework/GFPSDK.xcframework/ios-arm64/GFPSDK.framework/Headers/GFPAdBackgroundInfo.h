//
//  GFPAdBackgroundInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GFPAdBackgroundOwnerDelegate <NSObject>
@optional
- (void)showBg:(CGFloat)appearAnimTime;
- (void)showBg:(CGFloat)appearAnimTime delay:(CGFloat)delayTime;
- (void)hideBg:(CGFloat)disAppearAnimTime;
- (void)hideBg:(CGFloat)disAppearAnimTime delay:(CGFloat)delayTime;

- (void)needsToUpdateBg;

- (CGRect)customBackViewFrameToWindow;

@end


@protocol GFPAdBackgroundDelegate <NSObject>
@property (nonatomic, weak) id<GFPAdBackgroundOwnerDelegate> bgOwnerDelegate;
@optional
- (BOOL)isForcedBackgroundPadding;
- (CGFloat)adBottomMargin;
- (CGFloat)adHeightForBackground;
- (CGFloat)adWidthForBackground;
- (CGFloat)forcePaddingForLeft;
- (CGFloat)forcePaddingForRight;
- (CGFloat)forcePaddingForTop;
- (CGFloat)forcePaddingForBottom;

@end

@interface GFPAdBackgroundInfo : NSObject

@property (nonatomic, readonly, strong) UIColor *color;
@property (nonatomic, readonly, assign) CGFloat alpha;
@property (nonatomic, readonly, assign) CGFloat cornerRadius;
@property (nonatomic, readonly, assign) CGFloat left;
@property (nonatomic, readonly, assign) CGFloat right;
@property (nonatomic, readonly, assign) CGFloat top;
@property (nonatomic, readonly, assign) CGFloat bottom;

- (instancetype)initWithBackground:(UIColor *)color
                             alpha:(CGFloat)alpha
                              left:(CGFloat)left
                             right:(CGFloat)right
                               top:(CGFloat)top
                            bottom:(CGFloat)bottom
                      cornerRadius:(CGFloat)cornerRadius;

@end

NS_ASSUME_NONNULL_END
