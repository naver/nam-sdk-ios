//
//  GFPAdLoaderDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

@class GFPError;
@class GFPNativeAd;
@class GFPNativeSimpleAd;
@class GFPAdLoader;
@class GFPBannerView;
@class GFPLoadResponseInfo;

@protocol GFPAdLoaderDelegate <NSObject>

@optional
/**
 * 광고가 성공적으로 로드될 경우 호출됩니다. - Native
 * @param unifiedAdLoader 통합 광고 로더
 * @param nativeAd 네이티브 광고 객체
 */
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didReceiveNativeAd:(GFPNativeAd *)nativeAd;

/**
 * 광고가 성공적으로 로드될 경우 호출됩니다. - NativeSimple
 * @param unifiedAdLoader 통합 광고 로더
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didReceiveNativeSimpleAd:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * 광고가 성공적으로 로드될 경우 호출됩니다. - Banner
 * @param unifiedAdLoader 통합 광고 로더
 * @param bannerView 배너 광고 뷰
 */
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didReceiveBannerAd:(GFPBannerView *)bannerView;

/**
 * 광고 로드에 실패한 경우 호출됩니다.
 * @param unifiedAdLoader 통합 광고 로더
 * @param error 에러내용
 * @param responseInfo 광고 응답 정보객체
 */
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didFailWithError:(GFPError *)error responseInfo:(GFPLoadResponseInfo *)responseInfo;

@end

