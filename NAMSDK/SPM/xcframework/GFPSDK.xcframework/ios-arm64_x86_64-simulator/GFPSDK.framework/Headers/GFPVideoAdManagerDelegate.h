//
//  GFPVideoAdManagerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class AVPlayerItemAccessLog;
@class AVPlayerItemAccessLogEvent;
@class GFPVideoAdManager;
@class GFPError;
@class GFPLoadResponseInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPVideoAdManagerDelegate <NSObject>
@optional
/**
 * 광고가 성공적으로 로드될 경우 호출됩니다. 광고 매니저에서 startAd 를 호출하면 광고가 재생됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdManagerDidLoadAd:(GFPVideoAdManager *)videoAdManager;

/**
 * 광고 로드/재생에 실패한 경우 호출됩니다.
 * (본 영상을 재생해 주세요.)
 * @param videoAdManager 비디오 광고 매니저
 * @param error 에러내용
 * @param responseInfo 광고 응답 정보객체
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didFailWithError:(GFPError *)error responseInfo:(GFPLoadResponseInfo *)responseInfo;

/**
 * 광고 재생 시작시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdManagerDidStartAd:(GFPVideoAdManager *)videoAdManager;

/**
* 광고 재생 재 시작시 호출됩니다.
* @param videoAdManager 비디오 광고 매니저
*/
- (void)videoAdManagerDidResumeAd:(GFPVideoAdManager *)videoAdManager;


/**
 * 광고 재생 정지시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
*/
- (void)videoAdManagerDidPauseAd:(GFPVideoAdManager *)videoAdManager;


/**
 * 광고 재생 종료시 호출됩니다.
 * (본 영상을 재생해 주세요.)
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdManagerDidCompleteAd:(GFPVideoAdManager *)videoAdManager;

/**
 * 광고 클릭시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdWasClicked:(GFPVideoAdManager *)videoAdManager;

/**
 * 재생중인 광고플레이어가 AVPlayer 일 때(현재 NDA 한정), AVPlayerItem 에서 AccessLogEvent 가 발생한 경우 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 * @param accessLogEvents AVPlayerItemAccessLogEvent 배열
 */
 - (void)videoAdManager:(GFPVideoAdManager *)videoAdManager
didReceiveAccessLogEvents:(NSArray<AVPlayerItemAccessLogEvent *> *)accessLogEvents;


/**
 * 재생중인 광고플레이어가 AVPlayer 일 때(현재 NDA 한정), AVPlayerItem 에서 AccessLogEvent 가 발생한 경우 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 * @param accessLog AVPlayerItemAccessLog
 */
 - (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didReceiveAccessLog:(AVPlayerItemAccessLog *)accessLog;


/**
*  광고 중인 영상의  현재 progress가 변경될 떄마다 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 * @param mediaTime  비디오 광고 Play 시간
 * @param totalTime 비디오 광고 전체 시간
*/
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didChangeCurrentTime:(NSTimeInterval)mediaTime totalTime:(NSTimeInterval)totalTime;

/**
*  재생 컨트롤 Show 애니메이션 시작 시 호출됩니다.
 * @param duration Animation 타임
*/
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager playControlWillHide:(NSTimeInterval)duration;

/**
*  재생 컨트롤 Hide 애니메이션 시작 시 호출됩니다.
 * @param duration Animation 타임
*/
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager playControlWillShow:(NSTimeInterval)duration;

/**
 * Default In App Browser 사용 시, SFSafariViewController가 정상적으로 Present 시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdManagerDidPresentDefaultInAppBrowser:(GFPVideoAdManager *)videoAdManager;

/**
 * Default In App Browser 사용 시, SFSafariViewController가 정상적으로 Dismiss 시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdManagerDidDismissDefaultInAppBrowser:(GFPVideoAdManager *)videoAdManager;


@end

NS_ASSUME_NONNULL_END
