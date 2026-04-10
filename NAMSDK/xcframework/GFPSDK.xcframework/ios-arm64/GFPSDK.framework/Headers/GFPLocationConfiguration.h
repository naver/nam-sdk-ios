//
//  GFPLocationConfiguration.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 위치 수집 설정을 관리하는 클래스
 */
@interface GFPLocationConfiguration : NSObject

/**
 * 위치 수집 활성화 여부
 */
@property (nonatomic, assign) BOOL isLocationCollectionEnabled;

/**
 * 수집 주기 (초 단위, 기본값: 300초 = 5분)
 */
@property (nonatomic, assign) NSTimeInterval collectionInterval;

/**
 * 국내 트래픽만 수집할지 여부
 */
@property (nonatomic, assign) BOOL isDomesticOnlyCollection;

/**
 * 개발 환경 서버 URL
 */
@property (nonatomic, strong) NSString *developmentBaseURL;

/**
 * 개발 환경 엔드포인트
 */
@property (nonatomic, strong) NSString *developmentEndpoint;

/**
 * 운영 환경 서버 URL
 */
@property (nonatomic, strong) NSString *productionBaseURL;

/**
 * 운영 환경 엔드포인트
 */
@property (nonatomic, strong) NSString *productionEndpoint;

/**
 * 싱글톤 인스턴스
 */
+ (instancetype)sharedConfiguration;

/**
 * 기본 설정으로 초기화
 */
- (void)setupDefaultConfiguration;

/**
 * 현재 환경에 맞는 서버 URL 반환 (GFPPhaseType 기준)
 */
- (NSString *)getCurrentBaseURL;

/**
 * 현재 환경에 맞는 엔드포인트 반환 (GFPPhaseType 기준)
 */
- (NSString *)getCurrentEndpoint;

/**
 * 현재 환경에 맞는 전체 URL 반환
 */
- (NSString *)getCurrentFullURL;

/**
 * 수집 주기 변경 (분 단위)
 * @param minutes 수집 주기 (분)
 */
- (void)setCollectionIntervalInMinutes:(NSInteger)minutes;

/**
 * 설정 유효성 검사
 * @return 설정이 유효한지 여부
 */
- (BOOL)isConfigurationValid;

/**
 * 설정 정보를 로그로 출력
 */
- (void)logCurrentConfiguration;

@end

NS_ASSUME_NONNULL_END
