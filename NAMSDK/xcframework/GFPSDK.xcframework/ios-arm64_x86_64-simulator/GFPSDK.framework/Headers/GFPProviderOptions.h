//
//  GFPProviderOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#ifndef GFPProviderOptions_h
#define GFPProviderOptions_h

#include <Foundation/Foundation.h>


/**
 * GFP에서 지원하는 배너광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPBannerProviderOptions) {
    GFPBannerProviderOptionNone = 0,
    GFPBannerProviderOptionNDA = 1 << 0,     /* 네이버 디스플레이 광고 */
    GFPBannerProviderOptionDFP = 1 << 1,     /* 구글 DFP */
    // GFPBannerProviderOptionMoPub = 1 << 2,   /* (deprecate)모펍 */
    GFPBannerProviderOptionInMobi = 1 << 3,  /* 인모비 */
    GFPBannerProviderOptionFAN = 1 << 4,  /* 페이스북 FAN */
    GFPBannerProviderOptionUnity = 1 << 5, /* Unity */
};

/**
 * GFP에서 지원하는 비디오광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPVideoProviderOptions) {
    GFPVideoProviderOptionNone = 0,
    GFPVideoProviderOptionNDA = 1 << 0,    /* 네이버 디스플레이 광고 */
    GFPVideoProviderOptionIMA = 1 << 1,    /* 구글 IMA */
};

/**
 * GFP에서 지원하는 네이티브광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPNativeProviderOptions) {
    GFPNativeProviderOptionNone = 0,
    GFPNativeProviderOptionNDA = 1 << 0,     /* 네이버 디스플레이 광고 */
    GFPNativeProviderOptionDFP = 1 << 1,    /* 구글 DFP */
    GFPNativeProviderOptionFAN = 1 << 2,    /* 페이스북 FAN */
    // GFPNativeProviderOptionMoPub = 1 << 3,   /* (deprecate)모펍 */
    GFPNativeProviderOptionInMobi = 1 << 4,  /* 인모비 */
};

/**
 * GFP에서 지원하는 Combined (배너, 네이티브)광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPCombinedProviderOptions) {
    GFPCombinedProviderOptionNone = 0,
    GFPCombinedProviderOptionDFP = 1, /* 구글 DFP */
};

/**
 * GFP에서 지원하는 Reward 광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPRewardedAdProviderOptions) {
    GFPRewardedAdProviderOptionNone = 0,
    GFPRewardedAdProviderOptionDFP = 1, /* 구글 DFP */
    GFPRewardedAdProviderOptionFAN = 2, /* 페이스북 FAN */
    // GFPRewardedAdProviderOptionMoPub = 3, /* (deprecate)모펍 */
    GFPRewardedAdProviderOptionInMobi = 4, /* 인모비 */
    GFPRewardedAdProviderOptionUnity = 5, /* 유니티 */
};

/**
 * GFP에서 지원하는 Interstitial 광고 제공자 목록
 */
typedef NS_OPTIONS(NSInteger, GFPInterstitialAdProviderOptions) {
    GFPInterstitialAdProviderOptionNone = 0,
    GFPInterstitialAdProviderOptionDFP = 1, /* 구글 DFP */
    GFPInterstitialAdProviderOptionFAN = 2, /* 페이스북 FAN */
    // GFPInterstitialAdProviderOptionMoPub = 3, /* (deprecate)모펍 */
    GFPInterstitialAdProviderOptionInMobi = 4, /* 인모비 */
    GFPInterstitialAdProviderOptionUnity = 5, /* 유니티 */
};



#endif /* GFPProviderOptions_h */
