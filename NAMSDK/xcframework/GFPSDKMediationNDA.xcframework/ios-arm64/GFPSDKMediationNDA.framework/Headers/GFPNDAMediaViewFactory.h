//
//  GFPNDAMediaViewFactory.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPNDAMediaView.h"
#import "GFPNativeAdInfoProtocol.h"
#import "GFPNativeAdRenderingSetting.h"
#import "GFPNDAAdMuteView.h"
#import "GFPAdSkipInfo.h"

@class GFPAdChoiceInfo;
@class GFPSKAdNetworkInfo;
@class GFPNativeMediaInfo;
@class GFPNativeRichInfo;
@class GFPVideoOptions;
@class GFPAdImpressionInfo;
@class GFPAutoPlayInfo;
@class GFPAdSlotsNativeData;

NS_ASSUME_NONNULL_BEGIN


@interface GFPNDAMediaViewRenderInfo : NSObject

@property (nonatomic, assign, readonly) BOOL hasRenderAdBadge;
@property (nonatomic, assign, readonly) BOOL hasRenderAdChoice;

@property (nonatomic, strong, readonly) GFPNativeBaseRenderingSetting *renderingSetting;

@property (nonatomic, assign, readonly) GFPAdChoicesViewPosition adChoicesPosition;
@property (nonatomic, assign, readonly) GFPAdInterfaceStyle adInterfaceStyle;
@property (nonatomic, strong, readonly) GFPAdChoiceInfo *adChoiceInfo;
@property (nonatomic, assign, readonly) GFPNDAAdMuteState adMuteState;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(GFPNativeBaseRenderingSetting *)renderingSetting;
- (instancetype)initWith:(GFPAdChoiceInfo *)info renderAdBadge:(BOOL)renderAdBadge renderingSetting:(GFPNativeBaseRenderingSetting *)renderingSetting adMuteState:(GFPNDAAdMuteState)adMuteState;

@end

@interface GFPNDAMediaViewInfo : NSObject

@property (nonatomic, readonly, assign) GFPNDAMediaViewType type;
@property (nonatomic, readonly, strong, nullable) GFPNDAMediaViewRenderInfo *renderInfo;
@property (nonatomic, readonly, strong, nullable) GFPAdSkipInfo *skipInfo;

@property (nonatomic, readonly, strong) id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoExtensionPresentable> info;
@property (nonatomic, readonly, strong) GFPNativeAdInfo *nativeAdInfo;
@property (nonatomic, readonly, strong) NSString *alternativeText;

@property (nonatomic, readonly, strong, nullable) GFPSKAdNetworkInfo *skAdNetworkInfo;
@property (nonatomic, readonly, strong, nullable) NSNumber *vastMaxRedirect;

@property (nonatomic, readonly, strong, nullable) GFPVideoOptions *videoOptions;
@property (nonatomic, readonly, strong, nullable) NSNumber *videoLoadTimeout;
@property (nonatomic, readonly, strong, nullable) GFPAutoPlayInfo *autoPlayInfo;
@property (nonatomic, readonly, strong) NSString *creativeId;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoExtensionPresentable>)aInfo;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoExtensionPresentable>)aInfo
             skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                  renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
             vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoExtensionPresentable>)aInfo
             skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                  renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
             vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect
                videoOptions:(nullable GFPVideoOptions *)videoOptions
            videoLoadTimeout:(nullable NSNumber *)videoLoadTimeout
                autoPlayInfo:(nullable GFPAutoPlayInfo *)autoPlayInfo
                  creativeId:(nullable NSString *)creativeId;


- (instancetype)initWithCarouselInfo:(GFPNativeAdInfo *)aInfo
                     skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                          renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
                     vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect
                        videoOptions:(nullable GFPVideoOptions *)videoOptions
                        autoPlayInfo:(nullable GFPAutoPlayInfo *)autoPlayInfo;

- (instancetype)initWithDefaultRendererInfo:(GFPNativeAdInfo *)aInfo
                            skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                                 renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
                            vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect
                               videoOptions:(nullable GFPVideoOptions *)videoOptions
                               autoPlayInfo:(nullable GFPAutoPlayInfo *)autoPlayInfo;


@end



@interface GFPNDAMediaViewFactory : NSObject

+ (GFPNDAMediaView *)mediaViewWithInfo:(GFPNDAMediaViewInfo *)mediaInfo;

@end

NS_ASSUME_NONNULL_END
