//
//  GFPNativeAdRenderingSetting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
  


#import <UIKit/UIKit.h>

#import "GFPNativeAdDelegate.h"
#import "GFPNativeProtocol.h"

#import "GFPOMFriendlyObstruction.h"

#import "Swift-Enum.h"

@class GFPBackgroundOption;

NS_ASSUME_NONNULL_BEGIN

typedef CGFloat (^GFPMaxExtendingHeightSetter)(void);

typedef NS_OPTIONS(NSInteger, GFPAdChoicesViewPosition) {
    GFPAdChoicesViewPositionTopRightCorner = 1,
    GFPAdChoicesViewPositionTopLeftCorner,
    GFPAdChoicesViewPositionBottomRightCorner,
    GFPAdChoicesViewPositionBottomLeftCorner,
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
 * 네이티브 광고에 adChoicesView 위치를 미디어 크기로 정할 지
 * 전체 광고뷰로 정할 지 설정하는 옵션입니다.
 * s2s 광고에 한해 지원되며, YES인 경우 전체 광고뷰로 설정합니다.
 * 기본값은 NO입니다.
 */
@property (nonatomic, assign) BOOL adChoicesPositionInFullAdView;

/**
 * 네이티브 광고의 스타일을 설정합니다. (ex. adChoicesView 색상, rich media 광고 배경색 등)
 * 네이버 광고에서 제공하는 광고에 한해 동작하며 그 외 DSP들은 해당 기능을 제공하지 않습니다.
 * 기본값은 시스템의 mode를 따라갑니다.
 */
@property (nonatomic, assign) GFPAdInterfaceStyle adInterfaceStyle;

/**
 * 네이티브 광고의 adChoices 를 Custom 하게 사용할 경우 활성화 합니다.
 * 해당 옵션을 활성할 경우 GFP는 adChoicesView 를 그리지 않습니다.
 * 단, s2s 광고에 한해 제공합니다. (c2s의 경우 옵션과 관계 없이 처리)
 * 기본값은 NO 입니다.
 */
@property (nonatomic, assign) BOOL enableCustomAdChoices;

/**
 * 캐러셀 광고 시 슬롯의 여백 값 입니다.
 * 해당 값을 통해 캐로셀 콜렉션뷰의 inset을 지원합니다.
 */
@property (nonatomic, assign) UIEdgeInsets richMediaInsets;

/**
 * 캐러셀 광고의 MediaView 내부 폰트를 설정하고 싶을 때 전달합니다.
 * (기본값은 nil)
 */
@property (nonatomic, strong, nullable) UIFont *mediaRegularFont;

/**
 * 캐러셀 광고의 MediaView 내부 폰트를 설정하고 싶을 때 전달합니다.
 * (기본값은 nil)
 */
@property (nonatomic, strong, nullable) UIFont *mediaBoldFont;

/**
 * Special DA의 기본 탑 마진을 사용하지 않고 아래 확장만 사용할 시에 사용합니다.
 * (기본값은 NO)
 */
@property (nonatomic, assign) BOOL enableSpecialDABottomExtend;

/**
 * 광고의 MediaView에 Dimmed를 설정하고 싶을 때 설정합니다.
 * 옵션 사용 시 2%의 Dimmed가 적용됩니다. / 아웃스트림 동영상은 8%의 Dimmed가 적용됩니다.
 * (기본값은 NO)
 */
@property (nonatomic, assign) BOOL useMediaDimmed;

/**
 * OMSDK를 측정하는 광고의 friendlyObstruction을 설정합니다.
 * - s2s의 경우 OMSDK 의 friendlyObstruction을 설정함.
 * - c2s의 경우 동작하지 않음.
 *   - LAN AP에 한하여 view만 전달함.
 */
@property (nonatomic, strong, nullable) NSArray <GFPOMFriendlyObstruction *> *omFriendlyObstructions;

/**
 * Native 광고의 Media / Icon 등의 이미지 로딩을 LazyLoading으로 처리하고 싶을 때 사용합니다.
 * GFPNativeAdView의
 * (기본값은 NO)
 */
@property (nonatomic, assign) BOOL useLazyMediaLoading;

/**
 * 네이티브 Media 이미지 적용 시 이미지 사이즈를 우선 할 지 여부입니다.
 * (기본값은  NO)
 * 해당 기능을 YES로 셋팅 시, 셋팅된 광고 영역보다 이미지 사이즈가 우선되며 하단에 배치됩니다.
 */
@property (nonatomic, assign) BOOL isImageSizePreferred;

@end


@interface GFPNativeAdRenderingSetting : GFPNativeBaseRenderingSetting

/**
 * 네이티브 광고 레이아웃에 미디어 뷰가 포함되는지 여부에 따라 설정합니다.
 * (기본값은 YES)
 */
@property (nonatomic, assign) BOOL hasMediaView;

/**
 * 네이티브 광고 미디어뷰 여백의 블러처리 여부를 설정합니다.
 * (기본값은 NO)
 */
@property (nonatomic, assign) BOOL enableMediaBackgroundBlur;

/**
 * 네이티브 광고 성능을 위해 Internal Cache를 사용할 지 결정합니다.
 * (기본값은 NO)
 */
@property (nonatomic, assign) BOOL useInternalCache;

@end


@interface GFPNativeSimpleAdRenderingSetting : GFPNativeBaseRenderingSetting

/**
 * 네이티브 심플에 기반한  리치형 광고 비디오 플레이어 이벤트를 위한 델리게이트 설정
 */
@property (nonatomic, weak) id<GFPNativeVideoEventDelegate> videoEventDelegate;

/**
 * 확장형 리치형 광고의 최대 확장 높이를 제한합니다.
 * 광고가 호출된 이후에도 동적으로 관리할 수 있습니다.
 * 9:16 비율의 동영상도 제공하는 스페셜 DA 프리미엄형 "뉴" 동영상 확장형 이후로 부터 출시된 일부 광고 상품 부터 적용됩니다.
 * - maxExtendingHeight <= 0: 높이를 제한하지 않음
 * - maxExtendingHeight > 0: 높이를 제한 함.
 * (기본값 -1)
 */
@property (nonatomic, copy, nullable) GFPMaxExtendingHeightSetter maxExtendingHeight;

/**
 * Sets Native Simple Ad's background style.
 * Background style in ad response overrides this option.
 */
@property (nonatomic, strong, nullable) GFPBackgroundOption *backgroundOption;

@end

NS_ASSUME_NONNULL_END
