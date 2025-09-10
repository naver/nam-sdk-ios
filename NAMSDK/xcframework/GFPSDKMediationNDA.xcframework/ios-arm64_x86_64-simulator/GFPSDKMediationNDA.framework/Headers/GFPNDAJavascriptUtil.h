//
//  GFPNDAJavascriptUtil.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

extern NSString * _Nonnull const kNDAAdMuteJSInterfaceName;

extern NSString * _Nonnull const kNDAAdMuteComplete;
extern NSString * _Nonnull const kNDAAdMuteEventNameKey;

typedef NS_OPTIONS(NSInteger, GFPNDAJavascriptType) {
    GFPNDARendered = 1 << 0,    //old
    GFPNDAViewable = 1 << 2,    //old
    GFPNDAFluid = 1 << 3,       //old
    
    GFPNDAReady = 1 << 4,
    GFPNDAExposureChanged = 1 << 5,
    GFPNDAHostMeta = 1 << 6,
    GFPNDARenderedImpression = 1 << 7,
    GFPNDAViewableImpression = 1 << 8,
    
    GFPNDAAdMuteEventRegister = 1 << 9,
    GFPNDAAdMuteTheme = 1 << 10,
};

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAJavascriptUtil : NSObject

+ (NSString *)javaScriptWith:(GFPNDAJavascriptType)aType;
+ (NSString *)javaScriptWith:(GFPNDAJavascriptType)aType param:(NSString *)param;

@end

NS_ASSUME_NONNULL_END
