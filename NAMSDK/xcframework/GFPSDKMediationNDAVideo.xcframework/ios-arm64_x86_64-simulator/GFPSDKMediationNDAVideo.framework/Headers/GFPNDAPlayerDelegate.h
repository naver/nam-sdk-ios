//
//  GFPNDAPlayerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class AVPlayerItemAccessLog;

@class GFPNDAAVPlayerView;
@class GFPNDAPlayerView;
@class GFPError;

typedef NS_ENUM(NSInteger, GFPNDAPlayerStatus) {
    GFPNDAPlayerStatusNotLoaded = 0,
    GFPNDAPlayerStatusLoaded,
    GFPNDAPlayerStatusStarted,
    GFPNDAPlayerStatusPaused,
    GFPNDAPlayerStatusResumed,
    GFPNDAPlayerStatusCompleted,
    GFPNDAPlayerStatusReadyToReplay,
    GFPNDAPlayerStatusError
};


NS_ASSUME_NONNULL_BEGIN


@protocol GFPNDAAVPlayerDelegate <NSObject>

- (void)avPlayerView:(GFPNDAAVPlayerView *)avPlayerView didChangeSize:(CGSize)size;

@end


@protocol GFPNDAPlayerViewDelegate <GFPNDAAVPlayerDelegate>

- (void)playerView:(GFPNDAPlayerView *)playerView didChangePlayerStatus:(GFPNDAPlayerStatus)playerStatus;

- (void)playerView:(GFPNDAPlayerView *)playerView didChangeCurrentTime:(double)currentTime withDuration:(double)duration;

- (void)playerView:(GFPNDAPlayerView *)playerView didReceiveError:(GFPError *)error;

- (void)playerView:(GFPNDAPlayerView *)playerView didReceiveAccessLog:(AVPlayerItemAccessLog *)accessLog;

- (void)playerViewAdPlaybackReady:(GFPNDAPlayerView *)playerView;

- (void)playerViewDidStartBuffering:(GFPNDAPlayerView *)playerView;


- (void)playerWillPlay:(GFPNDAPlayerView *)playerView isMuted:(BOOL)isMuted;

- (void)playerDidPlay:(GFPNDAPlayerView *)playerView isMuted:(BOOL)isMuted;

- (void)playerWillPause:(GFPNDAPlayerView *)playerView isMuted:(BOOL)isMuted;

- (void)playerDidPause:(GFPNDAPlayerView *)playerView isMuted:(BOOL)isMuted;

- (void)playerMuteChanged:(GFPNDAPlayerView *)playerView isMuted:(BOOL)isMuted;

@optional
- (void)playerLoadRangeChanged:(GFPNDAPlayerView *)playerView loadedTime:(NSTimeInterval)loadedTime;

@end

NS_ASSUME_NONNULL_END
