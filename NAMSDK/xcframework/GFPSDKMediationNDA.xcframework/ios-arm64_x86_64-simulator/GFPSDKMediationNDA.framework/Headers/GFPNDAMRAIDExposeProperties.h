//
//  GFPNDAMRAIDExposeProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAMRAIDExposeProperties : NSObject

- (instancetype)initWithExpose:(CGFloat)percentage visibleRect:(CGRect)aVisibleRect;

- (NSString * _Nullable)updateJavaScriptExpose:(CGFloat)aExpose visibleRect:(CGRect)aVisibleRect;

@end

NS_ASSUME_NONNULL_END
