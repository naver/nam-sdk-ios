//
//  GFPNDAVideoAdManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>

@protocol GFPNDAVideoAdManagerDelegate;

@class AVPlayerItemAccessLog;
@class GFPNDAVideoAdEvent;
@class GFPNDAVast;
@class GFPVideoContext;
@class GFPAdSkipInfo;
@class GFPSKAdNetworkInfo;
@class GFPAdChoiceInfo;
@class GFPVideoAdPlayerSetting;
@class GFPVideoAdRenderingSetting;
@class GFPVideoAdQoeBaseInfo;
@class GFPVideoAdQoePlayerInfo;
@class GFPNDAVideoExtraInfo;
@class GFPVideoDisplayMode;
@class GFPError;

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS(NSInteger, GFPNDAAutoPlayStatus) {
    GFPNDAAutoPlayNone = 0,
    GFPNDAAutoPlayLanding = 1,
    GFPNDAAutoPlayPause = 2,
    GFPNDAAutoPlayResume = 3,
    GFPNDAAutoPlayBackground = 4,
    GFPNDAAutoPlayForeground = 5,
};


@interface GFPNDAVideoAdManager : NSObject

@property (nonatomic, weak) id <GFPNDAVideoAdManagerDelegate> delegate;
@property (readonly, nonatomic, strong) GFPNDAVideoExtraInfo *extraInfo;
@property (readonly, nonatomic, strong) GFPVideoAdQoeBaseInfo *baseInfo;
@property (readonly, nonatomic, strong) GFPVideoAdQoePlayerInfo *playerInfo;

@property (nonatomic, assign) float volume;
@property (nonatomic, strong, nullable) GFPVideoAdPlayerSetting *playerSetting;
@property (nonatomic, strong) GFPVideoDisplayMode *displayMode;

@property (nonatomic, readonly, assign) BOOL enableAttached;

- (instancetype)initManagerWithVastXML:(NSString *)vastXMLString
                       vastMaxRedirect:(NSNumber *)vastMaxRedirect
                              skipInfo:(GFPAdSkipInfo * _Nullable)skipInfo
                           skAdNetwork:(GFPSKAdNetworkInfo *)skAdNetwork
                          adChoiceInfo:(GFPAdChoiceInfo *_Nullable)adChoiceInfo
                          videoContext:(GFPVideoContext *)videoContext;

- (void)load;
- (void)start;
- (void)pauseWith:(BOOL)isUserAction;
- (void)resumeWith:(BOOL)isUserAction;
- (void)destroy;

- (void)showOverlay;
- (void)hideOverlay;

- (IBAction)skipButtonTapped:(id _Nullable)sender;
- (IBAction)moreButtonTapped:(id _Nullable)sender;

@end


// MARK: - GFPNDAVideoAdManagerDelegate
@protocol GFPNDAVideoAdManagerDelegate <NSObject>

- (void)videoAdManagerLoaded:(GFPNDAVideoAdManager *)manager withError:(GFPError * _Nullable)error;

- (void)videoAdManager:(GFPNDAVideoAdManager *)manager didRecieveAdEvent:(GFPNDAVideoAdEvent *)event;

- (void)videoAdManager:(GFPNDAVideoAdManager *)manager didRecieveAdError:(GFPError *)error;

- (void)videoAdManager:(GFPNDAVideoAdManager *)manager didReceiveAccessLog:(AVPlayerItemAccessLog *)accessLog;

- (void)videoAdManagerAdPlaybackReady:(GFPNDAVideoAdManager *)manager;

- (void)videoAdManagerDidStartBuffering:(GFPNDAVideoAdManager *)manager;

- (void)videoAdManager:(GFPNDAVideoAdManager *)manager
  didChangeCurrentTime:(NSTimeInterval)mediaTime
             totalTime:(NSTimeInterval)totalTime;

- (void)videoAdManagerCanBeSkipAd:(GFPNDAVideoAdManager *)manager;

@optional
- (void)videoAdManager:(GFPNDAVideoAdManager *)manager playControlWillShow:(NSTimeInterval)duration;
- (void)videoAdManager:(GFPNDAVideoAdManager *)manager playControlWillHide:(NSTimeInterval)duration;

- (void)videoAdManagerDidPresentDefaultInAppBrowser:(GFPNDAVideoAdManager *)manager;
- (void)videoAdManagerDidDismissDefaultInAppBrowser:(GFPNDAVideoAdManager *)manager;

@end

NS_ASSUME_NONNULL_END
