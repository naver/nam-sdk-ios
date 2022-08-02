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

@protocol GFPNativeAdDelegate;
@protocol GFPNativeSimpleAdDelegate;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNativeAdProviderType) {
    GFPNativeAdProviderTypeFAN = 1 << 0,     // Facebook Audience Network
    GFPNativeAdProviderTypeDFP = 1 << 1,     // Google DFP
    GFPNativeAdProviderTypeMoPub = 1 << 2,   // MoPub
    GFPNativeAdProviderTypeInMobi = 1 << 3,  // InMobi
    GFPNativeAdProviderTypeNDA = 1 << 4      // Naver Native
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
 * 광고 유효성 여부
 */
@property(readonly, nonatomic, assign) BOOL isAdInvalidate;

/**
 * 광고 제공자의 네이티브 광고 객체
 *
 * - adProvider 가 GFPNativeAdProviderFAN 인 경우,
 *   - GFPNativeAdRenderingSetting.hasMediaView == YES 이면, "FBNativeAd" 객체
 *   - GFPNativeAdRenderingSetting.hasMediaView == NO 이면, "FBNativeBannerAd" 객체
 * - adProvider 가 GFPNativeAdProviderDFP 인 경우, "GADNativeAd" 객체
 * - adProvider 가 GFPNativeAdProviderTypeMoPub 인 경우, "MPNativeAd" 객체
 * - adProvider 가 GFPNativeAdProviderTypeInMobi 인 경우, "IMNative" 객체
 */
@property(readonly, nonatomic, strong) id adProviderNativeAd;


/**
 * AdStyle
 */
@property (readonly, nonatomic, assign) GFPAdStyleType adStyleType;

/**
 * 광고 응답 객체
 */
@property (readonly, nonatomic, strong) GFPLoadResponseInfo *responseInfo;

@end


@interface GFPNativeAd : GFPNativeAdBase

@property(readwrite, nonatomic, weak) id <GFPNativeAdDelegate> delegate;

/**
 * 타이틀
 */
@property (readonly, nonatomic, strong) NSString *title;

/**
 * 본문
 */
@property (nullable, readonly, nonatomic, strong) NSString *body;

/**
 * 광고주 명
 */
@property (nullable, readonly, nonatomic, strong) NSString *advertiser;

/**
 * Social Context
 */
@property (nullable, readonly, nonatomic, strong) NSString *socialContext;

/**
 * 클릭 버튼 텍스트
 */
@property (nullable, readonly, nonatomic, strong) NSString *callToAction;

/**
 * Icon Image 존재 여부
 */
@property (readonly, nonatomic, assign) BOOL hasIconImage;

/**
 * Ad Badge
 */
@property (nullable, readonly, nonatomic, strong) NSString *badge;


@end


@interface GFPNativeSimpleAd : GFPNativeAdBase

@property(readwrite, nonatomic, weak) id <GFPNativeSimpleAdDelegate> delegate;

/**
 * Image 객체
*/
@property (readonly, nonatomic, strong, nonnull) UIImage *image;


- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;

@end


NS_ASSUME_NONNULL_END
