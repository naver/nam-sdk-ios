//
//  GFPCombinedAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPAdAdapting.h"
#import "GFPNativeAdapting.h"
#import "GFPBannerAdapting.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GFPCombinedAdapting <GFPAdAdapting>

@property (readonly, nonatomic, strong, nullable) GFPAdAdaptor <GFPBannerAdapting> *bannerAdaptor;
@property (readonly, nonatomic, strong, nullable) GFPAdAdaptor <GFPNativeAdapting> *nativeAdaptor;

@property (readonly, nonatomic, assign) BOOL nativeLoaded;

@end

NS_ASSUME_NONNULL_END
