//
//  GFPNDAPlayerControlViewDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAPlayerDelegate.h"
#import "GFPLanguageType.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAPlayerControlView;

@class GFPNDAPlayerControlView;
@class GFPNDAOutstreamControlView;
@class GFPNDAOutstreamContainerView;
@class GFPTrackingURLs;

@protocol GFPNDAOutstreamControlViewDelegate;

typedef NS_OPTIONS(NSUInteger , GFPNDALoadingOption) {
    GFPNDALoadingOptionNone = 0,
    GFPNDALoadingOptionStart = 1 << 0,
    GFPNDALoadingOptionBuffering = 1 << 1
};

typedef NS_OPTIONS(NSInteger, GFPNDAControlStatus) {
    GFPNDAControlStatusNone = 0,
    GFPNDAControlStatusStarted,
    GFPNDAControlStatusPause,
};

@protocol GFPNDAPlayerControlViewDelegate <NSObject>

- (void)playerControlView:(GFPNDAPlayerControlView *)controlView playButtonTapped:(UIButton *)sender;
- (void)playerControlView:(GFPNDAPlayerControlView *)controlView pauseButtonTapped:(UIButton *)sender;
- (void)playerControlView:(GFPNDAPlayerControlView *)controlView skipButtonTapped:(UIButton *)sender;
- (void)playerControlView:(GFPNDAPlayerControlView *)controlView keywordTapped:(GFPTrackingURLs *)tracking;
- (void)playerControlView:(GFPNDAPlayerControlView *)controlView landingTappedWithUrl:(NSString *)landingUrl;

@optional
- (void)playerControlView:(UIView *)controlView closeButtonTapped:(UIButton *)sender; //for pip
- (void)playerControlView:(UIView *)controlView returnButtonTapped:(UIButton *)sender; //for pip

- (void)playerControlView:(GFPNDAPlayerControlView *)controlView playControlWillShow:(CFTimeInterval)duration;
- (void)playerControlView:(GFPNDAPlayerControlView *)controlView playControlWillHide:(CFTimeInterval)duration;

- (void)playerControlView:(GFPNDAPlayerControlView *)controlView adChoicelandingTappedWithUrl:(NSString *)landingUrl;

@end

@protocol GFPNDAPlayerControlViewPresentable <NSObject>

@property (nonatomic, weak, nullable) id<GFPNDAPlayerControlViewDelegate> delegate;

@property (nonatomic, assign) CGFloat contentWidth;
@property (nonatomic, assign) BOOL isPreferContentWidthUI;

@property (nonatomic, readonly, assign) BOOL showSkipButton;

- (void)updateCurrentTime:(NSTimeInterval)currentTime;
- (void)showLoadingImageViewForType:(GFPNDALoadingOption)loadingType;
- (void)hideLoadingImageViewForType:(GFPNDALoadingOption)loadingType;
- (void)playerStatusChanged:(GFPNDAPlayerStatus)playerStatus;

- (void)showOverlay;
- (void)hideOverlay;

@end

NS_ASSUME_NONNULL_END
