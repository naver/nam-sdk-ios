//
//  DTBRenderingConstants.h
//  DTBiOSSDK
//
//  Created by Bharadwaj, Arjun on 2/18/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTBMraidConstants : NSObject

// Ad Placement status
typedef NS_ENUM(NSInteger, DTBAdPlacementType) {
    DTBAdPlacementTypeTypeInline = 0,    // Inline placement
    DTBAdPlacementTypeTypeInterstitial,  // Interstitial placement
};

// Ad State Status
typedef NS_ENUM(NSInteger, DTBAdState) {
    DTBAdStateLoading = 0,
    DTBADStateDefault,
    DTBAdStateExpanded,
    DTBAdStateResized,
    DTBAdStateHidden
};

// Completion handler for the evaluate java script call.
typedef void (^ DTBJSCompletionHandler)(_Nullable id, NSError * _Nullable error);
typedef enum {
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    CENTER_LEFT,
    CENTER_CENTER,
    CENTER_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
} DTBAdViewCloseButtonLocation;

typedef enum {
    NO_BUTTON,
    BUTTON_WITH_IMAGE,
    BUTTON_CUSTOM
} DTBAdViewCloseButtonType;

typedef void (^ DTBJSCompletionHandler)(_Nullable id, NSError * _Nullable error);

// Enum for MRAID Orientation.
typedef NS_ENUM(NSUInteger, DTBAdOrientation) {
    DTBAdOrientationPortrait,
    DTBAdOrientationLandscape,
    DTBAdOrientationNone
};

// Javascript API
// extern NSString * const kMraidBridgeJsApi;
// extern NSString * const kMraidJsApi;

// URL Schemes
extern NSString * const kMraidSMSScheme;
extern NSString * const kMraidTelScheme;

@end

NS_ASSUME_NONNULL_END
