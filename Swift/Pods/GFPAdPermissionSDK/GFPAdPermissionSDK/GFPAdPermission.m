//
//  GFPAdPermission.m
//  GFPAdPermissionSDK
//
//  Created by sodam on 2020/09/03.
//  Copyright © 2020 sodam. All rights reserved.
//

#import "GFPAdPermission.h"
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>

@implementation GFPAdPermission

+ (void)requestTrackingAuthorizationWith:(void(^)(GFPAdPermissionStatus status))completion {
    if (!completion) {
        return;
    }
    
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus attStatus) {
        
            GFPAdPermissionStatus status = [self statusWith:attStatus];
            completion(status);
        }];
    } else {
        completion([self status]);
    }
}

+ (GFPAdPermissionStatus)status {
    if (@available(iOS 14, *)) {
        return [self statusWith:ATTrackingManager.trackingAuthorizationStatus];;
    }
    else {
        return [self limitAdTracking] ? GFPAdPermissionStatusDenied : GFPAdPermissionStatusAuthorized;
    }
}

#pragma mark - Private

+ (GFPAdPermissionStatus)statusWith:(ATTrackingManagerAuthorizationStatus)attStatus  API_AVAILABLE(ios(14)){
    GFPAdPermissionStatus status = GFPAdPermissionStatusUnknown;
    
    switch (attStatus) {
        case ATTrackingManagerAuthorizationStatusNotDetermined:
            status = GFPAdPermissionStatusNotDetermined;
            break;

        case ATTrackingManagerAuthorizationStatusRestricted:
            status = GFPAdPermissionStatusRestricted;
            break;

        case ATTrackingManagerAuthorizationStatusDenied:
            status = GFPAdPermissionStatusDenied;
            break;

        case ATTrackingManagerAuthorizationStatusAuthorized:
            status = GFPAdPermissionStatusAuthorized;
            break;
    }
    
    return status;
}

+ (BOOL)limitAdTracking {
    return ![[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled];
}

@end
