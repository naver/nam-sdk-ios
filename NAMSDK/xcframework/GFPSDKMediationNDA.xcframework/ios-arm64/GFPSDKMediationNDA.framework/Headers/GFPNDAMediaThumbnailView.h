//
//  GFPNDAOutstreamThumbView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>
#import "GFPNativeAdRenderingSetting.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPError;
@class GFPNDAMediaThumbnailView;

typedef NS_OPTIONS(NSInteger, GFPNDAMediaThumbnailViewType) {
    GFPNDAMediaThumbnailViewTypeDefault = 1,
    GFPNDAMediaThumbnailViewTypeWithBlur = 2,
};

@interface GFPNDAMediaThumbnailView : UIView

@property (nonatomic, assign, readonly) BOOL isLoaded;
@property (nonatomic, weak, readonly, nullable) UIImage *image;


- (instancetype)initWith:(GFPNDAMediaThumbnailViewType)type enableBgBlur:(BOOL)enableBgBlur;

- (instancetype)initWith:(GFPNDAMediaThumbnailViewType)type image:(UIImage *)image;

- (void)updateThumbnail:(UIImage *)thumbnail;

@end

NS_ASSUME_NONNULL_END
