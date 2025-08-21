//
//  GFPConfigCache.h
//  GFPSDK
//
//  Created by dojin.park on 2022/05/20.
//

#import "GFPAdInitInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPInitResponseCache : NSObject

+ (void)cacheAdCallTimestamp:(NSNumber *)timestamp;
+ (void)cacheInitResponseDict:(NSDictionary *)dict;
+ (NSDictionary * _Nullable)loadInitResponseDict;
+ (GFPAdInitInfo * _Nullable)loadInitInfo;
+ (NSString * _Nullable)loadNac;
+ (void)cacheNac:(NSString *)nac;

@end

NS_ASSUME_NONNULL_END
