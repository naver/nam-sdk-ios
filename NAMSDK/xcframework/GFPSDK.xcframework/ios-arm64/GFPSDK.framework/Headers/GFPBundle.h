//
//  GFPBundle.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kSDKNameGFP;
extern NSString * const kSDKNameNAM;

@interface GFPBundle : NSObject

@property (class, nonatomic, readonly) GFPBundle *sharedInstance;

+ (NSString *)appVersion;
+ (NSString *)appName;
+ (NSString *)identifier;
+ (NSString *)sdkName;

- (NSArray <NSString *> *)skAdNetworkList;

@end

NS_ASSUME_NONNULL_END
