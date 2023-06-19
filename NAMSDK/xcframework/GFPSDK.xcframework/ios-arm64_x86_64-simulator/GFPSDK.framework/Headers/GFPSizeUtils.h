//
//  GFPSizeUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPSizeUtils : NSObject

+ (BOOL)isSquareWith:(CGSize)aSize;

+ (CGFloat)ratioWith:(CGSize)aSize;

@end

NS_ASSUME_NONNULL_END
