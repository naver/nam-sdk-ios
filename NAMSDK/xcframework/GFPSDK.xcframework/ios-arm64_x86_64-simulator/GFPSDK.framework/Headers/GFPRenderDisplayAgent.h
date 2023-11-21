//
//  GFPRenderDisplayAgent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


typedef NS_OPTIONS(NSInteger, GFPRenderDisplayAgentType) {
    GFPDisplayAgentTypeInApp = 1 << 0,
    GFPDisplayAgentTypeScheme = 1 << 1,
    GFPDisplayAgentTypeNativeSafari = 1 << 2
};

NS_ASSUME_NONNULL_BEGIN

@interface GFPRenderDisplayAgent : NSObject

@property (readonly, nonatomic, assign) GFPRenderDisplayAgentType type;
@property (readonly, nonatomic, strong, nullable) NSString *scheme __deprecated_msg("Use S2S Click Handler instead. it will be removed 7 version");
@property (nonatomic, assign) BOOL shouldEncoding;

@property (readonly, nonatomic, strong) NSString *typeRawValue;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithType:(GFPRenderDisplayAgentType)aType;

- (instancetype)initWithType:(GFPRenderDisplayAgentType)aType scheme:(NSString * _Nonnull)aScheme __deprecated_msg("Use S2S Click Handler instead. it will be removed 7 version");

- (nullable NSURL *)landingURLWith:(NSString *)aURL;

@end

NS_ASSUME_NONNULL_END
