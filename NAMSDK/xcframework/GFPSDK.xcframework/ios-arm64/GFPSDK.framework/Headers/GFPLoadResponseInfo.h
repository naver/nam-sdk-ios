//
//  GFPLoadResponseInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPInternalResponseInfo : NSObject

@property (nonatomic, strong, readonly) NSString *adaptorName;

@property (nonatomic, strong, readonly) NSNumber *loadLatency;
@property (nonatomic, strong, readonly) NSNumber *loadErrorLatency;

@property (nonatomic, strong, readonly) NSString *errorMesage;


@end


@interface GFPLoadResponseInfo : NSObject

@property (nonatomic, strong, readonly) NSString *requestID;

@property (nonatomic, strong, readonly) NSNumber *adCallLatency;
@property (nonatomic, strong, readonly) NSNumber *totalLoadLatency;
@property (nonatomic, strong, readonly) NSNumber *adaptorLoadLatency;

@property (nonatomic, strong, readonly) NSArray <GFPInternalResponseInfo *> *loadResponseList;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRequestTime:(NSNumber *)aAdRequestTime NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
