//
//  GFPLimitQueue.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol GFPQueueObject <NSObject>

@end



@interface GFPLimitQueue : NSObject

@property (readonly, strong) NSArray <id <GFPQueueObject>> *queue;
@property (readonly, assign) NSInteger size;

@property (readonly, assign) BOOL isFull;
@property (readonly, assign) BOOL isEmpty;

+ (instancetype)sizeWith:(NSInteger)size;
- (instancetype)initWithSize:(NSInteger)size;

- (void)enqueue:(id <GFPQueueObject>)queueObject;
- (void)enqueueAndReplace:(id <GFPQueueObject>)queueObject;

- (id)dequeue;

@end

NS_ASSUME_NONNULL_END
