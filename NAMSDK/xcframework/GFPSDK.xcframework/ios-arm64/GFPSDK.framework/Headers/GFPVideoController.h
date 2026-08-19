//
//  GFPVideoController.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

#import "GFPVideoEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPVideoController;
@class AVPlayer;

@interface GFPVideoProgressInfo : NSObject

@property (nonatomic, assign, readonly) NSTimeInterval duration;

@property (nonatomic, assign, readonly) NSTimeInterval currentTime;
@property (nonatomic, assign, readonly) NSTimeInterval bufferedTime;

@end


@interface GFPVideoController : NSObject

@property (nonatomic, weak) id <GFPVideoEventDelegate> delegate;

@property (nonatomic, strong, readonly) GFPVideoProgressInfo *progressInfo;
@property (nonatomic, assign, readonly) CGFloat aspectRatio;

@property (nonatomic, assign, readonly) BOOL enableControl;

@property (nonatomic, assign, readonly) BOOL isPlaying;

/**
 * 광고 영상 재생에 사용되는 AVPlayer 객체입니다. (관찰용)
 *
 * 재생 상태 관찰(time observer 등록 등) 용도로만 사용해주세요.
 * 재생 제어(play/pause/mute)는 반드시 GFPVideoController의 API를 사용해야 하며,
 * AVPlayer를 직접 제어할 경우 광고 이벤트 집계가 정상 동작하지 않을 수 있습니다.
 * AVPlayer 기반이 아닌 광고에서는 nil이 반환됩니다.
 */
@property (nonatomic, weak, readonly, nullable) AVPlayer *avPlayer;

/**
 * 광고 영상의 mute 여부를 설정합니다.
 */
@property (nonatomic, assign, getter=isMuted) BOOL mute;

- (void)updateMuteWith:(BOOL)isMuted isUser:(BOOL)isUser;

/**
 * 광고 영상의 forwardBufferDuration을 설정합니다.
 * cf. https://developer.apple.com/documentation/avfoundation/avplayeritem/1643630-preferredforwardbufferduration
 */
@property (nonatomic, assign) NSTimeInterval preferredForwardBufferDuration;

/**
 * 광고 영상 재생
 * - isUser user에 의해 재생되었을 경우 YES (=컴포넌트 터치), 아닐 경우 NO를 전달.
 */
- (void)play;
- (void)playWith:(BOOL)isUser;

/**
 * 광고 영상 일시 정지
 * - isUser user에 의해 정지되었을 경우 YES (=컴포넌트 터치), 아닐 경우 NO를 전달.
 */
- (void)pause;
- (void)pauseWith:(BOOL)isUser;

/**
 * 광고 영상을 중지하고 영상의 첫 프레임으로 이동합니다.
 * 영상을 다시 재생 하려면 play를 호출해주세요.
 */
- (void)stop;

/**
 * 광고 영상을 해당 progress만큼 seeking합니다.
 */
- (void)seek:(float)progress;


@end

NS_ASSUME_NONNULL_END
