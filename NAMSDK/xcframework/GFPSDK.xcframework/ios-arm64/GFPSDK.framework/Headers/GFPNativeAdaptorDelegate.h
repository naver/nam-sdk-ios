//
//  GFPNativeAdaptorDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>

@protocol GFPNativeAdapting;

@class GFPError;
@class GFPAdAdaptor;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeAdaptorDelegate <NSObject>
@required
- (void)nativeAdWasClicked:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdaptor;

- (void)nativeAdWasOnActiveImpression:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdaptor;

- (void)nativeAdAdaptor:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdAdaptor didFailWithError:(GFPError *)error;

- (void)nativeAdAdaptor:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdAdaptor didChangeMediaViewSizeWith:(CGSize)size;

- (void)nativeAdWasMuted:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdaptor;

@optional
- (void)nativeAdAdaptor:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdAdaptor richAdExtendSizeChanged:(CGSize)size;
- (void)nativeAdAdaptorDidReloadMedia:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdAdaptor;
- (void)nativeAdAdaptor:(GFPAdAdaptor <GFPNativeAdapting> *)nativeAdAdaptor didReloadFailWithError:(GFPError *)error;

@end

NS_ASSUME_NONNULL_END
