//
//  GFPVideoEventDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

@class GFPVideoController;

typedef NS_OPTIONS(NSInteger, GFPControlButtonType) {
    GFPControlButtonTypePlay,
    GFPControlButtonTypePause,
    GFPControlButtonTypeRewind,
    GFPControlButtonTypeAudio,
};

@protocol GFPVideoEventDelegate <NSObject>

/**
 * 네이티브 광고 영상 재생 시 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 */
- (void)adPlayerDidPlay:(GFPVideoController *)videoController;

/**
 * 네이티브 광고 영상 정지 시 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 */
- (void)adPlayerDidPause:(GFPVideoController *)videoController;

/**
 * 네이티브 광고 영상 재생 완료 시 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 */
- (void)adPlayerDidComplete:(GFPVideoController *)videoController;

/**
 * 네이티브 광고 영상 플레이어에 mute  상태가 변경 될 때 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 */
- (void)adPlayerDidChangeMuteState:(GFPVideoController *)videoController;

/**
 * 네이티브 광고 영상의 현재 진행률 변경 시 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 * @param currentTime 진행 시간
 */
- (void)adPlayer:(GFPVideoController *)videoController didChangeCurrentTime:(NSTimeInterval)currentTime;

/**
 * 네이티브 광고 영상의 버퍼 진행률 변경 시 호출됩니다.
 * @param videoController 네이티브 비디오 컨트롤 객체
 * @param bufferedTime 버퍼 시간
 */
- (void)adPlayer:(GFPVideoController *)videoController didChangeBufferedTime:(NSTimeInterval)bufferedTime;


@optional

/**
 * 네이티브 광고 영상의 control 버튼 클릭 시 호출 됩니다.
 * sdk에서 제공하는 default controlView 사용시 호출되며,  customControlView 사용시 호출되지 않습니다.
 * @param buttonType control 버튼 타입
 */
- (void)adPlayer:(GFPVideoController *)videoController didTappedControlButton:(GFPControlButtonType)buttonType;

@end
