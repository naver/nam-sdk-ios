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
@class GFPAdSkipInfo;
@class GFPError;
@class GFPAdChoicesData;
@class GFPNDANativeTapGesture;
@class GFPAutoPlayInfo;

@protocol GFPNDANativeAdDelegate <NSObject>

- (void)nativeAdDidLoad:(GFPNDANativeAd *)nativeAd;
- (void)nativeAd:(GFPNDANativeAd *)nativeAd didFailWithError:(GFPError *)error;
- (void)nativeAdWasSeen:(GFPNDANativeAd *)nativeAd;
- (void)nativeAdWasClicked:(GFPNDANativeAd *)nativeAd trackerList:(NSArray <NSString *> *)trackerList;
- (void)nativeAdMuteWasClicked:(GFPNDANativeAd *)nativeAd eventTracking:(GFPAdEventObject *)eventTracking;
- (void)nativeAdMuteWasCanceled:(GFPNDANativeAd *)nativeAd;
- (void)nativeAd:(GFPNDANativeAd *)nativeAd didChangeMediaViewSize:(CGSize)size;

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

@end


@interface GFPNDANativeAd : NSObject <GFPNDAMediaViewDelegate>

@property (nonatomic, weak) id <GFPNDANativeAdDelegate> delegate;
@property (nonatomic, weak, readonly, nullable) id <GFPS2SAdClickDelegate> clickDelegate;

@property (nonatomic, strong, readonly) GFPNativeAdInfo *nativeAdInfo;
@property (nonatomic, strong, readonly) GFPNativeAdData *nativeData;

@property (nonatomic, strong, readonly) GFPNDAMediaView *mediaView;
@property (nonatomic, strong, readonly) GFPNDAMediaViewRenderInfo *renderInfo;
@property (nonatomic, assign, readonly) BOOL isExpired;
@property (nonatomic, assign, readonly) BOOL isLoadedIcon; //for nn

@property (nonatomic, assign, readonly) CGSize cropSize;

@property (nonatomic, strong, readonly) NSDictionary <NSString *, NSObject *> *extraInfo;

@property (nonatomic, strong) NSNumber *vastMaxRedirect;

@property (nonatomic, strong, readonly) GFPAdChoicesData *adChoicesData; //for service
@property (nonatomic, strong, readonly) GFPAdChoiceInfo *adChoiceInfo;
@property (nonatomic, assign, readonly) GFPNDAAdMuteState adMuteState;

@property (nonatomic, strong) GFPVideoOptions *videoOptions;
@property (nonatomic, strong) GFPAutoPlayInfo *autoPlayInfo;

- (instancetype)initWithNativeAdInfo:(GFPNativeAdInfo *)nativeAdInfo
                     skAdNetworkInfo:(GFPSKAdNetworkInfo *)skNetworkInfo
                            skipInfo:(GFPAdSkipInfo *)skipInfo
                        adChoiceInfo:(GFPAdChoiceInfo *)adChoiceInfo
                     vastMaxRedirect:(NSNumber *)vastMaxRedirect
                             context:(GFPNativeContext *)context;

- (void)loadAd;

- (void)registerViewWith:(GFPNativeBaseView *)nativeAdView error:(GFPError **)error;
- (void)unregisterView;

- (void)updateLayout:(GFPNDAMediaView *)aMediaView nativeView:(UIView *)nativeView;
- (void)updateMediaAssetsWith:(UIView *)targetView;
- (void)updateAdMuteStateWith:(GFPNDAAdMuteState)adMuteState;

- (void)nativeAdDidLoad;
- (void)nativeAdDidFailWithError:(GFPError *)error;

- (void)layoutBackgroundView:(GFPNativeBaseView *)nativeAdView mediaView:(GFPNDAMediaView *)mediaView;
- (void)layoutMediaViews;

- (void)adPrivacyOpenLanding;

- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;

- (void)clearForMemoryWarning;
- (BOOL)isReloadRequired;
- (void)reloadMediaResource;


//for link
- (void)tapGestureWith:(GFPNDANativeTapGesture *)gesture;
- (void)tryLandingWith:(GFPNDANativeTapGesture *)gesture;
@end
