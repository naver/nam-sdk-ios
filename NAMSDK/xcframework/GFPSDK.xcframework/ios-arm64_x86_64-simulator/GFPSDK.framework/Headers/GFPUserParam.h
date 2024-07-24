//
//  GFPUserParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GFPUserParamGenderType) {
    GFPUserParamGenderTypeMale = 1,   // 성별 - 남자
    GFPUserParamGenderTypeFemale = 2, // 성별 - 여자
    GFPUserParamGenderTypeOther = 3 , // 성별 - 모름
};

@interface GFPUserParam: NSObject

/**
 * 성별
 */
@property (nonatomic, assign) GFPUserParamGenderType gender;

/**
 * 출생년도 ex) 1990
 */
@property (nonatomic, assign) NSUInteger yearOfBirth;

/**
 * 국가코드 ex) EN,KO
 */
@property (nonatomic, copy, nullable) NSString *userCountryCode;

/**
 * 서비스내 유저 식별 값
 */
@property (nonatomic, copy, nullable) NSString *userID;

/**
 * 타겟팅 광고를 위한 contentId 값
 */
@property (nonatomic, copy, nullable) NSString *contentId;

@end


NS_ASSUME_NONNULL_END
