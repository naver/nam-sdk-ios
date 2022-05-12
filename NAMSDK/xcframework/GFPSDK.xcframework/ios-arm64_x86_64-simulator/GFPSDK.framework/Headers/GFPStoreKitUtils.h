//
//  GFPStoreKitUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SKStoreProductViewController (GFPUtils)

+ (BOOL)canUseStoreProduct;

@end


@interface GFPStoreProductHelper : NSObject

- (instancetype)initWithTarget:(UIViewController * _Nonnull)aTarget paramaters:(NSDictionary * _Nonnull)aDict;

- (void)loadProductWith:(void (^)(BOOL isSuccess))aCompletion;

@end

NS_ASSUME_NONNULL_END
