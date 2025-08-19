//
//  GFPVideoAdQoeDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPVideoAdManager;
@class GFPVideoAdQoeInfo;
@class GFPError;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPVideoAdQoeDelegate <NSObject>
@optional
/**
 * 광고가 로드된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didLoadAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 시작 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didStartAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 일시중지 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didPauseAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고를 스킵 할 수 있을 때 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager canBeSkipAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 스킵 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didSkipAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 재시작 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didResumeAdWithQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고 재생이 종료 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didCompleteAdWitQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고가 클릭 된 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param info QOE 정보
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didReceiveAdClickEventWitQoeInfo:(GFPVideoAdQoeInfo *)info;

/**
 * 광고 관련 오류가 발생한 경우 발생
 * @param videoAdManager 비디오 매니저
 * @param error 발생 에러 내용
 */
- (void)videoAdManager:(GFPVideoAdManager *)videoAdManager didReciveAdErrorForQoe:(GFPError *)error;

@end

NS_ASSUME_NONNULL_END
