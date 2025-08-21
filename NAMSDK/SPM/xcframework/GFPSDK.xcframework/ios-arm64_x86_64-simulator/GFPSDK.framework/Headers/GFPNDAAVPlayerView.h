//
//  GFPNDAAVPlayerView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
@protocol GFPNDAAVPlayerDelegate;

@class AVPlayer;

NS_ASSUME_NONNULL_BEGIN


@interface GFPNDAAVPlayerView : UIView

@property (nonatomic, weak) id<GFPNDAAVPlayerDelegate> delegate;

@property (nonatomic, strong, nullable) AVPlayer *player;
@property (nonatomic, readonly, assign) CGSize playerSize;

- (void)setVideoGravity:(AVLayerVideoGravity)gravity;

@end

NS_ASSUME_NONNULL_END
