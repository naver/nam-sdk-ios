//
//  UIView+AmazonMediation.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 12/11/18.
//  Copyright © 2018 Krivopaltsev, Eugene. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (DTB)

- (void)setWidth:(CGFloat) width height:(CGFloat)height;
- (void)setBorderWidth:(CGFloat)width borderColor:(UIColor *)borderColor;
- (void)setParentSize;
- (void)setParentWidth;
- (void)setParentHeight;

-(UIViewController *)findOwningController;
- (NSArray *)findChildrenOfClass:(Class) clz;
- (UIView *) findAncestorOfClass:(Class) clz;
+ (UIInterfaceOrientation)currentOrientation;
- (CGSize) screenSize;
- (CGSize) maxSize;

+ (UIViewController *)getTopViewController;
+ (BOOL)isStoreKitInTheForeground;

@end

NS_ASSUME_NONNULL_END
