//
//  GFPNDANativeAdaptor.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPAdAdaptor.h"
#import "GFPNativeAdapting.h"
#import "GFPAdAdaptorParam.h"

@class GFPNativeBaseView;
@class GFPNDANativeAd;
@class GFPNativeContext;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeAdaptor : GFPNativeAdAdaptor <GFPNativeAdapting>

@property (nonatomic, readonly, strong) GFPNDANativeAd *ndaNativeAd;

- (instancetype)initWithParam:(GFPAdAdaptorParam *)adaptorParam
                        error:(GFPError *_Nullable *_Nullable)error;

- (GFPError * _Nullable)handleRegisterErrorWith:(GFPNativeBaseView *)nativeAdView
                                   nativeAdInfo:(GFPNativeAdInfo *)nativeAdInfo
                                   hasMediaView:(BOOL)hasMediaView;

- (BOOL)isDarkModeWith:(GFPNativeContext *)context;
- (BOOL)enableCustomAdChoicesWith:(GFPNativeContext *)context;

@end

NS_ASSUME_NONNULL_END
