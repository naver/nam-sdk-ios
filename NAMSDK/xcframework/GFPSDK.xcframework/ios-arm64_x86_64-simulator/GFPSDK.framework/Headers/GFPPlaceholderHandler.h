//
//  GFPPlaceholderHandler.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^GFPPlaceholderHandler)(UIImageView *imageView);
typedef void (^GFPPlaceholderRemovalHandler)(void);
/// Called immediately before a placeholder added by the SDK is removed.
/// Invoke `removeHandler` exactly once after any custom animation or transition finishes.
/// If `removeHandler` is not invoked, the placeholder remains visible.
typedef void (^GFPPlaceholderWillRemoveHandler)(UIImageView *imageView, GFPPlaceholderRemovalHandler removeHandler);

NS_ASSUME_NONNULL_END
