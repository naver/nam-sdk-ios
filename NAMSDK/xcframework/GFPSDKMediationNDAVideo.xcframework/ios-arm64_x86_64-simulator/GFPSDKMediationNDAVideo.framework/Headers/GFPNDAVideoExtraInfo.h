//
//  GFPNDAVideoExtraInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPRemindAd;
@class GFPNonLinearAdView;
@class GFPLoudnessNormalization;

NS_ASSUME_NONNULL_BEGIN


@interface GFPNDAVideoExtraInfo : NSObject


@property (readonly, nonatomic, strong) NSURL *vastURL;
@property (readonly, nonatomic, strong, nullable) NSArray <GFPRemindAd *> *remindAdList;
@property (readonly, nonatomic, strong, nullable) GFPLoudnessNormalization *loudness;

@property (readonly, nonatomic, strong, nullable) NSArray <GFPNonLinearAdView *> *remindViewList;

- (instancetype)initWithVastURL:(NSURL *)aURL remindAdList:(NSArray <GFPRemindAd *> * _Nullable)aRemindAdList loudness:(GFPLoudnessNormalization * _Nullable)aLoudness;


@end
NS_ASSUME_NONNULL_END
