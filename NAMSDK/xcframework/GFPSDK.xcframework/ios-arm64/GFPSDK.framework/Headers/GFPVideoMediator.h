//
//  GFPVideoMediator.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPMediator.h"

@protocol GFPVideoMediatorDelegate;
@protocol GFPEventReportDelegate;
@protocol GFPVideoAdapting;

@class GFPAdParam;
@class GFPVideoContext;
@class GFPVideoMediator;
@class GFPAdAdaptor;
@class GFPError;
@class GFPVideoAdParam;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPVideoMediatorDelegate <NSObject>

- (void)videoMediator:(GFPVideoMediator *)mediator didLoadVideoAdaptor:(GFPAdAdaptor <GFPVideoAdapting> *)adaptor;

- (void)videoMediator:(GFPVideoMediator *)mediator didFailToLoadVideoAdaptorWithError:(GFPError *)error;

@end


@interface GFPVideoMediator : GFPMediator

@property (nonatomic, weak) id <GFPEventReportDelegate> reportDelegate;

@property (readwrite, nonatomic, weak) id <GFPVideoMediatorDelegate> delegate;

- (void)loadVideoAdaptorWithAdUnitID:(NSString *)adUnitID
                        videoContext:(GFPVideoContext *)videoContext
                             adParam:(nullable GFPAdParam *)adParam
                          videoParam:(nullable GFPVideoAdParam *)videoParam
                     timeoutInterval:(NSTimeInterval)timeoutInterval;

@end

NS_ASSUME_NONNULL_END
