//
//  GFPDisplayLinkHelper.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GFPDisplayLinkOptions) {
    GFPDisplayLinkOptionNone = 0,
    GFPDisplayLinkOptionAutoReverse = 1 << 0,
    GFPDisplayLinkOptionRepeat = 1 << 1,
  
};

typedef void(^GFPDisplayLinkStartBlock)(void);
typedef void(^GFPDisplayLinkCompletionBlock)(void);
typedef void(^GFPDisplayLinkTickBlock)(CGFloat);
typedef void(^GFPDisplayLinkRepeatBlock)(void);
typedef void(^GFPDisplayLinkRepeatCompletionBlock)(void);
typedef CGFloat(^GFPDisplayLinkProgressBlock)(CFTimeInterval);

@interface GFPDisplayLinkHelper : NSObject

@property (nonatomic, strong, readonly) CADisplayLink *displayLink;

/// 첫 사이클의 진행 시작 지점(0~1). 기본 0. fire 시 startTime에 한 번만 반영된다.
/// 예) 0.5 → 첫 사이클은 0.5에서 시작해 1.0까지 진행하고, 이후 Repeat 사이클은 0→1로 정상 동작.
/// (초기 위상 지정용. fire 이전에 설정해야 적용됨)
@property (nonatomic, assign) CGFloat startProgress;

/// Repeat 사이클 사이에 넣을 대기 시간(초). 기본 0. (AutoReverse면 정·역 한 세트가 끝난 뒤 적용)
/// 대기 구간 동안에는 tick이 호출되지 않아 마지막 프레임 상태가 유지된다.
@property (nonatomic, assign) CFTimeInterval repeatDelay;

@property (nonatomic, copy, nullable) GFPDisplayLinkStartBlock start;
@property (nonatomic, copy, nullable) GFPDisplayLinkTickBlock tick;
@property (nonatomic, copy, nullable) GFPDisplayLinkCompletionBlock completion;
@property (nonatomic, copy, nullable) GFPDisplayLinkProgressBlock progress;
@property (nonatomic, copy, nullable) GFPDisplayLinkRepeatBlock repeat;

/// Repeat 모드에서 한 사이클이 끝날 때마다(다음 사이클 시작 직전) 호출된다. 비-Repeat이면 호출 안 됨.
/// (legacy `repeat` 블록과 달리 실제로 호출되는 사이클 완료 콜백)
@property (nonatomic, copy, nullable) GFPDisplayLinkRepeatCompletionBlock repeatCompletion;

- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                    tick:(GFPDisplayLinkTickBlock)tick
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;

/// tick + start + repeatCompletion 을 함께 받는 초기화.
/// start: 매 사이클 시작마다 호출(Repeat이면 사이클마다, 비-Repeat이면 1회).
/// repeatCompletion: Repeat 사이클이 끝날 때마다 호출(비-Repeat이면 호출 안 됨).
/// completion: 전체 종료 시 1회(Repeat이면 호출되지 않음).
- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                   start:(nullable GFPDisplayLinkStartBlock)start
                    tick:(GFPDisplayLinkTickBlock)tick
        repeatCompletion:(nullable GFPDisplayLinkRepeatCompletionBlock)repeatCompletion
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;

- (instancetype)initWith:(CFTimeInterval)duration
         reverseDuration:(CFTimeInterval)reverseDuration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                    tick:(GFPDisplayLinkTickBlock)tick
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;

- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                    tick:(GFPDisplayLinkTickBlock)tick
                  repeat:(nonnull GFPDisplayLinkRepeatBlock)repeat
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;

- (instancetype)initWith:(CFTimeInterval)duration
         reverseDuration:(CFTimeInterval)reverseDuration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                    tick:(GFPDisplayLinkTickBlock)tick
                  repeat:(nonnull GFPDisplayLinkRepeatBlock)repeat
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;


- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
           controlPoint1:(CGPoint)pt1
           controlPoint2:(CGPoint)pt2
                   start:(GFPDisplayLinkStartBlock)start
                    tick:(GFPDisplayLinkTickBlock)tick
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;


- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
           controlPoint1:(CGPoint)pt1
           controlPoint2:(CGPoint)pt2
                    tick:(GFPDisplayLinkTickBlock)tick
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;


- (instancetype)initWith:(CFTimeInterval)duration
         reverseDuration:(CFTimeInterval)reverseDuration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
           controlPoint1:(CGPoint)pt1
           controlPoint2:(CGPoint)pt2
                    tick:(GFPDisplayLinkTickBlock)tick
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;

- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
           controlPoint1:(CGPoint)pt1
           controlPoint2:(CGPoint)pt2
                    tick:(GFPDisplayLinkTickBlock)tick
                  repeat:(nonnull GFPDisplayLinkRepeatBlock)repeat
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;


- (instancetype)initWith:(CFTimeInterval)duration
         reverseDuration:(CFTimeInterval)reverseDuration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
           controlPoint1:(CGPoint)pt1
           controlPoint2:(CGPoint)pt2
                    tick:(GFPDisplayLinkTickBlock)tick
                  repeat:(nonnull GFPDisplayLinkRepeatBlock)repeat
              completion:(nullable GFPDisplayLinkCompletionBlock)completion;


- (void)fire;
- (void)invalidate;
- (BOOL)isComplete;

- (void)resume;
- (void)pause;
- (void)finish;

@end

NS_ASSUME_NONNULL_END
