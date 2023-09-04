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
@protocol GFPS2SAdClickDelegate;

@interface GFPRewardedAdManager : NSObject

@property (nonatomic, weak) id<GFPRewardedAdManagerDelegate> delegate;

@property (nonatomic, readonly, assign) BOOL isAdInvalidate;
@property (nonatomic, readonly, assign) BOOL isAdLoaded;

@property (nonatomic, class, assign) BOOL isMuted;

/**
 * 광고 요청이후 로드 완료시점까지 타임아웃 (Optional)
 */
@property(readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

- (instancetype)initWithUnitID:(NSString *)adUnitID
                       adParam:(GFPAdParam *)adParam;

- (void)load;
- (void)show:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
