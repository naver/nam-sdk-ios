//
//  GFPLocationData.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

// 밀리초 변환 상수
FOUNDATION_EXPORT const long long kGFPLocationMSPerSecond;

// GPS 포인트 JSON 키
FOUNDATION_EXPORT NSString * const kGPSPointKeyProvider;
FOUNDATION_EXPORT NSString * const kGPSPointKeyTimestamp;
FOUNDATION_EXPORT NSString * const kGPSPointKeyLongitude;
FOUNDATION_EXPORT NSString * const kGPSPointKeyLatitude;
FOUNDATION_EXPORT NSString * const kGPSPointKeyAccuracy;

/**
 * GPS 위치 정보를 나타내는 클래스
 */
@interface GFPGPSPoint : NSObject

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, assign) double longitude;
@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double accuracy;
@property (nonatomic, strong) NSString *provider;  // 위치 제공자 (예: "IGps", "GPS", "Network")

- (instancetype)initWithLocation:(CLLocation *)location;
- (NSDictionary *)toDictionary;

@end

/**
 * WiFi Access Point 정보를 나타내는 클래스
 * iOS에서는 WiFi AP 정보 수집이 불가능하므로 향후 확장을 위한 구조체
 */
@interface GFPAccessPoint : NSObject

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, strong) NSString *bssid;
@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, assign) NSInteger frequency;  // iOS에서는 -1 (수집 불가)
@property (nonatomic, assign) NSInteger rssi;       // iOS에서는 -999 (수집 불가)

- (instancetype)init;
- (NSDictionary *)toDictionary;

@end

/**
 * 위치 수집용 디바이스 정보를 나타내는 클래스
 */
@interface GFPLocationDeviceInfo : NSObject

@property (nonatomic, strong) NSString *deviceId;
@property (nonatomic, strong) NSString *caller;  // 호출자 식별자 (예: "gfp-sdk")

- (NSDictionary *)toDictionary;

@end

/**
 * 위치 데이터 전체를 포함하는 메인 클래스
 */
@interface GFPLocationData : NSObject

@property (nonatomic, strong) GFPLocationDeviceInfo *info;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, strong) NSMutableArray<GFPGPSPoint *> *gpsPoints;
@property (nonatomic, strong) NSMutableArray<GFPAccessPoint *> *accessPoints;
@property (nonatomic, strong) NSDictionary *keyValues;  // 추가 메타데이터 (sdk_version 등)

- (instancetype)initWithDeviceId:(NSString *)deviceId;
- (void)addGPSPoint:(GFPGPSPoint *)gpsPoint;
- (void)addAccessPoint:(GFPAccessPoint *)accessPoint;
- (NSDictionary *)toDictionary;
- (NSData *)toJSONData;

@end

NS_ASSUME_NONNULL_END
