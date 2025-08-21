//
//  GFPNDANativeSimpleAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPNDANativeAd.h"
#import "GFPNativeAdRenderingSetting.h"

@class GFPNativeAdInfo;
@class GFPNDANativeSimpleAd;
@class GFPNativeTemplateOptions;

NS_ASSUME_NONNULL_BEGIN

static CGFloat const kRichNaverAppBottomLayoverDefaultHeight = 24;

@interface GFPNDANativeSimpleAd : GFPNDANativeAd

@property (nonatomic, strong) GFPNativeTemplateOptions *templateOptions;
@property (nonatomic, readonly, assign) BOOL isImageSizePreferred;
@end

NS_ASSUME_NONNULL_END
