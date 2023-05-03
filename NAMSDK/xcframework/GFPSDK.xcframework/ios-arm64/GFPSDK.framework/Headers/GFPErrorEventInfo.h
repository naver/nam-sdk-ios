//
//  GFPErrorEventInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const GFPErrorSubcodeProviderNotInit;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeAdaptorInitFailed;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeIMAWrongRequest;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeIMANoFillWithAdRule;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeNDAVNoMediaUrl;
FOUNDATION_EXPORT NSString *const GFPErrorSubcodeAdaptorLoadTimeout;

@interface GFPErrorEventInfo : NSObject

@property (readwrite, nonatomic, strong) NSNumber *errorCode;
@property (readwrite, nonatomic, strong, nullable) NSString *errorSubcode;
@property (readwrite, nonatomic, strong, nullable) NSString *errorMessage;
@property (readwrite, nonatomic, strong, nullable) NSDictionary *errorObject;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithErrorCode:(NSNumber *)errorCode
                     errorSubcode:(NSString *_Nullable)errorSubcode
                     errorMessage:(NSString *_Nullable)errorMessage
                      errorObject:(NSDictionary *_Nullable)errorObject NS_DESIGNATED_INITIALIZER;

+ (instancetype)errorWithSize:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
