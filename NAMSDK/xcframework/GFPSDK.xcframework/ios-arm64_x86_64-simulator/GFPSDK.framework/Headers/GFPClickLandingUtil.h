//
//  GFPClickLandingUtil.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPSKAdNetworkInfo;
@class UIViewController;


NS_ASSUME_NONNULL_BEGIN

@interface GFPClickLandingUtil : NSObject

@property (nonatomic, strong) NSString *url;
@property (nonatomic, assign) BOOL forceURLLanding;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(UIViewController *)aTarget skAdNetwork:(GFPSKAdNetworkInfo * _Nullable)aSKAdNetwork NS_DESIGNATED_INITIALIZER;

- (void)openLanding:(void (^)(BOOL isSuccess))aCompletion;

@end

NS_ASSUME_NONNULL_END
