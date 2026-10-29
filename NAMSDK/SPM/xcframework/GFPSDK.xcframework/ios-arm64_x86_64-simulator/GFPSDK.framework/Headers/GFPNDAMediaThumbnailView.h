//
//  GFPNDAMediaThumbnailView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>
#import "GFPNativeAdRenderingSetting.h"
#import "GFPNDAMediaThumbnailMeta.h"

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

@property (nonatomic, strong, nullable) GFPNDAMediaThumbnailMeta *thumbnailMeta;

- (instancetype)initWith:(GFPNDAMediaThumbnailViewType)type enableBgBlur:(BOOL)enableBgBlur;

- (instancetype)initWith:(GFPNDAMediaThumbnailViewType)type image:(UIImage *)image;

- (void)updateThumbnail:(UIImage *)thumbnail;

/// 반투명 외곽을 이미지 자신의 색으로 채운 불투명 이미지. 알파 채널이 없으면 그대로 돌려준다.
+ (UIImage *)imageByFillingTranslucentEdges:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
