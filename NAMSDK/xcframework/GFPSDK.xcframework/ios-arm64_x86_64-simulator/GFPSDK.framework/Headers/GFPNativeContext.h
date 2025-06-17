//
//  GFPNativeContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPContext.h"

@class UIViewController;
@class GFPNativeAdRenderingSetting;
@class GFPNativeSimpleAdRenderingSetting;
@class GFPVideoOptions;
@class GFPNativeTemplateOptions;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeContextPresentable <NSObject>

@property (nonatomic, weak, nullable) UIViewController *rootViewController;

@property (nonatomic, strong) GFPNativeAdRenderingSetting *renderingSetting;
@property (nonatomic, strong) GFPNativeSimpleAdRenderingSetting *simpleAdRenderingSetting;

@property (nonatomic, strong) GFPVideoOptions *videoOptions; //for nn
@property (nonatomic, strong) GFPNativeTemplateOptions *templateOptions; //for ns

@end


@interface GFPNativeContext : GFPContext <GFPNativeContextPresentable>

- (instancetype)initWithRootViewController:(nullable UIViewController *)rootViewController
                          renderingSetting:(GFPNativeAdRenderingSetting *)renderingSetting
                              videoOptions:(nullable GFPVideoOptions *)videoOptions
                  simpleAdRenderingSetting:(GFPNativeSimpleAdRenderingSetting *)simpleAdRenderingSetting
                           templateOptions:(nullable GFPNativeTemplateOptions *)templateOptions
                             clickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate;

@end


@interface GFPCombinedContext : GFPNativeContext

- (instancetype)initWithNative:(GFPNativeContext *)nativeContext;

@end


NS_ASSUME_NONNULL_END
