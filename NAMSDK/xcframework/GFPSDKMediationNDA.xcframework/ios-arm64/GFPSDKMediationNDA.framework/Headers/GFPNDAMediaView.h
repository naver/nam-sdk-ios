//
//  GFPNDAMediaView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPNativeAdInfoProtocol.h"
#import "GFPNDAAdMuteView.h"
#import "GFPAdBackgroundInfo.h"
#import "GFPEventReporter.h"

@class GFPNativeMediaInfo;
@class GFPNativeRichInfo;
@class GFPMediaData;
@class GFPIconData;

@class GFPError;
@class GFPAdEventObject;
@class GFPNativeBaseView;
@class GFPNDAMediaViewRenderInfo;
@class GFPNDAMediaViewInfo;
@class GFPNDANativeLandingTapGesture;

static CGFloat const kRichAdStandardWidth = 360;
static CGFloat const kRichAdStandardImageWidth = 375;


/*
 * GFP Gravity Values
 * 0001 Left
 * 0010 Right
 * 0100 Top
 * 1000 Bottom
 * 0001 0000 Horizontal Center
 * 0010 0000 Vertical Center
 */
static NSInteger const kElectionBadgePositionLeftBottom = 0b1001;   // 9
static NSInteger const kElectionBadgePositionRightBottom = 0b1010;  // 10
static NSInteger const kElectionBadgePositionLeftTop = 0b0101;      // 5
static NSInteger const kElectionBadgePositionRightTop = 0b0110;     // 6

typedef NS_OPTIONS(NSInteger, GFPNDAMediaViewType) {
    GFPNDAMediaViewIcon = 0,
    GFPNDAMediaViewImage = 1,
    GFPNDAMediaViewVideo = 2,
    GFPNDAMediaViewCarousel = 3,
    GFPNDAMediaViewComplex = 4,
    GFPNDAMediaViewImageMotionScroll = 5,
    
    GFPNDARichMediaViewVideoExtend = 102,
    GFPNDARichMediaViewCountdown = 103,
    GFPNDARichMediaViewImageExtend = 104,
    GFPNDARichMediaViewNewVideoExtend = 105,
    GFPNDARichMediaViewDragExtend = 106,
    GFPNDARichMediaViewNewVideoExtendV2 = 107,
    GFPNDARichMediaViewDoubleCrown = 108,
    GFPNDARichMediaViewVideoExtendV3 = 109,
    GFPNDARichMediaViewTripleCrown = 110,
    GFPNDARichMediaViewImageExtendV3 = 111,
    GFPNDARichMediaViewNewVideoExtendV2Renewal = 112, // 동확플 V2 신규 디자인. 구 V2(107)와 별도 상품

    GFPNDARendererMediaViewShoppingLabel = 1000,
    GFPNDARendererMediaViewSmartChannelFlicking = 1001,
    GFPNDARendererMediaViewShoppingNDA = 1002,
    GFPNDARendererMediaViewSplash = 1003,
    GFPNDARendererMediaViewTravelSpecialDA = 1004,
    GFPNDARendererMediaViewSplashVideo = 1005,
    GFPNDARendererMediaViewShoppingLabelRetail = 1006,
    GFPNDARendererMediaViewSmartChannelSpecialDA = 1007,
};

typedef NS_OPTIONS(NSInteger, GFPNDAMediaViewRenderType) {
    GFPNDAMediaViewRenderAdPrivacy = 0,
    GFPNDAMediaViewRenderAdMute = 1,
    GFPNDAMediaViewRenderElectionBadge = 2,
    GFPNDAMediaViewRenderAdAIUsageBadge = 3,
};


NS_ASSUME_NONNULL_BEGIN


typedef void (^LoadCompletion)(NSError *_Nullable error);

@protocol GFPNDAMediaViewDelegate <NSObject>

@required
- (void)didLoadWith:(GFPNDAMediaViewType)aType;
- (void)didFailWith:(GFPNDAMediaViewType)aType error:(GFPError *)aError;

