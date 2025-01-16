//
//  GFPRewardedAdAdaptorDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GFPRewardedAdAdapting;

@class GFPReward;
@class GFPAdAdaptor;

@protocol GFPRewardedAdAdaptorDelegate <NSObject>

- (void)rewardedAdDidStart:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor;
- (void)rewardedAdAdaptor:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor didCompleteWithReward:(GFPReward *_Nullable)reward;
- (void)rewardedAdDidClose:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor elapsedTime:(NSString *)elapsedTime;
- (void)rewardedAdAdaptor:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor didFailWithError:(GFPError *)error;

- (void)rewardedAdWasClicked:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor;
- (void)rewardedAdAdaptorRecieveImpression:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor;

- (void)rewardedAdAdaptor:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor didChangedMute:(BOOL)isMuted;

@optional
- (void)rewardedAdAdaptorDidPresentDefaultInAppBrowser:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor;
- (void)rewardedAdAdaptorDidDismissDefaultInAppBrowser:(GFPAdAdaptor <GFPRewardedAdAdapting> *)rewardedAdAdaptor;

@end

NS_ASSUME_NONNULL_END
