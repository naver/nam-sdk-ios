//
//  GFPVideoAdPlayerSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS (NSInteger, GFPVideoAudioSettingType) {
    GFPVideoAudioSettingDefault = 1 << 0,   /* Audio unplug 시 광고 정지 (Default : AVPlayer 기본 동작) */
    GFPVideoAudioSettingAuto = 1 << 1,      /* Audio unplug : 광고 정지, Audio plug : 광고 재생 */
};


typedef NS_OPTIONS (NSInteger, GFPVideoBackgroundActionType) {
    GFPVideoBackgroundPause = 1 << 0,   /* Background 광고 Puase. (Default)*/
    GFPVideoBackgroundPlay = 1 << 1,    /* Background 광고 재생. */
};


@interface GFPVideoAdPlayerSetting : NSObject


/**
 * 광고 재생 도중 Background 진입 시 동작 option 처리. (Default는 Pause)
 */
@property (readwrite, nonatomic, assign) GFPVideoBackgroundActionType backAction;


/**
 * 광고 재생 도중 Audio output 관련 동작 정리. (Optional, Default는 AVPlayer 기본 동작)
 */
@property (readwrite, nonatomic, assign) GFPVideoAudioSettingType audioSetting;


- (instancetype)initWithAction:(GFPVideoBackgroundActionType)aAction;
- (instancetype)initWithAudioSetting:(GFPVideoAudioSettingType)aType;

- (instancetype)initWithAction:(GFPVideoBackgroundActionType)aAction audioSetting:(GFPVideoAudioSettingType)aType;


@end

NS_ASSUME_NONNULL_END
