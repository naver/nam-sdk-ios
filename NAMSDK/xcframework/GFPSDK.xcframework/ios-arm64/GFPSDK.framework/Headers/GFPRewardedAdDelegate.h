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

NS_ASSUME_NONNULL_BEGIN

- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didCompleteWithReward:(GFPReward *)reward;
- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didFaileWithError:(GFPError *)error;

- (void)rewardedAdStarted:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdWasClicked:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdClosed:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdRecieveImpression:(GFPRewardedAd *)rewardedAd;

- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didChangedMute:(BOOL)isMuted;

@optional
- (void)rewardedAdDidPresentDefaultInAppBrowser:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAdDidDismissDefaultInAppBrowser:(GFPRewardedAd *)rewardedAd;


- (void)rewardedAdDidSuccessServerRewardVerification:(GFPRewardedAd *)rewardedAd;
- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didFailedServerRewardVerification:(GFPError *)error;
- (void)rewardedAd:(GFPRewardedAd *)rewardedAd didReceiveErrorServerRewardVerification:(GFPError *)error;

NS_ASSUME_NONNULL_END

@end
