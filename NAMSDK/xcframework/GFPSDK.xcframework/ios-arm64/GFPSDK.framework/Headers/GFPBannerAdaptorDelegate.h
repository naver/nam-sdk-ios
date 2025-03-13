//
//  GFPBannerAdaptorDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@protocol GFPBannerAdapting;

@class GFPAdAdaptor;
@class GFPBannerAdSize;
@class GFPError;

typedef NS_OPTIONS(NSUInteger, GFPBannerSizeChangeType){
    GFPBannerSizeChangeDefault = 1 << 0,
    GFPBannerSizeChangeRestore = 1 << 1,    //MRAID
    GFPBannerSizeChangeResized = 1 << 2,    //MRAID
};

NS_ASSUME_NONNULL_BEGIN

@protocol GFPBannerAdaptorDelegate <NSObject>

@required

- (void)bannerAdDidFailedToRendering:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor error:(GFPError *)error;

- (void)bannerAdWasClicked:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;
- (void)bannerAdWasOnActiveImpression:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;

- (void)bannerAdaptor:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor didChangeWith:(GFPBannerAdSize *)size type:(GFPBannerSizeChangeType)changeType;

// For Mraid.
- (void)bannerShouldUnload:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;

// For NDA
- (void)bannerAdaptor:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor didChangeWith:(NSDictionary *)adMeta;
- (void)bannerAdWasMuted:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;

@optional
- (void)bannerAdaptorDidPresentDefaultInAppBrowser:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;
- (void)bannerAdaptorDidDismissDefaultInAppBrowser:(GFPAdAdaptor <GFPBannerAdapting> *)bannerAdaptor;

@end

NS_ASSUME_NONNULL_END
