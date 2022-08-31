//
//  GFPNetworkUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPNetworkUtils : NSObject

@property (class, nonatomic, readonly) GFPNetworkUtils *sharedInstance;

+ (BOOL)isWIFI;

+ (NSString *)networkTypeDescForInit;
+ (NSString *)networkTypeDescForAdcall;

@end

NS_ASSUME_NONNULL_END
