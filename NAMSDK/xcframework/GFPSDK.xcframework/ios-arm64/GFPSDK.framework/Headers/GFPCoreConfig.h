//
//  GFPCoreConfig.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <Foundation/Foundation.h>
#import "GFPRenderDisplayAgent.h"
#import "GFPAdConfiguration.h"
#import "GFPUserParam.h"

#import "GFPAdManagerDelegate.h"

#import "GFPAPIRequest.h"

@class GFPError;
@protocol GFPDictPresentable;

NS_ASSUME_NONNULL_BEGIN

#define GFP_SDK_VERSION              @"6.1.0"

@interface GFPCoreConfig : NSObject

@property (class, readonly, nonatomic) GFPCoreConfig *sharedInstance;

@property (nonatomic, nullable, weak) id <GFPAdManagerDelegate> delegate;

@property (nonatomic, assign) NSTimeInterval defaultVideoStartTimeout;

@property (nonatomic, strong) GFPAdConfiguration *configuration;

@property (nonatomic, assign, getter=isDebugMode) BOOL debugMode;
@property (nonatomic, strong, readonly) id <GFPDictPresentable> sdkInfo;
@property (nonatomic, strong, readonly) id <GFPDictPresentable> initializeInfo;
@property (nonatomic, strong, readonly) id <GFPDictPresentable> appVersionInfo;

@property (nullable, nonatomic, strong, readwrite) GFPUserParam *userParam;
@property (nonatomic, strong, readonly, nullable) NSString *adID;
@property (nonatomic, strong, readonly, nullable) NSString *idfv;

@property (nonatomic, readonly, assign) GFPATTAuthorizationStatus attStatus;

@property (nonatomic, strong, readonly) NSString *gfpUserAgent;


- (void)updateUserAgentWith:(NSString *)externalUserAgent;
- (BOOL)limitAdTracking;
- (NSDictionary<NSString *, NSString *> *)commonCookieHeader;
- (NSDictionary<NSString *, NSString *> *)commonHeader;

- (NSString *)requestBaseURLWithType:(GFPRequestType)aType;
@end

NS_ASSUME_NONNULL_END
