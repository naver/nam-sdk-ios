//
//  GFPMediator.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

#import "GFPLoadResponseInfo+Common.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPMediator : NSObject <GFPResponseInfoPresentable>

@property (nonatomic, strong, readonly) NSDictionary *preloadWaterfallDict;

- (instancetype)initWithPreloadWaterfallResponse:(NSDictionary *)preloadWaterfallDict;

@end

NS_ASSUME_NONNULL_END
