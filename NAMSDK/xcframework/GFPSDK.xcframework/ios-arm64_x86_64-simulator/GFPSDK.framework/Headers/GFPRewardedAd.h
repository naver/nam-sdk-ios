//
//  GFPRewardedAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPRewardedAdDelegate.h"

@protocol GFPRewardedAdAdapting;

@class UIViewController;
@class GFPAdAdaptor;
@class GFPLoadResponseInfo;

NS_ASSUME_NONNULL_BEGIN

@interface GFPRewardedAd : NSObject

@property(nonatomic, weak) id <GFPRewardedAdDelegate> delegate;

/**
 * 광고 제공자 이름
 */
@property (nonatomic, readonly, strong) NSString *adProviderName;

/**
 * 광고 유효성 여부
 */
@property (nonatomic, readonly, assign) BOOL isAdInvalidate;

/**
 * 광고 로드 여부
 */
@property (nonatomic, readonly, assign) BOOL isAdLoaded;

/**
 * 광고 응답 객체
 */
@property (nonatomic, readonly, strong) GFPLoadResponseInfo *responseInfo;


/**
 * S2S Player mute 정보
 */
@property (nonatomic, readonly, assign) BOOL isS2SPlayerMuted;

/**
 * S2S Player mute 셋팅
 */
- (void)setS2SPlayerMute:(BOOL)isMuted;

@end


NS_ASSUME_NONNULL_END
