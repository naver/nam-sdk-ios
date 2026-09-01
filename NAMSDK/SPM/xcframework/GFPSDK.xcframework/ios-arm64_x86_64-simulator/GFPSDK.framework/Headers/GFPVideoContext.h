//
//  GFPVideoContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "GFPContext.h"
#import "GFPVideoAdPlacement.h"


NS_ASSUME_NONNULL_BEGIN
@class GFPNativeBaseRenderingSetting;
@class GFPVideoAdRenderingSetting;

@interface GFPVideoContext : GFPContext

@property (nonatomic, weak) UIView *videoView;
@property (nonatomic, strong, nullable) GFPVideoAdRenderingSetting *renderingSetting;
@property (nonatomic, strong, nullable) GFPNativeBaseRenderingSetting *adRenderingSetting;

@property (readonly, nonatomic, assign) GFPVideoPlacementType placementType;
@property (readonly, nonatomic, weak, nullable) UIViewController *rootViewController;

- (instancetype)initWithVideoView:(UIView *)videoView
                 renderingSetting:(GFPVideoAdRenderingSetting * _Nullable)renderingSetting
                    placementType:(GFPVideoPlacementType)aType
                    clickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate
                            logId:(NSUUID *)logId;

- (instancetype)initWithVideoView:(UIView *)videoView
                 renderingSetting:(GFPVideoAdRenderingSetting * _Nullable)renderingSetting
                    placementType:(GFPVideoPlacementType)aType
                    clickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate
               rootViewController:(UIViewController * _Nullable)rootViewController
                            logId:(NSUUID *)logId;

- (instancetype)initWithVideoView:(UIView *)videoView
                 renderingSetting:(GFPVideoAdRenderingSetting *)renderingSetting
                    placementType:(GFPVideoPlacementType)aType
                    clickDelegate:(nullable id<GFPS2SAdClickDelegate>)clickDelegate
               rootViewController:(UIViewController * _Nullable)rootViewController
               adRenderingSetting:(nullable GFPNativeBaseRenderingSetting *)adRenderingSetting
                            logId:(NSUUID *)logId;

@end

NS_ASSUME_NONNULL_END
