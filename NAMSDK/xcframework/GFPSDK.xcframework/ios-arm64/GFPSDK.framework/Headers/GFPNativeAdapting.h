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

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNativeAdapting <GFPAdAdapting>

@property (nullable, readwrite, nonatomic, weak) id <GFPNativeAdaptorDelegate> delegate;

- (GFPNativeAdProviderType)adProviderType;

- (nullable id)adProviderNativeAd;

- (BOOL)hasIconImage;

- (NSString * _Nullable)title;

- (NSString * _Nullable)body;

- (NSString * _Nullable)advertiser;

- (NSString * _Nullable)badge;

- (NSString * _Nullable)callToAction;

- (NSString * _Nullable)socialContext;

- (void)registerView:(GFPNativeBaseView *)nativeAdView;

- (void)unregisterView;

- (BOOL)isRegistered;

@optional
- (void)updateMediaViewLayout;

- (GFPAdStyleType)adStyleType;

- (BOOL)isInvalid;

- (UIImage * _Nullable)image;

- (NSString * _Nullable)notice;

- (GFPWaterfallDedup * _Nullable)dedup;

- (CGFloat)estimateHeightWith:(CGFloat)viewWidth;

- (NSDictionary *)nativeExtraInfo;

- (void)clearResource;

- (BOOL)isReloadRequired;

- (void)reloadMediaResource;

- (CGSize)imageSize; //deprecate

- (UIImage *)image; //deprecate

- (GFPMediaData * _Nullable)mediaData;

- (NSString * _Nullable)extraTextWith:(NSString *)key;

- (GFPLabelOption * _Nullable)extraTextOptionWith:(NSString *)key;

- (void)applyExtraViewLink:(NSString *)key withView:(UIView *)extraView;

- (void)existUserInterestDelegateWith:(BOOL)isExist;

- (GFPLabelOption * _Nullable)titleOption;

- (GFPLabelOption * _Nullable)bodyOption;

- (GFPLabelOption * _Nullable)advertiserOption;

- (GFPLabelOption * _Nullable)badgeOption;

- (GFPLabelOption * _Nullable)callToActionOption;

- (GFPLabelOption * _Nullable)socialContextOption;

- (GFPLabelOption * _Nullable)noticeOption;

@end

NS_ASSUME_NONNULL_END
