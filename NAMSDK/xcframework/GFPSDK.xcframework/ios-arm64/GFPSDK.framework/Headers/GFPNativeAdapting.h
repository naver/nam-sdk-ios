//
//  GFPNativeAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdAdapting.h"
#import "GFPNativeAd.h"

@protocol GFPNativeAdaptorDelegate;

@class GFPNativeAd;
@class GFPNativeBaseView;

@class GFPWaterfallDedup;
@class GFPMediaData;
@class GFPLabelOption;
@class GFPAdChoicesData;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeAdapting <GFPAdAdapting>

@property (nullable, readwrite, nonatomic, weak) id <GFPNativeAdaptorDelegate> delegate;

- (GFPNativeAdProviderType)adProviderType;

- (nullable id)adProviderNativeAd;

- (BOOL)hasIconImage;

- (NSString * _Nullable)title;
- (GFPLabelOption * _Nullable)titleOption;

- (NSString * _Nullable)body;
- (GFPLabelOption * _Nullable)bodyOption;

- (NSString * _Nullable)advertiser;
- (GFPLabelOption * _Nullable)advertiserOption;


- (NSString * _Nullable)badge;

- (NSString * _Nullable)callToAction;
- (GFPLabelOption * _Nullable)callToActionOption;

- (NSString * _Nullable)socialContext;

- (void)registerView:(GFPNativeBaseView *)nativeAdView;

- (void)unregisterView;

- (BOOL)isRegistered;

@optional

- (NSString * _Nullable)adStyleVisualKey;

- (void)updateMediaViewLayout;

- (GFPAdStyleType)adStyleType;

- (NSString *)c2sSubRenderType;

- (GFPAdStyleOption * _Nullable)adStyleOption;

- (BOOL)isInvalid;

- (UIImage * _Nullable)image;

- (NSString * _Nullable)notice;
- (GFPLabelOption * _Nullable)noticeOption;

- (GFPWaterfallDedup * _Nullable)dedup;

- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;

- (NSDictionary *)nativeExtraInfo;

- (void)clearResource;

- (BOOL)isReloadRequired;

- (void)reloadMediaResource;

- (GFPMediaData * _Nullable)mediaData;

- (GFPIconData * _Nullable)iconData;

- (GFPAdChoicesData * _Nullable)adChoicesData;

- (NSString * _Nullable)extraTextWith:(NSString *)key;

- (GFPLabelOption * _Nullable)extraLabelOptionWith:(NSString *)key;

- (UIImage * _Nullable)extraImageWith:(NSString *)key;

- (NSURL * _Nullable)extraImageUrlWith:(NSString *)key;

- (NSString * _Nullable)extraImageAccessibilityWith:(NSString *)key;

- (void)applyExtraViewLink:(NSString *)key withView:(UIView *)extraView;

- (void)existUserInterestDelegateWith:(BOOL)isExist;

@end

NS_ASSUME_NONNULL_END
