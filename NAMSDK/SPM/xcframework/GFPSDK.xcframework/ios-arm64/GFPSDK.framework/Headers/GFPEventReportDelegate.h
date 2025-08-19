//
//  GFPEventReportDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@protocol GFPEventReportDelegate <NSObject>

- (void)reportTrackingAckImp:(NSString *)aUrl;
- (void)reportTrackingViewableImp:(NSString *)aUrl;
- (void)reportTrackingRenderedImp:(NSString *)aUrl;
- (void)reportTrackingAttachedImp:(NSString *)aUrl;
- (void)reportTrackingClickEvent:(NSString *)aUrl;
- (void)reportTrackingMuteEvent:(NSString *)aUrl;

- (void)reportTrackingLoadError:(NSString *)loadEventInfo;
- (void)reportTrackingStartError:(NSString *)startEventInfo;

- (void)reportTrackingLazySlotRenderFail:(NSString *)lazySlotRenderInfo;


@end

NS_ASSUME_NONNULL_END
