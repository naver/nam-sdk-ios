//
//  GFPNDAVideoAdaptor.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import "GFPVideoAdapting.h"
#import "GFPAdAdaptor.h"

@class GFPAdAdaptorParam;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAVideoAdaptor : GFPAdAdaptor <GFPVideoAdapting>

- (instancetype)initWithParam:(GFPAdAdaptorParam *)param error:(GFPError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
