//
//  GFPVideoAdQoeInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVPlayerItem.h>

#import "GFPVideoAdPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoAdQoeBaseInfo : NSObject

/**
 * 광고 위치 명
 * - 전광고 : "pre"
 * - 중간광고: "mid"
 * - 후광고 : "post"
 */
@property (readonly, nonatomic, strong) NSString * placementType;

/**
 *  광고 영상 길이 (초)
 */
@property (readonly, nonatomic, assign) NSTimeInterval duration;

/**
 *  광고 스킵 오프셋 (초)
 */
@property (readonly, nonatomic, assign) NSTimeInterval skipOffset;

/**
 * 광고 영상 가로 길이
 */
@property (readonly, nonatomic, assign) NSInteger mediaWidth;

/**
 * 광고 영상 세로 길이
 */
@property (readonly, nonatomic, assign) NSInteger mediaHeight;



- (instancetype)initWithPlacementType:(GFPVideoPlacementType)placementType
                             duration:(NSTimeInterval)duration
                           skipOffset:(NSTimeInterval)skipOffset
                           mediaWidth:(NSInteger)mediaWidth
                          mediaHeight:(NSInteger)mediaHeight;

- (void)updateSize:(CGSize)size;

@end


@interface GFPVideoAdQoePlayerInfo : NSObject

@property (readonly, nonatomic, assign) float fps;

@property (readonly, nonatomic, strong, nullable) NSNumber *audioTrackNumber;
@property (readonly, nonatomic, strong, nullable) NSNumber *videoTrackNumber;

@property (readonly, nonatomic, assign) float playRate;
@property (readonly, nonatomic, assign) CMTimeRange bufferedTimeRange;

- (instancetype)initWithAVPlayerItem:(AVPlayerItem *)playerItem rate:(float)playRate;

- (void)updateBufferedTimeWith:(NSValue *)aValue;


@end


@interface GFPVideoAdQoeInfo : GFPVideoAdQoeBaseInfo

/**
 * 광고 제공자 명 (없으면 nil)
 */
@property (readonly, nonatomic, strong, nullable) NSString *provider;


/**
 * 광고 Player 기본 정보 (Naver 광고의 경우에만 지원 가능)
 */
@property (nonatomic, strong, nullable) GFPVideoAdQoePlayerInfo *playerInfo;


- (instancetype)initWithProvider:(NSString *)aProvider
                        baseInfo:(GFPVideoAdQoeBaseInfo *)aBaseInfo;

- (instancetype)initWithProvider:(NSString *)aProvider
                        baseInfo:(GFPVideoAdQoeBaseInfo *)aBaseInfo
                      playerInfo:(GFPVideoAdQoePlayerInfo *)aPlayerInfo;


- (instancetype)initWithProvider:(NSString *)provider
                   placementType:(NSString *)placementType
                        duration:(NSTimeInterval)duration
                      skipOffset:(NSTimeInterval)skipOffset
                      mediaWidth:(NSInteger)mediaWidth
                     mediaHeight:(NSInteger)mediaHeight;


- (instancetype)initUnKnownWithProvider:(NSString *)provider;


@end


NS_ASSUME_NONNULL_END
