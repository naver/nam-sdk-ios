//
//  GFPAdManagerDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPATTAuthorizationStatus.h"


@protocol GFPAdManagerDelegate <NSObject>

- (GFPATTAuthorizationStatus)attStatus;


@end
