//
//  DTBLog.h
//  DTBiOSSDK
//
//  Created by Singh, Prashant Bhushan on 2/4/15.
//  Copyright (c) 2015 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

// Log level for the DTBLog util class.
// Lower = finer-grained logs.
typedef enum
{
    DTBLogLevelAll   = 0,
    DTBLogLevelTrace = 10,
    DTBLogLevelDebug = 20,
    DTBLogLevelInfo  = 30,
    DTBLogLevelWarn  = 40,
    DTBLogLevelError = 50,
    DTBLogLevelFatal = 60,
    DTBLogLevelOff   = 70
} DTBLogLevel;

/**
 * Application implements this protocol if further manipulations besides NSLog are required
 *
 */
@protocol DTBLogDelegate
/**
 * delegate is call with a message originated from DTBLog
 */
-(void)onMessageLogged:(NSString * _Nonnull) message;

@end


@protocol DTBLogTagDelegate

-(NSString * _Nonnull) requestedTag;
/**
 * delegate is call with a message originated from DTBLog
 */
-(void)onMessageLogged:(NSString * _Nonnull) message;

@end

// Util class to log the events in DTB Mobile API.
// Logger works only when the constant DTB_DEBUG_MODE is set to 1 in DTBConstants.h file
// If DTB_DOMAIN is set to BETA then default log level is DTBLogLevelAll
// otherwise default Log level is DTBLogLevelError.
@interface DTBLog : NSObject

// Returns the current set log level
+(DTBLogLevel) logLevel;

// Set's the log level
+(void) setLogLevel:(DTBLogLevel) level;

+(void)setDelegate:(id<DTBLogDelegate> _Nullable)delegate;

+(void)setTagDelegate:(id<DTBLogTagDelegate> _Nullable)delegate;

+(void) trace:(NSString * _Nonnull) format, ...;
+(void) debug:(NSString * _Nonnull) format, ...;
+(void) info: (NSString * _Nonnull) format, ...;
+(void) warn: (NSString * _Nonnull) format, ...;
+(void) error:(NSString * _Nonnull) format, ...;
+(void) fatal:(NSString * _Nonnull) format, ...;

+(void) traceWithTag:(NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
+(void) debugWithTag:(NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
+(void) infoWithTag: (NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
+(void) warnWithTag: (NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
+(void) errorWithTag:(NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
+(void) fatalWithTag:(NSString * _Nonnull)tag format: (NSString * _Nonnull) format, ...;
@end

