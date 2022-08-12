//
//  DTBAdDispatcher.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 1/2/19.
//  Copyright © 2019 Krivopaltsev, Eugene. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
@class DTBAdView;
#import "DTBMraidUtils.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DTBUseCustomCloseDelegate <NSObject>
-(void)customCloseUpdated;
@end


@interface DTBAdDispatcher : NSObject<WKNavigationDelegate>

// Current adView which the controller / dispatcher controls.
@property (nonatomic, weak) DTBAdView *adView;
// Current mraid state. e.g. 'loading', 'default', expanded, 'resized', 'hidden'
@property (nonatomic) DTBAdState currentState;
// Placement Type. e.g. 'inline' or 'interstitial'
@property (nonatomic) DTBAdPlacementType placementType;
// Default position of the ad regardless of current state
@property (nonatomic) CGRect defaultPosition;
// Current position of the ad
@property (nonatomic) CGRect currentPosition;
// Max Size an ad can expand or resize to
@property (nonatomic) CGSize maxSize;
// Screen Size of the device
@property (nonatomic) CGSize screenSize;

// Exposure / Viewable Event data structures
@property (nonatomic) CGSize  currentSize;

// Set orientation properties data structure fields
@property (nonatomic) BOOL pageLoaded;

// Close button
@property (nonatomic) UIButton *closeButton;

@property (nonatomic) NSString* currentOrientation;

@property (nonatomic) BOOL useCustomClose;

@property (nonatomic) BOOL ignoreLogEventsForExposureChange;

- (void) evaluateJavaScriptFromString:(NSString *)script;

// Setup commands
- (void) prepareMRAID;
- (void) fireSetSupportPropertiesEvent;
- (void) firePlacementTypeChangeEvent:(DTBAdPlacementType) pType;
- (void) fireCurrentPositionEvent;
- (void) fireDefaultPositionEvent;
- (void) fireSetStateEvent: (DTBAdState) cState;
- (void) fireSetMaxSizeEvent;
- (void) fireScreenSizeEvent;
- (void) fireSetCurrentOrientationEvent;

-(void) onOpenUrl:(NSURL * _Nonnull)url;

// MRAID State Events JS (error, success, change, etc.)
- (void) fireErrorEvent:(NSString*) errorMessage forAction:(NSString*) action;
- (void) fireReadyEvent;
- (void) fireSizeChangeEvent;
- (void) fireStateChangeEvent;
- (void) fireExposureChangeEvent:(int) exposureChange withVisibleRect:(CGRect) visibleRect;
- (void) fireNativeCommandCompleted:(NSString *) command;

// MRAID Commands
- (void) executeOpen:(NSString *) url;
- (void) executeClose;
- (void) executeResize: (NSDictionary*) params;
- (void) executeUnload;
- (void) executeExpand : (NSDictionary *) params;
- (void) useCustomClose: (NSDictionary *) params;
- (void) executeJSReadyCommand;
- (void) cleanup;
- (BOOL) isValidTapEventForRedirection;
// Ad view exiting function
- (void) adViewDidDisappear:(DTBAdView *) adview;

// Close helper functions
- (void) addCloseIndicator:(CGPoint) closeCoordinates toView:(UIView*) supView;

// Orientation notification methods
- (void) updateCurrentOrientationProperties;
- (void) orientationDidChange:(NSString *) updatedOrientation;

// Viewability functions
- (void) onViewabilityChanged:(BOOL) changedVal;

// JS fired impression
- (void)impressionFired;

// custom close delegate
@property (nonatomic, weak) id<DTBUseCustomCloseDelegate> customCloseDelegate;

@end

NS_ASSUME_NONNULL_END
