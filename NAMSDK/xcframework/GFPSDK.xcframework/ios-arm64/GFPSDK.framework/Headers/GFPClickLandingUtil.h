//
//  GFPClickLandingUtil.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
  


#import <Foundation/Foundation.h>
#import "GFPS2SAdClickDelegate.h"
@import NaverAdsServices;

@class GFPSKAdNetworkInfo;
@class UIViewController;
@protocol GFPS2SAdClickDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface GFPClickLandingUtil : NSObject

@property (nonatomic, strong) NSString *url;
@property (nonatomic, assign) BOOL forceURLLanding;

@property (nonatomic, assign, readonly) BOOL useCustomClick;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWith:(UIViewController * _Nullable)aTarget
             skAdNetwork:(GFPSKAdNetworkInfo * _Nullable)aSKAdNetwork
           clickDelegate:(id <GFPS2SAdClickDelegate> _Nullable)clickDelegate NS_DESIGNATED_INITIALIZER;

- (void)openLanding:(GFPS2SAdLandingHandler)aCompletion;
- (void)openLandingForExceptSKAdn:(GFPS2SAdLandingHandler)aCompletion;
- (void)openLanding:(GFPS2SAdLandingHandler)aCompletion storeDelegate:(nullable id<SKStoreViewControllerCloseDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
