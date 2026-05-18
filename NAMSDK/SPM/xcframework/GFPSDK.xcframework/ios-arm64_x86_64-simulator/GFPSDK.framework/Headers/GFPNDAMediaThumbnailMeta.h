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

- (instancetype)initWith:(UIViewContentMode)thumbnailContentMode;

@end

NS_ASSUME_NONNULL_END
