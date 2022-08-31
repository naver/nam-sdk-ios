//
//  GFPAdNativeSimpleOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

@class GFPNativeSimpleAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdNativeSimpleOptions : NSObject

/**
 * 네이티브 Simple 형(=단일 이미지) 광고 렌더링 세팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) GFPNativeSimpleAdRenderingSetting *simpleAdRenderingSetting;


@end

NS_ASSUME_NONNULL_END
