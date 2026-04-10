//
//  GFPNDAVideoEventReporter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
@import NaverAdsServices;

@class GFPVastEvent;
@class GFPTrackingURLs;
@class GFPOMMediaEvent;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAVideoEventReporter : NSObject

@property (readonly, nonatomic, strong) GFPVastTrackingInfo *nasVastEvent;
@property (readonly, nonatomic, strong) GFPOMMediaEvent *omidMediaEvent;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNASVastEventInfo:(GFPVastTrackingInfo * _Nullable)aVastEvent logId:(NSUUID *)logId;

- (void)reportProgressWithCurrentTime:(double)currentTime;
- (void)reportImpression;
- (void)reportStart;
- (void)reportComplete;
- (void)reportSkip;
- (void)reportClick;
- (void)reportError;
- (void)reportErrorWith:(NSInteger)errorCode;
- (void)reportClose;
- (void)reportCloseLinear;

- (void)reportPauseWith:(BOOL)isUserAction;
- (void)reportResumeWith:(BOOL)isUserAction;
- (void)reportRewindWith:(BOOL)isUserAction;
- (void)reportMuteWith:(BOOL)isUserAction;
- (void)reportUnMuteWith:(BOOL)isUserAction;

- (void)reportTrackingWith:(NSArray <NSString *> *)urls;

- (void)updateOMIDMediaEvent:(GFPOMMediaEvent * _Nullable)mediaEvent;

@end

NS_ASSUME_NONNULL_END
