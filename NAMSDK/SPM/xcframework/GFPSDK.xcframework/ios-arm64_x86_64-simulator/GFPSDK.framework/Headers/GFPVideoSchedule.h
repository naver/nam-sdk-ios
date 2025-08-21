//
//  GFPVideoSchedule.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPVideoAdBreak.h"


NS_ASSUME_NONNULL_BEGIN


/*
 N개의 AdSource
 adSources: [
         {
             id: "preroll-1-1",
             withRemindAd: true
         },
         {
             id: "preroll-1-2",
             withRemindAd: false
         },
         {
             id: "preroll-1-3",
             withRemindAd: false
         }
     ],
     id: "preroll-1",
     timeOffset: 0,
     preFetchSec: 0,
     adUnitId: "NS_AOS_NDP_VIDEO_TEST",
     noticeDurationSec: 0
 ]
 */


@interface GFPVideoScheduleHead : NSObject

@property (readonly, nonatomic, strong) NSString *version;
@property (readonly, nonatomic, strong) NSString *desc;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


extern NSString * const kGFPGeneratedScheduleRequestId;


@interface GFPVideoSchedule : NSObject


@property (nonatomic, readonly, strong) NSString *scheduleID;
@property (nonatomic, readonly, strong) GFPVideoScheduleHead *head;
@property (nonatomic, readonly, strong) NSString *requestID;

@property (nonatomic, readonly, assign) GFPVideoPlacementType lastType;
@property (nonatomic, readonly, strong) NSString *postSourceID;

@property (nonatomic, readonly, strong) NSArray <GFPVideoAdBreak *> *adBreakList;

@property (nonatomic, readonly, strong) NSArray <GFPVideoAdBreak *> *preAdBreakList;
@property (nonatomic, readonly, strong) NSArray <GFPVideoAdBreak *> *midAdBreakList;
@property (nonatomic, readonly, strong) NSArray <GFPVideoAdBreak *> *postAdBreakList;

@property (nonatomic, readonly, strong) NSArray <GFPVideoAdBreak *> *midPostAdBreakList;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict noticeDuration:(NSTimeInterval)aNoticeDuration withError:(GFPError * _Nullable * _Nullable)aError NS_DESIGNATED_INITIALIZER;


- (GFPVideoAdBreak * _Nullable)adBreakWithAdSource:(GFPVideoAdSource *)aAdSource;

@end

NS_ASSUME_NONNULL_END
