//
//  GFPExceptionUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPExceptionUtils : NSObject

/**
 * A function to catch NSException in swift.
 */

+ (BOOL)catchException:(void(^)(void))tryBlock error:(NSError *_Nullable*_Nullable)error;

@end

NS_ASSUME_NONNULL_END