@optional
- (void)didChangeSize:(CGSize)size mediaViewType:(GFPNDAMediaViewType)type;
- (void)didClickWith:(GFPNDAMediaViewRenderType)aType event:(GFPAdEventObject * _Nullable)aEvent landingURL:(NSURL * _Nullable)url;
- (void)didAdMuteChangeWith:(GFPNDAAdMuteState)aState; //for NS Ad.
- (void)didAdMuteCanceled;
- (void)didReloadWith:(GFPNDAMediaViewType)aType;
- (void)didReloadFailWith:(GFPNDAMediaViewType)aType error:(GFPError *)aError;
- (void)didTappedLandingViewWith:(GFPNDAMediaViewType)aType landingUrl:(NSString *)landingUrl trackers:(NSArray <NSString *> *)trackers;
- (void)didRenderingFailWith:(GFPNDAMediaViewType)aType error:(GFPError *)aError;
- (void)didSlotRenderingFailWith:(GFPNDAMediaViewType)aType error:(GFPError *)aError;

- (void)didPresentDefaultInAppBrowser:(GFPNDAMediaViewType)aType;
- (void)didDismissDefaultInAppBrowser:(GFPNDAMediaViewType)aType;

- (void)registerGestureForExtraView:(UIView *)extraView linkInfo:(id<GFPNativeAdInfoLinkPresentable>)linkInfo;
- (CGFloat)minimumSpecialDaRegionHeight;

- (void)shouldCalculatePreferredHeight;

/// 렌더러가 그린 텍스트(POC 가격·혜택 티켓·고지)가 비동기로 바뀌어 단일 포커스 접근성 문구를 다시 만들어야 할 때.
- (void)didChangeAccessibilityContentWith:(GFPNDAMediaViewType)aType;

@end


@protocol GFPNDAMediaOverrideProtocol

/**
 * 각 미디어 뷰에서 필수적으로 구현해야 하는 메소드들.
 */
@required
- (void)loadNativeMedia;
- (void)createMediaData;

/**
 * 각 미디어 뷰에서 선택적으로 구현해야하는 메소드들.
 */
@optional
- (void)updateViewLayout;
- (void)updateInitialBgSetting;
/// 원본 미디어와 다른 표시 영역 비율이 필요한 미디어 뷰만 구현한다.
- (CGSize)preferredPresentationSizeWithMediaSize:(CGSize)mediaSize;

//for ns
- (void)updateViewWith:(GFPNativeBaseView *)nativeView renderInfo:(GFPNDAMediaViewRenderInfo *)renderInfo cropSize:(CGSize)cropSize;
- (void)updateFrame:(CGRect)frame contentMode:(UIViewContentMode)contentMode isPreferredImage:(BOOL)isImageSizePreferred;

//for rich video
- (BOOL)isVideoPlaying;
- (BOOL)isVideoMuted;

//for media cache
- (void)setMediaForRegister;
- (BOOL)isReloadRequired;
- (void)clearForUnregister;
- (void)clearForMemoryWarning;
- (void)reloadNativeMedia;
- (void)additionalRenderingViewClicked:(UIView *)clickedView;

//for deferred video lazy loading
- (BOOL)hasDeferredVideoLoad;
- (void)triggerDeferredVideoLoad;
@end

//For carousel
@protocol GFPNDAMediaAssetTouchDelegate <NSObject>

- (void) didClickAssetWith:(GFPNDANativeLandingTapGesture *)gesture slotIndex:(NSNumber *_Nullable)slotIndex;

@end

@interface GFPNDAMediaView : UIView <GFPAdBackgroundDataSource, GFPNDAMediaOverrideProtocol>

@property (nonatomic, weak) id <GFPNDAMediaViewDelegate> delegate;

@property (nonatomic, readonly, assign) GFPNDAMediaViewType type;
@property (nonatomic, readonly, strong) id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoMediaExtPresentable> mediaInfo;

