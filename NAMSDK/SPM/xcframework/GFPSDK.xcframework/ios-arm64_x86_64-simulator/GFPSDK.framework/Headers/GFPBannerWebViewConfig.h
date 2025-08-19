//
//  GFPBannerWebViewConfig.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface GFPBannerWebViewConfig : NSObject


+ (GFPBannerWebViewConfig *)sharedInstance;


- (WKWebViewConfiguration *)configuration;
- (WKWebViewConfiguration *)companionConfiguration;


@end

NS_ASSUME_NONNULL_END
