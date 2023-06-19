//
//  GFPBannerAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPAdAdapting.h"

@protocol GFPBannerAdaptorDelegate;

@class GFPAd;
@class GFPAdAdaptorParam;
@class GFPAdAdaptor;
@class GFPBannerAdSize;


NS_ASSUME_NONNULL_BEGIN


@protocol GFPBannerAdapting <GFPAdAdapting>

@property(readwrite, nonatomic, weak) id <GFPBannerAdaptorDelegate> delegate;
@property(readwrite, nonatomic, strong) UIView *adView;
@property(readwrite, nonatomic, strong) GFPBannerAdSize *bannerAdSize;

@end




NS_ASSUME_NONNULL_END
