//
//  GFPNDANativeAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPNativeContext.h"
#import "GFPNDAMediaView.h"
#import "GFPNDAAdMuteView.h"
#import "GFPEventReporter.h"
#import "GFPNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPSKAdNetworkInfo;

@class GFPAdChoiceInfo;
@class GFPAdEventObject;
@class GFPNDANativeAd;
@class GFPNativeAdInfo;
@class GFPNativeAdData;
@class GFPNativeBaseView;
@class GFPAdEventObject;
@class GFPNDAMediaView;
@class GFPNDAMediaViewRenderInfo;
@class GFPNDALazyMediaLoadCoordinator;
@class GFPError;
@class GFPAdChoicesData;
@class GFPNDANativeLandingTapGesture;
@class GFPAutoPlayInfo;
@class GFPNDAVastVerification;
@class GFPOMMediaEvent;

@protocol GFPNDANativeAdDelegate <NSObject>

- (void)nativeAdDidLoad:(GFPNDANativeAd *)nativeAd;
- (void)nativeAd:(GFPNDANativeAd *)nativeAd didFailWithError:(GFPError *)error;
- (void)nativeAdWasRendered:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdWasSeen:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdWasClicked:(GFPNDANativeAd *)nativeAd trackerList:(NSArray <NSString *> *)trackerList cURL:(NSURL *)cURL;
- (void)nativeAdMuteWasClicked:(GFPNDANativeAd *)nativeAd eventTracking:(GFPAdEventObject *)eventTracking;
- (void)nativeAdMuteWasCanceled:(GFPNDANativeAd *)nativeAd;
- (void)nativeAd:(GFPNDANativeAd *)nativeAd didChangeMediaViewSize:(CGSize)size;
- (void)nativeAdPrivWasClicked:(GFPNDANativeAd *)nativeAd;

@optional
- (void)nativeAd:(GFPNDANativeAd *)nativeAd richAdExtendSizeChanged:(CGSize)size;
- (void)nativeRichAdExtendComplete:(GFPNDANativeAd *)nativeAd;
- (void)nativeRichAdExtendStart:(GFPNDANativeAd *)nativeAd toSize:(CGSize)size;
- (void)nativeRichAdShrinkComplete:(GFPNDANativeAd *)nativeAd;
- (void)nativeRichAdShrinkStart:(GFPNDANativeAd *)nativeAd toSize:(CGSize)size;

- (void)nativeAdDidReload:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdDidReloadFailed:(GFPNDANativeAd *)nativeAd error:(GFPError *)error;

- (void)nativeAdDidRenderingFailed:(GFPNDANativeAd *)nativeAd error:(GFPError *)error;

- (void)nativeAdDidRenderingSlotFailed:(GFPNDANativeAd *)nativeAd error:(GFPError *)error;

- (void)nativeAdDidPresentDefaultInAppBrowser:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdDidDismissDefaultInAppBrowser:(GFPNDANativeAd *)nativeAd;

- (void)nativeAdDidLoadMediaData:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdDidFailToLoadMediaData:(GFPNDANativeAd *)nativeAd;
- (void)shouldCalculatePreferredHeight:(GFPNDANativeAd *)nativeAd;
- (void)nativeAd:(GFPNDANativeAd *)nativeAd
didChangeMediaAssetLoadingState:(GFPNativeAdMediaLoadingState)state
       assetType:(GFPNativeAdMediaAssetType)assetType;

- (CGFloat)minimumSpecialDaRegionHeight;

@end

@class GFPNDANativeAd;

/**
 * lazy 비디오 미디어의 VAST 사이즈 resolver 인터페이스.
 * 구현체(GFPNDAVastMediaSizeResolver)는 VAST 파서 접근이 가능한 MediationNDARich 모듈에 있고,
 * 베이스는 NSClassFromString 으로 동적 로딩한다(팩토리의 기존 모듈 경계 관례).
 */
@protocol GFPNDALazyVideoMediaSizeResolving <NSObject>

+ (nullable id<GFPNDALazyVideoMediaSizeResolving>)resolverForNativeAd:(GFPNDANativeAd *)nativeAd
                                                           completion:(void (^)(CGSize mediaSize,
                                                                                id _Nullable vastAd,
                                                                                id _Nullable vastMacroProvider))completion;
- (void)resolveWithVastXML:(nullable NSString *)vastXML;

@end


@interface GFPNDANativeAd : NSObject <GFPNDAMediaViewDelegate>

@property (nonatomic, weak) id <GFPNDANativeAdDelegate> delegate;
@property (nonatomic, weak, readonly, nullable) id <GFPS2SAdClickDelegate> clickDelegate;

@property (nonatomic, strong, readonly) GFPNativeAdInfo *nativeAdInfo;
@property (nonatomic, strong, readonly) GFPNativeAdData *nativeData;
@property (nonatomic, strong, readonly) GFPAdInfoID *adInfoId;


@property (nonatomic, strong, readonly) GFPNDAMediaView *mediaView;
@property (nonatomic, strong, readonly) GFPNDAMediaViewRenderInfo *renderInfo;
//LazyLoading 시 유예된 비디오 로드의 등록/트리거를 광고 단위로 조율. renderInfo를 통해 미디어 뷰로 전달된다.
@property (nonatomic, strong, readonly) GFPNDALazyMediaLoadCoordinator *lazyMediaLoadCoordinator;
@property (nonatomic, assign, readonly) BOOL isExpired;
@property (nonatomic, assign, readonly) BOOL isLoadedIcon; //for nn
@property (nonatomic, assign, readonly) BOOL isLazyLoading;
@property (nonatomic, assign, readonly) GFPNativeAdMediaLoadingState iconLoadingState;
@property (nonatomic, assign, readonly) GFPNativeAdMediaLoadingState mediaLoadingState;

