//
//  GFPTimeUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


static NSTimeInterval const kInvalidTimeInterval = -1;


NS_ASSUME_NONNULL_BEGIN

@interface GFPTimeUtils : NSObject

+ (NSNumber *)currentUptime;

+ (NSTimeInterval)convertTimeFormatString:(NSString * _Nullable)timeString;

+ (NSTimeInterval)convertTimeOrPercentFormatString:(NSString *)string
                          withDurationTimeInterval:(NSTimeInterval)durationTimeInterval;

+ (NSInteger)secondFromTimeInterval:(NSTimeInterval)aTimeInterval;

@end

NS_ASSUME_NONNULL_END
