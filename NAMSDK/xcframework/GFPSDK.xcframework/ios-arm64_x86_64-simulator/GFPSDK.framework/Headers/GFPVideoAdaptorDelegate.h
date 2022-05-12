//
//  GFPVideoAdaptorDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GFPVideoAdapting;

@class GFPAdAdaptor;
@class GFPError;


@protocol GFPVideoAdaptorDelegate <NSObject>

@required

- (void)videoAdWasStarted:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdWasClicked:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdWasCompleted:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor didFailWithError:(GFPError *)error;

- (void)videoAdWasSkipped:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdWasPaused:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdWasResumed:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;


@optional

- (void)videoAdAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor
didReceiveAccessLogEvents:(NSArray<AVPlayerItemAccessLogEvent *> *)accessLogEvents;

- (void)videoAdAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor didReceiveAccessLog:(AVPlayerItemAccessLog *)accessLog;

- (void)videoAdAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor didChangeCurrentTime:(NSTimeInterval)mediaTime totalTime:(NSTimeInterval)totalTime;

- (void)videoAdCanBeSkipped:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdCloseBtnTappedInPIP:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdReturnBtnTappedInPIP:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor;

- (void)videoAdAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor playControlWillShow:(NSTimeInterval)duration;

- (void)videoAdAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)videoAdaptor playControlWillHide:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
