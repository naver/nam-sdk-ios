//
//  GFPLogLevel.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, GFPLogLevel) {
    GFPLogLevelTrace = 0,
    GFPLogLevelDebug,
    GFPLogLevelInfo,
    GFPLogLevelWarn,
    GFPLogLevelError,
    GFPLogLevelNone
};
