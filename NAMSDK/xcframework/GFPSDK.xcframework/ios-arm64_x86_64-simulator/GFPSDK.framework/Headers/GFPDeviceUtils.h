//
//  GFPDeviceUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPDeviceLocInfo : NSObject

@property (nonatomic, readonly) NSString *latitude;
@property (nonatomic, readonly) NSString *longitude;

- (instancetype)initWithLatitude:(double)latitude longitude:(double)longitude;

@end


@interface GFPDeviceUtils : NSObject

+ (NSString *)preferredLanguageCode;
+ (NSString *)getDeviceCountryCode;
+ (NSString *)localeIdentifier;
+ (BOOL)isStatusBarLandscape;
+ (BOOL)isIPad;

+ (NSString *)systemName;
+ (NSString *)systemVer;

+ (NSString *)deviceModel;
+ (NSString *)carrier;

+ (CGRect)screenRect;
+ (CGFloat)nativeScaleFactor;

+ (BOOL)isSKAdNetworkAvaliable;

+ (GFPDeviceLocInfo *)getLocationInfo;

@end


NS_ASSUME_NONNULL_END
