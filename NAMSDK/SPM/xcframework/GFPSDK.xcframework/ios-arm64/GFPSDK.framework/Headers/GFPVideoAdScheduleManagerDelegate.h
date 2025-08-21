//
//  GFPVideoAdScheduleManagerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class AVPlayerItemAccessLog;
@class GFPVideoAdScheduleManager;
@class GFPVideoAdBreakResult;
@class GFPVideoAdBreak;
@class GFPVideoAdQoeInfo;
@class GFPError;
@class GFPRemindAd;

NS_ASSUME_NONNULL_BEGIN


@protocol GFPVideoAdScheduleDelegate <NSObject>
@optional


/**
 * 광고 스케쥴이 성공적으로 로드가 완료된 경우 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didLoadedSchedule:(NSArray <GFPVideoAdBreak *> * _Nullable)aAdBreak;


/**
 * 광고 스케쥴 로드에 실패할 경우 호출됩니다. 스케쥴 매니저에서 start 를 호출하면 광고가 재생됩니다.
 * (컨텐츠 영상을 재생해 주세요.)
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aError 에러내용
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didFailScheduleWithError:(GFPError *)aError;


/**
 * 광고 스케쥴의 수행이 모두  완료된 경우 호출됩니다.
 * 컨텐츠 영상 종료 시점 (후광고가 있는 경우, 후광고 종료 시점)
 * @param aScheduleAdManager 스케쥴 매니저
 */
- (void)scheduleManagerDidCompleted:(GFPVideoAdScheduleManager *)aScheduleAdManager;


/**
 * 컨텐츠를 재생할 시점이 되었을 때 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
*/
- (void)scheduleManagerContentResumeRequest:(GFPVideoAdScheduleManager *)aScheduleAdManager;

/**
 * 컨텐츠를 정지할 시점이 되었을 때 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
*/
- (void)scheduleManagerContentPauseRequest:(GFPVideoAdScheduleManager *)aScheduleAdManager;


@end


@protocol GFPVideoAdScheduleManagerDelegate <GFPVideoAdScheduleDelegate>

@optional


/**
 * 광고 스케쥴 재생 종료시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didCompleteAd:(GFPVideoAdBreakResult *)aResult;


/**
 * 광고 재생 시작 가능 시  호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didStartReadyAd:(GFPVideoAdBreakResult *)aResult;



/**
 * 광고 재생 정지 시  호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didPauseAd:(GFPVideoAdBreakResult *)aResult;


/**
 * 광고 재생 재 시작 시  호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didResumeAd:(GFPVideoAdBreakResult *)aResult;


/**
 * 광고 재생 시작시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didStartAd:(GFPVideoAdBreakResult *)aResult;


/**
 * 각 광고가 성공적으로 로드될 경우 호출됩니다. 광고 매니저에서 startAd 를 호출하면 광고가 재생됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didLoadAd:(GFPVideoAdBreakResult *)aResult;

/**
 * 광고 로드, 재생에 실패한 경우 호출됩니다.
 * (컨텐츠 영상을 재생해 주세요.)
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 에러 결과
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didFailWithResult:(GFPVideoAdBreakResult *)aResult;

/**
 * 각 광고 클릭시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보*
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager wasClicked:(GFPVideoAdBreakResult *)aResult;

/**
 * 재생중인 광고플레이어가 AVPlayer 일 때(현재 NDA 한정), AVPlayerItem 에서 AccessLogEvent 가 발생한 경우 호출됩니다.
 @param aScheduleAdManager 스케쥴 매니저
 @param accessLogEvents AVPlayerItemAccessLogEvent 배열
  */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager
     didReceiveAccessLogEvents:(NSArray<AVPlayerItemAccessLogEvent *> *)accessLogEvents;


/**
 * 재생중인 광고플레이어가 AVPlayer 일 때(현재 NDA 한정), AVPlayerItem 에서 AccessLog 가 발생한 경우 호출됩니다.
 @param aScheduleAdManager 스케쥴 매니저
 @param accessLog AVPlayerItemAccessLog
  */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didReceiveAccessLog:(AVPlayerItemAccessLog *)accessLog;

/**
* 중간 광고의 경우 광고가 나가기 전 광고 재생 문구가 노출될 때 호출됩니다.
* 광고 Notice를 노출 후 재생 가능한 비디오 광고 StartReady가 호출됩니다.
@param aScheduleAdManager 스케쥴 매니저
@param aDuration 광고 Notice 노출 시간 (초).
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager showAdNotice:(NSInteger)aDuration;


/**
* Remind Text 광고가 있을 경우 호출됩니다.
@param aScheduleAdManager 스케쥴 매니저
@param aRemindAd 노출할 RemindAd
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didStartReadyRemindAd:(GFPRemindAd *)aRemindAd;


/**
* 광고 영상의 현재 진행률 변경 시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param mediaTime  비디오 광고 Play 시간
 * @param totalTime 비디오 광고 전체 시간
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didChangeCurrentTime:(NSTimeInterval)mediaTime totalTime:(NSTimeInterval)totalTime;

/**
 * 재생 컨트롤 Show 애니메이션 시작 시 호출됩니다.
 * @param duration Animation 타임
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager playControlWillShow:(NSTimeInterval)duration;

/**
 * 재생 컨트롤 Hide 애니메이션 시작 시 호출됩니다.
 * @param duration Animation 타임
*/
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager playControlWillHide:(NSTimeInterval)duration;

@end


@protocol GFPVideoAdScheduleManagerQoeDelegate <NSObject>
@optional
/**
 * 광고가 로드된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didLoadAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 시작 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didStartAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 일시중지 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didPauseAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고를 스킵 할 수 있을 때 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager canBeSkipAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 스킵 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didSkipAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 재시작 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didResumeAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고 재생이 종료 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didCompleteAdWitQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 클릭 된 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param info QOE 정보
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didReceiveAdClickEventWitQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고 관련 오류가 발생한 경우 발생
 * @param aScheduleAdManager 스케쥴 매니저
 * @param error 발생 에러 내용
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didReciveAdErrorForQoe:(GFPError *)error;


@end


@protocol GFPVideoAdScheduleManagerPIPDelegate <NSObject>
@optional

/**
 * PIP 영역 상단의 닫기 버튼 클릭 시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보*
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didTappedCloseBtnInPIP:(GFPVideoAdBreakResult *)aResult;

/**
 * PIP 영역 상단의 리턴 버튼 클릭 시 호출됩니다.
 * @param aScheduleAdManager 스케쥴 매니저
 * @param aResult 재생 광고 정보*
 */
- (void)scheduleManager:(GFPVideoAdScheduleManager *)aScheduleAdManager didTappedReturnBtnInPIP:(GFPVideoAdBreakResult *)aResult;

@end

NS_ASSUME_NONNULL_END
