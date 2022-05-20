//  GFPSDKPhase.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdConfiguration.h"

typedef NS_OPTIONS(NSInteger, GFPServerType) {
    GFPServerTypeVer1 = 1 << 0,
    GFPServerTypeVer2 = 1 << 1, //for NAM
};
NS_ASSUME_NONNULL_BEGIN
 
 @interface GFPSDKPhase : NSObject
 
+ (NSString *)sdkInitPhaseWith:(GFPPhaseType)aType serverType:(GFPServerType)serverType;
 
+ (NSString *)skadnRegisterPhaseWith:(GFPPhaseType)aType serverType:(GFPServerType)serverType;
 
+ (NSString *)waterfallPhaseWith:(GFPPhaseType)aType serverType:(GFPServerType)serverType;
 
+ (NSString *)videoSchedulePhaseWith:(GFPPhaseType)aType serverType:(GFPServerType)serverType;
 
 @end

NS_ASSUME_NONNULL_END
