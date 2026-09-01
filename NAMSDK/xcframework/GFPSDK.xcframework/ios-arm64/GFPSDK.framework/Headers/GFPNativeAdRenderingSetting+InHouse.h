//
//  GFPNativeAdRenderingSetting+InHouse.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import "GFPNativeAdRenderingSetting.h"

@class GFPCustomAsset;

@interface GFPNativeBaseRenderingSetting ()

/**
 * 네이티브 광고에 adMute 아이콘을 설정합니다.
 * 전달된 리소스가 존재하지 않을 경우, sdk 가 정의한 default 아이콘으로 설정됩니다.
 */
@property (nonatomic, strong) GFPCustomAsset *adMuteCustomAsset DEPRECATED_MSG_ATTRIBUTE("This property will be removed. Use adChoicesCustomAsset.");

/**
 * 네이티브 광고에 adChoices 아이콘을 설정합니다.
 * 전달된 리소스가 존재하지 않을 경우, sdk 가 정의한 default 아이콘으로 설정됩니다.
 */
@property (nonatomic, strong) GFPCustomAsset *adChoicesCustomAsset;

@end
