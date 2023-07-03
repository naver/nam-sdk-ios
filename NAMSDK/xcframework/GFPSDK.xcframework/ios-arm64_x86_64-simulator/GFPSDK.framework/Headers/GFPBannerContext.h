//
//  GFPBannerContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <Foundation/Foundation.h>
#import "GFPContext.h"
#import "Swift-Enum.h"
@class UIViewController;
@class GFPAdBannerWebViewOptions;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kNDAHostMetaThemeKey;
extern NSString *const kNDAHostMetaThemeSystem;
extern NSString *const kNDAHostMetaThemeDark;
extern NSString *const kNDAHostMetaThemeLight;

@interface GFPBannerContext : GFPContext

@property (nonatomic, weak, nullable) UIViewController *rootViewController;

@property (nonatomic, strong, nullable) NSDictionary <NSString *, NSString *> *hostMeta;
@property (nonatomic, assign) GFPBannerViewLayoutType layoutType;
@property (nonatomic, strong, nullable) GFPAdBannerWebViewOptions *webViewOptions;

- (instancetype)initWithRootViewController:(nullable UIViewController *)rootViewController
                                  hostMeta:(NSDictionary <NSString *, NSString *> *)hostMeta
                                layoutType:(GFPBannerViewLayoutType)layoutType
                            webViewOptions:(nullable GFPAdBannerWebViewOptions *)webViewOptions
                             clickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate;

@end

NS_ASSUME_NONNULL_END
