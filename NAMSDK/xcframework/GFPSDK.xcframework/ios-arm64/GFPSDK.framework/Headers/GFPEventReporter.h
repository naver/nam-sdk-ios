//
//  GFPEventReporter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//




#import <Foundation/Foundation.h>

#import "GFPWaterfallList.h"

@class GFPLoadEvent;
@class GFPStartEvent;
@class GFPEventExtraInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPEventReportPresentable <NSObject>

@property (nonatomic, strong) NSNumber *adCallRequestTime;

@end


@interface GFPBaseEventReporter : NSObject

@property (nonatomic, strong) GFPAdInfoEvent *providerEvent;

- (instancetype)initWithProviderEvent:(GFPAdInfoEvent *)providerEvent;
- (void)reportProviderEvent:(NSArray<GFPAdEventObject *> *)providerEvtObjs;
- (void)reportProviderEvent:(NSArray<GFPAdEventObject *> *)providerEvtObjs queryItems:(NSArray<NSURLQueryItem *> *_Nullable)queryItems;

- (void)reportVImp100;
- (void)reportVImp100p;
- (void)reportVImp1px;

@end

@interface GFPEventReporter : GFPBaseEventReporter <GFPEventReportPresentable>


@property (readonly, nonatomic, strong) GFPAdEvent *gfpEvent;
@property (readonly, nonatomic, strong) NSString *encrypted;

@property (readwrite, nonatomic, strong) NSNumber *loadRequestTime;      // uptime
@property (readwrite, nonatomic, strong) NSNumber *startRequestTime;     // uptime

@property (nonatomic, assign, readonly) BOOL existBounceBackEvent;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithProviderEvent:(GFPAdInfoEvent *)providerEvent // ads event
                             gfpEvent:(GFPAdEvent *)gfpEvent          // waterfallList event
                            encrypted:(NSString *)encrypted;

- (void)reportEmptyImpressions;

- (void)reportAckImpression:(GFPLoadEvent *)loadEventInfo;
- (void)reportAckImpression:(GFPLoadEvent *)loadEventInfo extraInfo:(GFPEventExtraInfo * _Nullable)aExtraInfo;

- (void)reportRenderedImpressions;
- (void)reportRenderedImpressionsWithExtraInfo:(GFPEventExtraInfo * _Nullable)aExtraInfo;

- (void)reportViewableImpressions;
- (void)reportViewableImpressionsWithExtraInfo:(GFPEventExtraInfo * _Nullable)aExtraInfo;

- (void)reportClick;
- (void)reportClickWithExtraInfo:(GFPEventExtraInfo * _Nullable)aExtraInfo;

- (void)reportLoadError:(GFPLoadEvent *)loadEventInfo;

- (void)reportStartError:(GFPStartEvent *)startEventInfo;

- (void)reportGfpTracking:(NSString *)gfpBaseUrl;

- (void)reportRewardVideoClose:(NSString *)playTime;

- (void)reportMute;

- (void)reportLazySlotRenderFail;

- (void)reportCustomTrackersWith:(NSArray <NSString *> *)trackers;
- (void)reportCustomEventsWith:(NSArray <GFPAdEventObject *> *)eventObjects;

- (void)reportAttachImpressionsWithExtraInfo:(GFPEventExtraInfo *_Nullable)aExtraInfo;

- (void)reportCompleteImpressionsWithExtraInfo:(GFPEventExtraInfo *_Nullable)aExtraInfo;

- (void)reportBounceBack;

- (void)reportBounceBack:(double)bbt;

@end

NS_ASSUME_NONNULL_END