@property (nonatomic, readonly, assign) CGSize contentSize;

@property (nonatomic, readonly, assign) BOOL isLoaded;
@property (nonatomic, readonly, assign) BOOL isLandingEnable;
/// VoiceOver 이중 탭에서 root link 랜딩이 isLandingEnable 로 막혔을 때, 미디어가 터치로 처리하던 자체 랜딩을 수행한다. 수행했으면 YES. 기본 구현은 NO (자체 랜딩 없음).
- (BOOL)performAccessibilityLanding;

@property (nonatomic, readonly, strong, nullable) GFPIconData *iconData;
@property (nonatomic, readonly, strong) GFPMediaData *mediaData;
@property (nonatomic, readonly, strong) NSString *alternativeText;

@property (nonatomic, readonly, strong) NSUUID *logId;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLogId:(NSUUID *)logId;

- (instancetype)initWithType:(GFPNDAMediaViewType)aType
                        info:(GFPNDAMediaViewInfo *_Nonnull)aInfo
                       logId:(NSUUID *)logId;

- (instancetype)initWithFrame:(CGRect)aFrame
                         type:(GFPNDAMediaViewType)aType
                         info:(GFPNDAMediaViewInfo *_Nonnull)aInfo
                        logId:(NSUUID *)logId;

- (UIView * _Nullable)touchView;

- (void)shrinkExtendedRichAd;
- (void)restoreRichAdLayout;
- (void)updateComplexMediaCornerRadius:(nullable NSNumber *)cornerRadius roundedCorners:(UIRectCorner)roundedCorners;

//register / unregister lifecycle hooks
- (void)postRenderingWith:(GFPNativeBaseView *)nativeAdView;
- (void)postUnregisterRendering;

//accessibility — 광고 단위 단일 포커스(NN)에서 광고 요소 다음에 각자 포커스를 받을 뷰
/// 미디어 안에서 자기 동작(랜딩·재생·슬라이드 등)이 있어 광고 전체 포커스와 분리해야 하는 뷰들. 순서대로 포커스를 받는다.
/// 이미지: AI 활용 배지(보이면 항상, 버튼 유형은 curl 있을 때만)·선거광고 배지 / 동영상·캐러셀: 미디어뷰 자신(컨테이너, 내부 컨트롤·슬롯을 VoiceOver 가 순회) / 기본: 없음.
- (NSArray<UIView *> *)accessibilitySeparateFocusViews;
/// AI 활용 배지가 실제로 그려져 있는지 (curl 무관) — 단일 포커스 문구의 "AI 활용" 접두어 판정용.
- (BOOL)hasVisibleAIUsageBadge;
/// 단일 포커스 문구에 메인 이미지(alt, 없으면 "광고 이미지")를 넣는 미디어인지. 이미지 계열만 YES, 동영상·캐러셀은 별도 포커스라 NO.
- (BOOL)accessibilityReadsMainImage;
/// 미디어 위에 SDK 가 그린 장식(POC 쿠폰·가격 등)의 화면 텍스트. 단일 포커스 문구에서 extraImage 뒤·CTA 앞에 읽힌다 (AOS 정합 2026-11-06). 기본 빈 배열.
- (NSArray<NSString *> *)accessibilityDecorationTexts;
/// 미디어가 그린 AdChoices(광고 옵션) 뷰. 단일 포커스에서 미디어 별도 포커스 뷰 다음 순서로 포커스를 받는다 (NS 전 상품, 2026-11). 기본 nil.
- (nullable UIView *)accessibilityAdChoiceView;
/// 선거광고 배지가 실제로 그려져 있는지 — 단일 포커스 문구의 "선거광고" 접두어 판정용(리치). 기본 NO.
- (BOOL)hasVisibleElectionBadge;

- (void)didPresentDefaultInAppBrowser;
- (void)didDismissDefaultInAppBrowser;
- (void)simpleViewChanged;
- (id)getExtraInfoWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
