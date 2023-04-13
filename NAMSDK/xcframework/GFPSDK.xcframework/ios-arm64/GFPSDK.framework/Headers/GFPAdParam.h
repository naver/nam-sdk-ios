//
//  GFPAdParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAPSAdParam;
@class GFPContentInfo;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GFPAdParamGenderType) {
    GFPAdParamGenderTypeMale = 1,   // 성별 - 남자
    GFPAdParamGenderTypeFemale = 2, // 성별 - 여자
    GFPAdParamGenderTypeOther = 3,  // 성별 - 모름
};

@interface GFPAdParam : NSObject
/**
 * 출생년도 ex) 1990
 */
@property (nonatomic, assign) NSUInteger yearOfBirth;

/**
 * 성별코드
 */
@property (nonatomic, assign) GFPAdParamGenderType gender;

/**
 * 지역코드 ex) EN,KO
 */
@property (nonatomic, copy, nullable) NSString *userCountryCode;

/**
 * 현재 페이지를 나타내는 url
 */
@property (nonatomic, copy, nullable) NSString *currentPageUrl;

/**
 * 현재 컨텐츠를 설명하는 키워드 목록
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *keywords;

/**
 * referrer url
 */
@property (nonatomic, copy, nullable) NSString *referrerPageUrl;

/**
 * 서비스내 유저 식별 값
 */
@property (nonatomic, copy, nullable) NSString *userID;

/**
 * opt-out (0: 미설정, 1: 설정)
 */
@property (nonatomic, copy, nullable) NSNumber *optOut;


/**
 * 추가 파라미터 (주의! 추가 파라미터 사전의 키/값은 모두 문자열 타입이어야 합니다.)
 */
@property (nonatomic, copy, nullable) NSDictionary <NSString *, NSString *> *customUserParam;


/**
 * PrebidMobile 헤더 비딩 파라미터 (주의! Dictionary 의 Key/Value는 모두 문자열 타입이어야 합니다.)
 */
@property (readwrite, nonatomic, copy, nullable) NSDictionary <NSString *, NSString *> *prebidHBParam;

/**
 * Amazon  헤더 비딩 파라미터.
 */
@property (readwrite, nonatomic, nullable) GFPAPSAdParam *apsParam;

/**
 * Communication Ad 용 Content Info.
 */
@property (readwrite, nonatomic, nullable) GFPContentInfo *contentInfo;

@end

NS_ASSUME_NONNULL_END
