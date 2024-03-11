//
//  GFPNDAVideoEventReporter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>

@class GFPVastEvent;
@class GFPTrackingURLs;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAVideoEventReporter : NSObject

@property (readonly, nonatomic, strong) GFPVastEvent *vastEvent;

- (instancetype)initWithVastEvent:(GFPVastEvent * _Nullable)aVastEvent;


- (void)reportProgressWithCurrentTime:(double)currentTime;
- (void)reportImpression;
- (void)reportStart;
- (void)reportComplete;
- (void)reportSkip;
- (void)reportClick;
- (void)reportPause;
- (void)reportResume;
- (void)reportRewind;
- (void)reportError;
- (void)reportMute;
- (void)reportUnMute;

- (void)reportTrackingWith:(NSArray <NSString *> *)urls;

@end

NS_ASSUME_NONNULL_END
