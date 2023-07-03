//
//  GFPRewardedAdContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPRewardedAdContext : GFPContext

@property (nonatomic, strong) NSString *productType;

- (instancetype)initWithProductType:(NSString *)productType;
@end

NS_ASSUME_NONNULL_END
