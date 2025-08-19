//
//  GFPURLSession.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPAPIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPURLSession : NSObject

- (instancetype)init NS_UNAVAILABLE; // CHECK: - 광고 요청 시 CookieStroage 공유 불필요.
+ (instancetype)ephemeralSession;
+ (instancetype)ephemeralSessionWithTimeout:(NSTimeInterval)timeoutInterval;

- (NSURLSessionDataTask * _Nullable)dataTaskWithRequest:(GFPAPIRequest *)aAPIRequest
                                      completionHandler:(nonnull void (^)(NSData * _Nullable, NSURLResponse * _Nullable, NSError * _Nullable))completionHandler;
@end

NS_ASSUME_NONNULL_END
