//
//  GFPNDAMRAIDOrientationProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import "GFPNDAMRAIDUtil.h"

@interface GFPNDAMRAIDOrientationProperties : NSObject

+ (GFPNDAMRAIDOrientationProperties *)orientationPropertiesWith:(NSDictionary *)mraidDict;

- (instancetype)initWithAllowOrientationChange:(BOOL)allowOrientationChange
                              forceOrientation:(GFPNDAMRAIDOrientation)forceOrientation;

@property (nonatomic, readonly, assign) BOOL allowOrientationChange;
@property (nonatomic, readonly, assign) GFPNDAMRAIDOrientation forceOrientation;

@end
