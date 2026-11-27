//
//  GFPNativeAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "Swift-Enum.h"

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
    GFPNativeAdProviderTypePangle = 1 << 9,
    GFPNativeAdProviderTypeTeads = 1 << 10,  // Teads
    GFPNativeAdProviderTypeMoloco = 1 << 11,
    GFPNativeAdProviderTypeDT = 1 << 12     // Digital Turbine
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
extern NSString *const kGFPNaverAppLogoInfoKey;
extern NSString *const kGFPMediaViewType;

typedef NS_OPTIONS(NSInteger, GFPExternalMediaViewType) {
    GFPExternalMediaViewTypeDoubleCrown = 108,
    GFPExternalMediaViewTypeTripleCrown = 110
};

typedef NS_ENUM(NSInteger, GFPNativeAdMediaLoadingState) {
    GFPNativeAdMediaLoadingStateNotAvailable = 0,
    GFPNativeAdMediaLoadingStateLoading,
    GFPNativeAdMediaLoadingStateLoaded,
    GFPNativeAdMediaLoadingStateFailed,
};

typedef NS_ENUM(NSInteger, GFPNativeAdMediaAssetType) {
    GFPNativeAdMediaAssetTypeIcon = 0,
    GFPNativeAdMediaAssetTypeMedia,
};

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

@property (readonly, nonatomic, strong) NSUUID *logId;

/**
 * 광고 배경 정보
 */
@property (nullable, readonly, nonatomic, strong) GFPAdStyleOption *adStyleOption;

/**
 * Icon asset loading state.
 *
 * If the ad has no icon asset, or the provider does not expose per-asset loading state,
 * the value is GFPNativeAdMediaLoadingStateNotAvailable.
 */
@property (readonly, nonatomic, assign) GFPNativeAdMediaLoadingState iconLoadingState;

/**
 * Main media asset loading state.
 *
 * If the ad has no media asset, or the provider does not expose per-asset loading state,
 * the value is GFPNativeAdMediaLoadingStateNotAvailable.
 */
@property (readonly, nonatomic, assign) GFPNativeAdMediaLoadingState mediaLoadingState;

- (void)updateInterfaceStyle:(GFPAdInterfaceStyle)interfaceStyle NS_SWIFT_NAME(updateInterfaceStyle(_:));

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

/**
 * 캐러셀 1+N형(복합형) 광고의 메인 미디어 귀퉁이를 런타임에 변경합니다.
 * 호출한 광고에만 적용되며, 렌더링 세팅(GFPNativeAdRenderingSetting)의 값은 바꾸지 않습니다.
 * 1+N형이 아닌 광고에서는 동작하지 않습니다.
 *
 * @param cornerRadius 네 귀퉁이에 공통으로 적용할 반경. nil 이면 SDK 기본 반경 16, 0 이면 직각입니다.
 * @param roundedCorners 둥글게 처리할 귀퉁이. 선택하지 않은 귀퉁이는 직각으로 그려집니다.
 */
- (void)updateComplexMediaCornerRadius:(nullable NSNumber *)cornerRadius
                        roundedCorners:(UIRectCorner)roundedCorners NS_SWIFT_NAME(updateComplexMediaCorner(radius:roundedCorners:));

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
- (void)shrinkExtendedRichAd __attribute__((deprecated("It will be removed in a future version.")));

@end


NS_ASSUME_NONNULL_END
