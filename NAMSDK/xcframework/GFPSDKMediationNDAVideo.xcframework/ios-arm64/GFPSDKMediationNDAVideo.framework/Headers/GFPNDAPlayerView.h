//
//  GFPNDAPlayerView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPNDAPlayerDelegate.h"
#import "Swift-Enum.h"


@class GFPNDAVastMediaFile;
@class GFPVideoAdQoePlayerInfo;
@class GFPError;
@class GFPLoudnessNormalization;
@class AVPlayer;
@class AVPlayerItemAccessLog;
@class AVPlayerItem;
@class GFPNDAAVPlayerView;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAPlayerView : UIView

@property (nonatomic, weak) id <GFPNDAPlayerViewDelegate> delegate;
@property (readonly, atomic, assign) GFPNDAPlayerStatus playerStatus;

@property (nonatomic, readonly, strong) GFPVideoAdQoePlayerInfo *playerInfo;

@property (nonatomic, readonly, assign) BOOL playerIsPlaying;
@property (nonatomic, readonly, assign) CGSize playerSize;

@property (nonatomic, assign) float volume;
@property (nonatomic, assign) GFPVideoAudioSettingType audioSetting; // Start 시점 전에만 결정.

//for native extension
@property (nonatomic, strong, nullable) AVPlayer *player;
@property (atomic, strong, nullable) AVPlayerItem *playerItem;
@property (nonatomic, strong, nullable) GFPNDAAVPlayerView *playerLayerView;


- (instancetype)initWithFrame:(CGRect)frame mediaURL:(nonnull NSURL *)aURL loudness:(GFPLoudnessNormalization * _Nullable)aLoudness;

- (void)start;
- (void)pause;
- (void)resume;

- (void)removePlayer;
- (void)restorePlayer;

- (void)updateExternalPlayBackWith:(BOOL)disableExternalPlayBack;
- (void)updateForwardBufferDuration:(NSTimeInterval)forwardBufferDuration;

//for native extension
- (void)changePlayerStatus:(GFPNDAPlayerStatus)playerStatus;
- (void)notifyStatusWith:(GFPNDAPlayerStatus)playerStatus;
- (void)unregisterNotification;
- (void)requestToPauseBeforeLoadWith:(BOOL)isEnable;

@end


NS_ASSUME_NONNULL_END
