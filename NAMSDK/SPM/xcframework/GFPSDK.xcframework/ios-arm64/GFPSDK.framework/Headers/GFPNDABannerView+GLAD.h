//
//  GFPNDABannerView+GLAD.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPNDABannerView.h"
#import "GFPSchemeCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDABannerView (GLAD)

// bridge.js
- (void)notifyGladReadyEvent;
- (void)updateFluidWidthSupported;
- (void)notifyHostMetaChanged;
- (void)handleGLADSchemeWith:(GFPSchemeComponent *)component;

// admute.js
- (void)registerAdMuteEvent;
- (void)updateAdMuteTheme;

@end

NS_ASSUME_NONNULL_END
