//
//  GFPInterstitialAdManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPInterstitialAdManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPAdParam;


@interface GFPInterstitialAdManager : NSObject

@property (nonatomic, weak) id<GFPInterstitialAdManagerDelegate> delegate;

- (instancetype)initWithUnitID:(NSString *)adUnitID
                       adParam:(GFPAdParam *)adParam;

- (void)load;
- (void)show:(UIViewController *)rootViewController;
- (BOOL)isAdInvalidate;
- (BOOL)isAdLoaded;


/**
 * 광고 요청이후 로드 완료시점까지 타임아웃 (Optional)
 */
@property(readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

@end

NS_ASSUME_NONNULL_END
