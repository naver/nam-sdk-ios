//
//  GFPNDAAdMuteResourceUtils.h
//  GFPSDKMediationNDA
//
//  Created by sodam on 2022/05/31.
//  Copyright © 2022 Naver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPNativeAdRenderingSetting.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNDAAdChoiceImageType) {
    GFPNDAAdChoiceImageTypeNone = 0,
    GFPNDAAdChoiceImageTypeAD,
    GFPNDAAdChoiceImageTypeI,
    GFPNDAAdChoiceImageTypePrivacy,
    GFPNDAAdChoiceImageTypePrivacyMark,
    GFPNDAAdChoiceImageTypeBack,
    GFPNDAAdChoiceImageTypeLogo,
    GFPNDAAdChoiceImageTypeCustom,
};

typedef NS_OPTIONS(NSInteger, GFPNDAAdChoiceColorType) {
    GFPNDAAdChoiceColorTypeNone = 0,
    GFPNDAAdChoiceColorTypeText,
    GFPNDAAdChoiceColorTypeBackground,
    GFPNDAAdChoiceColorTypeBtnBack,
    GFPNDAAdChoiceColorTypeBtnBorder,
    GFPNDAAdChoiceColorTypeBtnShadow,
    GFPNDAAdChoiceColorTypeHighlightedBtnText,
    GFPNDAAdChoiceColorTypeHighlightedBtnBack,
    GFPNDAAdChoiceColorTypeBlurredText,
};

@class GFPNDAAdChoiceResourceUtils;
@class GFPCustomAsset;


@protocol GFPNDAAdChoiceResourcePresentable <NSObject>

@property (nonatomic, strong, readonly, nullable) GFPNDAAdChoiceResourceUtils *resourceUtils;

- (void)changeResource;

/**
 * View 에서 아래 메소드를 Override 하여, 모드 변경에 따라 리소스를 바꾸어주어야함.
 */
- (void)layoutSubviews;
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection;

@optional
- (void)updateResourceUtilsWith:(GFPNDAAdChoiceResourceUtils *)utils;

@end


@interface GFPNDAAdChoiceResourceUtils : NSObject

@property (nonatomic, strong, readonly) GFPNativeBaseRenderingSetting *renderingSetting;
@property (nonatomic, assign, readonly) BOOL isDarkMode;

- (instancetype)initWith:(GFPNativeBaseRenderingSetting *)renderingSetting;

- (UIImage *)imageWith:(GFPNDAAdChoiceImageType)type;
- (UIImage *)imageWith:(GFPNDAAdChoiceImageType)type customAsset:(GFPCustomAsset * _Nullable)customAsset;

- (UIColor * _Nullable)colorWith:(GFPNDAAdChoiceColorType)type;

@end

NS_ASSUME_NONNULL_END
