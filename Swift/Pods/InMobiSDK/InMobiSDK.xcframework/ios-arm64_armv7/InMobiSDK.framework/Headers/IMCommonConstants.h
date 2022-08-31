//
//  IMCommonConstants.h
//  iOS-SDK
//
//  Copyright (c) 2015 InMobi. All rights reserved.
//

#ifndef COMMONCONSTANTSINCLUEDE_H
#define COMMONCONSTANTSINCLUEDE_H

#import <UIKit/UIKit.h>

static NSString * const IM_GDPR_CONSENT_AVAILABLE = @"gdpr_consent_available";
static NSString * const IM_GDPR_CONSENT_IAB = @"gdpr_consent";
static NSString * const IM_SUBJECT_TO_GDPR = @"gdpr";
static NSString * const IM_PARTNER_GDPR_CONSENT_AVAILABLE = @"partner_gdpr_consent_available";
static NSString * const IM_PARTNER_GDPR_APPLIES = @"partner_gdpr_applies";

typedef NS_ENUM(NSInteger, IMSDKLogLevel) {
    kIMSDKLogLevelNone,
    kIMSDKLogLevelError,
    kIMSDKLogLevelDebug
};

/**
 * User Gender
 */
typedef NS_ENUM (NSInteger, IMSDKGender) {
    kIMSDKGenderMale = 1,
    kIMSDKGenderFemale
};

/**
 * User Education
 */
typedef NS_ENUM (NSInteger, IMSDKEducation) {
    kIMSDKEducationHighSchoolOrLess = 1,
    kIMSDKEducationCollegeOrGraduate,
    kIMSDKEducationPostGraduateOrAbove
};

typedef NS_ENUM(NSInteger, IMSDKAgeGroup) {
    kIMSDKAgeGroupBelow18 = 1,
    kIMSDKAgeGroupBetween18And24,
    kIMSDKAgeGroupBetween25And29,
    kIMSDKAgeGroupBetween30And34,
    kIMSDKAgeGroupBetween35And44,
    kIMSDKAgeGroupBetween45And54,
    kIMSDKAgeGroupBetween55And65,
    kIMSDKAgeGroupAbove65
};

#endif /* COMMONCONSTANTSINCLUEDE_H */
