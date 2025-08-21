//
//  GFPInterstitialAdManager+WFPreload.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

#import "GFPInterstitialAdManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPInterstitialAdManager (WFPreload)

/**
 * InterstitialAdManager 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithDict:(NSDictionary *)preloadWaterfallResponse;

/**
 * InterstitialAdManager 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithString:(NSString *)preloadWaterfallResponse;

/**
 * InterstitialAdManager 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithData:(NSData *)preloadWaterfallResponse;

@end

NS_ASSUME_NONNULL_END
