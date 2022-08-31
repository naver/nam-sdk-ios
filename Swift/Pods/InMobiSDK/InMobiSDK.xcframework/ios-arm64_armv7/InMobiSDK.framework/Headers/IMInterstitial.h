//
//  IMInterstitial.h
//  APIs
//  Copyright (c) 2015 InMobi. All rights reserved.
//
/**
 * Class to integrate full screen interstitial ads in your application
 * Adding interstitial ads is demonstrated in the code fragment below
 * Implement the following in the viewcontroller
 
 IMInterstitial *interstitialView = [[IMInterstitial alloc] initWithPlacementId:1203280001];
 interstitialView.delegate = self;
 [interstitialView load];
 
 - (void)interstitialDidFinishLoading:(IMInterstitial *)interstitial {
 [interstitial show];
 }
 
- (void)interstitialDidReceiveAd:(IMInterstitial *)interstitial {
 NSLog(@"interstitialDidReceiveAd");
 }
 
 - (void)interstitial:(IMInterstitial *)interstitial didFailToLoadWithError:(IMRequestStatus *)error {
 NSLog(@"Interstitial failed to load ad");
 NSLog(@"Error : %@",error.description);
 }
 
 - (void)interstitial:(IMInterstitial *)interstitial didFailToPresentWithError:(IMRequestStatus *)error{
 NSLog(@"Interstitial didFailToPresentWithError");
 NSLog(@"Error : %@",error.description);
 }
 
 - (void)interstitialDidDismiss:(IMInterstitial *)interstitial {
 NSLog(@"interstitialDidDismiss");
 }
 
 - (void)interstitialWillDismiss:(IMInterstitial *)interstitial {
 NSLog(@"interstitialWillDismiss");
 }
 
 - (void)interstitialWillPresent:(IMInterstitial *)interstitial {
 NSLog(@"interstitialWillPresent");
 }
 
 - (void)interstitialDidPresent:(IMInterstitial *)interstitial {
 NSLog(@"interstitialDidPresent");
 }
 
 - (void)userWillLeaveApplicationFromInterstitial:(IMInterstitial *)interstitial {
 NSLog(@"userWillLeaveApplicationFromInterstitial");
 }
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <InMobiSDK/IMInterstitialDelegate.h>
#import <InMobiSDK/IMCoreConstants.h>
#import <InMobiSDK/IMInterstitialPreloadManager.h>

#ifndef INTERSTITIALINCLUDE_H
#define INTERSTITIALINCLUDE_H

@interface IMInterstitial : NSObject

/**
 * The placement ID for this Interstitial.
 */
@property (nonatomic, assign) long long placementId;
/**
 * The delegate to receive callbacks
 */
@property (nonatomic, weak) id<IMInterstitialDelegate> delegate;
/**
 * A free form set of keywords, separated by ',' to be sent with the ad request.
 * E.g: "sports,cars,bikes"
 */
@property (nonatomic, strong) NSString* keywords;
/**
 * Any additional information to be passed to InMobi.
 */
@property (nonatomic, strong) NSDictionary* extras;
/**
 * A unique identifier for the creative.
 */
@property (nonatomic, strong, readonly) NSString* creativeId;
/**
 *The prelaod Manager for Preload flow.
*/
@property (nonatomic, strong, readonly) IMInterstitialPreloadManager* preloadManager;
/**
 * contentUrl for OMSDK
 */
@property (nonatomic, strong) NSString* contentUrl;
/**
 * init and new methods are unavailable for this class
 * use "initWithPlacementId:" or "initWithPlacementId:delegate:" method.
 */
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initialize an Interstitial with the given PlacementId
 * @param placementId The placementId for loading the interstitial
 */
-(instancetype)initWithPlacementId:(long long)placementId;
/**
 * Initialize an Interstitial with the given PlacementId
 * @param placementId The placementId for loading the interstitial
 * @param delegate The delegate to receive callbacks
 */
-(instancetype)initWithPlacementId:(long long)placementId delegate:(id<IMInterstitialDelegate>)delegate NS_DESIGNATED_INITIALIZER;
/**
 *Get a Signal packet from the InMobi SDK. Signals are used in the Open Auction scenarios and are an abstraction of InMobi'sAd Request. Signals are asynchronously passed via IMInterstitialDelegate Protocol method "Interstitial:gotSignals:"
 */
- (void)getSignals;
/**
 * Loads an Interstitial
 */
-(void)load;
/**
 * Loads an Interstitial Ad with a response Object. This is used for Open Auction use cases
 * @param response An NSData object which contains the InMobi Banner Ad
 */
-(void)load:(NSData*)response;
/**
 * To query if the interstitial is ready to be shown
 */
-(BOOL)isReady;
/**
 * Displays the interstitial on the screen
 * @param viewController , this view controller will be used to present interestitial.
 */
-(void)showFromViewController:(UIViewController *)viewController;
/**
 * Displays the interstitial on the screen
 * @param viewController , this view controller will be used to present interestitial.
 * @param type The transition type for interstitial presentation.
 */
-(void)showFromViewController:(UIViewController *)viewController withAnimation:(IMInterstitialAnimationType)type;
/**
 * Contains additional information of ad.
 */
- (NSDictionary *)getAdMetaInfo;
/**
 * Releases memory and remove ad from screen.
 */
- (void)cancel;

@end

#endif /* INTERSTITIALINCLUDE_H */

