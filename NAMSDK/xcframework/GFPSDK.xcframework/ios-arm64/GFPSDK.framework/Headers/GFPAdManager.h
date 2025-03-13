//
//  GFPAdManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#include <AvailabilityMacros.h>
#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#import "GFPRenderDisplayAgent.h"
#import "GFPAdConfiguration.h"
#import "GFPUserParam.h"

#import "GFPAdManagerDelegate.h"

@class GFPError;

NS_ASSUME_NONNULL_BEGIN

extern NSTimeInterval const kGFPDefaultBannerAdRequestTimeout;
extern NSTimeInterval const kGFPDefaultVideoAdRequestTimeout;
extern NSTimeInterval const kGFPDefaultUnifiedAdRequestTimeout;
extern NSTimeInterval const kGFPDefaultRewardedAdRequestTimeout;
extern NSTimeInterval const kGFPDefaultInterstitialAdRequestTimeout;

typedef void(^GFPAdManagerCompletionHandler)(GFPError * _Nullable error);


@interface GFPAdManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * 광고 매니저를 초기화 합니다.
 * GFP를 통해 광고를 받아올 광고 provider 등록할 필요 없이, cocoapods 등록한 provider 별로 초기화가 이루어 집니다.
 * provider에 따라 초기화에 시간이 오래 걸릴 수 있으므로 어플리케이션 로드시점 한번만 호출해주시면 됩니다. (eg. IMA는 구글 문서기준 약 1~2초 소요)
 * 여기서 초기화되지 않은 provider로 부터의 광고는 이후 서버로부터의 응답결과와 관계없이 처리되지 않습니다.
 * 오류결과는 completionHandler의 error 에서 확인해 주세요.
 *
 * @param publisherCd 광고 퍼블리셔 Code
 * @param target Limited Ad Tracking 스테이터스 조회 Delegate
 * @param completionHandler 초기화 결과 확인 handler
*/
+ (void)setupWithPublisherCd:(NSString * _Nullable)publisherCd
                      target:(id <GFPAdManagerDelegate> _Nullable)target
           completionHandler:(GFPAdManagerCompletionHandler)completionHandler;


/**
 * 광고 매니저를 초기화 합니다.
 * GFP를 통해 광고를 받아올 광고 provider 등록할 필요 없이, cocoapods 등록한 provider 별로 초기화가 이루어 집니다.
 * provider에 따라 초기화에 시간이 오래 걸릴 수 있으므로 어플리케이션 로드시점 한번만 호출해주시면 됩니다. (eg. IMA는 구글 문서기준 약 1~2초 소요)
 * 여기서 초기화되지 않은 provider로 부터의 광고는 이후 서버로부터의 응답결과와 관계없이 처리되지 않습니다.
 * 오류결과는 completionHandler의 error 에서 확인해 주세요.
 *
 * @param publisherCd 광고 퍼블리셔 Code
 * @param target Limited Ad Tracking 스테이터스 조회 Delegate
 * @param configuration 광고 관련 설정 옵션
 * @param completionHandler 초기화 결과 확인 handler
*/
+ (void)setupWithPublisherCd:(NSString * _Nullable)publisherCd
                      target:(id<GFPAdManagerDelegate> _Nullable)target
               configuration:(GFPAdConfiguration * _Nullable)configuration
           completionHandler:(GFPAdManagerCompletionHandler)completionHandler;

/**
 * 광고 매니저를 초기화 합니다.
 * GFP를 통해 광고를 받아올 광고 provider 등록할 필요 없이, cocoapods 등록한 provider 별로 초기화가 이루어 집니다.
 * provider에 따라 초기화에 시간이 오래 걸릴 수 있으므로 어플리케이션 로드시점 한번만 호출해주시면 됩니다. (eg. IMA는 구글 문서기준 약 1~2초 소요)
 * 여기서 초기화되지 않은 provider로 부터의 광고는 이후 서버로부터의 응답결과와 관계없이 처리되지 않습니다.
 * 오류결과는 completionHandler의 error 에서 확인해 주세요.
 *
 * @param publisherCd 광고 퍼블리셔 Code
 * @param serviceCd 발급 받은 Service Code (optional)
 * @param target Limited Ad Tracking 스테이터스 조회 Delegate
 * @param completionHandler 초기화 결과 확인 handler
*/
+ (void)setupWithPublisherCd:(NSString * _Nullable)publisherCd
                   serviceCd:(NSString * _Nullable)serviceCd
                      target:(id <GFPAdManagerDelegate> _Nullable)target
           completionHandler:(GFPAdManagerCompletionHandler)completionHandler;


/**
 * 광고 매니저를 초기화 합니다.
 * GFP를 통해 광고를 받아올 광고 provider 등록할 필요 없이, cocoapods 등록한 provider 별로 초기화가 이루어 집니다.
 * provider에 따라 초기화에 시간이 오래 걸릴 수 있으므로 어플리케이션 로드시점 한번만 호출해주시면 됩니다. (eg. IMA는 구글 문서기준 약 1~2초 소요)
 * 여기서 초기화되지 않은 provider로 부터의 광고는 이후 서버로부터의 응답결과와 관계없이 처리되지 않습니다.
 * 오류결과는 completionHandler의 error 에서 확인해 주세요.
 *
 * @param publisherCd 광고 퍼블리셔 Code
 * @param serviceCd 발급 받은 Service Code (optional)
 * @param target Limited Ad Tracking 스테이터스 조회 Delegate
 * @param configuration 광고 관련 설정 옵션
 * @param completionHandler 초기화 결과 확인 handler
*/
+ (void)setupWithPublisherCd:(NSString * _Nullable)publisherCd
                   serviceCd:(NSString * _Nullable)serviceCd
                      target:(id<GFPAdManagerDelegate> _Nullable)target
               configuration:(GFPAdConfiguration * _Nullable)configuration
           completionHandler:(GFPAdManagerCompletionHandler)completionHandler;


/**
 *  GFPSDK 설정
 */
+ (void)setAdConfiguration:(GFPAdConfiguration *)sdkConfig;

/**
 * GFPSDK 설정 조회
 */
+ (GFPAdConfiguration *)adConfiguration;

/**
 * 유저 타겟 정보 설정
 */
+ (void)setUserParam:(GFPUserParam *)param;

/**
 * 유저 타겟 정보 조회
 */
+ (nullable GFPUserParam *)userParam;


/**
 * GFPSDK Cookie 조회
*/
+ (NSDictionary <NSString *, NSString *> *)cookie;


/**
 * GFPSDK Cookie 세팅
*/
+ (void)setCookie:(NSDictionary <NSString *, NSString *> *)aCookie;

/**
 *  Add GFPSDK cookie
*/
+ (void)appendCookie:(NSDictionary <NSString *, NSString *> *)aCookie;

/**
 * Remove all oookies.
*/
+ (void)clearCookie;

/**
 * Register web view for interaction with iOS SDK.
 */
+ (void)registerWebView:(WKWebView *)webView;

/**
 * Check for web view registration success  .
 */
+ (void)examineWebViewStatus:(WKWebView *)webView result:(void (^)(NSError * _Nullable error, NSDictionary *statusInfo))result;

/**
 * GFPSDK Version.
 */
+ (NSString *)sdkVersion;

/**
 * GFPSDK 초기화 여부
 */
+ (BOOL)isSdkInitialized;


/**
 * MemoryCache Clear (for memory warning)
 */
+ (void)clearMemoryCache;

@end

NS_ASSUME_NONNULL_END
