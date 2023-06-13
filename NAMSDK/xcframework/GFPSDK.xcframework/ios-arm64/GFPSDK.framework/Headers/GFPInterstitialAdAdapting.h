//
//  GFPInterstitialAdAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPAdAdapting.h"

@protocol GFPInterstitialAdAdaptorDelegate;

typedef NS_OPTIONS(NSInteger, GFPInterstitialStatus) {
    GFPInterstitialNotYet = 1 << 0,
    GFPInterstitialLoaded = 1 << 1,
    GFPInterstitialShowed = 1 << 2,
};

NS_ASSUME_NONNULL_BEGIN

@protocol GFPInterstitialAdAdapting <GFPAdAdapting>

@property (nullable, readwrite, nonatomic, weak) id <GFPInterstitialAdAdaptorDelegate> delegate;

@property (nonatomic, assign) BOOL isExpired;
@property (nonatomic, assign) GFPInterstitialStatus status;

@required

- (void)requestPresentInterstitialAd:(UIViewController *)rootViewController;
- (BOOL)isAdInvalidate;
- (BOOL)isAdLoaded;

@end

NS_ASSUME_NONNULL_END
