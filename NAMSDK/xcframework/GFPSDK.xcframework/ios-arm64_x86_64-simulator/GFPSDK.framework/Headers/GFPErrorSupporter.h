//
//  GFPErrorSupporter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@import NaverAdsServices;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const GFPErrorDomain;
FOUNDATION_EXPORT NSString *const GFPErrorUnityDomain;
FOUNDATION_EXPORT NSString *const GFPErrorMessageKey;
FOUNDATION_EXPORT NSString *const GFPErrorDescriptionKey;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeKey;

FOUNDATION_EXPORT NSString *const GFPBannerProviderDFPErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderNDAErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderInMobiErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderFANErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderUnityErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderAppLovinErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderVungleErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderDTErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderISErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderChartBoostErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderBidMachineErrorKey;
FOUNDATION_EXPORT NSString *const GFPBannerProviderPangleErrorKey;

FOUNDATION_EXPORT NSString *const GFPVideoProviderIMAErrorKey;
FOUNDATION_EXPORT NSString *const GFPVideoProviderNDAErrorKey;
FOUNDATION_EXPORT NSString *const GFPVideoProviderFANErrorKey;

FOUNDATION_EXPORT NSString *const GFPNativeProviderDFPErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderFANErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderInMobiErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderVungleErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderNDAErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderLANErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderBidMachineErrorKey;
FOUNDATION_EXPORT NSString *const GFPNativeProviderPangleErrorKey;

FOUNDATION_EXPORT NSString *const GFPInterstitialProviderDFPErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderFANErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderUnityErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderAppLovinErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderVungleErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderDTErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderISErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderLANErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderChartBoostErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderBidMachineErrorKey;
FOUNDATION_EXPORT NSString *const GFPInterstitialProviderPangleErrorKey;

FOUNDATION_EXPORT NSString *const GFPRewardProviderDFPErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderFANErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderUnityErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderAppLovinErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderVungleErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderNDAErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderDTErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderISErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderAPSErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderLANErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderChartBoostErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderBidMachineErrorKey;
FOUNDATION_EXPORT NSString *const GFPRewardProviderPangleErrorKey;

FOUNDATION_EXPORT NSString *const GFPNativeCarouselNotSupportedVisualKeySubErrorCodeKey;
FOUNDATION_EXPORT NSString *const GFPNativeCarouselNotSupportedSlotTypeSubErrorCodeKey;
FOUNDATION_EXPORT NSString *const GFPNativeCarouselNotSupportedSlotVisualSubErrorCodeKey;
FOUNDATION_EXPORT NSString *const GFPNativeCarouselNotEnoughSlotCountSubErrorCodeKey;

FOUNDATION_EXPORT NSErrorUserInfoKey const GFPErrorHttpStatusCode;

typedef NS_ENUM(NSInteger, GFPErrorCode) {
    // General Error
    GFPErrorInternal = 1000,
    GFPErrorWrongCommand = 1100,

    // SDK Initialization
    GFPErrorInitProvider = 2200,
    GFPErrorInitUnknownProvider = 2210,
    GFPErrorInitBannerProvider = 2220,
    GFPErrorInitVideoProvider = 2230,
    GFPErrorInitNativeProvider = 2240,
    GFPErrorInitCombinedProvider = 2250,
    
    // SDK Init API
    GFPErrorParamInitInfo = 2300,
    GFPErrorRequestInitInfo = 2310,
    GFPErrorParseInitInfo = 2320,
    GFPErrorWrongFormatInitInfo = 2321,
    
    // GFP Load AD
    GFPErrorLoad = 3000,
    GFPErrorCancelInternal = 3001,
    GFPErrorBannerInvalidSize = 3002,
    GFPErrorVideoVastEmpty = 3003,
    GFPErrorVideoVastWrongFormat = 3004,
    GFPErrorVideoLoudnessWrongFormat = 3005,
    GFPErrorVideoNonLinearWrongFormat = 3006,
    GFPErrorVideoAdBreakWrongFormat = 3007,

    GFPErrorInvalidAdUnit = 3110,
    GFPErrorInvalidAdParam = 3120,

    GFPErrorRequestAdList = 3210,
    GFPErrorParseAdList = 3220,
    GFPErrorWrongFormatAdList = 3221,

    GFPErrorNoValidProvider = 3301,
    GFPErrorNoFill = 3310,
    GFPErrorBannerProviderLoadFailed = 3311,
    GFPErrorVideoProviderLoadFailed = 3312,
    GFPErrorNativeProviderLoadFailed = 3313,
    GFPErrorInvalidAdSize = 3314,

    GFPErrorRenderingNotSupported = 3320,

    GFPErrorRequestTimeout = 3400,

    // Video Ad
    GFPErrorVideoAdStartFailed = 4110,
    GFPErrorVideoAdNotYetLoaded = 4111,
    GFPErrorVideoStartTimeout = 4112,
    GFPErrorVideoBufferingTimeout = 4113,

    // Native Ad
    GFPErrorNativeAdRendering = 5100,
    GFPErrorNativeImageLoadFailed = 5110,
    GFPErrorNativeVideoLoadFailed = 5120,
    
    // Mraid Ad
    GFPErrorMraidSDKInternal = 60000,
    GFPErrorMraidResizeAdSizeError = 60001,
    GFPErrorMraidUnloadCalled = 60002,

    // JSTag Ad
    GFPErrorJSTagInternal = 70000,    

    
    // Schedule Ad
    GFPErrorSchedule = 9000,
    GFPErrorInvalidScheduleInValidParam = 9100,
    GFPErrorInvalidScheduleUnit = 9110,
    GFPErrorInvalidScheduleParam = 9120,
    
    GFPErrorRequestScheduleList = 9210,
    GFPErrorParseScheduleList = 9220,
    GFPErrorScheduleVideoLoadFailed = 9312,
    
    // Rewarded Ad
    GFPErrorRewardedAd = 6000,
    GFPErrorRewardedAdRendering = 6100,
    GFPErrorRewardedAdNotComplete = 6101,
    
    GFPErrorRewardedServerResponse = 6200,
    GFPErrorRewardedServerResponseJsonInvalid = 6201,
    GFPErrorRewardedServerResponseFailReason = 6202,
    GFPErrorRewardedServerResponseFailRejected = 6203,


    // Interstitial Ad
    GFPErrorInterstitialAd = 7000,
    GFPErrorInterstitialAdRendering = 7100,
};


@interface GFPErrorSupporter : NSObject

+ (NSDictionary *)supportedErrorCodeNameDict;
+ (NSString *)domain;
+ (NSString *)errorMessageKey;

@end

NS_ASSUME_NONNULL_END
