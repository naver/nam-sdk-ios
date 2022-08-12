//
//  DTBAdSize.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 10/2/15.
//  Copyright © 2015 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#define DTB_VIDEO_WIDTH ((int) 640)
#define DTB_VIDEO_HEIGHT ((int) 390)

typedef enum {
    VIDEO,
    DISPLAY,
    INTERSTITIAL
} ADType;

@interface DTBAdSize : NSObject
@property(readonly, nonatomic) ADType adType;
@property(readonly, nonatomic) NSInteger width;
@property(readonly, nonatomic) NSInteger height;
@property(readonly, nonatomic) NSString *slotUUID;
@property(nonatomic) NSDictionary *pubSettings;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initBannerAdSizeWithWidth: (NSInteger)width height: (NSInteger)height andSlotUUID: (NSString *) slotUUID;

- (instancetype)initInterstitialAdSizeWithSlotUUID: (NSString *) slotUUID;

- (instancetype)initVideoAdSizeWithPlayerWidth: (NSInteger)width height: (NSInteger)height andSlotUUID: (NSString *) slotUUID;

- (instancetype)initVideoAdSizeWithPlayerWidth: (NSInteger)width height: (NSInteger)height slotUUID: (NSString *)slotUUID andPubSettings: (NSDictionary *)pubSettings ;

- (BOOL)isInterstitialAd;

@end
