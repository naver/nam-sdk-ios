//
//  GFPLocationLogger.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPLocationConfiguration.h"
#import "GFPLocationData.h"

@class GFPError;

NS_ASSUME_NONNULL_BEGIN

@class GFPLocationLogger;

/**
 * 위치 Logger 상태 델리게이트
 */
@protocol GFPLocationLoggerDelegate <NSObject>

@optional
- (void)locationLogger:(GFPLocationLogger *)logger didInitializeSuccessfully:(NSString *)deviceId;
- (void)locationLogger:(GFPLocationLogger *)logger didFailToInitialize:(GFPError *)error;
- (void)locationLogger:(GFPLocationLogger *)logger didSendLocationData:(GFPLocationData *)locationData;
- (void)locationLogger:(GFPLocationLogger *)logger didFailToSendLocationData:(GFPError *)error;

@end

/**
 * 네이버 앱 위치 정보 수집 Logger 메인 클래스
 * 위치 정보를 수집하여 지도앱 서버로 전송하는 기능을 제공합니다.
 */
@interface GFPLocationLogger : NSObject

@property (nonatomic, weak, nullable) id<GFPLocationLoggerDelegate> delegate;
@property (nonatomic, assign, readonly) BOOL isInitialized;
@property (nonatomic, assign, readonly) BOOL isCollectionActive;

/**
 * 싱글톤 인스턴스
 */
+ (instancetype)sharedLogger;

/**
 * Logger 초기화 (deviceId 자동 생성)
 * deviceId는 IDFA 우선, IDFA가 없으면 IDFV(기기 UUID) 사용
 * @param delegate 델리게이트
 */
- (void)initializeWithDelegate:(id<GFPLocationLoggerDelegate> _Nullable)delegate;

/**
 * Logger 초기화 (deviceId 직접 지정)
 * @param deviceId 디바이스 식별자
 * @param delegate 델리게이트
 */
- (void)initializeWithDeviceId:(NSString *)deviceId delegate:(id<GFPLocationLoggerDelegate> _Nullable)delegate;

/**
 * 위치 수집 시작
 */
- (void)startLocationCollection;

/**
 * 위치 수집 중지
 */
- (void)stopLocationCollection;

/**
 * 네이버 로그인 쿠키(NID_AUT, NID_SES)가 설정되었는지 확인
 * @return 쿠키 설정 여부
 */
- (BOOL)isCookieReady;

/**
 * 네이버 위치정보 약관 동의 여부 확인
 * @return 약관 동의 여부
 */
- (BOOL)isTermsAgreed;

/**
 * 저장된 위치 데이터를 서버로 벌크 전송
 * 쿠키가 설정되지 않은 경우 전송하지 않음
 */
- (void)sendBulkLocationData;


/**
 * 수집 주기 설정
 * @param minutes 수집 주기 (분 단위)
 */
- (void)setCollectionIntervalInMinutes:(NSInteger)minutes;

/**
 * 국내 트래픽만 수집할지 설정
 * @param domesticOnly 국내만 수집 여부
 */
- (void)setDomesticOnlyCollection:(BOOL)domesticOnly;

/**
 * 위치 수집 활성화/비활성화
 * @param enabled 활성화 여부
 */
- (void)setLocationCollectionEnabled:(BOOL)enabled;

/**
 * 커스텀 서버 URL 설정
 * @param baseURL 서버 기본 URL
 * @param endpoint API 엔드포인트
 */
- (void)setCustomServerURL:(NSString *)baseURL endpoint:(NSString *)endpoint;

/**
 * 현재 Logger 상태 정보 반환
 */
- (NSDictionary *)getLoggerStatus;

/**
 * 설정 정보 로그 출력
 */
- (void)logCurrentConfiguration;

@end

NS_ASSUME_NONNULL_END
