//
//  GFPErrorUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPProvider.h"

@class GFPError;
@class GFPAdInfoSize;

NS_ASSUME_NONNULL_BEGIN

static NSString *const GFPProviderClassItem = @"GFPProviderClassItem";


@interface GFPErrorUtils : NSObject

+ (GFPError *)providerInitlizeErrorWith:(GFPProviderCreativeType)aType message:(NSString *)aMessage;

+ (GFPError *)nativeAdRenderingErrorWithMediaViewSetting:(BOOL)hasMediaView
                                      adViewHasMediaView:(BOOL)adViewHasMediaView;

+ (GFPError *)nativeAdRenderingErrorWithMessage:(NSString *)message;

+ (GFPError *)adSizeErrorWithRequestSizes:(NSArray<GFPAdInfoSize *> *)reqSizes;

+ (GFPError *)adSizeErrorWithResponseSize:(GFPAdInfoSize *)respSize;

+ (GFPError *)noFillErrorWithDesc:(nullable NSString *)desc;

+ (GFPError *)noFillError;

@end

NS_ASSUME_NONNULL_END
