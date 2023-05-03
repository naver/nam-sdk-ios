//
//  GFPVideoAdManager+Common.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import "GFPVideoAdManager.h"
NS_ASSUME_NONNULL_BEGIN

@class GFPVideoMediator;

@interface GFPVideoAdManager (Common)

- (void)loadInternal:(GFPVideoMediator *)videoMediator;

@end

NS_ASSUME_NONNULL_END
