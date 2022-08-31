//
//  GFPAdNativeOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

@class GFPNativeAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdNativeOptions : NSObject

/**
 * 광고 렌터링 세팅 (Optional)
 */
@property(readwrite, nonatomic, strong, nullable) GFPNativeAdRenderingSetting *renderingSetting;


@end

NS_ASSUME_NONNULL_END
