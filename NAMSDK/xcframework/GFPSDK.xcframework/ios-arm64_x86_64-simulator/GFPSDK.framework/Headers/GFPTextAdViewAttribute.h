//
//  GFPTextAdViewAttribute.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * RemindText 노출 위치에 따른 Type
 * Container Inner : Content Player 영역 내부 노출.
 * Container Outer : Content Player 영역 외l부 노출.
 */
typedef NS_OPTIONS(NSInteger, GFPNonLinearContainerType) {
    GFPNonLinearContainerOuter = 1 << 0,
    GFPNonLinearContainerInner = 1 << 1,
};

@interface GFPTextAdViewAttribute : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *verticalBarColor;
@property (nonatomic, strong) UIImage *closeIcon;
@property (nonatomic, strong) UIImage *moreIoon;

@property (nonatomic, strong, nonnull) UIView *containerView;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithContainer:(UIView * _Nonnull)containerView NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
