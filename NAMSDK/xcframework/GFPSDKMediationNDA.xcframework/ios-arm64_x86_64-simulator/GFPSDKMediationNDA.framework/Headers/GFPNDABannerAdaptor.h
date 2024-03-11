//
//  GFPNDABannerAdaptor.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import "GFPAdAdaptor.h"
#import "GFPBannerAdapting.h"

@class GFPAdAdaptorParam;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDABannerAdaptor : GFPAdAdaptor <GFPBannerAdapting>

- (instancetype)initWithParam:(GFPAdAdaptorParam *)adaptorParam
                        error:(GFPError *_Nullable *_Nullable)error;


@end

NS_ASSUME_NONNULL_END
