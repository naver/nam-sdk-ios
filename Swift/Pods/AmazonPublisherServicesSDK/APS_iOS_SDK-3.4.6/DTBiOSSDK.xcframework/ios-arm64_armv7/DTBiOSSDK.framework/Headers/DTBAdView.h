//
//  AmazonBanner.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 12/10/18.
//  Copyright © 2018 Krivopaltsev, Eugene. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTBAdView : WKWebView

- (void)evaluateJavaScriptFromString:(NSString *)script;

@end

NS_ASSUME_NONNULL_END
