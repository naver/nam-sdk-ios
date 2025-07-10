//
//  GFPAdAdaptor.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <UIKit/UIKit.h>
#import "GFPAdAdapting.h"


@class GFPEventReporter;
@class GFPError;
@class GFPImpressionTrackingTarget;
@class GFPAdAttachmentInfo;
@class GFPAdImpressionInfo;
@class GFPAdMetaData;

extern NSTimeInterval const kGFPVideoAdViewableImpSec;


NS_ASSUME_NONNULL_BEGIN

@interface GFPAdAdaptor : NSObject <GFPAdAdapting>

@property (nonatomic, strong, nullable) NSString *adUnitId;

@property (readonly, nonatomic, strong) GFPEventReporter *eventReporter;
@property (nonatomic, strong, nullable) NSString *adProviderName;
@property (nonatomic, strong, nullable) NSString *renderType;

@property (readwrite, nonatomic, strong) GFPAdImpressionInfo *viewableImpInfo;
@property (readwrite, nonatomic, strong, nullable) GFPEventExtraInfo *extraInfo;

@property (readwrite, atomic, strong) GFPAdAttachmentInfo *attachmentInfo;

@property (readwrite, nonatomic, strong, nullable) GFPAdMetaData *adMetaData;

- (void)loadAdWithCompletionHandler:(GFPAdAdaptorLoadCompletionHandler)completionHandler
                      timeoutMillis:(nullable NSNumber *)timeoutMillis;

- (void)startTrackingRenderedImpWithView:(UIView *)viewToBeTracked
                       completionHandler:(void (^)(GFPImpressionTrackingTarget *target))completionHandler;

- (void)stopTrackingRenderedImp;

- (void)startTrackingViewableImpWithView:(UIView *)viewToBeTracked
                       completionHandler:(void (^)(GFPImpressionTrackingTarget *target))completionHandler;

- (void)stopTrackingViewableImp;

- (void)startTrackingBounceBackImp:(UIView *)viewToBeTracked
                 completionHandler:(void (^)(GFPImpressionTrackingTarget *target))completionHandler;

- (void)stopTrackingBouncBackImp;

- (GFPImpressionTrackingTarget *)startTrackingCustomImpWithView:(UIView *)viewToBeTracked
                                               adImpressionInfo:(GFPAdImpressionInfo *)adImpressionInfo
                                              completionHandler:(void (^)(GFPImpressionTrackingTarget *target))completionHandler;

- (void)stopTrackingCustomImpWith:(GFPImpressionTrackingTarget *)trackingTarget;

- (void)markedAttachedOnSuperView;
- (void)trackingAttachedOnSuperViewWith:(GFPEventExtraInfo *)aExtraInfo;

@end


@interface GFPNativeAdAdaptor: GFPAdAdaptor

//needs call
- (void)updateRegisterStatus:(BOOL)isRegister adView:(nullable UIView *)adView;
- (void)updateExistUserDelegate:(BOOL)isExist;

//needs override
- (void)notifyDidChangeUserInterestWith:(BOOL)isUserInterest;

@end

NS_ASSUME_NONNULL_END
