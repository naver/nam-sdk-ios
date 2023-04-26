//
//  NSTimer+GFPUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import <Foundation/Foundation.h>


#define kAttachedCheckDefaultFrequency 0.1


@interface NSTimer (GFPUtils)

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                      block:(void (^)(void))block
                                    repeats:(BOOL)repeats;

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                      block:(void (^)(void))block
                                    repeats:(BOOL)repeats
                                       mode:(NSRunLoopMode)mode;

@end
