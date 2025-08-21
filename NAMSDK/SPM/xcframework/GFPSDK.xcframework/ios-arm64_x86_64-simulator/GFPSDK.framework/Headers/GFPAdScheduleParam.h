//
//  GFPAdScheduleParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <Foundation/Foundation.h>
#import "GFPAdParam.h"
#import "GFPVideoAdPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPTextAdViewAttribute;

@interface GFPAdScheduleParam : NSObject

@property (nonatomic, readonly, assign) GFPVideoPlacementType policyType;
@property (nonatomic, readonly, strong) NSString *policy;


@property (nonatomic, readonly, assign) NSTimeInterval duration;
@property (nonatomic, readonly, strong) GFPAdParam *adParam;

// Optional.
@property (nonatomic, assign) NSTimeInterval noticeDurationSec;
@property (nonatomic, assign) NSTimeInterval startOffset;

@property (nonatomic, assign) BOOL isPreAdOff;
@property (nonatomic, assign) BOOL isMidAdOff;
@property (nonatomic, assign) BOOL isPostAdOff;

@property (nonatomic, strong, nullable) GFPTextAdViewAttribute *textAttribute;

- (instancetype)initWithPlacementPolicy:(GFPVideoPlacementType)aPolicy duration:(NSTimeInterval)aDuration param:(nullable GFPAdParam *)aAdParam;


@end

NS_ASSUME_NONNULL_END
