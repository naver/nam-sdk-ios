//
//  GFPVideoAdScheduleManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <AVKit/AVKit.h>
#import <UIKit/UIKit.h>

#import "Swift-Enum.h"
#import "GFPAdScheduleParam.h"
#import "GFPAdvertiseParams.h"

#import "GFPVideoAdScheduleManagerDelegate.h"
#import "GFPNonLinearDelegate.h"

#import "GFPS2SAdClickDelegate.h"

#if __has_include("NAMSDK.h")
#import "NAMSDK.h"
#endif

@protocol GFPNonLinearDelegate;
@protocol GFPS2SAdClickDelegate;
@class GFPVideoAdRenderingSetting;
@class GFPVideoDisplayMode;
@class GFPVideoAdPlayerSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoAdScheduleManager : NSObject

@property (nonatomic, weak) id<GFPVideoAdScheduleManagerDelegate> delegate;
@property (nonatomic, weak) id<GFPVideoAdScheduleManagerQoeDelegate> qoeDelegate;
@property (nonatomic, weak) id<GFPVideoAdScheduleManagerPIPDelegate> pipDelegate;
@property (nonatomic, weak) id<GFPNonLinearDelegate> nonLinearDelegate;

// Readonly
@property (nonatomic, readonly, strong, nonnull) NSString *adScheduleID;
@property (nonatomic, readonly, strong) AVPlayer *contentPlayer;
@property (nonatomic, readonly, strong) UIView *videoView;

@property (nonatomic, readonly, strong) GFPAdScheduleParam *scheduleParam;

// Readwrite
@property (nonatomic, strong, nullable) GFPAdvertiseParams *advertiseParams;

@property (nonatomic, strong, nullable) GFPVideoAdRenderingSetting *renderingSetting;
@property (nonatomic, strong, nullable) GFPVideoAdPlayerSetting *playerSetting;
@property (nonatomic, strong, nullable) GFPVideoDisplayMode *displayMode;

@property (nonatomic, assign) NSTimeInterval playBufferInterval;

/*
 * 광고 볼륨  세팅 (Optional)
 * From 0 (muted) to 1 (loudest). Default value is 1.
 **/
@property (nonatomic, assign) float volume;


/**
 * 구글 광고 로드를 위해서는 필수 조건 (View hierachy가 있는 ViewController.)
*/
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

#if !NAMSDK
/**
 * s2s 광고 클릭 지원. delegate 설정 후 openURL:landingDelegate: 구현 시 클릭에 관한 커스톰 동작이 가능합니다.
 */
@property (nonatomic, weak, nullable) id <GFPS2SAdClickDelegate> s2sClickDelegate;
#endif


- (instancetype)initWithAdScheduleID:(NSString * _Nonnull)aAdScheduleID contentPlayer:(AVPlayer *)aContentPlayer videoView:(UIView *)aVideoView scheduleParam:(GFPAdScheduleParam *)aScheduleParam;

- (void)loadSchedule;

- (void)startWith:(BOOL)isNormal;

- (void)resume;
- (void)pause;
- (void)destroy;


/**
 * 광고의 Overlay(Seekbar, Pause, Resume, 선거 광고, 후광고 Text) 영역을 노출합니다.
 */
- (void)showOverlayView;


/**
 * 광고의 Overlay(Seekbar, Pause, Resume, 선거 광고, 후광고 Text) 영역을 사라지게 합니다.
 */
- (void)hideOverlayView;

/**
 * RemindAd(Banner, Text) 광고를 노출합니다.
 * ContainerType 없이 기본 위치에 노출. [배너 : Inner, 텍스트 : 가로 방향 (Inner), 세로 방향 (Outer)]
*/
- (void)showNonLinearAd;

/**
 * RemindAd(Banner, Text) 광고를 노출합니다.
 * @param type RemindText 광고를 Content 영역 노출 위치 결정 [내부(Inner) 또는 외부(Outer)].
 */
- (void)showNonLinearAd:(GFPNonLinearContainerType)type;

/**
 * RemindAd(Banner, Text) 광고를 사라지게 합니다.
 */
- (void)hideNonLinearAd;


/**
 * 광고 Skip 버튼 클릭을 원하는 경우, action 연결.
 */
- (IBAction)skipButtonTapped:(id)sender;


/**
 * 광고 더보기 버튼 클릭을 원하는 경우, action 연결.
 */
- (IBAction)moreButtonTapped:(id)sender;


/**
 * RemindAd(Banner, Text) outer 광고 컨테이너를 변경합니다.
 * @param textAdViewAttribute 새로 셋팅해 줄 containerViewAttribute
*/
- (void)replaceTextAdViewAttribute:(GFPTextAdViewAttribute *)textAdViewAttribute;


@end

NS_ASSUME_NONNULL_END
