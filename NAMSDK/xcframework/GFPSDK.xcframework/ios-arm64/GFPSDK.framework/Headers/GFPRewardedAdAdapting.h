//
//  GFPRewardedAdAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPAdAdapting.h"

@protocol GFPRewardedAdAdaptorDelegate;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPRewardedStatus) {
    GFPRewardedNotYet = 1 << 0,
    GFPRewardedLoaded = 1 << 1,
    GFPRewardedShowed = 1 << 2,
};

@protocol GFPRewardedAdAdapting <GFPAdAdapting>

@property (nullable, readwrite, nonatomic, weak) id <GFPRewardedAdAdaptorDelegate> delegate;

@property (nonatomic, assign) BOOL isExpired;
@property (nonatomic, assign) GFPRewardedStatus status;

@required

- (void)requestPresentRewardedAd:(UIViewController *)rootViewController;
- (BOOL)isAdInvalidate;
- (BOOL)isAdLoaded;

@end

NS_ASSUME_NONNULL_END
