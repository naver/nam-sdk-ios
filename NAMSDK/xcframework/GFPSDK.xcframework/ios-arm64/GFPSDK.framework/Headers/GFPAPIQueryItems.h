//
//  GFPAPIQueryItems.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class GFPAdParam;
@class GFPVideoAdParam;
@class GFPExtraRequestParam;
@class GFPAdScheduleParam;
@class GFPAdInitReqInfo;
@class GFPSKAdNetworkData;
@class GFPLogReqInfo;
@class GFPCachedAdParam;

static const NSString *kGFPExtraParamKeyFAN = @"fb";
static const NSString *kGFPExtraParamKeyVungle = @"vungle";

@interface GFPAPIQueryItems : NSObject

@property (nonatomic, readonly, strong) NSArray <NSURLQueryItem *> *items;
@property (nonatomic, readonly, strong, nullable) NSData *data;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWith:(NSString *)aUnitID
                 adParam:(GFPAdParam * _Nullable)aAdParam
              videoParam:(GFPVideoAdParam *_Nullable)aVideoAdParam
              extraParam:(GFPExtraRequestParam *_Nullable)aExtraParam;

- (instancetype)initWith:(NSString *)aScheduleID scheduleParam:(GFPAdScheduleParam *)aScheduleParam;

- (instancetype)initWith:(GFPAdInitReqInfo *)aInitInfo;

- (instancetype)initWithData:(NSData *)data;

- (instancetype)initWithLog:(GFPLogReqInfo *)aLogInfo;

@end


NS_ASSUME_NONNULL_END
