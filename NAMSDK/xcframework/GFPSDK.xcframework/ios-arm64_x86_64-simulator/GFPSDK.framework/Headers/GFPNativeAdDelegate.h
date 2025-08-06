//
//  GFPNativeAdDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPNativeAdBase;
@class GFPNativeAd;
@class GFPNativeSimpleAd;
@class GFPError;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeAdDelegate <NSObject>
@optional

/**
 * 광고가 렌더링 될 때 호출됩니다. (rendered impression)
 * @param nativeAd 네이티브 광고 응답객체
 */
- (void)nativeAdWasRendered:(GFPNativeAd *)nativeAd;

/**
 * 광고가 사용자에게 보여진 경우 호출됩니다. (viewable impression)
 * @param nativeAd   네이티브 광고 응답객체
 */
- (void)nativeAdWasSeen:(GFPNativeAd *)nativeAd;

/**
 * 광고 클릭 시 호출됩니다.
 * @param nativeAd   네이티브 광고 응답객체
 */
- (void)nativeAdWasClicked:(GFPNativeAd *)nativeAd;

/**
 * 에러 발생 시 호출됩니다.
 * @param nativeAd  네이티브 광고 객체
 * @param error     에러객체
 */
- (void)nativeAd:(GFPNativeAd *)nativeAd didFailWithError:(GFPError *)error;

/**
 * 광고 뮤트 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdWasMuted:(GFPNativeAd *)nativeAd;

/**
 * 광고 뮤트 취소 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdWasCanceledMute:(GFPNativeAd *)nativeAd;

/**
 * 리소스 재로드가 필요할 때 리소스 재 로드 성공 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdDidReloaded:(GFPNativeAd *)nativeAd;

/**
 * 리소스 재로드가 필요할 때 리소스 재 로드 실패 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 * @param error     에러객체
 */
- (void)nativeAd:(GFPNativeAd *)nativeAd didReloadFailWithError:(GFPError *)error;

/**
 * Default In App Browser 사용 시, SFSafariViewController가 정상적으로 Present 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdDidPresentDefaultInAppBrowser:(GFPNativeAd *)nativeAd;

/**
 * Default In App Browser 사용 시, SFSafariViewController가 정상적으로 Dismiss 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdDidDismissDefaultInAppBrowser:(GFPNativeAd *)nativeAd;


/**
 * LazyLoading 사용 시, 실 사용되는 MediaData로드가 완료되었을 때 호출 ( 이미지 로드 시점과 동일 )
 * @param nativeAd 네이티브 광고 객체
 */
- (void)nativeAdDidLoadMediaData:(GFPNativeAd *)nativeAd;
@end

@protocol GFPNativeSimpleAdDelegate <NSObject>
@optional

/**
 * 광고가 렌더링 될 때 호출됩니다. (rendered impression)
 * @param nativeSimpleAd   네이티브 광고 응답객체
 */
- (void)nativeSimpleAdWasRendered:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * 광고가 사용자에게 보여진 경우 호출됩니다.
 * @param nativeSimpleAd   네이티브 광고 응답객체
 */
- (void)nativeSimpleAdWasSeen:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * 광고 클릭 시 호출됩니다.
 * @param nativeSimpleAd   네이티브 광고 응답객체
 */
- (void)nativeSimpleAdWasClicked:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * 에러 발생 시 호출됩니다.
 * @param nativeSimpleAd  네이티브 광고 객체
 * @param error     에러객체
 */
- (void)nativeSimpleAd:(GFPNativeSimpleAd *)nativeSimpleAd didFailWithError:(GFPError *)error;

/**
 * 광고 뮤트 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleAdWasMuted:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * 광고 뮤트 취소 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleAdWasCanceledMute:(GFPNativeSimpleAd *)nativeSimpleAd;


/**
 * 미디어뷰 사이즈 변경 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 * @param size 변경된 사이즈
 */
- (void)nativeSimpleAd:(GFPNativeSimpleAd *)nativeSimpleAd didChangeMediaViewSizeWith:(CGSize)size;

/**
 * Rich  Extend 광고에서 미디어뷰 사이즈 변경 시마다 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 * @param size 변경된 사이즈
 */
- (void)nativeSimpleAd:(GFPNativeSimpleAd *)nativeSimpleAd didChangeRichAdSizeWith:(CGSize)size;

/**
 * Rich  Extend 광고에서 미디어뷰 사이즈 확장 완료 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleRichAdExtendComplete:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * Rich  Extend 광고에서 미디어뷰 사이즈 확장 시작 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 * @param size 확장될 최종 크기
 */
- (void)nativeSimpleRichAdExtendStart:(GFPNativeSimpleAd *)nativeSimpleAd toSize:(CGSize)size;

/**
 * Rich  Extend 광고에서 미디어뷰 사이즈 축소 완료 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleRichAdShrinkComplete:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * Rich  Extend 광고에서 미디어뷰 사이즈 축소 시작 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 * @param size 축소될 최종 크기
 */
- (void)nativeSimpleRichAdShrinkStart:(GFPNativeSimpleAd *)nativeSimpleAd toSize:(CGSize)size;

/**
 * Default In App Browser 사용 시, 클릭이 이루어져서 SFSafariViewController가 정상적으로 Present 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleAdDidPresentDefaultInAppBrowser:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * Default In App Browser 사용 시, 클릭이 이루어져서 SFSafariViewController가 정상적으로 Dismiss 시 호출됩니다.
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleAdDidDismissDefaultInAppBrowser:(GFPNativeSimpleAd *)nativeSimpleAd;

/**
 * LazyLoading 사용 시, 실제 기존 로딩과 같은 타이밍 알림
 * @param nativeSimpleAd 네이티브 광고 객체
 */
- (void)nativeSimpleAdDidLoadMedia:(GFPNativeSimpleAd *)nativeSimpleAd;

@end

@protocol GFPNativeVideoEventDelegate <NSObject>

@optional

/**
 * Rich광고 비디오 재생 시 호출됩니다. player start 직전에 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 * @param isMuted 현재 비디오 Mute여부
 */
- (void)nativeAd:(NSObject *)nativeAd richVideoWillPlayWith:(BOOL)isMuted;

/**
 * Rich광고 비디오 재생 시 호출됩니다. player start 후 스테이터스 변경 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 * @param isMuted 현재 비디오 Mute여부
 */

- (void)nativeAd:(NSObject *)nativeAd richVideoDidPlayWith:(BOOL)isMuted;

/**
 * Rich광고 비디오 정지 시 호출됩니다. player pause 직전에 호출됩니다.
 * 재생 중 메모리 해제 시에는 호출되지 않습니다.
 * @param nativeAd 네이티브 광고 객체
 * @param isMuted 현재 비디오 Mute여부
 */
- (void)nativeAd:(NSObject *)nativeAd richVideoWillStopWith:(BOOL)isMuted;

/**
 * Rich광고 비디오 정지 시 호출됩니다. player pause 후 스테이터스 변경 시, 메모리 해제 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 * @param isMuted 현재 비디오 Mute여부
 */
- (void)nativeAd:(NSObject *)nativeAd richVideoDidStopWith:(BOOL)isMuted;

/**
 * Rich광고 비디오 플레이어에 mute 셋팅 시 호출됩니다.
 * @param nativeAd 네이티브 광고 객체
 * @param isMuted Mute 여부 상태
 */
- (void)nativeAd:(NSObject *)nativeAd richVideoMuteChanged:(BOOL)isMuted;

@end


NS_ASSUME_NONNULL_END
