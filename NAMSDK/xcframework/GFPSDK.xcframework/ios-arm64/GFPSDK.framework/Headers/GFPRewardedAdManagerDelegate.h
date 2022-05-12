//
//  GFPRewardedAdManagerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class GFPRewardedAdManager;
@class GFPAdAdaptor;
@class GFPError;
@class GFPRewardedAd;
@class GFPReward;
@class GFPLoadResponseInfo;

@protocol GFPRewardedAdAdapting;

@protocol GFPRewardedAdManagerDelegate <NSObject>

-(void)rewardedAdManager:(GFPRewardedAdManager *)manager didLoadAd:(GFPRewardedAd *)rewardedAd;
-(void)rewardedAdManager:(GFPRewardedAdManager *)manager didStartAd:(GFPRewardedAd *)rewardedAd;
-(void)rewardedAdManager:(GFPRewardedAdManager *)manager wasClickedAd:(GFPRewardedAd *)rewardedAd;
-(void)rewardedAdManager:(GFPRewardedAdManager *)manager didCloseAd:(GFPRewardedAd *)rewardedAd;
-(void)rewardedAdManager:(GFPRewardedAdManager *)manager didCompleteAd:(GFPRewardedAd *)rewardedAd withReward:(nullable GFPReward *)reward;
-(void)rewardedAdManager:(GFPRewardedAdManager *)manager didFailWithError:(GFPError *)error responseInfo:(nullable GFPLoadResponseInfo *)responseInfo;

@end

NS_ASSUME_NONNULL_END
