//
//  GFPNativeAd+InHouse.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.

#import "GFPNativeAd.h"

@class GFPNativeAdView;

@interface GFPNativeAd ()

/**
 * S2S 사용 시 mediaView Image 초기화를 위한 기능
 */
- (void)clearForMemoryWarning;

/**
 * S2S 사용 시 mediaView Image 재로드가 필요한 경우
 */
- (BOOL)isReloadRequired;

/**
 * S2S 사용 시 mediaView Image 수동 재로드
 */
- (void)reloadMedia;

/**
 * 등록된 view 판단 여부
 */
- (BOOL)isRegiterViewWith:(GFPNativeAdView *)adView;

@end

