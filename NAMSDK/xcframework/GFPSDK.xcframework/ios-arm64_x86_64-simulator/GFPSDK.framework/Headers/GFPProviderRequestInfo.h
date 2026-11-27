//
//  GFPProviderRequestInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2026-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 광고 요청 직전 provider 에 추가 요청 파라미터 수집을 맡길 때 넘기는 입력.
@interface GFPProviderRequestInfo : NSObject

@property (nonatomic, copy, readonly, nullable) NSString *adUnitId;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAdUnitId:(NSString * _Nullable)adUnitId NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
