//
//  GFPNDAPlayerControlPIPView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAPlayerDelegate.h"
#import "GFPNDAPlayerControlViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAVast;
@class GFPVideoDisplayMode;

@interface GFPNDAPlayerControlPIPView : UIView <GFPNDAPlayerControlViewPresentable>


- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame vast:(nonnull GFPNDAVast *)aVast displayMode:(GFPVideoDisplayMode *)displayMode;


- (void)updateCustomTopView:(UIView *)customTopView;
- (void)tapControlUI;

@end

NS_ASSUME_NONNULL_END
