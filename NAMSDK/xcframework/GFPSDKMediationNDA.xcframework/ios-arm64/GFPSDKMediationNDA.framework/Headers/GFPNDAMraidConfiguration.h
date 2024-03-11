//
//  GFPNDAMraidConfiguration.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPNDAMRAIDUtil.h"

@class GFPAPSAdParam;
@class GFPSKAdNetworkInfo;

NS_ASSUME_NONNULL_BEGIN

static NSString *const kMraidAdTypeInline   = @"inline";
static NSString *const kMraidAdTypeInterstitial   = @"interstitial";

@interface GFPNDAMraidConfiguration : NSObject

- (instancetype)initParamWith:(GFPAPSAdParam *)apsParam adProviderName:(NSString *)adProviderName baseUrlInfo:(NSString *)publicsherInfo;

@property (nonatomic, readwrite, assign) GFPNDAMRAIDState  initialMRAIDState;
@property (nonatomic, readwrite, strong) NSString* adTypeForMRAID;

@property (nonatomic, readonly, strong, nullable) NSURL *baseURL;
@property (nonatomic, readonly, strong, nullable) GFPSKAdNetworkInfo *skAdNetworkInfo;

@property (nonatomic, readonly, assign) BOOL isRapidCheck;

@end

NS_ASSUME_NONNULL_END
