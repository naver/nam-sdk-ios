//
//  GFPNDAMRAIDJavascriptUtil.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import "GFPNDAMRAIDUtil.h"

#define GFP_MRAID_SUPPORT_VERSION  @"3.0"


@interface GFPNDAMRAIDJavascriptUtil : NSObject

+ (NSString *)readyEvent;
+ (NSString *)stateChange:(GFPNDAMRAIDState)state;
+ (NSString *)error:(NSString *)errorString
        forFunction:(NSString *)function;
+ (NSString *)placementType:(NSString *)placementType;
+ (NSString *)isViewable:(BOOL)isViewable;
+ (NSString *)currentSize:(CGSize)size;
+ (NSString *)currentPosition:(CGRect)position;
+ (NSString *)defaultPosition:(CGRect)position;
+ (NSString *)screenSize:(CGSize)size;
+ (NSString *)maxSize:(CGSize)size;
+ (NSString *)featureJavascript:(GFPMraidSupportType)aType;


+ (NSString *)getState;

+ (NSString *)setCurrentAppOrientation:(NSString *)orientation
                             lockedOrientation:(BOOL)locked;

+ (NSString *)close;

//3.0 added spec
+ (NSString *)exposureChangeExposedPercentage:(CGFloat)exposedPercentage visibleRectangle:(CGRect)visibleRect;

+ (NSString *)mraidEnv;
+ (NSString *)audioVolumeChange:(NSInteger)audioPer;

@end
