//
//  GFPAdLoader+WFPreload.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import "GFPAdLoader.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdLoader (WFPreload)

/**
 * AdLoader 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithDict:(NSDictionary *)preloadWaterfallResponse NS_SWIFT_NAME(loadAdWith(dict:));

/**
 * AdLoader 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithString:(NSString *)preloadWaterfallResponse NS_SWIFT_NAME(loadAdWith(string:));

/**
 * AdLoader 에 광고 요청, WF 단계를 건너뛰기 위한 요청
 * @param preloadWaterfallResponse  서비스 측에서 미리 로드된 WF 전문
*/
- (void)loadAdWithData:(NSData *)preloadWaterfallResponse NS_SWIFT_NAME(loadAdWith(data:));

@end

NS_ASSUME_NONNULL_END
