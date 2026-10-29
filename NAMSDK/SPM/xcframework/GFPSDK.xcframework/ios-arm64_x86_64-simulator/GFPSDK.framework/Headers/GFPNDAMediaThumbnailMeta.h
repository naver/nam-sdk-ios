//
//  GFPNDAMediaThumbnailMeta.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAMediaThumbnailMeta : NSObject

@property (nonatomic, assign) UIViewContentMode thumbnailContentMode;
/// 썸네일 이미지의 반투명 외곽을 불투명하게 채운다. 영상 위를 덮는 정지컷에서 아래 영상이 테두리로 비치지 않게 한다. (기본 NO)
@property (nonatomic, assign) BOOL fillsTranslucentEdges;

- (instancetype)initWith:(UIViewContentMode)thumbnailContentMode;

@end

NS_ASSUME_NONNULL_END
