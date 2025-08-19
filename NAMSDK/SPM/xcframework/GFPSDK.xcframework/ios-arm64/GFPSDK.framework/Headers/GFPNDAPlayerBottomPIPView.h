//
//  GFPNDAPlayerBottomPIPView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

static const CGFloat kPlayerBottomPIPViewHeight = 5.0;

@interface GFPNDAPlayerBottomPIPView : UIView

@property (nonatomic, assign) BOOL isPIP;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame duration:(NSTimeInterval)aDuration NS_DESIGNATED_INITIALIZER;

- (void)updateProgressWith:(NSTimeInterval)aCurrentTime;

@end


NS_ASSUME_NONNULL_END
