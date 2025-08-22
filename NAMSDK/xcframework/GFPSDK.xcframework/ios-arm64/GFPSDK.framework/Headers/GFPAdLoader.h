//
//  GFPAdLoader.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPAdLoaderDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPAdParam;
@class GFPAdBannerOptions;
@class GFPAdNativeSimpleOptions;
@class GFPAdNativeOptions;
@class GFPBannerContext;
@class GFPNativeContext;

@protocol GFPBannerViewDelegate;
@protocol GFPNativeSimpleAdDelegate;
@protocol GFPNativeAdDelegate;
@protocol GFPS2SAdClickDelegate;


@interface GFPAdLoader : NSObject

@property (readonly, nonatomic, strong) NSString *adUnitID;

@property (readonly, nonatomic, strong) GFPAdParam *adParam;

@property (readwrite, nonatomic, weak) id <GFPAdLoaderDelegate> delegate;

/**
 * 광고 요청이후 로드 완료시점까지 타임아웃 (Optional)
 */
@property (readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

/**
 * 통합 로더 초기화.
 * @param adUnitID              배너 광고 유닛 아이디
 * @param rootViewController    루트 뷰 컨트롤러
 * @param adParam               광고 요청에 사용할 파라미터
 */
- (instancetype)initWithUnitID:(NSString *)adUnitID
            rootViewController:(UIViewController *)rootViewController
                       adParam:(GFPAdParam *)adParam;

/**
 * 통합 로더를 통해 배너 광고 로드 시 사용.
 * @param bannerDelegate 광고 요청 결과를 받을 수 있는 delegate.
 * @param bannerOptions   배너 광고 옵션.
 */
- (void)setBannerDelegate:(id <GFPBannerViewDelegate>)bannerDelegate
            bannerOptions:(nonnull GFPAdBannerOptions *)bannerOptions;

/**
 * 통합 로더를 통해 네이티브 이미지형 (Native Simple) 로드 시 사용.
 * @param nativeSimpleDelegate 광고 요청 결과를 받을 수 있는 delegate.
 * @param nativeSimpleOptions   네이티브 광고 옵션 설정 (SimpleAdRenderingSetting - Default : YES)
*/
- (void)setNativeSimpleDelegate:(id <GFPNativeSimpleAdDelegate>)nativeSimpleDelegate
            nativeSimpleOptions:(nullable GFPAdNativeSimpleOptions *)nativeSimpleOptions;

/**
 * 통합 로더를 통해 네이티브 로드 시 사용.
 * @param nativeDelegate 광고 요청 결과를 받을 수 있는 delegate.
 * @param nativeOptions  네이티브 광고 옵션 설정
*/
- (void)setNativeDelegate:(id <GFPNativeAdDelegate>)nativeDelegate
            nativeOptions:(nullable GFPAdNativeOptions *)nativeOptions;

/**
 * 통합 로더에 광고 요청
*/
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
