//
//  DTBAdResponse+Mediation.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 12/11/18.
//  Copyright © 2018 Krivopaltsev, Eugene. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DTBAdResponse.h"
NS_ASSUME_NONNULL_BEGIN

@interface DTBAdResponse(Mediation)

-(NSString * _Nonnull)bidInfo;

-(NSString * _Nonnull)bidInfoInterstitial;

-(NSString * _Nonnull)amznSlots;

-(DTBAdSize * _Nonnull)adSize;

-(NSDictionary * _Nonnull)mediationHints:(BOOL)isSmartBanner;

-(NSDictionary * _Nonnull)mediationHints;

-(void)setHostName:(NSString * _Nonnull)hostName;

-(void)setCrid: (NSString * _Nonnull) crid;

@end

NS_ASSUME_NONNULL_END
