//
//  GFPNativeAdRenderingSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdInterfaceStyle.h"
#import "GFPAdBackgroundInfo.h"
#import "GFPNativeAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPAdChoicesViewPosition) {
    GFPAdChoicesViewPositionTopRightCorner,
    GFPAdChoicesViewPositionTopLeftCorner,
    GFPAdChoicesViewPositionBottomRightCorner,
    GFPAdChoicesViewPositionBottomLeftCorner
};

@interface GFPNativeBaseRenderingSetting : NSObject

/**
 * 네이티브 광고에 adChoicesView 위치를 설정합니다.
 * NN의 경우 Google DFP adChoiceView 의 위치를 설정하며, Overlay 형식으로 네이티브 뷰의 네 귀퉁이중 한 곳에 그려집니다.
 * NS의 경우 adChoicesView 내부에 마크가 그려집니다.
 * 기본값은 우측상단입니다.
 */
@property (nonatomic, assign) GFPAdChoicesViewPosition preferredAdChoicesViewPosition;

/**
 * 네이티브 광고의 스타일을 설정합니다. (ex. adChoicesView 색상, rich media 광고 배경색 등)
 * 네이버 광고에서 제공하는 광고에 한해 동작하며 그 외 DSP들은 해당 기능을 제공하지 않습니다.
 * 기본값은 시스템의 mode를 따라갑니다.
 */
@property (nonatomic, assign) GFPAdInterfaceStyle adInterfaceStyle;

/**
 * 네이티브 광고의 Custom 배경을 설정합니다.
 * 네이버 광고에서 제공하는 광고에 한해 동작하며 그 외 DSP들은 해당 기능을 제공하지 않습니다.
 */
@property (readwrite, nonatomic, strong, nullable) GFPAdBackgroundInfo *adBackgroundInfo;

/**
 * 네이티브 Media 이미지 적용 시 이미지 사이즈를 우선 할 지 여부입니다.
 * (기본값은  NO)
 * 해당 기능을 YES로 셋팅 시, 셋팅된 광고 영역보다 이미지 사이즈가 우선되며 하단에 배치됩니다.
 */
@property (nonatomic, assign) BOOL isImageSizePreferred;

/**
 * Native  리치형 광고 비디오 플레이어 이벤트를 위한 델리게이트 설정
 */
@property (nonatomic, weak) id<GFPNativeVideoEventDelegate> videoEventDelegate;


@end


@interface GFPNativeAdRenderingSetting : GFPNativeBaseRenderingSetting

/**
 * 모펍 SDK 네이티브 뷰를 직접 렌더링 하는 경우에만 세팅합니다. (설정한 뷰 클래스에 렌더링 됨)
 * GFPNativeAdView를 사용하는 경우, 세팅하지 않습니다.
 *
 * 주의!) 클래스는 UIView 객체이며 MPNativeAdRendering 프로토콜을 구현한 클래스이어야 합니다.
 */
@property (nullable, nonatomic, copy) Class renderingViewClass;

/**
 * 네이티브 광고 레이아웃에 미디어 뷰가 포함되는지 여부에 따라 설정합니다.
 * (기본값은 YES)
 */
@property (nonatomic, assign) BOOL hasMediaView;

@end


@interface GFPNativeSimpleAdRenderingSetting : GFPNativeBaseRenderingSetting

/**
 * 네이티브 Simple형(=단일 이미지뷰) 광고에 AdBadge가 포함되는 지 결정합니다. AdBadge는 우측하단에 그려집니다.
 * (기본값은 YES)
 * 해당 기능은 deprecate 되었으며, 내부의 로직에 의해 AdBadge를 그립니다.
 */
@property (nonatomic, assign) BOOL renderAdBadge DEPRECATED_ATTRIBUTE;;

@end

NS_ASSUME_NONNULL_END
