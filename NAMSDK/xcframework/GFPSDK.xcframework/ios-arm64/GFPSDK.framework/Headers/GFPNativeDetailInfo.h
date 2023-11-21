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


@interface GFPNativeLinkInfo : NSObject

@property (nonatomic, readonly, strong) NSURL *cURL;
@property (nonatomic, readonly, strong) NSArray <NSString *> *trackerList;
@property (nonatomic, readonly, strong) NSURL *fURL;
@property (nonatomic, readonly, strong) NSDictionary *extraDict;

@property (nonatomic, readonly, strong) NSURL *openURL;

+ (instancetype)dict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;
- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeTitleInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeSizeInfo : NSObject

@property (nonatomic, readonly, assign) CGSize size;

@end


@interface GFPNativeRichInfo : NSObject

@property (readonly, nonatomic, assign) NSInteger richType;
@property (readonly, nonatomic, strong, nullable) GFPRichTrackingURLs *richTrackings;
@property (readonly, nonatomic, assign) GFPNativeLinkInfo *link;

- (instancetype _Nullable)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;

- (GFPRichDetailInfo *)imageWithKey:(NSString *)key;
- (GFPRichDetailInfo *)videoWithKey:(NSString *)key;
- (GFPRichDetailInfo *)textWithKey:(NSString *)key;

@end


@interface GFPNativeExtensionInfo : NSObject
@property (nonatomic, readonly, strong, nullable) GFPNativeStyleInfo *styleInfo;

- (instancetype _Nullable)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;

@end

@interface GFPNativeMediaExtensionInfo : NSObject

@property (nonatomic, readonly, strong) NSString *alternativeText;
@property (nonatomic, readonly, strong, nullable) GFPNativeRichInfo *richInfo;

@property (nonatomic, readonly, assign) BOOL isExistRichAssets;

- (instancetype _Nullable)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)aDict
                                        link:(GFPNativeLinkInfo *)link NS_DESIGNATED_INITIALIZER;



- (void)removeRichInfo;

@end


@interface GFPNativeStyleBaseInfo : NSObject

@property (nonatomic, readonly, strong, nullable) UIColor *bgColor;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeStyleDetailInfo : GFPNativeStyleBaseInfo

@property (nonatomic, readonly, strong, nullable) UIColor *textColor;
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


@interface GFPNativeBodyInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeIconInfo : NSObject <GFPNativeAdInfoLinkPresentable, GFPNativeAdInfoSourcePresentable, GFPNativeAdInfoSource, GFPNativeAdInfoExtensionPresentable>

@property (nonatomic, readonly, strong) NSURL *source;
@property (nonatomic, readonly, assign) CGSize size;

@property (nonatomic, readonly, assign) BOOL isValid;

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeSponsorInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeBadgeInfo : NSObject <GFPNativeAdInfoLabelPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end


@interface GFPNativeCTAInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable, GFPNativeAdInfoExtStylePresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeNoticeInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end


@interface GFPNativeExtraTextInfo : NSObject <GFPNativeAdInfoLabelPresentable, GFPNativeAdInfoLinkPresentable>

- (instancetype)initWithDict:(NSDictionary *)aDict link:(GFPNativeLinkInfo *)aLink;

@end



NS_ASSUME_NONNULL_END
