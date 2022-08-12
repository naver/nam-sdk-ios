//
//  DTBAdResponse.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 10/4/15.
//  Copyright © 2015 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTBAdSize.h"

typedef enum {
    NETWORK_ERROR = 81,
    NETWORK_TIMEOUT,
    NO_FILL,
    INTERNAL_ERROR,
    REQUEST_ERROR
} DTBAdError;

@interface DTBAdResponse : NSObject

@property (nonatomic) NSString * _Nonnull bidId;

@property (nonatomic) BOOL isVideo;

@property NSDictionary * _Nonnull kvp;

@property NSDictionary * _Nullable skAdNetworkParams;

@property (nonatomic) NSArray * _Nullable clickTrackersArray;

- (void)addDTBPricePoint: (id _Nonnull) pp;

- (NSString * _Nullable)crid;

- (NSString * _Nonnull)hostname;

- (NSArray * _Nonnull)adSizes;

- (NSString * _Nullable)pricePoints:(DTBAdSize * _Nonnull)adSize __deprecated;

- (NSString * _Nonnull)defaultPricePoints __deprecated;

- (DTBAdSize * _Nonnull)adSize;

- (NSDictionary<NSString *, NSString *> * _Nullable)customTargeting;

- (NSString * _Nonnull)keywordsForMopub;

@end

