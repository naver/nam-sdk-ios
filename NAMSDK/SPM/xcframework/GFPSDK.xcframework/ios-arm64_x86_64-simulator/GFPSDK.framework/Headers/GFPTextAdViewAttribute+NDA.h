//
//  GFPTextAdViewAttribute+NDA.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPTextAdViewAttribute;
NS_ASSUME_NONNULL_BEGIN

@interface GFPNDATextAdViewAttribute : NSObject


+ (GFPTextAdViewAttribute *)landscapeAttribute;
+ (GFPTextAdViewAttribute *)portraitAttribute;


@end

NS_ASSUME_NONNULL_END
