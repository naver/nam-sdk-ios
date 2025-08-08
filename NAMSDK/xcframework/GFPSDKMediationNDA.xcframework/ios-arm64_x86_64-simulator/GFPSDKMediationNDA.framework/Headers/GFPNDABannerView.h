//
//  GFPNDABannerView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#import "GFPBannerAdaptorDelegate.h"
#import "GFPNDAMRAIDUtil.h"
#import "GFPNDAMRAIDExecutor.h"


NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDABannerViewDelegate;

@class GFPBannerContext;

@class GFPAdHTML;
@class GFPBannerAdSize;
@class GFPSKAdNetworkInfo;
@class GFPNDABannerView;
@class GFPBannerWebViewConfig;
@class GFPNDAMraidConfiguration;


@class GFPError;


@interface GFPNDABannerView : UIView

@property (nonatomic, weak) id <GFPNDABannerViewDelegate> delegate;
@property (nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, readonly, strong) WKWebView *webView;

@property (nonatomic, strong) GFPBannerAdSize *bannerAdSize;

- (instancetype)initWithFrame:(CGRect)frame
                       adHTML:(GFPAdHTML *)adHTML
              skAdNetworkInfo:(GFPSKAdNetworkInfo *)aSKNetworkInfo
                      context:(nonnull GFPBannerContext *)context
                configuration:(GFPNDAMraidConfiguration *)configuration
                      isJsTag:(BOOL)isJsTag
                        logId:(NSUUID *)logId;

- (void)loadAd;

- (void)reportRenderedImpression;
- (void)reportViewableImpression;

- (void)ndaBannerViewClicked;
- (void)ndaBannerViewDidLoadAd:(GFPNDABannerView *)bannerView;
- (void)ndaBannerViewDidFailToLoadAdWithError:(GFPError *)error;

- (void)ndaBannerViewDidRequestLandingWithUrl:(NSString *)landingUrl;
- (void)ndaBannerViewDidChangeSize:(GFPBannerAdSize *)size type:(GFPBannerSizeChangeType)type;
- (void)ndaBannerViewDidChangeAdMeta:(NSDictionary *)adMeta;
- (void)ndaBannerViewShouldUnload;

@end

NS_ASSUME_NONNULL_END
