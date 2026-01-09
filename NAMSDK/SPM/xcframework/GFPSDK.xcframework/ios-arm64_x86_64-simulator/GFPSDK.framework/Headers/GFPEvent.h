//
//  GFPEvent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPEvent : NSObject


@property (readonly, nonatomic, strong) NSNumber *eventTime;  // uptime
@property (readonly, nonatomic, strong) NSNumber *eventTimestamp;


@end

NS_ASSUME_NONNULL_END
