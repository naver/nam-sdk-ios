//
//  GFPNativeAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UIView;
@class UIImage;

@class GFPLoadResponseInfo;
@class GFPAdMetaData;
@class GFPMediaData;
@class GFPIconData;
@class GFPLabelOption;
@class GFPAdChoicesData;
@class GFPAdStyleOption;

@protocol GFPNativeAdDelegate;
@protocol GFPNativeSimpleAdDelegate;
@protocol GFPUserInterestDelegate;
@protocol GFPNativeAssetProtocol;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNativeAdProviderType) {
    GFPNativeAdProviderTypeFAN = 1 << 0,        // Facebook Audience Network
    GFPNativeAdProviderTypeDFP = 1 << 1,        // Google DFP
    // GFPNativeAdProviderTypeMoPub = 1 << 2,   // MoPub (deprecate)
    GFPNativeAdProviderTypeInMobi = 1 << 3,     // InMobi
    GFPNativeAdProviderTypeNDA = 1 << 4,        // Naver Native
//    GFPNativeAdProviderTypeAppLovin = 1 << 5, // AppLovin (deprecate)
    GFPNativeAdProviderTypeLAN = 1 << 6,
    GFPNativeAdProviderTypeBidMachine = 1 << 7,
    GFPNativeAdProviderTypeVungle = 1 << 8, // Vungle
};

typedef NS_OPTIONS(NSInteger, GFPAdStyleType) {
    GFPAdStyleUnknown = 1 << 0,
    GFPAdStyleFeedNative = 1 << 1,
    GFPAdStyleOutstreamVideo = 1 << 2,
    GFPAdStyleBannerNative = 1 << 3,
    GFPAdStyleBannerImage = 1 << 4,
    GFPAdStyleCompositeAds = 1 << 5,
    GFPAdStyleCarousel = 1 << 6
};

/**
 * extraInfo's key
 */
extern NSString *const kGFPNativeIconSizeKey;


@interface GFPNativeAdBase : NSObject

/**
 * 네이티브 응답의 광고 제공자 타입
 */
@property(readonly, nonatomic, assign) GFPNativeAdProviderType adProviderType;

/**
 * 광고 제공자 이름
 */
@property(readonly, nonatomic, strong) NSString *adProviderName;

/**
 * 광고 비주얼 키
 */
@property(readonly, nonatomic, strong, nullable) NSString *adVisualKey;

/**
 * 광고 유효성 여부
 */
@property(readonly, nonatomic, assign) BOOL isAdInvalidate;

/**
 * 광고 제공자의 네이티브 광고 객체
 *
 * - adProvider 가 GFPNativeAdProviderTypeFAN 인 경우,
 *   - GFPNativeAdRenderingSetting.hasMediaView == YES 이면, "FBNativeAd" 객체
 *   - GFPNativeAdRenderingSetting.hasMediaView == NO 이면, "FBNativeBannerAd" 객체
 * - adProvider 가 GFPNativeAdProviderTypeDFP 인 경우, "NativeAd" 객체
 * - adProvider 가 GFPNativeAdProviderTypeInMobi 인 경우, "IMNative" 객체
 * - adProvider 가 GFPNativeAdProviderTypeLAN 인 경우, "FADAdViewCustomLayout" 객체 혹은 "FADNative" 객체
 */
@property (readonly, nonatomic, strong) id adProviderNativeAd;

/**
 * AdStyle
 */
@property (readonly, nonatomic, assign) GFPAdStyleType adStyleType;

/**
 * 광고 응답 객체
 */
@property (readonly, nonatomic, strong) GFPLoadResponseInfo *responseInfo;


/**
 * 광고 배경 정보
 */
@property (nullable, readonly, nonatomic, strong) GFPAdStyleOption *adStyleOption;

@end


@interface GFPNativeAd : GFPNativeAdBase <GFPNativeAssetProtocol>

/**
 * 광고 응답 객체
 */
@property (readwrite, nonatomic, strong) GFPLoadResponseInfo *responseInfo;

/**
 * 광고 메타 데이터
 */
@property (readwrite, nonatomic, strong, nullable) GFPAdMetaData *adMetaData;

@property (readwrite, nonatomic, weak) id <GFPNativeAdDelegate> delegate;
@property (readwrite, nonatomic, weak) id <GFPUserInterestDelegate> userInterestDelegate;

@end


@interface GFPNativeSimpleAd : GFPNativeAdBase

/**
 * 광고 응답 객체
 */
@property (readwrite, nonatomic, strong) GFPLoadResponseInfo *responseInfo;

/**
 * 광고 메타 데이터
 */
@property (readwrite, nonatomic, strong, nullable) GFPAdMetaData *adMetaData;

@property (nonatomic, readonly, assign) BOOL isImageSizepreferred;

@property (readwrite, nonatomic, weak) id <GFPNativeSimpleAdDelegate> delegate;
@property (readonly, nonatomic, strong, nullable) id <GFPNativeAssetProtocol> assets;

- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;

/**
 * Shrink extended rich ads to default layout state.
 * Some rich ads may perform animations.
 */
- (void)shrinkExtendedRichAd;

@end


NS_ASSUME_NONNULL_END
