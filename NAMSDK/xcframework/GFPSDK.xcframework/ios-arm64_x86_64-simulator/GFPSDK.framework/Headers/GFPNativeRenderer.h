//
//  GFPNativeRenderer.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GFPNativeBaseView;
@class GFPLabelOption;
@class GFPAdChoicesData;
@class GFPMediaData;
@class GFPIconData;
@class GFPNativeBaseRenderingSetting;

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
- (NSString * _Nullable)extraImageAccessibilityWith:(NSString * _Nonnull)key;

@end

@protocol GFPNativeAssetViewProtocol <NSObject>

@optional

- (UIView *_Nullable)titleAssetView;
- (UIView *_Nullable)bodyAssetView;
- (UIView *_Nullable)advertiseAssetView;
- (UIView *_Nullable)socialContextAssetView;
- (UIView *_Nullable)ctaAssetView;
- (UIView *_Nullable)adBadgeAssetView;
- (UIView *_Nullable)noticeAssetView;

- (UIView * _Nullable)iconContainerView;
- (UIView * _Nullable)mediaContainerView;
- (UIView * _Nullable)adChoicesContainerView;

- (UIView * _Nullable)extraViewWith:(NSString * _Nonnull)key;

@end

@protocol GFPNativeRendererViewProtocol <GFPNativeAssetViewProtocol>

+ (UIView * _Nullable)createView;

- (void)bindWith:(id <GFPNativeAssetProtocol> _Nullable)asset;
- (void)changeStyleWith:(BOOL)isDarkMode;

@optional

- (CGFloat)estimateHeight;
- (CGFloat)scaleRatio;

- (void)updateRenderingSetting:(GFPNativeBaseRenderingSetting * _Nullable)renderingSetting NS_SWIFT_NAME(updateRenderingSetting(renderingSetting:));

@end
