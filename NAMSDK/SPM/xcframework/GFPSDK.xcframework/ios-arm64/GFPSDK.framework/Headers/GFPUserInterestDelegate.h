//
//  GFPUserInterestDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	
#import <Foundation/Foundation.h>

@protocol GFPUserInterestDelegate <NSObject>

- (void)ad:(NSObject *)ad didChangeUserInterest:(BOOL)userInterest;

@end
