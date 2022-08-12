//
//  DTBAdLoader.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 10/2/15.
//  Copyright © 2015 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTBAdSize.h"
#import "DTBAdCallback.h"

#define A9_BID_ID_KEY @"amzn_b"
#define A9_HOST_KEY @"amzn_h"
#define A9_PRICE_POINTS_KEY @"amznslots"
#define A9_VID_KEY @"amzn_vid"
#define A9_SKADN_KEY @"amzn_skadn"

@interface DTBAdLoader : NSObject

@property (nonatomic)NSString * _Nullable slotGroup;

- (void)setSizes:(DTBAdSize * _Nonnull)size,... NS_REQUIRES_NIL_TERMINATION;

- (void)setAdSizes:(NSArray * _Nonnull)adSizes;

- (void)putCustomTarget: (NSString * _Nonnull)value withKey: (NSString * _Nonnull)key;

- (void)loadAd: (id<DTBAdCallback>  _Nonnull) callback;

- (NSError * _Nullable)loadSmartBanner: (id<DTBAdCallback>  _Nonnull) callback;

- (void)setAutoRefresh;

- (void)stop;

- (void)setAutoRefresh: (int)seconds;

- (void)pauseAutorefresh;
- (void)resumeAutorefresh;

@end
