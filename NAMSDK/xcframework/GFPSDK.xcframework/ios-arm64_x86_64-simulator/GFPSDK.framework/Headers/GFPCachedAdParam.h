//
//  GFPCachedAdParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPCachedAdParam: NSObject

@property (nonatomic, copy, readwrite, nullable) NSString *nac;

+ (void)updateNac:(NSString *)nac;

@end

NS_ASSUME_NONNULL_END
