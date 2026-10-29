//
//  GFPNativeProtocol.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPNativeAccessibilityItem.h"

@class GFPNativeBaseView;
@class GFPMediaView;
@class GFPLabelOption;
@class GFPAdChoicesData;
@class GFPMediaData;
@class GFPIconData;
@class GFPNativeBaseRenderingSetting;
@class GFPAdStyleOption;

@protocol GFPNativeAssetProtocol <NSObject>

/**
 * 타이틀
 */
@property (nullable, readonly, nonatomic, strong) NSString *title;
@property (nullable, readonly, nonatomic, strong) GFPLabelOption *titleOption;

/**
 * 본문
 */
@property (nullable, readonly, nonatomic, strong) NSString *body;
@property (nullable, readonly, nonatomic, strong) GFPLabelOption *bodyOption;

/**
 * Media 관련 정보
 */
@property (readonly, nonatomic, strong, nullable) GFPMediaData *mediaData;

/**
 * icon 관련 정보
 */
@property (readonly, nonatomic, strong, nullable) GFPIconData *iconData;


/**
 * AdChoices 관련 정보
 */
@property (readonly, nonatomic, strong, nullable) GFPAdChoicesData *adChoicesData;

/**
 * 광고주 명
 */
@property (nullable, readonly, nonatomic, strong) NSString *advertiser;
@property (nullable, readonly, nonatomic, strong) GFPLabelOption *advertiserOption;

/**
 * 클릭 버튼 텍스트
 */
@property (nullable, readonly, nonatomic, strong) NSString *callToAction;
@property (nullable, readonly, nonatomic, strong) GFPLabelOption *callToActionOption;

/**
 * Ad Badge
 */
@property (nullable, readonly, nonatomic, strong) NSString *badge;

/**
 * 고지 문구
 */
@property (nullable, readonly, nonatomic, strong) NSString *notice;
@property (nullable, readonly, nonatomic, strong) GFPLabelOption *noticeOption;

/**
 * Social Context
 */
@property (nullable, readonly, nonatomic, strong) NSString *socialContext;

/**
 * Icon Image 존재 여부
 */
@property (readonly, nonatomic, assign) BOOL hasIconImage;

/**
 * 그 외 정보
 * - iconSize
 *   - key: kGFPNativeIconSizeKey, value: icon view 소재 크기. 존재하지 않으면 CGSizeZero 를 반환.
 */
@property (nullable, readonly, nonatomic, strong) NSDictionary <NSString *, NSObject *> *extraInfo;

/**
 * s2s 광고 시 Extra Texts
 */
- (NSString * _Nullable)extraTextWith:(NSString * _Nonnull)key;
- (GFPLabelOption * _Nullable)extraLabelOptionWith:(NSString * _Nonnull)key;

/**
 * s2s 광고 시 Extra Images
 */
- (UIImage * _Nullable)extraImageWith:(NSString * _Nonnull)key;
- (NSURL * _Nullable)extraImageUrlWith:(NSString * _Nonnull)key;
- (NSString * _Nullable)extraImageAccessibilityWith:(NSString * _Nonnull)key;

@end

@protocol GFPNativeAssetViewProtocol <NSObject>

@optional

- (UILabel *_Nullable)titleAssetView;
- (UILabel *_Nullable)bodyAssetView;
- (UILabel *_Nullable)advertiseAssetView;
- (UILabel *_Nullable)socialContextAssetView;
- (UILabel *_Nullable)ctaAssetView;
- (UILabel *_Nullable)adBadgeAssetView;
- (UILabel *_Nullable)noticeAssetView;

- (UIImageView * _Nullable)iconContainerView;
- (GFPMediaView * _Nullable)mediaContainerView;
- (UIView * _Nullable)adChoicesContainerView;

- (UIView * _Nullable)serviceAdBadgeContainerView;

- (UIView * _Nullable)extraViewWith:(NSString * _Nonnull)key;

@end

@protocol GFPNativeTemplateViewProtocol <GFPNativeAssetViewProtocol>

+ (UIView * _Nullable)createView;

- (void)bindWith:(id <GFPNativeAssetProtocol> _Nullable)asset;
- (void)changeStyleWith:(BOOL)isDarkMode;

@optional

- (CGFloat)estimateHeight;
- (CGFloat)scaleRatio;

- (void)updateRenderingSetting:(GFPNativeBaseRenderingSetting * _Nullable)renderingSetting NS_SWIFT_NAME(updateRenderingSetting(renderingSetting:));
- (void)updateAdStyleOptionWith:(GFPAdStyleOption * _Nullable)defaultOption darkOption:(GFPAdStyleOption * _Nullable)darkOption;
- (void)updateExtraInfo:(NSDictionary<NSString *, NSObject *> * _Nullable)info;

/**
 * 광고 단위 단일 포커스 접근성 문구에 들어갈 항목을 화면에 보이는 순서(눈 흐름)대로 돌려준다.
 * - 화면에 그려진 에셋만 넣는다. 엑스트라 이미지는 alt 가 있을 때만 Text 로 넣는다 (alt 없으면 읽지 않음).
 * - "광고" 접두어와 AI 활용 접두어는 SDK 가 붙이므로 포함하지 않는다. 빈 항목은 SDK 가 제외한다.
 * - 미구현이거나 nil 을 돌려주면 SDK 기본 순서(광고주 → 제목 → 본문 → 메인 이미지 → CTA → 고지)를 쓴다.
 */
- (NSArray<GFPNativeAccessibilityItem *> * _Nullable)accessibilitySummaryItems;

@end
