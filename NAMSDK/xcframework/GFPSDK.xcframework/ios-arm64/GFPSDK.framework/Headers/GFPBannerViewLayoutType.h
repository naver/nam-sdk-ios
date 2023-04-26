//
//  GFPBannerViewLayoutType.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#ifndef GFPBannerViewLayoutType_h
#define GFPBannerViewLayoutType_h


typedef NS_OPTIONS(NSInteger, GFPBannerViewLayoutType) {
    GFPBannerViewLayoutTypeFixed = 1 << 0,           // 가로 및 세로 고정 크기
    GFPBannerViewLayoutTypeFluidWidth = 1 << 1,      // 가로 가변, 세로 고정 크기
    GFPBannerViewLayoutTypeFluidHeight = 1 << 2,     // 가로 고정, 세로 가변 크기
    GFPBannerViewLayoutTypeFluid = 1 << 3            // 가로 가변, 세로 가변 크기
};


#endif /* GFPBannerViewLayoutType_h */
