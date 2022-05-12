//
//  GFPNonLinearFactory.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


@class GFPRemindAd;
@class GFPNonLinearAdView;
@class GFPVideoAdInfo;

NS_ASSUME_NONNULL_BEGIN


@interface GFPNonLinearFactory : NSObject


- (void)append:(GFPRemindAd *)aRemindAd;
- (void)appendList:(NSArray <GFPRemindAd *> *)aRemindList;

- (GFPRemindAd * _Nullable)remindAdWithOffset:(NSInteger)aOffset;

- (void)appendViewList:(NSArray <GFPNonLinearAdView *> *)viewList;
- (GFPNonLinearAdView * _Nullable)nonLinearViewWithOffset:(NSInteger)offSet;


- (void)updateVideoAdInfo:(GFPVideoAdInfo *)aVideoInfo;

@end

NS_ASSUME_NONNULL_END
