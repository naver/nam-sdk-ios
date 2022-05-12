//
//  GFPNativeSimpleAdView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPNativeBaseView.h"

#import "GFPNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNativeSimpleAdView : GFPNativeBaseView

@property (nonatomic, strong, nullable) GFPNativeSimpleAd *nativeAd;

@end

NS_ASSUME_NONNULL_END
