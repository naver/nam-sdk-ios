//
//  GFPNDAMRAIDExpandViewController.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "GFPNDAMRAIDUtil.h"

@class GFPNDAMRAIDExpandProperties;
@class GFPNDAMRAIDExecutor;
@class GFPNDAMraidConfiguration;
@class GFPNDAMRAIDOrientationProperties;

@protocol GFPNDAMRAIDExpandViewControllerDelegate;

//mraid 2.0 spec
static CGFloat const kGFPNDAMRAIDExpandViewControllerCloseRegionWidth = 50.0;
static CGFloat const kGFPNDAMRAIDExpandViewControllerCloseRegionHeight = 50.0;

@interface GFPNDAMRAIDExpandViewController : UIViewController

@property (nonatomic, readwrite, strong) GFPNDAMRAIDExecutor *executor;
@property (nonatomic, readwrite, strong) GFPNDAMRAIDOrientationProperties *orientationProperties;


- (instancetype)initWithExecutor:(GFPNDAMRAIDExecutor *)executor
                expandProperties:(GFPNDAMRAIDExpandProperties *)expandProperties
                    expandConfig:(GFPNDAMraidConfiguration *)configuration;

- (instancetype)initWithExecutor:(GFPNDAMRAIDExecutor *)executor
                expandProperties:(GFPNDAMRAIDExpandProperties *)expandProperties;

- (UIView *)detachContentView;
//폴드 등으로 화면 크기가 바뀐 뒤 확장 웹뷰 크기를 현재 화면 기준으로 재계산 (풀스크린 확장은 새 화면을 채우고, 고정 크기 확장은 유지)
- (void)updateContentSizeForCurrentScreen;
- (void)closeAddTarget:(id)aTarget selector:(SEL)aSelector;


@end
