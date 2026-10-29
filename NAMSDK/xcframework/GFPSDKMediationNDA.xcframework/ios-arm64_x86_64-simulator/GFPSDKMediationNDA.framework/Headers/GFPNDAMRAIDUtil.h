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

// MARK: - View 기준 조회 (멀티씬 대응)
// UIScreen.main 은 iPhone Duo 에서 외부(접힘) 화면에 고정되어 펼침 상태에서 실제 화면과 값이 갈린다.
// 뷰(웹뷰)가 있으면 그 씬의 화면 기준으로 계산하고, nil 이면 기존 전역 동작으로 폴백한다.
+ (CGSize)screenSizeForView:(UIView * _Nullable)view;
+ (CGSize)maxSizeSafeAreaForView:(UIView * _Nullable)view;
+ (CGRect)portraitScreenBoundsForView:(UIView * _Nullable)view;
+ (CGRect)portraitScreenBoundsApplyingSafeAreaInsetsForView:(UIView * _Nullable)view;
+ (CGRect)adjustAbsoluteRectFrom:(CGRect)rect forView:(UIView * _Nullable)view;
+ (NSString *)currentOrientationForView:(UIView * _Nullable)view;

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

