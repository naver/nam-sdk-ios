//
//  GFPAdCacheOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

@class GFPAdParam;
@class GFPOMFriendlyObstruction;

@class GFPAdNativeSimpleOptions;
@class GFPAdNativeOptions;

@protocol GFPS2SAdClickDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdCacheBaseOptions: NSObject

@property (nonatomic, strong, readonly) NSString *adUnitId;
@property (nonatomic, strong, readonly) GFPAdParam *adParam;

@property (nonatomic, assign) NSTimeInterval requestTimeoutInterval;

@property (nonatomic, weak, nullable) id <GFPS2SAdClickDelegate> s2sClickDelegate;

- (instancetype)initWith:(NSString *)adUnitId adParam:(GFPAdParam * _Nullable)adParam;

@end


@interface GFPAdCacheNativeOptions: GFPAdCacheBaseOptions

@property (nonatomic, strong, readonly) GFPAdNativeSimpleOptions *simpleOptions;
@property (nonatomic, strong, readonly) GFPAdNativeOptions *nativeOptions;

- (instancetype)initWith:(NSString *)adUnitId
                 adParam:(GFPAdParam * _Nullable)adParam
           simpleOptions:(GFPAdNativeSimpleOptions * _Nullable)simpleOptions
           nativeOptions:(GFPAdNativeOptions * _Nullable)nativeOptions;

@end

NS_ASSUME_NONNULL_END
