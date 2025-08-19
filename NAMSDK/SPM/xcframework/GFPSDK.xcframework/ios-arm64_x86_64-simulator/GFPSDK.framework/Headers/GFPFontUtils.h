//
//  GFPFontUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPFontUtils : NSObject

+ (UIFont *)customFontWithName:(NSString *)name size:(CGFloat)size;
+ (UIFont *)customFontWithName:(NSString *)name size:(CGFloat)size weight:(UIFontWeight)weight;

@end

NS_ASSUME_NONNULL_END
