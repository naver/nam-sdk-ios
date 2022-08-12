//
//  DTBAds.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 1/30/15.
//  Copyright (c) 2015 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DTBLog.h"

@class DTBSlotGroup;

/* NOTE: these values have been decided based on the custom
 encoding scheme. We have chosen the following values for the
 consent status: Unknown = 1, Explicit Yes = 7, Explicit No = 0 */
typedef NS_ENUM(NSInteger, DTBConsentStatus)  {
    CONSENT_NOT_DEFINED = -1,
    UNKNOWN = 1,
    EXPLICIT_YES = 7,
    EXPLICIT_NO = 0
};

/* Same as above. These values have been decided based on the custom
 encoding protocol: Google = 1, MoPub = 2 */
typedef NS_ENUM(NSInteger, DTBCMPFlavor) {
    CMP_NOT_DEFINED = -1,
    GOOGLE_CMP = 1,
    MOPUB_CMP = 2
};

typedef enum
{
    // set as default use MoPub, then DFP
    AUTO_DETECT_MRAID,
    // set mraid version based on DFP
    DFP_MRAID,
    // set mraid version based on MOPUB
    MOPUB_MRAID,
    // ignore mraid version
    NONE_MRAID,
    // use applicatio set MRAID version
    CUSTOM_MRAID
} DTBMRAIDPolicy;

@interface DTBAds : NSObject

@property (nonatomic) BOOL useSecureConnection;
@property (nonatomic) BOOL testMode;
@property (nonatomic) BOOL useGeoLocation;
@property (nonatomic) DTBMRAIDPolicy mraidPolicy;
@property (nonatomic) NSArray<NSString *> *  _Nullable mraidCustomVersions;
@property (nonatomic) BOOL isReady;

// Serverless Environment Markers
@property (nonatomic) NSArray * _Nonnull serverlessMarkers;

// Properties for GDPR NON-IAB AdMob Compliance support.
- (void)setVendorList:(NSArray<NSNumber *> *_Nullable)vendorList;
- (void)setConsentStatus:(DTBConsentStatus)consentStatus;
- (void)setCmpFlavor:(DTBCMPFlavor) cmpFlavor;

// The client needs to call this API to determine if the consent status is unknown.
- (BOOL) isConsentStatusUnknown;

+ (DTBAds * _Nonnull)sharedInstance;

// Set the applicationId provided by the Amazon Appstore.
- (void)setAppKey:(NSString * _Nonnull)appKey;

// Retrieves the appKey, if already stored, otherwise will throw an exception
- (NSString * _Nullable)appKey;

- (void)setLogLevel: (DTBLogLevel)logLevel;

- (BOOL)handleURL: (NSURL *  _Nonnull)url;

+ (NSString * _Nonnull)version;

-(void)addSlotGroup:(DTBSlotGroup * _Nonnull) group;

-(DTBSlotGroup * _Nullable)slotGroupByName:(NSString * _Nullable)name;

-(BOOL)hasAdapters;

-(void)removeNonIAB;

/**
 * A Boolean value indicating whether the APS SDK should create a ID that can be used
 * for frequency capping when the user has provided consent, limit ad tracking is on and the IDFA is all zeros.
 * When set to NO, the SDK will not create a frequency capping id ID in the above case. When set to YES, the
 * SDK will generate a frequency capping ID. The default value is YES, meaning the feature is enabled by default. This
 * can be overriden by server side from APS Developer Portal.
 */
-(void)setAPSFrequencyCappingIdFeatureEnabled:(BOOL)frequencyCappingIdFeatureEnabled;

/**
 * Use these APIs to add any custom attributes or parameters that might
 * be important for APS SDK to pick up.
 * The value type can be anything but please try to use NSString or NSDictionary for simplicity.
 */
-(void)addCustomAttribute:(NSString * _Nonnull)withKey value:(id _Nonnull)value;
-(void)removeCustomAttribute:(NSString * _Nonnull)forKey;

/*
 * Alternative method to store and retrieve the local extras
 */
+(NSDictionary * _Nullable)getLocalExtras:(NSString * _Nonnull)adUnitId;
+(void)setLocalExtras:(NSString * _Nonnull)adUnitId localExtras:(NSDictionary * _Nonnull)localExtras;
+(void)removeLocalExtras:(NSString * _Nonnull)key;
@end
