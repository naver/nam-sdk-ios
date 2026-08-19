//
//  GFPMagnitePrebidAdParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2026-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPMagnitePrebidAdParam : NSObject

/**
 * Magnite Prebid 의 configId.
 */
@property (readwrite, nonatomic, copy, nullable) NSString *configId;

/**
 * Magnite Prebid 헤더 비딩 파라미터 (PrebidMobile SDK 의 targetingKeywords 에 해당)
 * GFP 서버로 전달되어 입찰 비교에 사용된다.
 */
@property (readwrite, nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *targetingKeywords;

/**
 * 매체가 사전 입찰로 받은 winning bid (PrebidMobile.Bid 객체).
 */
@property (readwrite, nonatomic, strong, nullable) id winningBid;

@end

NS_ASSUME_NONNULL_END
