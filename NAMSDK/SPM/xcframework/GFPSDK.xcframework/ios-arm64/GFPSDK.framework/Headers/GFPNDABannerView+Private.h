//
//  GFPNDABannerView+Private.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <WebKit/WebKit.h>
#import <Foundation/Foundation.h>

#import "GFPNDABannerView.h"
#import "GFPNDAMRAIDExpandViewController.h"
#import "GFPNDAMRAIDResizeViewManager.h"
#import "Swift-Enum.h"

static NSTimeInterval const kNDAExposureTimeInterval = 0.2;

@class GFPNDAMraidConfiguration;
@class GFPBannerTouchCheck;

NS_ASSUME_NONNULL_BEGIN


@interface GFPNDABannerView () <WKUIDelegate, WKNavigationDelegate, UIGestureRecognizerDelegate>

@property (atomic, strong, nullable) GFPBannerTouchCheck *touchCheck;


//MARK: NORMAL
@property (atomic, assign) BOOL finishedInitialLoad;
@property (nonatomic, readwrite) BOOL isMraid;

@property (nonatomic, assign) CGSize responseSize;

@property (nonatomic, strong) NSDictionary <NSString *, NSString *> *hostMeta;
@property (nonatomic, assign) GFPBannerViewLayoutType layoutType;

@property (nonatomic, assign) CGFloat exposedPercent;

@property (nonatomic, strong, nullable) NSTimer *exposureTimer;

- (void)landingAction:(NSString *)aURL;
- (void)didWebViewLoadFinished;

@end

NS_ASSUME_NONNULL_END
