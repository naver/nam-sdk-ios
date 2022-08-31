//
//  GFPAdBannerOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <UIKit/UIKit.h>
#import "GFPBannerViewDelegate.h"
#import "GFPMRAIDSupportSetting.h"
#import "GFPBannerViewLayoutType.h"
#import "GFPAdConfiguration.h"

@class GFPNativeAdRenderingSetting;
@class GFPNativeSimpleAdRenderingSetting;
@class GFPBannerAdSize;
@class GFPAdBannerWebViewOptions;
NS_ASSUME_NONNULL_BEGIN

@interface GFPAdBannerOptions : NSObject

/**
 * 배너 레이아웃 타입. (기본값: GFPBannerViewLayoutTypeFixed)
 */
@property (readwrite, nonatomic, assign) GFPBannerViewLayoutType layoutType;

/**
 * 배너 광고 MetaData 셋팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) NSDictionary <NSString *, NSString *> *hostMeta;

/**
 * 로드된 배너 광고 제공자 명 (없으면 nil)
 */
@property (readonly, nonatomic, strong, nullable) NSString *adProviderName;

/**
 * 로드된 배너 광고 사이즈 정보 (없으면 nil)
 */
@property (readonly, nonatomic, strong) GFPBannerAdSize *adSize;


/**
 * Mraid 추가 feature Support 세팅 정보 ( 0 -> default )
 */
@property (readwrite, nonatomic, setter=setMraidSupportType:) GFPMraidSupportType mraidSupportType;


/**
 * Banner webview option 설정
 */
@property (readwrite, nonatomic, strong) GFPAdBannerWebViewOptions *webViewOption;

@end

@interface GFPAdBannerWebViewOptions : NSObject

/**
 * Banner Inset 설정 insets mode
 */
@property (readwrite, assign) UIScrollViewContentInsetAdjustmentBehavior contentInsetAdjustmentBehavior;
/**
 * Banner Inset 설정 default size
 */
@property (readwrite, assign) CGPoint defaultContentOffset;

@end


NS_ASSUME_NONNULL_END
