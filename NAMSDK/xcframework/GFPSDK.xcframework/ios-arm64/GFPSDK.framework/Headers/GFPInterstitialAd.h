//
//  GFPInterstitialAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

#import "GFPInterstitialAdDelegate.h"

@protocol GFPInterstitialAdAdapting;

@class GFPLoadResponseInfo;

NS_ASSUME_NONNULL_BEGIN

@interface GFPInterstitialAd : NSObject

@property (nonatomic, weak) id <GFPInterstitialAdDelegate> delegate;

/**
 * 로드된 전면형  광고 제공자 명 (없으면 nil)
 */
@property (nonatomic, readonly, strong, nullable) NSString *adProviderName;

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

@end

NS_ASSUME_NONNULL_END
