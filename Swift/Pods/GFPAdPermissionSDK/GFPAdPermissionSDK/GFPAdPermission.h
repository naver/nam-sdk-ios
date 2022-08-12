//
//  GFPAdPermission.h
//  GFPAdPermissionSDK
//
//  Created by sodam on 2020/09/03.
//  Copyright © 2020 sodam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GFPAdPermissionStatus){
    GFPAdPermissionStatusUnknown = 0,
    GFPAdPermissionStatusNotDetermined = 1 << 0,
    GFPAdPermissionStatusRestricted = 1 << 1,
    GFPAdPermissionStatusDenied = 1 << 2,
    GFPAdPermissionStatusAuthorized = 1 << 3,
};

@interface GFPAdPermission : NSObject

@property (class, nonatomic, readonly, assign) GFPAdPermissionStatus status;

+ (void)requestTrackingAuthorizationWith:(void(^)(GFPAdPermissionStatus status))completion;

@end

NS_ASSUME_NONNULL_END
