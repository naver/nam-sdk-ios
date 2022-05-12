//
//  GFPVideoAdInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


@class GFPRemindAd;
@class GFPLoudnessNormalization;
@class GFPNonLinearAdView;


NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoAdInfo : NSObject


/**
* 로드된 광고 제공자 명 (없으면 nil)
*/
@property (readonly, nonatomic, strong) NSString *adProviderName;


/**
* 로드된 비디오 광고 URL
*/
@property (readonly, nonatomic, strong, nullable) NSURL *url;


/**
* 로드된 Loudness Normalization.
*/
@property (readonly, nonatomic, strong, nullable) GFPLoudnessNormalization *loudnessNormalization;


/**
* 로드된 Remind Ad (Text, Banner) : SMR 전용 상품
*/
@property (readonly, nonatomic, strong, nullable) NSArray <GFPRemindAd *> *remindAdList;


/**
* 로드된 Remind Ad (Text, Banner) View
*/
@property (readonly, nonatomic, strong, nullable) NSArray <GFPNonLinearAdView *> *nonLinearViewList;


- (instancetype)initWithProvider:(NSString *)aProviderName;
- (instancetype)initWithProvider:(NSString *)aProviderName url:(NSURL * _Nullable)aURL;

- (instancetype)initWithProvider:(NSString *)aProviderName
                             url:(NSURL *)aURL
                    remindAdList:(NSArray <GFPRemindAd *> *)aRemindAdList
                  remindViewList:(NSArray <GFPNonLinearAdView *> *)remindViewList
           loudnessNormalization:(GFPLoudnessNormalization *)aLoundess;


@end

NS_ASSUME_NONNULL_END
