//
//  GFPNDAMRAIDUtil.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
/*   Copyright 2014 APPNEXUS INC
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <UIKit/UIKit.h>
#import "GFPMRAIDSupportSetting.h"

typedef NS_OPTIONS(NSUInteger, GFPNDAMRAIDOrientation) {
    GFPNDAMRAIDOrientationPortrait,
    GFPNDAMRAIDOrientationLandscape,
    GFPNDAMRAIDOrientationNone
};


typedef NS_OPTIONS(NSUInteger, GFPNDAMRAIDCustomClosePosition) {
    GFPNDAMRAIDCustomClosePositionUnknown,
    GFPNDAMRAIDCustomClosePositionTopLeft,
    GFPNDAMRAIDCustomClosePositionTopCenter,
    GFPNDAMRAIDCustomClosePositionTopRight,
    GFPNDAMRAIDCustomClosePositionCenter,
    GFPNDAMRAIDCustomClosePositionBottomLeft,
    GFPNDAMRAIDCustomClosePositionBottomCenter,
    GFPNDAMRAIDCustomClosePositionBottomRight
};


typedef NS_OPTIONS(NSUInteger, GFPNDAMRAIDState) {
    GFPNDAMRAIDStateUnknown,
    GFPNDAMRAIDStateLoading,
    GFPNDAMRAIDStateDefault,
    GFPNDAMRAIDStateExpanded,
    GFPNDAMRAIDStateHidden,
    GFPNDAMRAIDStateResized
};


typedef NS_OPTIONS(NSUInteger, GFPNDAMRAIDAction) {
    GFPNDAMRAIDActionUnknown,
    GFPNDAMRAIDActionExpand,
    GFPNDAMRAIDActionClose,
    GFPNDAMRAIDActionResize,
    GFPNDAMRAIDActionCreateCalendarEvent,
    GFPNDAMRAIDActionPlayVideo,
    GFPNDAMRAIDActionStorePicture,
    GFPNDAMRAIDActionSetOrientationProperties,
    GFPNDAMRAIDActionSetUseCustomClose,
    GFPNDAMRAIDActionOpenURI,
    GFPNDAMRAIDActionUnload,
};

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAMRAIDUtil : NSObject

+ (BOOL)supportWith:(GFPMraidSupportType)aType;
+ (NSString *)supportFeatureWith:(GFPMraidSupportType)aType;

+ (CGSize)screenSize;
+ (CGSize)maxSizeSafeArea;

+ (GFPNDAMRAIDAction)actionForCommand:(NSString *)command;
+ (GFPNDAMRAIDCustomClosePosition)customClosePositionWith:(NSString *)customClosePositionString;
+ (GFPNDAMRAIDOrientation)orientationFromForceOrientationString:(NSString *)orientationString;

+ (GFPNDAMRAIDState)stateFromString:(NSString *)string;
+ (NSString * _Nullable)stateStringFromState:(GFPNDAMRAIDState)state;

+ (BOOL)canPresentFromViewController:(UIViewController * _Nullable)viewController;
+ (CGRect)portraitScreenBoundsApplyingSafeAreaInsets;
+ (CGRect)portraitScreenBounds;
+ (CGRect)adjustAbsoluteRectFrom:(CGRect)rect;

+ (NSString *)currentOrientation;
+ (BOOL)isLockedOrientation;

@end

NS_ASSUME_NONNULL_END

