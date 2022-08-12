//
//  DTBAdCallback.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 3/13/15.
//  Copyright (c) 2015 amazon.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "DTBAdResponse.h"

@protocol DTBAdCallback

- (void)onFailure: (DTBAdError)error;

- (void)onSuccess: (DTBAdResponse *)adResponse;

@end
