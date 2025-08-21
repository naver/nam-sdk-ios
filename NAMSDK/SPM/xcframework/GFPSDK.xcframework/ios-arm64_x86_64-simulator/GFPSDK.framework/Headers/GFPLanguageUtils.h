//
//  GFPLanguageUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

#import "GFPLanguageType.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPLanguageUtils : NSObject

+ (NSString * _Nullable)languageCodeWith:(GFPLanguageType)languageType;

@end

NS_ASSUME_NONNULL_END
