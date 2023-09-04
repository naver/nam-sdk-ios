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

/**
 * 광고 영상의 mute 여부를 설정합니다.
 */
@property (nonatomic, assign, getter=isMuted) BOOL mute;

/**
 * 광고 영상의 forwardBufferDuration을 설정합니다.
 * cf. https://developer.apple.com/documentation/avfoundation/avplayeritem/1643630-preferredforwardbufferduration
 */
@property (nonatomic, assign) NSTimeInterval preferredForwardBufferDuration;

- (void)play;
- (void)pause;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
