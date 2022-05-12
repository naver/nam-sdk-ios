//
//  GFPAdvertiseParams.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAdScheduleParam;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdvertiseParams : NSObject

@property (nonatomic, readonly, strong, nonnull) NSString *scheduleID;
@property (nonatomic, readonly, strong, nullable) GFPAdScheduleParam *scheduleParam;

@property (nonatomic, readonly, assign) BOOL isInvalid;


- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(NSString *)aParam NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
