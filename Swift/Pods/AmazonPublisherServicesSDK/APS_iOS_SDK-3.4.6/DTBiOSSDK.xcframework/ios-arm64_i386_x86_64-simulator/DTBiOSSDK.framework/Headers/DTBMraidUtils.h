//
//  DTBMraidUtils.h
//  DTBiOSSDK
//
//  Created by Bharadwaj, Arjun on 2/1/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "DTBMraidConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface DTBMraidUtils : NSObject

+ (NSString*) placementTypeAsString : (DTBAdPlacementType) placementType;
+ (NSString*) stateTypeToString : (DTBAdState) adStatusType;
+ (NSString*) mraidEnvParametersAsString:(NSDictionary *)params;
+ (NSString*) MRAIDSupportObjectAsJSONString;
+ (DTBAdOrientation)orientationFromForceOrientationString:(NSString *)orientationString;
+ (NSString *) orientationTypeToString:(DTBAdOrientation) orientation;
+ (UIInterfaceOrientation) dtbOrientationToUIOrientationState: (DTBAdOrientation) orientation;
+ (DTBAdOrientation) UIOrientationStateToDTBOrientationState:(UIInterfaceOrientation) orientation;
+ (BOOL) isAppOrientationLocked;
+ (NSArray *) supportedOrientationsAsArray;

@end

NS_ASSUME_NONNULL_END
