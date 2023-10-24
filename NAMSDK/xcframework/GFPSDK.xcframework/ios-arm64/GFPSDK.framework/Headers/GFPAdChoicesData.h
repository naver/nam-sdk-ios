//
//  GFPAdChoicesData.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

#import "GFPNativeLanguageType.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, GFPAdChoicesType) {
    GFPAdChoicesTypeNone = 0,
    GFPAdChoicesTypeAdMute,
    GFPAdChoicesTypePrivacy,
    GFPAdChoicesTypeOptOut, //AdMute + Privacy
};


@interface GFPAdMuteData : NSObject

@property (nonatomic, strong, readonly) NSArray <NSString *> *reasonCodes;

- (NSString * _Nullable)textWith:(NSString *)reasonCode;
- (NSString * _Nullable)textWith:(NSString *)reasonCode languageType:(GFPNativeLanguageType)languageType;

- (NSString * _Nullable)resourceIdWith:(NSString *)reasonCode;

- (void)reportClickWith:(NSString *)reasonCode;

@end


@interface GFPAdChoicesData : NSObject

@property (nonatomic, assign, readonly) GFPAdChoicesType type;

@property (nonatomic, strong, readonly, nullable) GFPAdMuteData *adMuteData;
@property (nonatomic, strong, readonly, nullable) NSURL *privacyUrl;

@end

NS_ASSUME_NONNULL_END
