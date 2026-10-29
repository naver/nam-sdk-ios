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

@optional
//화면 지오메트리(방향 또는 화면 크기)가 바뀌어 screenSize/maxSize 를 재전송한 뒤 호출된다.
//폴더블 접힘/펼침처럼 회전 노티 없이 화면이 바뀌는 경우 resize 뷰 재배치 등에 사용한다.
- (void)screenGeometryDidChangeWithExecutor:(GFPNDAMRAIDExecutor *)executor;

@end


@protocol GFPNDAMRAIDOrientationDelegate <NSObject>

-(void)orientationPropertiesDidChanged:(GFPNDAMRAIDOrientationProperties *)orientationProperty executor:(GFPNDAMRAIDExecutor *)executor;

- (GFPNDAMRAIDOrientationProperties *)getOrientationProperties;
- (void)setOrientationProperties:(GFPNDAMRAIDOrientationProperties *)orientationProperies;

@end

NS_ASSUME_NONNULL_END
