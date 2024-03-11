//
//  GFPNDAPlayerMidControlView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAPlayerControlViewDelegate.h"
#import "GFPLanguageType.h"

@class GFPNDAPlayerMidControlView;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDAPlayerViewMidDelegate <NSObject>

- (void)midControlView:(GFPNDAPlayerMidControlView *)aMidView didPlayTapped:(UIButton *)aSender;
- (void)midControlView:(GFPNDAPlayerMidControlView *)aMidView didPauseTapped:(UIButton *)aSender;

@optional
- (void)midControlView:(GFPNDAPlayerMidControlView *)aMidView didCloseTapped:(UIButton *)aSender; //for pip
- (void)midControlView:(GFPNDAPlayerMidControlView *)aMidView didReturnTapped:(UIButton *)aSender; //for pip

@end

static const NSTimeInterval kOverlayAnimationDuration = 0.3;
static const CGFloat kPlayerPlayResumeButtonSize = 53.0;

@interface GFPNDAPlayerMidControlView : UIView

@property (nonatomic, assign) id<GFPNDAPlayerViewMidDelegate> delegate;

@property (nonatomic, readonly, assign) BOOL showControl;
@property (atomic, readonly, assign) GFPNDALoadingOption loadingOption;

- (instancetype)initWithFrame:(CGRect)frame
                 languageType:(GFPLanguageType)languageType;

- (void)showLoadingWithOption:(GFPNDALoadingOption)aOption;
- (void)hideLoadingWithOption:(GFPNDALoadingOption)aOption;

- (void)hidePlayBack:(BOOL)isHidden;
- (void)updatePlayHidden:(BOOL)isHidden;

- (void)showAnimation;
- (void)hideAnimation;

@end


@interface GFPNDAPlayerTopMidControlPIPView : GFPNDAPlayerMidControlView

@property (nonatomic, weak) UIView *customTopView;

- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame customTopView:(UIView *)customTopView;

- (void)showSubViews;

@end

NS_ASSUME_NONNULL_END
