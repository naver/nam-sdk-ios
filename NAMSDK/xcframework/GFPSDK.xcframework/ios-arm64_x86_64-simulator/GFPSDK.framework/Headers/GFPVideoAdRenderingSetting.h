//
//  GFPVideoAdRenderingSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT const NSInteger GFPVideoAdRenderingSettingAutodetectBitrate;
FOUNDATION_EXPORT const NSTimeInterval GFPVideoAdRenderingSettingDefaultStartTimeout;
FOUNDATION_EXPORT const NSTimeInterval GFPVideoAdRenderingSettingDefaultBufferingTimeout;

@interface GFPVideoAdRenderingSetting : NSObject

/**
 * 광고영상의 최대 bitrate (kbit/sec)
 * 입력값 보다 낮은 bitrate 광고영상 중 가장 높은 bitrate 영샹이 채택되며,
 * 입력값 보다 낮은 bitrate 영상이 없는 경우 가장 가까운 bitrate 영샹이 재생됩니다.
 * 기본값(GFPVideoAdRenderingSettingAutodetectBitrate)인 경우,s
 * WIFI 사용중에는 최대, Cellular 환경에서는 최소 bitrate 영샹이 재생됩니다.
 */
@property(readwrite, nonatomic, assign) NSInteger bitrateKbps;

/**
 * 광고영상의 MIME type 목록
 * 기본값(=nil or Empty)은, AVPlayer 에서 지원하는 모든 타입이 허용됩니다.
 * 명시한 MIME type에 해당하는 영상 URL이 서버로부터 제공되지 않으면, 광고로드시 Error 가 송출됩니다.
 */
@property(readwrite, nonatomic, copy, nullable) NSArray<NSString *> *mimeTypes;

/**
 * 광고 시작요청 이후 실제 시작 시점까지 타임아웃 (기본값은 -1 이며, 이 경우 타임아웃 5초가 적용 됩니다.)
 */
@property(readwrite, nonatomic, assign) NSTimeInterval startTimeoutInterval;

/**
 * 재생도중 버퍼링이 발생한 경우, 설정된 시간을 초과하면 타임아웃 에러가 발생합니다. (기본값은 -1 이며, 이 경우 타임아웃이 적용되지 않습니다.)
 */
@property(readwrite, nonatomic, assign) NSTimeInterval bufferingTimeoutInterval;

/**
 * 광고 UI 컴포넌트를 그릴 때 기준을 설정합니다. (기본값은 false)
 * false: GFPVideoAdScheduleManager.videoView 혹은 GFPVideoAdmanager.videoView 의 너비에 따라 컴포넌트를 그림.
 * true: 광고 영상의 실제 width 에 따라 컴포넌트를 그림.
 */
@property(readwrite, nonatomic, assign) BOOL isPreferContentWidthUI;

@end


NS_ASSUME_NONNULL_END
