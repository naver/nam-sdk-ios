//
//  GFPAdDedupeManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAdLoader;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdDedupeManager : NSObject

@property (readonly, nonatomic, assign) NSInteger numAdsDeduped;

- (instancetype)initWithNumAdsDeduped:(NSInteger)numAdsDeduped;

- (void)loadAdWith:(GFPAdLoader *)adLoader;

@end

NS_ASSUME_NONNULL_END
