//
//  GFPURLUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPS2SAdClickDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPURLUtils : NSObject

+ (NSString *)paramValueForKey:(NSString *)key inURL:(NSURL *)url;

+ (NSURL *)URLWithString:(NSString *)urlString;

+ (void)sendGFPEventToUrl:(NSString *)url;

+ (NSString *)encodingURIComponent:(NSString *)string;

+ (NSURL *)URLWithBaseString:(NSString *)baseStr queryItems:(NSArray<NSURLQueryItem *> *)queryItems;

+ (BOOL)canOpenURL:(NSURL *)aURL;

+ (void)openURLWith:(NSString *)aURL completion:(GFPS2SAdLandingHandler)aCompletion;

+ (NSURLRequest *)defaultRequestWith:(NSURL * __nonnull)url;

+ (BOOL)hasHttpPrefix:(NSURL *)aURL;

@end

NS_ASSUME_NONNULL_END