@property (nonatomic, assign, readonly) CGSize cropSize;

@property (nonatomic, strong, readonly) NSDictionary <NSString *, NSObject *> *extraInfo;
@property (readwrite, nonatomic, nullable, strong) NSNumber *slotIndex;

@property (nonatomic, strong) NSNumber *vastMaxRedirect;

@property (nonatomic, strong, readonly) GFPAdChoicesData *adChoicesData; //for service
@property (nonatomic, strong, readonly) GFPAdChoiceInfo *adChoiceInfo;
@property (nonatomic, assign, readonly) GFPNDAAdMuteState adMuteState;

@property (nonatomic, strong) GFPVideoOptions *videoOptions;
@property (nonatomic, strong) GFPAutoPlayInfo *autoPlayInfo;

@property (nonatomic, weak) GFPNativeBaseView *adView;
@property (nonatomic, strong, readonly, nullable) NSArray <GFPNDAVastVerification *> *vastOmidInfos;
@property (nonatomic, readonly, strong) NSUUID *logId;

- (instancetype)initWithNativeAdInfo:(GFPNativeAdInfo *)nativeAdInfo
                     skAdNetworkInfo:(GFPSKAdNetworkInfo *)skNetworkInfo
                         nasSkipInfo:(GFPVastAdSkipInfo *)skipInfo
                        adChoiceInfo:(GFPAdChoiceInfo *)adChoiceInfo
                     vastMaxRedirect:(NSNumber *)vastMaxRedirect
                             context:(GFPNativeContext *)context
                            adInfoId:(GFPAdInfoID *)adInfoId;

- (void)loadAd;

/**
 * LazyLoading 시 광고 타입(loadAd 재정의 여부)과 무관하게 로드 완료를 통지하기 위한 진입점.
 * adaptor가 loadAd 직후 호출한다. lazyLoading이 아니거나 이미 완료 통지되었으면 no-op.
 */
- (void)completeLoadForLazyLoadingIfNeeded;

/**
 * lazy 로드 완료 통지 훅. 기본 구현은 비디오 메인 미디어의 VAST 사이즈 resolve 를 마친 뒤
 * notifyLoadCompletionForLazyLoading 을 호출한다. (비디오는 응답에 크기가 없어 resolve 전에는
 * mediaData 를 만들 수 없으므로, 타입별 재정의 누락으로 mediaData nil 인 채 통지되지 않도록
 * 베이스에서 일괄 보장한다 — CAROUSEL_VIDEO_MEDIA 초기 높이 0 재발 방지)
 */
- (void)performLazyLoadCompletion;

/**
 * lazy 로드 완료를 delegate에 통지한다. performLazyLoadCompletion 구현체가 호출.
 */
- (void)notifyLoadCompletionForLazyLoading;

/**
 * lazy 비디오 미디어의 VAST 사이즈 resolve 완료 훅 (기본 no-op).
 * 서브클래스가 resolve 결과물(vastAd 등)을 자신의 미디어 뷰에 전달할 때 override 한다.
 * vastAd/vastMacroProvider 는 각각 GFPVastAd/GFPVastMacroProvider 이며,
 * resolve 실패 시 mediaSize 는 CGSizeZero, vastAd 는 nil 일 수 있다.
 */
- (void)didResolveLazyVideoMediaSize:(CGSize)mediaSize
                              vastAd:(nullable id)vastAd
                   vastMacroProvider:(nullable id)vastMacroProvider;

- (void)registerViewWith:(GFPNativeBaseView *)nativeAdView error:(GFPError **)error;
- (void)unregisterView;

- (void)updateLayout:(GFPNDAMediaView *)aMediaView nativeView:(UIView *)nativeView;
- (void)updateMediaAssetsWith:(UIView *)targetView;
- (void)updateAdMuteStateWith:(GFPNDAAdMuteState)adMuteState;
- (void)updateOMIDMediaEventWith:(GFPOMMediaEvent * _Nullable)mediaEvent;

- (void)nativeAdDidLoad;
- (void)nativeAdDidFailWithError:(GFPError *)error;
- (void)nativeAdDidFailBeforeAssetLoad:(GFPError *)error;

- (BOOL)triggerDeferredVideoLoadIfNeeded;

- (void)layoutBackgroundView:(GFPNativeBaseView *)nativeAdView mediaView:(GFPNDAMediaView *)mediaView;
- (void)layoutMediaViews;
- (void)layoutSubviewsBySimpleViewChanged;

- (void)adPrivacyOpenLanding;

- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;


- (void)clearForMemoryWarning;
- (BOOL)isReloadRequired;
- (void)reloadMediaResource;
- (void)additionalRenderingViewClicked:(UIView *)clickedView;

- (void)markMediaLoading;
- (void)markIconLoading;
- (void)resetMediaLoadingState;
- (void)resetIconLoadingState;

//for link
- (void)tapGestureWith:(GFPNDANativeLandingTapGesture *)gesture;
- (void)tryLandingWith:(GFPNDANativeLandingTapGesture *)gesture slotIndex:(NSNumber *_Nullable)slotIndex;
@end

NS_ASSUME_NONNULL_END
