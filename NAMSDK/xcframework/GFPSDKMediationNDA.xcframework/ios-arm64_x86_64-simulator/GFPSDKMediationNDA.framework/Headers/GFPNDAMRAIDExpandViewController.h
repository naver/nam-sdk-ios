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
- (void)closeAddTarget:(id)aTarget selector:(SEL)aSelector;


@end
