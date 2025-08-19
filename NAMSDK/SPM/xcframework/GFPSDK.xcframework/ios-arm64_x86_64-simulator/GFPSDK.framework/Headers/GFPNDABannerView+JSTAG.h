//
//  GFPNDABannerView+JSTAG.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "GFPNDABannerView.h"

@class GFPSchemeComponent;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDABannerView (JSTAG) 

- (void)handleJsTagSchemeWith:(GFPSchemeComponent *)component;

@end

NS_ASSUME_NONNULL_END
