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

@class GFPAdChoiceInfo;
@class GFPSKAdNetworkInfo;
@class GFPNativeMediaInfo;
@class GFPNativeRichInfo;
@class GFPVideoOptions;
@class GFPAdImpressionInfo;
@class GFPAutoPlayInfo;
@class GFPAdSlotsNativeData;
@class GFPNativeTemplateOptions;

NS_ASSUME_NONNULL_BEGIN

//LazyLoading 시 유예(deferred)된 비디오 로드의 시작 시점을 광고 단위로 조율한다.
//비디오 뷰는 유예하는 순간 스스로 등록하므로, 뷰 계층 구조나 광고 타입(Complex/Renderer 등
//컨테이너가 비디오 뷰를 품는 형태)과 무관하게 트리거가 누락되지 않는다. (GFPSDK-1579)
@interface GFPNDALazyMediaLoadCoordinator : NSObject

//아직 트리거 전이면 mediaView를 보류 목록에 등록하고 YES를 반환한다.
//이미 트리거된 후면 NO를 반환하며, 호출측은 유예 없이 즉시 로드해야 한다.
//(코디네이터 또는 mediaView가 nil이면 NO가 되어 즉시 로드로 안전하게 동작)
- (BOOL)deferVideoLoadForMediaView:(GFPNDAMediaView * _Nullable)mediaView;

//보류 중인 모든 비디오 뷰의 로드를 시작시키고, 이후의 유예 요청은 거절되도록 래치를 세운다.
//하나라도 트리거했으면 YES를 반환한다.
- (BOOL)triggerDeferredVideoLoads;

- (BOOL)hasPendingDeferredVideoLoad;

@end

@interface GFPNDAMediaViewRenderInfo : NSObject

@property (nonatomic, assign, readonly) BOOL hasRenderAdBadge;
@property (nonatomic, assign, readonly) BOOL hasRenderAdChoice;

@property (nonatomic, strong, readonly) GFPNativeBaseRenderingSetting *renderingSetting;

@property (nonatomic, assign, readonly) GFPAdChoicesViewPosition adChoicesPosition;
@property (nonatomic, assign, readonly) GFPAdInterfaceStyle adInterfaceStyle;
@property (nonatomic, strong, readonly) GFPAdChoiceInfo *adChoiceInfo;
@property (nonatomic, assign, readonly) GFPNDAAdMuteState adMuteState;

//renderInfo는 접근할 때마다 새로 생성되지만(GFPNDANativeNormalAd/SimpleAd의 renderInfo getter),
//코디네이터는 광고(GFPNDANativeAd)가 단일 소유한 인스턴스를 실어 나른다.
@property (nonatomic, strong, nullable) GFPNDALazyMediaLoadCoordinator *lazyMediaLoadCoordinator;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(GFPNativeBaseRenderingSetting *)renderingSetting;
- (instancetype)initWith:(GFPAdChoiceInfo *)info renderAdBadge:(BOOL)renderAdBadge renderingSetting:(GFPNativeBaseRenderingSetting *)renderingSetting adMuteState:(GFPNDAAdMuteState)adMuteState;

- (void)updateRenderingSetting:(GFPNativeBaseRenderingSetting *)renderingSetting; //for shoppingLabelRetail

@end

@interface GFPNDAMediaViewInfo : NSObject

@property (nonatomic, readonly, assign) GFPNDAMediaViewType type;
@property (nonatomic, readonly, strong, nullable) GFPNDAMediaViewRenderInfo *renderInfo;
@property (nonatomic, readonly, strong, nullable) GFPVastAdSkipInfo *nasSkipInfo;

@property (nonatomic, readonly, strong) id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoMediaExtPresentable> info;
@property (nonatomic, readonly, strong) GFPNativeAdInfo *nativeAdInfo;
@property (nonatomic, readonly, strong) NSString *alternativeText;

@property (nonatomic, readonly, strong, nullable) GFPSKAdNetworkInfo *skAdNetworkInfo;
@property (nonatomic, readonly, strong, nullable) NSNumber *vastMaxRedirect;

@property (nonatomic, readonly, strong, nullable) GFPVideoOptions *videoOptions;
@property (nonatomic, readonly, strong, nullable) NSNumber *videoLoadTimeout;
@property (nonatomic, readonly, strong, nullable) GFPAutoPlayInfo *autoPlayInfo;
@property (nonatomic, readonly, strong) NSString *creativeId;

@property (nonatomic, readonly, strong, nullable) GFPNativeTemplateOptions *templateOptions;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoMediaExtPresentable>)aInfo;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoMediaExtPresentable>)aInfo
                nativeAdInfo:(nullable GFPNativeAdInfo *)nativeAdInfo
             skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                  renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
             vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect;

- (instancetype)initWithInfo:(id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoMediaExtPresentable>)aInfo
                nativeAdInfo:(nullable GFPNativeAdInfo *)nativeAdInfo
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

- (instancetype)initWithDefaultRendererInfo:(GFPNativeAdInfo *)nativeAdInfo
                            skAdNetworkInfo:(nullable GFPSKAdNetworkInfo *)skAdNetworkInfo
                                 renderInfo:(nullable GFPNDAMediaViewRenderInfo *)renderInfo
                            vastMaxRedirect:(nullable NSNumber *)vastMaxRedirect
                               videoOptions:(nullable GFPVideoOptions *)videoOptions
                           videoLoadTimeout:(nullable NSNumber *)videoLoadTimeout
                               autoPlayInfo:(nullable GFPAutoPlayInfo *)autoPlayInfo
                                 creativeId:(nullable NSString *)creativeId
                            templateOptions:(nullable GFPNativeTemplateOptions *)templateOptions;


@end



@interface GFPNDAMediaViewFactory : NSObject

+ (GFPNDAMediaView *)mediaViewWithInfo:(GFPNDAMediaViewInfo *)mediaInfo logId:(NSUUID *)logId;

@end

NS_ASSUME_NONNULL_END
