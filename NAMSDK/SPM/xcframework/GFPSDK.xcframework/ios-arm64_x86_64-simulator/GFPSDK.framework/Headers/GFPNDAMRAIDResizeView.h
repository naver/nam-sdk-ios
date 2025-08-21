//
//  GFPNDAMRAIDResizeView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import <UIKit/UIKit.h>
#import "GFPNDAMRAIDUtil.h"

@class GFPNDAMRAIDResizeProperties;

//mraid resize spec.
static CGFloat const kGFPNDAMraidResizeViewCloseRegionWidth = 50.0;
static CGFloat const kGFPNDAMraidResizeViewCloseRegionHeight = 50.0;

@protocol GFPNDAMRAIDResizeViewCloseDelegate;

@interface GFPNDAMRAIDResizeView : UIView

- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithProperties:(GFPNDAMRAIDResizeProperties *)aProperties;

- (void)attachContentView:(UIView *)contentView;
- (UIView *)detachContentView;

@property (nonatomic, readonly, weak) UIView *contentView;
@property (nonatomic, readwrite, weak) id<GFPNDAMRAIDResizeViewCloseDelegate> delegate;

@end

@protocol GFPNDAMRAIDResizeViewCloseDelegate <NSObject>

- (void)closeRegionClickedOnResizeView:(GFPNDAMRAIDResizeView *)resizeView;

@end
