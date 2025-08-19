//
//  GFPMediaCropInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPMediaCropInfo : NSObject

@property (nonatomic, readonly) CGRect rect;
@property (nonatomic, readonly) UIViewContentMode contentMode;
@property (nonatomic, readonly) CGFloat scaleFactor;

- (instancetype)initWith:(CGSize)aSize contentMode:(UIViewContentMode)aContentMode;
- (instancetype)initWith:(CGSize)aSize contentMode:(UIViewContentMode)aContentMode scaleFactor:(CGFloat)factor;

@end

NS_ASSUME_NONNULL_END
