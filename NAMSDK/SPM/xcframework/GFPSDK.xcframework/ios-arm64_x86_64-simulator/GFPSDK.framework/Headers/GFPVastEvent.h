//
//  GFPVastEvent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPNDAVastTracking;
@class GFPTrackingURLs;
@class GFPNDAVastProgressEvent;

NS_ASSUME_NONNULL_BEGIN

@interface GFPVastEvent : NSObject

@property (readonly, nonatomic, strong) GFPNDAVastTracking *trackingInfo;
@property (readonly, nonatomic, strong) GFPTrackingURLs *trackingURLs;

@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readonly, nonatomic, strong) NSArray<GFPNDAVastProgressEvent *> *progressEvents;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(GFPNDAVastTracking *)aTrackingInfo trackingURLs:(GFPTrackingURLs *)aTrackingURLs duration:(NSTimeInterval)aDuration NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
