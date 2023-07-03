//
//  GFPAPIRequest.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPAPIQueryItems.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS(NSInteger, GFPRequestType) {
    GFPRequestInitializer = 0,
    GFPRequestSKADNRegister,
    GFPRequestWaterfall,
    GFPRequestSchedule,
    GFPRequestURL,
    GFPRequestNelo,
};

@interface GFPAPIRequest : NSObject

@property (nonatomic, readonly, assign) GFPRequestType type;
@property (nonatomic, readonly, strong, nullable) NSURLRequest *request;

- (instancetype)initWithType:(GFPRequestType)aType queryItems:(GFPAPIQueryItems *)aQuery;
- (instancetype)initWithType:(GFPRequestType)aType path:(NSString * _Nullable)aPath queryItems:(GFPAPIQueryItems *)aQuery;
- (instancetype)initWithType:(GFPRequestType)aType url:(NSString *)aURL queryItems:(GFPAPIQueryItems * _Nullable)aQuery;

@end

NS_ASSUME_NONNULL_END
