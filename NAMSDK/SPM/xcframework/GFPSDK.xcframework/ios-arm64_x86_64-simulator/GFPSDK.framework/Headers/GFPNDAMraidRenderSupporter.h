//
//  GFPNDAMraidRenderSupporter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import "GFPNDABannerView.h"
#import "GFPNDAMRAIDExpandViewController.h"
#import "GFPNDAMRAIDResizeViewManager.h"
#import "Swift-Enum.h"


NS_ASSUME_NONNULL_BEGIN

@class GFPNDAMraidConfiguration;

@protocol GFPNDAMraidRenderDataSource <NSObject>

@required
- (WKWebView *)contentWebView;
- (CGRect)containerFrame;
- (UIView *)containerView;
- (void)landingAction:(NSString *)urlString;

- (void)didMraidUnloadActionCalled;
- (void)didMraidViewClickActionCalled;
- (void)didMraidResetFromResize;
- (BOOL)availableMraidLanding;

@end


@interface GFPNDAMraidRenderSupporter : NSObject <GFPNDAMRAIDExecutorDelegate, GFPNDAMRAIDResizeViewManagerDelegate, GFPNDAMRAIDOrientationDelegate>


@property (nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, weak) id<GFPNDAMraidRenderDataSource> dataSource;

//MARK: Common
@property (atomic, assign) BOOL finishedMraidLoad;


//MARK: MRAID
@property (nonatomic, readwrite, strong) GFPNDAMraidConfiguration *mraidConfiguration;

@property (nonatomic, strong, nullable) NSTimer *exposureTimer;
@property (nonatomic, nullable, strong) WKWebView *expandWebView;

@property (nonatomic, readwrite, strong) GFPNDAMRAIDExecutor *executor;


//Interstitial
@property (nonatomic, readwrite, assign) BOOL useCustomClose;
@property (nonatomic, readwrite, strong) UIButton *customCloseRegion;

//Expand
@property (nonatomic, readwrite, nullable, strong) GFPNDAMRAIDExpandViewController *expandController;


//Resize
@property (nonatomic, readwrite, nullable, strong) GFPNDAMRAIDResizeViewManager *resizeManager;
@property (nonatomic, readwrite, strong) GFPNDAMRAIDOrientationProperties *orientationProperties;


- (instancetype)initWithDataSource:(id<GFPNDAMraidRenderDataSource>)dataSource
                rootViewController:(UIViewController *)rootViewController;
- (void)setupMRAID:(GFPNDAMraidConfiguration *)aConfiguration;
- (void)didWebViewLoaded;
- (BOOL)forwardNavigationActionWith:(WKWebView *)webView
                   navigationAction:(WKNavigationAction *)navigationAction;


@end

NS_ASSUME_NONNULL_END
