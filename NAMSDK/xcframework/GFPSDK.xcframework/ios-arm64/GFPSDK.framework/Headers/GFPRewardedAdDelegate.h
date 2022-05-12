//
//  GFPRewardedAdDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

@class GFPRewardedAd;
@class GFPReward;
@class GFPError;

@protocol GFPRewardedAdDelegate <NSObject>

- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didCompleteWithReward:(GFPReward *)reward;
- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didFaileWithError:(GFPError *)error;

- (void)rewardedAdStarted:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdWasClicked:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdClosed:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdRecieveImpression:(GFPRewardedAd *)rewardedAd;

@end
