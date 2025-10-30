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
    
    GFPNDARichMediaViewVideoExtend = 102,
    GFPNDARichMediaViewCountdown = 103,
    GFPNDARichMediaViewImageExtend = 104,
    GFPNDARichMediaViewNewVideoExtend = 105,
    GFPNDARichMediaViewDragExtend = 106,
    GFPNDARichMediaViewNewVideoExtendV2 = 107,
    GFPNDARichMediaViewDoubleCrown = 108,
    GFPNDARichMediaViewVideoExtendV3 = 109,
    GFPNDARichMediaViewTripleCrown = 110,

    GFPNDARendererMediaViewShoppingLabel = 1000,
    GFPNDARendererMediaViewSmartChannelFlicking = 1001,
    GFPNDARendererMediaViewShoppingNDA = 1002,
    GFPNDARendererMediaViewSplash = 1003,
};

typedef NS_OPTIONS(NSInteger, GFPNDAMediaViewRenderType) {
    GFPNDAMediaViewRenderAdPrivacy = 0,
    GFPNDAMediaViewRenderAdMute = 1,
    GFPNDAMediaViewRenderElectionBadge = 2,
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

- (CGFloat)minimumSpecialDaRegionHeight;
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
@end

//For carousel
@protocol GFPNDAMediaAssetTouchDelegate <NSObject>

- (void) didClickAssetWith:(GFPNDANativeLandingTapGesture *)gesture slotIndex:(NSNumber *_Nullable)slotIndex;

@end

@interface GFPNDAMediaView : UIView <GFPAdBackgroundDataSource, GFPNDAMediaOverrideProtocol>

@property (nonatomic, weak) id <GFPNDAMediaViewDelegate> delegate;

@property (nonatomic, readonly, assign) GFPNDAMediaViewType type;
@property (nonatomic, readonly, strong) id <GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoExtensionPresentable> mediaInfo;

@property (nonatomic, readonly, assign) CGSize contentSize;

@property (nonatomic, readonly, assign) BOOL isLoaded;
@property (nonatomic, readonly, assign) BOOL isLandingEnable;

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

- (void)didPresentDefaultInAppBrowser;
- (void)didDismissDefaultInAppBrowser;
- (void)simpleViewChanged;
- (id)getExtraInfoWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
