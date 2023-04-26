//
//  GFPBannerAdSize.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import "GFPBannerViewLayoutType.h"

typedef NS_OPTIONS(NSInteger, GFPBannerSizeType) {
    GFPBannerFixed = 0,
    GFPBannerFluidWidth = 1,
    GFPBannerFluidHeight = 2,
    GFPBannerFluid = 3,
};

extern CGFloat const kGFPFluidAdSize;
extern CGFloat const kGFPFluidReponseAdSize;

@interface GFPBannerAdSize : NSObject

@property (readonly, nonatomic, assign) CGSize size;
@property (readonly, nonatomic, assign) CGSize fluidSize;
@property (readonly, nonatomic, assign) BOOL isValid;

@property (readonly, nonatomic, assign) GFPBannerSizeType type;
@property (readonly, nonatomic, assign) GFPBannerViewLayoutType layoutType;

- (instancetype)initWithSize:(CGSize)size
                        type:(GFPBannerSizeType)type;

@end

@interface GFPBannerAdSizeHelper : NSObject

+ (GFPBannerSizeType)typeWith:(GFPBannerViewLayoutType)aLayoutType;

@end
