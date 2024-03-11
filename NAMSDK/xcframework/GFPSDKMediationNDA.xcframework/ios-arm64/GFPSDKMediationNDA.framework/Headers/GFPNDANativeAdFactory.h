//
//  GFPNDANativeAdFactory.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPNDANativeAd.h"
#import "GFPProvider.h"

@class GFPAdAdaptorParam;
@class GFPNativeContext;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNDANativeType) {
    GFPNDANativeSimple = 1 << 0,
    GFPNDANativeNormal = 1 << 1,
    GFPNDANativeComposite = 1 << 2,
};


@interface GFPNDANativeAdFactory : NSObject

+ (GFPNDANativeAd *)creativeNativeParamWith:(GFPAdAdaptorParam *)aAdParam
                                    context:(GFPNativeContext *)context;

@end

NS_ASSUME_NONNULL_END
