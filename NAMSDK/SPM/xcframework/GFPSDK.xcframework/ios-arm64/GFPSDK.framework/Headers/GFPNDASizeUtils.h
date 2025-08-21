//
//  GFPNDASizeUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPBannerAdSize.h"

@class GFPSchemeComponent;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDABannerSizeInfo : NSObject

@property (nonatomic, readonly, assign) GFPBannerSizeType type;
@property (nonatomic, readonly, assign) CGSize size;

- (instancetype)initWith:(GFPBannerSizeType)aType size:(CGSize)aSize;

@end

@interface GFPNDASizeUtils : NSObject

+ (GFPNDABannerSizeInfo * _Nullable)refineSizeWith:(GFPSchemeComponent *)aComponent frame:(CGRect)aFrame responseSize:(CGSize)aResponseSize;
+ (BOOL)isValidBannerSizeWith:(GFPBannerSizeType)aType layoutType:(GFPBannerViewLayoutType)aLayoutType;

@end

NS_ASSUME_NONNULL_END
