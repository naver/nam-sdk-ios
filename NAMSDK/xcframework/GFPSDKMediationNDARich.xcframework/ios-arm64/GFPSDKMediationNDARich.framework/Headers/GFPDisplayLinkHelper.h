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
typedef CGFloat(^GFPDisplayLinkProgressBlock)(CFTimeInterval);

@interface GFPDisplayLinkHelper : NSObject

@property (nonatomic, strong, readonly) CADisplayLink *displayLink;
@property (nonatomic, copy, nullable) GFPDisplayLinkStartBlock start;
@property (nonatomic, copy, nullable) GFPDisplayLinkTickBlock tick;
@property (nonatomic, copy, nullable) GFPDisplayLinkCompletionBlock completion;
@property (nonatomic, copy, nullable) GFPDisplayLinkProgressBlock progress;
@property (nonatomic, copy, nullable) GFPDisplayLinkRepeatBlock repeat;

- (instancetype)initWith:(CFTimeInterval)duration
                   delay:(CFTimeInterval)delay
                  target:(id)target
                 options:(GFPDisplayLinkOptions) options
          customProgress:(GFPDisplayLinkProgressBlock)progress
                    tick:(GFPDisplayLinkTickBlock)tick
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
