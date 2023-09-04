//
//  GFPLoadEvent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import "GFPEvent.h"

@class GFPError;
@class GFPErrorEventInfo;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GFPLoadEventStat) {
    /**
     * Don't change the value. This is the value defined in the specification.
     */
    GFPLoadEventStatError = 0,
    GFPLoadEventStatAdSelected = 1,
    GFPLoadEventStatNoFill = 2,
    GFPLoadEventStatTimeout = 3,
};


@interface GFPLoadEvent : GFPEvent

@property (nonatomic, strong) GFPErrorEventInfo *errorEventInfo;
@property (nonatomic, assign) GFPLoadEventStat loadEventStat;

+ (GFPLoadEvent *)successEvent;

+ (GFPLoadEvent *)errorEventWithStat:(GFPLoadEventStat)loadEventStat
                           errorInfo:(GFPErrorEventInfo *)errorEventInfo;

@end

NS_ASSUME_NONNULL_END
