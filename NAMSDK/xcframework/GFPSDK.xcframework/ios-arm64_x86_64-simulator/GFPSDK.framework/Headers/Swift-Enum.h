//
//  Swift-Enum.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#ifndef Swift_Enum_h
#define Swift_Enum_h

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, GFPPhaseType) {
    GFPPhaseTypeAlpha = 1,
    GFPPhaseTypeDev = 2,
    GFPPhaseTypeTest = 3,
    GFPPhaseTypeReal = 4,
};

typedef NS_OPTIONS(NSInteger, GFPAdInterfaceStyle) {
    GFPAdInterfaceStyleSystem = 1,
    GFPAdInterfaceStyleLight = 2,
    GFPAdInterfaceStyleDark = 3,
};

typedef NS_OPTIONS(NSInteger, GFPAdProviderSettingType) {
    GFPAdProviderSettingTypeNone = 0,
    GFPAdProviderSettingTypeDFP = 1,
    GFPAdProviderSettingTypeFAN = 2,
    GFPAdProviderSettingTypeUnity = 3,
    GFPAdProviderSettingTypeOMID = 100,
};

typedef NS_ENUM(NSInteger, GFPBannerViewLayoutType) {
    GFPBannerViewLayoutTypeFixed = 0,
    GFPBannerViewLayoutTypeFluidWidth = 1,
    GFPBannerViewLayoutTypeFluidHeight = 2,
    GFPBannerViewLayoutTypeFluid = 3,
};

typedef NS_ENUM(NSInteger, GFPATTAuthorizationStatus) {
    GFPATTAuthorizationStatusNotDetermined = 0,
    GFPATTAuthorizationStatusRestricted = 1,
    GFPATTAuthorizationStatusDenied = 2,
    GFPATTAuthorizationStatusAuthorized = 3,
};

/**
 * RemindText 노출 위치에 따른 Type
 * Container Inner : Content Player 영역 내부 노출.
 * Container Outer : Content Player 영역 외l부 노출.
 */
typedef NS_OPTIONS(NSInteger, GFPNonLinearContainerType) {
    GFPNonLinearContainerTypeOuter = 1,
    GFPNonLinearContainerTypeInner = 2,
};
typedef NS_OPTIONS(NSInteger, GFPOMContantsType);

typedef NS_ENUM(NSInteger, GFPNativeAdMediaType){
    GFPNativeAdMediaTypeUnknown = 0,
    GFPNativeAdMediaTypeImage = 1,
    GFPNativeAdMediaTypeVideo = 2,
    GFPNativeAdMediaTypeHtml = 3,
    GFPNativeAdMediaTypeSVG = 4,
    GFPNativeAdMediaTypeLottie = 5,
};
typedef NS_OPTIONS(NSInteger, GFPNativeAdDataType){
    GFPNativeAdDataTypeTitle = 1,
    GFPNativeAdDataTypeMedia = 2,
    GFPNativeAdDataTypeBody = 3,
    GFPNativeAdDataTypeIcon = 4,
    GFPNativeAdDataTypeSponsor = 5,
    GFPNativeAdDataTypeBadge = 6,
    GFPNativeAdDataTypeCTA = 7,
    GFPNativeAdDataTypeNotice = 8,
    GFPNativeAdDataTypeExtraText = 9,
};


typedef NS_OPTIONS(NSInteger, GFPVideoAudioSettingType){
    GFPVideoAudioSettingTypeDefault = 1, /* Audio unplug 시 광고 정지 (Default : AVPlayer 기본 동작) */
    GFPVideoAudioSettingTypeAuto = 2, /* Audio unplug : 광고 정지, Audio plug : 광고 재생 */
};

#endif /* Swift_Enum_h */
