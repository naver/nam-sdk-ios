//
//  DTBAdDispatcher.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 12/26/18.
//  Copyright © 2018 Krivopaltsev, Eugene. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DTBAdDispatcher.h"

@protocol DTBAdBannerDispatcherDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface DTBAdBannerDispatcher : DTBAdDispatcher

-(instancetype)initWithAdFrame:(CGRect)frame delegate:(id<DTBAdBannerDispatcherDelegate>) delegate;

-(void)fetchBannerAdWithParameters:(NSDictionary *)parameters;

-(void)fetchBannerAd:(NSString * _Nonnull)htmlString;

-(void)fetchBannerAd:(NSString * _Nonnull)htmlString params:(NSDictionary * _Nullable) params;

@end

@protocol DTBAdBannerDispatcherDelegate

- (void)adDidLoad:(UIView * _Nonnull)adView ;
- (void)adFailedToLoad:(UIView * _Nullable)banner errorCode:(NSInteger)errorCode;
- (void)bannerWillLeaveApplication:(UIView *)adView;
- (void)impressionFired;


@end

NS_ASSUME_NONNULL_END
