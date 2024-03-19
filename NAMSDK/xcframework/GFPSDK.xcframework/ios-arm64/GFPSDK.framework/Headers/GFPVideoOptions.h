//
//  GFPVideoOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

@class GFPQoeTrackingInfo;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPVideoPlayPolicy) {
    GFPVideoPlayPolicyManual = 1,
    GFPVideoPlayPolicyAutoPlay = 2,
    GFPVideoPlayPolicyAutoPlayOnlyWiFi = 3,
};


typedef NS_OPTIONS(NSInteger, GFPVideoViewType) {
    GFPVideoViewTypeDefault,
    GFPVideoViewTypeLanding,
};


@interface GFPVideoGlobalOptions : NSObject

/**
 * 광고 자동 재생 비활성화 전역 설정 (기본값 NO)
 * 단, S2S 아웃스트림 광고에 한해 useGlobalOptions이 활성화 되었을 경우 적용됩니다.
 *
 * - YES: YES로 설정 시 재생되는 광고가 정지하며, 재생 조건 도달 시에도 광고를 재생시키지 않습니다.
 * - NO: NO로 설정 시 재생 조건 도달 시 광고를 재생합니다.
 */
@property (class, nonatomic, assign) BOOL disableAutoPlayback;

/**
 * 광고 자동 재생 정책 전역 설정 (기본값 Auto)
 * 단, S2S 아웃스트림 광고에 한해 useGlobalOptions이 활성화 되었을 경우 적용됩니다.
 *
 * - Auto: 네트워크가 WiFi, Cellular 일 때 영상 끝까지 재생됩니다.
 * - Auto Only WiFi: 네트워크가 WiFi 일 때 영상 끝까지 재생됩니다. Cellular의 경우 n초 재생 후 정지합니다.
 * - Manual: 광고 노출 시 영상이 일시정지 상태에서 노출됩니다. 재생 시점은 서비스에서 결정합니다.
 */
@property (class, nonatomic, assign) GFPVideoPlayPolicy globalPlayPolicy;

@end


@interface GFPVideoOptions : NSObject

/**
 * 광고 영상의 재생 정책을 설정합니다. (기본값 Auto)
 *
 * - Auto: 네트워크가 WiFi, Cellular 일 때 영상 끝까지 재생됩니다.
 * - Auto Only WiFi: 네트워크가 WiFi 일 때 영상 끝까지 재생됩니다. Cellular의 경우 n초 재생 후 정지합니다.
 * - Manual: 광고 노출 시 영상이 일시정지 상태에서 노출됩니다. 재생 시점은 서비스에서 결정합니다.
 */
@property (nonatomic, readonly, assign) GFPVideoPlayPolicy playPolicy;

/**
 * 광고 영상의 view type 을 설정합니다.
 * - Default: 영상 화면 클릭 시 컨트롤 버튼이 노출됩니다.
 * - Landing: 영상 화면 클릭 시 광고주 사이트로 랜딩 됩니다.
 */
@property (nonatomic, readonly, assign) GFPVideoViewType viewType;

/**
 * 광고 영상의 Custom Control View 사용 여부를 설정합니다. (기본값 false)
 * true로 설정 시 control 구성 요소를 숨기며, false로 설정 시 sdk 내에서 control 구성 요소를 그려줍니다.
 */
@property (nonatomic, readonly, assign) BOOL useCustomControlView;

/**
 * 광고영상의 최대 bitrate (kbit/sec) (기본값 800)
 * 입력값 보다 낮은 bitrate 광고영상 중 가장 높은 bitrate 영샹이 채택되며,
 * 입력값 보다 낮은 bitrate 영상이 없는 경우 가장 가까운 bitrate 영샹이 재생됩니다.
 */
@property (nonatomic, assign) NSInteger maxBitrateKbps;


/**
 * 광고 영상의 전역 설정 사용 여부를 조회합니다.
 */
@property (nonatomic, readonly, assign) BOOL useGlobalOptions;


/**
 * 광고 영상의 qoe 로깅을 위해 정보를 전달합니다.
 */
@property (nonatomic, strong, nullable) GFPQoeTrackingInfo *qoeTrackingInfo;


+ (instancetype)createGlobalOptionsWithViewType:(GFPVideoViewType)viewType;
+ (instancetype)createGlobalOptionsWithUseCustomControlView:(BOOL)useCustomControlView;
+ (instancetype)createGlobalOptionsWithViewType:(GFPVideoViewType)viewType useCustonControlView:(BOOL)useCustomControlView;

- (instancetype)initWithPlayPolicy:(GFPVideoPlayPolicy)playPolicy viewType:(GFPVideoViewType)viewType;
- (instancetype)initWithPlayPolicy:(GFPVideoPlayPolicy)playPolicy useCustomControlView:(BOOL)useCustomControlView;
- (instancetype)initWithPlayPolicy:(GFPVideoPlayPolicy)playPolicy viewType:(GFPVideoViewType)viewType useCustomControlView:(BOOL)useCustomControlView;

@end

NS_ASSUME_NONNULL_END
