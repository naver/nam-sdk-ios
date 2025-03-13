//
//  GFPNativeDetailInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPNativeAdInfoProtocol.h"
#import "GFPWaterfallList.h"
#import "GFPRichTrackingURLs.h"
#import "Swift-Enum.h"


NS_ASSUME_NONNULL_BEGIN

typedef NSString *GFPRichExtendMediaRatioType NS_STRING_ENUM;
FOUNDATION_EXPORT NSString *const GFPRichExtendMediaRatioTypeOther;
FOUNDATION_EXPORT NSString *const GFPRichExtendMediaRatioType1_1;
FOUNDATION_EXPORT NSString *const GFPRichExtendMediaRatioType9_16;
FOUNDATION_EXPORT NSString *const GFPRichExtendMediaRatioType16_9;

@interface GFPNativeLinkInfo : NSObject

@property (nonatomic, readonly, strong) NSURL *cURL;
@property (nonatomic, readonly, strong) NSArray <NSString *> *trackerList;
@property (nonatomic, readonly, strong) NSURL *fURL;
@property (nonatomic, readonly, strong) NSDictionary *extraDict;

@property (nonatomic, readonly, strong) NSURL *openURL;

+ (instancetype)dict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;
- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeTitleInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeSizeInfo : NSObject

@property (nonatomic, readonly, assign) CGSize size;

@end


@interface GFPNativeRichInfo : NSObject

@property (readonly, nonatomic, assign) NSInteger richType;
@property (readonly, nonatomic, strong, nullable) GFPRichTrackingURLs *richTrackings;
@property (readonly, nonatomic, assign) GFPNativeLinkInfo *link;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;

- (GFPRichDetailInfo * _Nullable)propertyWithKey:(NSString *)key;
- (GFPRichDetailInfo * _Nullable)imageWithKey:(NSString *)key;
- (GFPRichDetailInfo * _Nullable)videoWithKey:(NSString *)key;
- (GFPRichDetailInfo * _Nullable)textWithKey:(NSString *)key;

@end


@interface GFPNativeExtensionInfo : NSObject
@property (nonatomic, readonly, strong, nullable) GFPNativeStyleInfo *styleInfo;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;

@end

@interface GFPNativeMediaBadgeInfo : NSObject <GFPNativeAdInfoLinkPresentable>

@property (nonatomic, readonly, assign) CGFloat width;
@property (nonatomic, readonly, assign) CGFloat height;
@property (nonatomic, readonly, strong) NSString *src;
@property (nonatomic, readonly, strong) GFPNativeStyleInfo *styleInfo;
@property (nonatomic, readonly, strong) GFPNativeLinkInfo *link;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict NS_DESIGNATED_INITIALIZER;

@end


@interface GFPNativeMediaExtensionInfo : NSObject

@property (nonatomic, readonly, strong) NSString *alternativeText;
@property (nonatomic, readonly, strong, nullable) GFPNativeRichInfo *richInfo;
@property (nonatomic, readonly, assign) BOOL isExistRichAssets;

@property (nonatomic, readonly, strong) NSDictionary<NSString *, GFPNativeMediaBadgeInfo *> *badges;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;


- (void)updateAccessibilityTextWith:(NSString *)accessibilityText; //for renderer
- (void)removeRichInfo;

@end


@interface GFPNativeStyleBaseInfo : NSObject

/**
 * [주의] style bgColor 참고
 * - Title, Body 등의 텍스트 에셋의 경우
 *   - bgColor는 highlightBgColor를 의미한다.
 *     - ex) CTA 100%+1s 전환 색상 등
 *   - defaultBgColor는 bgColor를 의미한다.
 *     - ex) CTA 배경 색상, 쇼핑 라벨 배경 색상 등
 * - Media, Icon 등 그 외 ext.style의 경우 bgColor는 말 그대로 bgColor를 의미한다.
 *   - ex) NS 리치 광고 배경 색상 등
 */
@property (nonatomic, readonly, strong, nullable) UIColor *bgColor;
@property (nonatomic, readonly, strong, nullable) UIColor *defaultBgColor;

@property (nonatomic, readonly, strong, nullable) UIColor *textColor;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end

