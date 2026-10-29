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
//폴더블 접힘/펼침 등 기기 회전 노티 없이 화면 지오메트리가 바뀐 경우의 재배치 (회전은 기존 디바이스 방향 노티가 처리)
- (void)handleScreenGeometryChange;

@end


@protocol GFPNDAMRAIDResizeViewManagerDelegate <NSObject>

- (void)resizeViewClosedWith:(GFPNDAMRAIDResizeViewManager *)manager;

@end
