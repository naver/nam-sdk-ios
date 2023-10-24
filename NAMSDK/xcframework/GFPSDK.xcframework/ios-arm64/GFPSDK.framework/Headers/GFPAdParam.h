//
//  GFPAdParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAPSAdParam;
@class GFPContentInfo;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdParam : NSObject

/**
 * 현재 페이지를 나타내는 url
 */
@property (nonatomic, copy, nullable) NSString *currentPageUrl;

/**
 * 현재 컨텐츠를 설명하는 키워드 목록
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *keywords;

/**
 * referrer url
 */
@property (nonatomic, copy, nullable) NSString *referrerPageUrl;

/**
 * opt-out (0: 미설정, 1: 설정)
 */
@property (nonatomic, copy, nullable) NSNumber *optOut __deprecated;

/**
 * 추가 파라미터 (주의! 추가 파라미터 사전의 키/값은 모두 문자열 타입이어야 합니다.)
 */
@property (nonatomic, copy, nullable) NSDictionary <NSString *, NSString *> *customUserParam;

/**
 * PrebidMobile 헤더 비딩 파라미터 (주의! Dictionary 의 Key/Value는 모두 문자열 타입이어야 합니다.)
 */
@property (readwrite, nonatomic, copy, nullable) NSDictionary <NSString *, NSString *> *prebidHBParam;

/**
 * Amazon  헤더 비딩 파라미터.
 */
@property (readwrite, nonatomic, nullable) GFPAPSAdParam *apsParam;

/**
 * Communication Ad 용 Content Info.
 */
@property (readwrite, nonatomic, nullable) GFPContentInfo *contentInfo;

/**
 * s2s waterfall skip을 위해 지원하는 queryString.
 */
- (NSString *)adCallQueryWith:(NSString *)adUnitId;

@end

NS_ASSUME_NONNULL_END