@interface GFPNativeStyleSpannableInfo : NSObject

@property (nonatomic, readonly, assign) NSInteger startPos;
@property (nonatomic, readonly, assign) NSInteger endPos;
@property (nonatomic, readonly, assign) BOOL isBold;
@property (nonatomic, readonly, strong, nullable) UIColor *textColor;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end

@interface GFPNativeStyleDetailInfo : GFPNativeStyleBaseInfo

/**
 * for rich ad
 */
@property (nonatomic, readonly, assign) float alpha;
@property (nonatomic, readonly, assign) float radius;
@property (nonatomic, readonly, assign) float leftMargin;
@property (nonatomic, readonly, assign) float rightMargin;
@property (nonatomic, readonly, assign) float topMargin;
@property (nonatomic, readonly, assign) float bottomMargin;
@property (nonatomic, readonly, assign) float maxWidth;

@property (nonatomic, readonly, strong, nullable) UIColor *shadowColor;
@property (nonatomic, readonly, assign) float shadowAlpha;
@property (nonatomic, readonly, assign) float shadowX;
@property (nonatomic, readonly, assign) float shadowY;
@property (nonatomic, readonly, assign) float shadowBlur;
@property (nonatomic, readonly, assign) float shadowSpread;

@property (nonatomic, readonly, assign) NSInteger gravity;


/**
 * For Badge
 */
@property (nonatomic, readonly, strong, nullable) UIColor *borderColor;
@property (nonatomic, readonly, assign) float borderAlpha;
@property (nonatomic, readonly, strong, nullable) UIColor *badgeColor;
@property (nonatomic, readonly, assign) float bgColorAlpha;
@property (nonatomic, readonly, assign) float borderWidth;
@property (nonatomic, readonly, assign) BOOL isBold;

/**
 * For attributeString
 */
@property (nonatomic, readonly, strong, nullable) NSArray<GFPNativeStyleSpannableInfo *> *spannableInfo;


- (instancetype)initWithDict:(NSDictionary *)aDict;

@end

@interface GFPNativeStyleInfo : NSObject

@property (nonatomic, readonly, strong, nullable) GFPNativeStyleDetailInfo *defaultColor;
@property (nonatomic, readonly, strong, nullable) GFPNativeStyleDetailInfo *darkColor;
@property (nonatomic, readonly, strong, nullable) GFPNativeStyleInfo *richStyleInfo;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeMediaInfo : NSObject <GFPNativeAdInfoLinkPresentable, GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoSource, GFPNativeAdInfoExtensionPresentable>

@property (nonatomic, readonly, assign) GFPNativeAdMediaType type;
@property (nonatomic, readonly, assign, getter=isVideo) BOOL video;

@property (nonatomic, readonly, assign) BOOL isRichMedia;
@property (nonatomic, readonly, assign) BOOL isExistRichAssets;

@property (nonatomic, readonly, strong) NSURL *source;
@property (nonatomic, readonly, strong) NSString *body;
@property (nonatomic, readonly, strong) NSURL *tsource;

@property (nonatomic, readonly, assign) CGSize size;
@property (nonatomic, readonly, assign) CGFloat ratio;

@property (nonatomic, readonly, assign) BOOL isValid;

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeBodyInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeIconInfo : NSObject <GFPNativeAdInfoLinkPresentable, GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoSource, GFPNativeAdInfoExtensionPresentable>

@property (nonatomic, readonly, strong) NSURL *source;
@property (nonatomic, readonly, assign) CGSize size;

@property (nonatomic, readonly, assign) BOOL isValid;

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeSponsorInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeBadgeInfo : NSObject <GFPNativeAdInfoLabelPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeCTAInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeNoticeInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeExtraTextInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdLabelOptionPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end

@interface GFPNativeExtraImageInfo : NSObject <GFPNativeAdInfoLinkPresentable, GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoSource, GFPNativeAdInfoExtensionPresentable>

@property (nonatomic, readonly, strong) NSURL *source;
@property (nonatomic, readonly, assign) CGSize size;

@property (nonatomic, readonly, assign) BOOL isValid;

@property (nonatomic, weak) UIImage *image; //for renderer

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end





NS_ASSUME_NONNULL_END
