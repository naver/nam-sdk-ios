//
//  GFPNDAMRAIDResizeViewManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAMRAIDResizeProperties.h"
#import "GFPNDAMRAIDResizeView.h"

@class GFPNDAMRAIDResizeView;
@class GFPError;

@protocol GFPNDAMRAIDResizeViewManagerDelegate;

@interface GFPNDAMRAIDResizeViewManager : NSObject

@property (nonatomic, readonly, strong) GFPNDAMRAIDResizeView *resizeView;
@property (nonatomic, readwrite, weak) id<GFPNDAMRAIDResizeViewManagerDelegate> delegate;
@property (nonatomic, readonly, assign, getter=isResized) BOOL resized;

- (instancetype)initWithContentView:(UIView *)contentView
                         anchorView:(UIView *)anchorView
                     resizeProperty:(GFPNDAMRAIDResizeProperties *)resizeProperties
                              error:(GFPError **)error;

- (BOOL)tryResizeWithProperties:(GFPNDAMRAIDResizeProperties *)properties
                          error:(GFPError **)error;
- (void)detachResizeView;
- (void)didMoveAnchorViewToWindow;

@end


@protocol GFPNDAMRAIDResizeViewManagerDelegate <NSObject>

- (void)resizeViewClosedWith:(GFPNDAMRAIDResizeViewManager *)manager;

@end
