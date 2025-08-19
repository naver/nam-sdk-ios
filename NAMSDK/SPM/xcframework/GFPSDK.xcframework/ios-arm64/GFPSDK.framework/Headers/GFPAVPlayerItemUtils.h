//
//  GFPAVPlayerItemUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPAVPlayerItemUtils : NSObject

+ (NSValue * _Nullable)gfpBufferedTimeRangeWith:(AVPlayerItem *)playerItem;
+ (NSTimeInterval)gfpBufferedTimeWith:(AVPlayerItem *)playerItem;

@end

NS_ASSUME_NONNULL_END
