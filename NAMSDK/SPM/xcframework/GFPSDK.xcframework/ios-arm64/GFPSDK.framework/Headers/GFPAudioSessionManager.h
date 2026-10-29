//
//  GFPAudioSessionManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GFPAudioSessionManager;

@protocol GFPAudioSessionManagerDelegate <NSObject>
@optional
/**
 * SDK 광고 영상이 unmute 상태로 재생되어 다른 앱의 오디오를 중단시키기 직전에 호출됩니다.
 * 앱 자체 오디오(TTS, 배경음 등)를 일시 정지해야 하는 경우 이 시점을 사용합니다.
 */
- (void)audioSessionManagerWillPlayAudio:(GFPAudioSessionManager *)manager;

/**
 * unmute 재생을 포함한 SDK 광고 영상 재생이 모두 종료되어 오디오세션을 관리 시작 전 상태로 복원한 뒤 호출됩니다.
 * 앱 자체 오디오를 재개할 시점으로 사용합니다.
 */
- (void)audioSessionManagerDidStopPlayingAudio:(GFPAudioSessionManager *)manager;
@end

/**
 * 아웃스트림(네이티브/리치/리워드/인터스티셜) 광고 영상 재생 구간의 AVAudioSession 카테고리를 SDK가 관리합니다.
 * `GFPAdConfiguration.manageAudioSession` 이 YES 인 경우에만 동작합니다. (기본 NO)
 *
 * 동시에 여러 광고 영상이 재생되는 경우 전체 상태를 집계하여 하나의 카테고리를 결정합니다.
 *  - 재생 중인 모든 영상이 muted: AVAudioSessionCategoryAmbient (다른 앱 오디오와 공존)
 *  - 하나라도 unmuted: AVAudioSessionCategorySoloAmbient (광고 사운드 단독 출력, 무음 스위치 준수)
 *  - 모든 영상 정지: 관리 시작 전 카테고리로 복원하고, 광고로 인해 중단된 다른 앱 오디오가 재개되도록 통보
 *
 * 제약: 재생 중 unmute → mute 로 되돌린 경우 카테고리는 Ambient 로 전환되지만, 재생이 끝나기 전까지는
 * 세션을 반납할 수 없어 이미 중단된 다른 앱 오디오는 재생 종료 시점에 재개됩니다.
 */
@interface GFPAudioSessionManager : NSObject

@property (class, readonly, nonatomic) GFPAudioSessionManager *sharedInstance;

@property (nonatomic, weak, nullable) id <GFPAudioSessionManagerDelegate> delegate;

/**
 * SDK가 현재 오디오세션 카테고리를 변경해 둔 상태인지 여부
 */
@property (nonatomic, readonly, getter=isManagingSession) BOOL managingSession;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
