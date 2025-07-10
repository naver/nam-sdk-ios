//
//  GFPBannerViewDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


@class GFPBannerView;
@class GFPError;
@class GFPNativeAd;
@class GFPBannerAdSize;
@class GFPLoadResponseInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPBannerViewDelegate <NSObject>
@optional

@optional
/**
 * 배너 광고가 정상적으로 로드된 경우 호출됩니다.
 * @param bannerView 로드를 요청한 GFPBannerView 객체
 */
- (void)bannerViewDidReceiveAd:(GFPBannerView *)bannerView;

/**
 * GFPBannerView 의 네이티브 광고 로드가 허용(nativeAdEnabled = YES)되어 있을 때, 네이티브 광고가 정상적으로 로드되면 호출됩니다.
 * @param bannerView 로드를 요청한 GFPBannerView 객체
 * @param nativeAd 네이티브 광고 응답
 */
- (void)bannerView:(GFPBannerView *)bannerView didLoadNativeAd:(GFPNativeAd *)nativeAd;

/**
 * 광고 로드 및 렌더링에 실패한 경우 호출됩니다.
 * @param bannerView GFPBannerView
 * @param error GFPError
 */
- (void)bannerView:(GFPBannerView *)bannerView didFailToReceiveAdWithError:(GFPError *)error;

/**
 * 배너 광고가 렌더링 될 때 호출됩니다. (rendered impression)
 * @param bannerView GFPBannerView
 */
- (void)bannerAdWasRendered:(GFPBannerView *)bannerView;

/**
 * 배너 광고가 사용자에게 보여진 경우 호출됩니다.(viewable impression)
 * @param bannerView GFPBannerView
 */
- (void)bannerAdWasSeen:(GFPBannerView *)bannerView;

/**
 * 배너 광고 클릭 시 호출됩니다.
 * @param bannerView GFPBannerView
 */
- (void)bannerAdWasClicked:(GFPBannerView *)bannerView;

/**
 * 배너 사이즈 변경 시 호출됩니다.
 * @param bannerView GFPBannerView
 * @param size GFPBannerAdSize
 */
- (void)bannerView:(GFPBannerView *)bannerView didChangeWith:(GFPBannerAdSize *)size;

/**
 * 배너 광고 소재에서 MetaData 변경 시 호출됩니다.
 * @param bannerView GFPBannerView
 * @param adMeta NSDictionary
 */
- (void)bannerView:(GFPBannerView *)bannerView didChangeAdMeta:(NSDictionary <NSString *, NSString *>*)adMeta;

/**
 * 배너 뷰가 Mraid 3.0 스펙의 Unload로 인해 뷰가 제거되기 전에 호출됩니다.
 * @param bannerView GFPBannerView
 */
- (void)bannerShouldUnload:(GFPBannerView *)bannerView;

/**
 * 배너 광고 뮤트 시 호출됩니다.
 * @param bannerView GFPBannerView
 */
- (void)bannerAdWasMuted:(GFPBannerView *)bannerView;


/**
 * Default In App Browser 사용 시, 클릭이 이루어져서 SFSafariViewController가 정상적으로 Present 시 호출됩니다.
 * @param bannerView GFPBannerView
 */
- (void)bannerAdDidPresentDefaultInAppBrowser:(GFPBannerView *)bannerView;

/**
 * Default In App Browser 사용 시, 클릭이 이루어져서 SFSafariViewController가 정상적으로 Dismiss 시 호출됩니다.
 * @param bannerView GFPBannerView
 */
- (void)bannerAdDidDismissDefaultInAppBrowser:(GFPBannerView *)bannerView;

@end

NS_ASSUME_NONNULL_END

