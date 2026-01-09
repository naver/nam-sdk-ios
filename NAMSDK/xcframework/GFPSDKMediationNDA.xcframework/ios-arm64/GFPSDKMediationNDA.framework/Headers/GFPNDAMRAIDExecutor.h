//
//  GFPNDAMRAIDExecutor.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
NS_ASSUME_NONNULL_BEGIN


@class GFPNDAMraidConfiguration;
@class GFPNDAMRAIDOrientationProperties;
@class GFPError;

@protocol GFPNDAMRAIDExecutorDelegate;
@protocol GFPNDAMRAIDExpandDelegate;
@protocol GFPNDAMRAIDOrientationDelegate;

typedef void (^MraidBannerCompletion)(_Nullable id, NSError * _Nullable error);


@interface GFPNDAMRAIDExecutor : NSObject

@property (nonatomic, readwrite, weak) id<GFPNDAMRAIDExecutorDelegate> executorDelegate;
@property (nonatomic, readwrite, weak) id<GFPNDAMRAIDOrientationDelegate> orientationDelegate;

@property (nonatomic, readonly, weak, nullable) WKWebView *webView;

@property (nonatomic, readonly, assign) BOOL isViewable;

@property (nonatomic, readonly, assign) CGRect visibleRect;
@property (nonatomic, readonly, assign) CGFloat exposedPercent;

- (instancetype)initWithConfiguration:(GFPNDAMraidConfiguration *)configuration
                                webView:(WKWebView *)webView;

- (void)updateWebViewPositioniewabilityStatus;
- (void)adDidFinishExpand;
- (void)adDidFinishResize:(BOOL)success error:(GFPError * _Nullable)error;

- (void)evaluateJavaScript:(NSString *)javascript;
- (void)evaluateJavaScript:(NSString *)javascript withCompletion:(MraidBannerCompletion)completionHandler;
- (void)stopWebViewLoad;

- (void)attachContentView;
- (UIView *)detachContentView;
- (void)updateConstraintSize:(CGSize)size isValid:(BOOL)isValid;

- (void)expandRequestWith:(NSDictionary *)queryComponents;
- (void)orientationPropertiesWith:(NSDictionary *)queryComponents;

- (void)resetWebView;

- (void)finishMRAIDLoad;

- (BOOL)forwardNavigationActionWith:(WKWebView *)webView
                   navigationAction:(WKNavigationAction *)navigationAction
                          isTouched:(BOOL)isTouched;

@end


@protocol GFPNDAMRAIDExecutorDelegate <NSObject>

- (void)openUrlWith:(nonnull NSString *)urlString webView:(nonnull WKWebView *)webView;
- (void)handleMRAIDURL:(NSURL *)URL executor:(GFPNDAMRAIDExecutor *)executor isTouched:(BOOL)isTouched;

@end


@protocol GFPNDAMRAIDOrientationDelegate <NSObject>

-(void)orientationPropertiesDidChanged:(GFPNDAMRAIDOrientationProperties *)orientationProperty executor:(GFPNDAMRAIDExecutor *)executor;

- (GFPNDAMRAIDOrientationProperties *)getOrientationProperties;
- (void)setOrientationProperties:(GFPNDAMRAIDOrientationProperties *)orientationProperies;

@end

NS_ASSUME_NONNULL_END
