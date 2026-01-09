//
//  GFPRewardedAdManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPRewardedAdManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPAdParam;
@class GFPOMFriendlyObstruction;

@protocol GFPS2SAdClickDelegate;

@interface GFPRewardedAdManager : NSObject

@property (readonly, nonatomic, strong) NSString *adUnitID;

@property (nonatomic, weak) id<GFPRewardedAdManagerDelegate> delegate;

@property (nonatomic, readonly, assign) BOOL isAdInvalidate;
@property (nonatomic, readonly, assign) BOOL isAdLoaded;

/**
 S2S Server Reward 적용된 광고 여부
 */
@property (nonatomic, readonly, assign) BOOL isAdServerVerificationEnabled;

/**
 * 광고 요청이후 로드 완료시점까지 타임아웃 (Optional)
 */
@property(readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

/**
 * OMSDK를 측정하는 광고의 friendlyObstruction을 설정합니다.
 */
@property (nonatomic, strong, nullable) NSArray <GFPOMFriendlyObstruction *> *omFriendlyObstructions;


- (instancetype)initWithUnitID:(NSString *)adUnitID
                       adParam:(GFPAdParam *)adParam;

- (void)load;
- (void)show:(UIViewController *)rootViewController;

+ (void)resumeCurrentRewardVideo;


/**
 * S2S광고에 한해 현재 뮤트 상태에 대한 기능을 제공합니다.
 */
- (BOOL)isS2SPlayerMuted;
- (void)setS2SPlayerMute:(BOOL)isMuted;

/**
 S2S Server Reward Check 요청 API
 */
- (void)requestServerVerification;
/**
 S2S 광고에 한해 제공되는 Close 옵션
 */
- (void)close;

@end

NS_ASSUME_NONNULL_END
