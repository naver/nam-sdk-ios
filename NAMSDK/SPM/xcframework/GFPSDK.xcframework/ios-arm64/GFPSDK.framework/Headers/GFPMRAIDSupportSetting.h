//
//  GFPMRAIDSupportSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GFPMraidSupportType) {
    GFPMraidSupportNone         = 0,
    GFPMraidSupportSMS          = 1 << 0,
    GFPMraidSupportTel          = 1 << 1,
    GFPMraidSupportCalendar     = 1 << 2,
    GFPMraidSupportInlineVideo  = 1 << 3,
    GFPMraidSupportPicture      = 1 << 4,
    GFPMraidSupportLocation     = 1 << 5,
    GFPMraidSupportVPAID        = 1 << 6,
    GFPMraidSupportDefault      = 1 << 7
};

@interface GFPMRAIDSupportSetting : NSObject

+ (void) updateTypes:(GFPMraidSupportType) types;

+ (BOOL) supportsSMS;
+ (BOOL) supportsTel;
+ (BOOL) supportsCalendar;
+ (BOOL) supportsInlineVideo;
+ (BOOL) supportsStorePicture;
+ (BOOL) supportsLocation;
+ (BOOL) supportsVPAID;

@end

NS_ASSUME_NONNULL_END
