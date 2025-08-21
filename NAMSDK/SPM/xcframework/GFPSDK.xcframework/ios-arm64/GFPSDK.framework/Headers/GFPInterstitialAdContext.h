//
//  GFPInterstitialAdContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPContext.h"

@class GFPOMFriendlyObstruction;

NS_ASSUME_NONNULL_BEGIN

@interface GFPInterstitialAdContext : GFPContext

@property (nonatomic, strong) NSString *productType;
@property (nonatomic, strong, nullable) NSArray <GFPOMFriendlyObstruction *> *omFriendlyObstructions;


- (instancetype)initWithProductType:(NSString *)productType logId:(NSUUID *)logId;

@end

NS_ASSUME_NONNULL_END
