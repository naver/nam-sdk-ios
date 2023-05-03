//
//  GFPEventExtraInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPProvider.h"



NS_ASSUME_NONNULL_BEGIN

extern NSString * const kGFPEventExtraInfoSize;
extern NSString * const kGFPEventExtraInfoPremium;


@interface GFPEventExtraInfo : NSObject


@property (nonatomic, readonly, strong) GFPProviderCreativeType creativeType;
@property (nonatomic, readonly, strong) NSDictionary *dict;

@property (nonatomic, readonly, strong) NSString *sizeDescription;
@property (nonatomic, readonly, strong) NSString *premiumDescription;


- (instancetype)initWithCreativeType:(GFPProviderCreativeType)aCreativeType;
- (instancetype)initWithCreativeType:(GFPProviderCreativeType)aCreativeType dictionary:(NSDictionary *_Nullable)aDict;


@end

NS_ASSUME_NONNULL_END
