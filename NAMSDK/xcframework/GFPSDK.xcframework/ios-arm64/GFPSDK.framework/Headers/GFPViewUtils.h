//
//  GFPViewUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPViewUtils : NSObject

+ (void)removeSubviews:(UIView *)aView;

+ (CGRect)originalFrame:(UIView *)aView;

+ (BOOL)isVisibility:(UIView *)aView;
+ (BOOL)isViewableOnScreen:(UIView *)aView;
+ (BOOL)isAtLeastHalfViewable:(UIView *)aView;

+ (CGFloat)exposedPercentage:(UIView *)aView;
+ (CGRect)visibleRectangle:(UIView *)aView;

+ (void)fillSuperviewWithCenterAlignment:(UIView *)aView;
+ (void)setConstraintWithFrameSize:(UIView *)aView;
+ (void)setConstraintWithSize:(CGSize)size view:(UIView *)aView;

+ (void)matchSuperViewSize:(UIView *)aView;
+ (void)matchSuperViewSafetyAreaThroughConstraints:(UIView *)aView;

+ (void)arrangeToSuperviewWithXAttribute:(NSLayoutAttribute)xAttribute
                              yAttribute:(NSLayoutAttribute)yAttribute
                                    view:(UIView *)aView;

+ (void)arrangeToSuperViewWithXAttribute:(NSLayoutAttribute)xAttribute
                              yAttribute:(NSLayoutAttribute)yAttribute
                                 offsetX:(CGFloat)offsetX
                                 offsetY:(CGFloat)offsetY
                                    view:(UIView *)aView;

+ (void)arrangeToSuperViewApplyingSafeAreaWithXAttribute:(NSLayoutAttribute)xAttribute
                                              yAttribute:(NSLayoutAttribute)yAttribute
                                                 offsetX:(CGFloat)offsetX
                                                 offsetY:(CGFloat)offsetY
                                                    view:(UIView *)aView;

+ (void)removeSizeConstraintOnSuperview:(UIView *)aView;
+ (void)removeArrangeConstraintsOnSuperview:(UIView *)aView;

+ (void)removeSizeConstraintOnSelf:(UIView *)aView;

@end

NS_ASSUME_NONNULL_END
