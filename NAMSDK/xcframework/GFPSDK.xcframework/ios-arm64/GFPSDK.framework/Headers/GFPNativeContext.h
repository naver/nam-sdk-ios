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


NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeContextPresentable <NSObject>

@property (nonatomic, weak, nullable) UIViewController *rootViewController;
@property (nonatomic, strong) GFPNativeAdRenderingSetting *renderingSetting;
@property (nonatomic, strong) GFPNativeSimpleAdRenderingSetting *simpleAdRenderingSetting;

@end


@interface GFPNativeContext : GFPContext <GFPNativeContextPresentable>

- (instancetype)initWithRootViewController:(nullable UIViewController *)rootViewController
                          renderingSetting:(GFPNativeAdRenderingSetting *)renderingSetting
                  simpleAdRenderingSetting:(GFPNativeSimpleAdRenderingSetting *)simpleAdRenderingSetting
                             clickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate;

@end

@interface GFPNativeSimpleContext: GFPNativeContext

@end

@interface GFPCombinedContext : GFPNativeContext

- (instancetype)initWithNative:(GFPNativeContext *)nativeContext;

@end


NS_ASSUME_NONNULL_END
