//
//  GFPVideoAdBreak.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPErrorSupporter.h"
#import "GFPVideoAdManager.h"
#import "GFPVideoAdPlacement.h"

/*
 {
   "id": "preroll-1",
   "startDelay": 0,
   "preFetchSec": 0,
   "adUnitId": "NS_AOS_NDP_VIDEO_TEST",
   "noticeDurationSec": 0,
   "adSources": [
     {
       "id": "preroll-1-1",
       "withRemindAd": true
     },
     {
       "id": "preroll-1-2",
       "withRemindAd": false
     },
     {
       "id": "preroll-1-3",
       "withRemindAd": false
     }
   ]
 }
 */


typedef NS_OPTIONS(NSInteger, GFPVideoSourceStatus) {
    GFPVideoSourceStatusNotLoaded = 0,
    GFPVideoSourceStatusLoaded,
    GFPVideoSourceStatusStarted,
    GFPVideoSourceStatusResume,
    GFPVideoSourceStatusPause,
    GFPVideoSourceStatusCompleted,
    GFPVideoSourceStatusError,
};


NS_ASSUME_NONNULL_BEGIN

#pragma mark - GFPVideoAdSource
@interface GFPVideoAdSource : NSObject <NSCopying>

@property (nonatomic, readonly, assign) GFPVideoPlacementType type;
@property (nonatomic, readonly, strong) NSString *sourceID;
@property (nonatomic, readonly, assign) BOOL hasRemindAd;
@property (nonatomic, readonly, assign) NSInteger delayMills;


- (instancetype)initWithDictionary:(NSDictionary *)aDict type:(GFPVideoPlacementType)aType;

+ (NSArray <GFPVideoAdSource *> *)adSourcesWithDictionary:(NSArray <NSDictionary *> *)aDicts type:(GFPVideoPlacementType)aType;

@end



#pragma mark - GFPVideoAdSourceInfo
@interface GFPVideoAdSourceInfo : GFPVideoAdSource

@property (nonatomic, assign) GFPVideoSourceStatus status;

@property (nonatomic, readonly, assign) BOOL notYetLoaded;
@property (nonatomic, readonly, assign) BOOL isLoaded;
@property (nonatomic, readonly, assign) BOOL isError;

@end



#pragma mark - GFPVideoAdBreak
@interface GFPVideoAdBreak : NSObject <NSCopying>

@property (nonatomic, readonly, assign) GFPVideoPlacementType type;
@property (nonatomic, readonly, strong) NSString *adBreakID;
@property (nonatomic, readonly, assign) NSInteger startDelay;
@property (nonatomic, readonly, assign) NSInteger timeOffset;
@property (nonatomic, readonly, assign) NSInteger preFetchSecond;
@property (nonatomic, readonly, strong) NSString *adUnitID;
@property (nonatomic, readonly, assign) BOOL hasNotice;
@property (nonatomic, readonly, strong) NSArray <GFPVideoAdSource *> *adSources;

@property (nonatomic, readonly, assign) NSInteger prefetchOffset;
@property (nonatomic, readonly, assign) NSInteger noticeOffset;

@property (nonatomic, readonly, assign) BOOL isPreRoll;
@property (nonatomic, readonly, assign) BOOL isPostRoll;

@property (nonatomic, readonly, assign) BOOL isAllLoaded;
@property (nonatomic, readonly, assign) BOOL isAllCompleted;
@property (nonatomic, readonly, assign) BOOL hasMoreLoaded;
@property (nonatomic, readonly, assign) BOOL hasLoadedAd;
@property (nonatomic, readonly, assign) BOOL isPlaying;

@property (nonatomic, assign) NSTimeInterval noticeDuration;


- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDictionary:(NSDictionary *)aDict withError:(GFPError *_Nullable *_Nullable)aError NS_DESIGNATED_INITIALIZER;

- (void)updateDuration:(NSInteger)aDuration;


+ (NSArray <GFPVideoAdBreak *> *)adBreaksWithDictionary:(NSArray <NSDictionary *> *)aDict noticeDuration:(NSTimeInterval)aNoticeDuration withError:(GFPError *_Nullable *_Nullable)aError;


@end


#pragma mark - GFPVideoAdBreakResult
@interface GFPVideoAdBreakResult : NSObject

@property (nonatomic, readonly, strong) GFPVideoAdSource *adSource;
@property (nonatomic, readonly, strong) GFPVideoAdManager *videoManager;
@property (nonatomic, strong, nullable) GFPError *error;

- (instancetype)initWithAdSource:(GFPVideoAdSource * __nullable)aAdSource videoManager:(GFPVideoAdManager *)aVideoManager;

- (NSString *)adProviderName;


@end

NS_ASSUME_NONNULL_END
