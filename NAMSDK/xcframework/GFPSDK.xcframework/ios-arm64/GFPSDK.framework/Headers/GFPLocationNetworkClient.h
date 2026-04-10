//
//  GFPLocationNetworkClient.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPLocationData.h"

@class GFPError;

NS_ASSUME_NONNULL_BEGIN

@class GFPLocationNetworkClient;

/**
 * 네트워크 전송 완료 콜백
 */
typedef void(^GFPLocationNetworkCompletionHandler)(BOOL success, GFPError * _Nullable error);

/**
 * 위치 데이터 전송을 위한 네트워크 클라이언트
 */
@interface GFPLocationNetworkClient : NSObject

/**
 * 싱글톤 인스턴스
 */
+ (instancetype)sharedClient;

/**
 * 위치 데이터를 서버로 전송
 * @param locationData 전송할 위치 데이터
 * @param adId 광고 식별자 (x-adid 헤더용)
 * @param completionHandler 전송 완료 콜백
 */
- (void)sendLocationData:(GFPLocationData *)locationData
                    adId:(NSString * _Nullable)adId
       completionHandler:(GFPLocationNetworkCompletionHandler)completionHandler;

/**
 * 위치 데이터를 Gzip 압축하여 서버로 전송 (테스트용)
 * @param locationData 전송할 위치 데이터
 * @param adId 광고 식별자 (x-adid 헤더용)
 * @param completionHandler 전송 완료 콜백
 */
- (void)sendLocationDataWithGzip:(GFPLocationData *)locationData
                            adId:(NSString * _Nullable)adId
               completionHandler:(GFPLocationNetworkCompletionHandler)completionHandler;

/**
 * HMAC Secret Key 설정 (초기화 API 응답의 extra.location.ki 에서 전달)
 * @param hmacKey 서버 환경에 맞는 HMAC Secret Key
 */
- (void)configureHMACKey:(NSString * _Nullable)hmacKey;

/**
 * 현재 설정된 서버 URL 반환
 */
- (NSString *)getCurrentServerURL;

@end

NS_ASSUME_NONNULL_END
