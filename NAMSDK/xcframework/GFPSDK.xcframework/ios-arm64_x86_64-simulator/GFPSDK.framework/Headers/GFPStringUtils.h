//
//  GFPStringUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPStringUtils : NSObject

+ (BOOL)isValidUDID:(NSString *)adID;

+ (NSString *)whiteSpaceTrimWith:(NSString *)aString;

+ (BOOL)hasLengthWhiteSpaceTimeWith:(NSString *)aString;

+ (BOOL)isEmptyWith:(NSString *)aString;

+ (NSString *)encodeByAddingPercentEscapesWith:(NSString*)string;

+ (NSDictionary *)queryComponentsWith:(NSString *)aString;

+ (BOOL)isValidTimeOrPercentFormatString:(NSString *)percentString;

+ (BOOL)isValidTimeFormatString:(NSString *)percentString;

+ (BOOL)isValidPercentFormatString:(NSString *)percentString;

+ (NSString *)whiteSpaceTrim:(NSString *)aString;

+ (NSString *)whiteSpaceNewLineTrim:(NSString *)aString;

+ (BOOL)hasLengthWhiteSpaceTime:(NSString *)aString;

+ (NSString *)filterJsonStringWith:(NSDictionary *)dictionary;

+ (BOOL)hasHttpPrefix:(NSString * _Nonnull)url;

+ (NSString *)jsonStringWith:(NSDictionary *)dictionary;

+ (NSString *)convertWith:(id)object;

@end

NS_ASSUME_NONNULL_END
