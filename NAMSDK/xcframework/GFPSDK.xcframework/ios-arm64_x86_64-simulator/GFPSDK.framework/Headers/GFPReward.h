//
//  GFPReward.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPReward : NSObject

@property (nonatomic, readonly, strong) NSString *type;
@property (nonatomic, readonly, strong) NSNumber *amount;

- (nonnull instancetype)initWithRewardType:(nonnull NSString *)rewardType
                              rewardAmount:(nonnull NSNumber *)rewardAmount;

@end

NS_ASSUME_NONNULL_END
