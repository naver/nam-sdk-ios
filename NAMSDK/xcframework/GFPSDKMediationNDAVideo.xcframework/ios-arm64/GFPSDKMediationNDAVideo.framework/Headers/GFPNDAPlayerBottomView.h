//
//  GFPNDAPlayerBottomView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPLanguageType.h"

NS_ASSUME_NONNULL_BEGIN

static const CGFloat kPlayerBottomViewMaxHeight = 45.0;
static const CGFloat kPlayerBottomViewMinHeight = 25.0;

@interface GFPNDAPlayerBottomView : UIView

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame 
                     duration:(NSTimeInterval)aDuration
                 languageType:(GFPLanguageType)languageType NS_DESIGNATED_INITIALIZER;

- (void)updateProgressWith:(NSTimeInterval)aCurrentTime;

- (void)showOverlayView;
- (void)hideOverlayView;

@end

NS_ASSUME_NONNULL_END
