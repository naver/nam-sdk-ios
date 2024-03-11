//
//  GFPNDANativeTapGesture.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol GFPNativeAdInfoLinkPresentable;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeTapGesture : UITapGestureRecognizer

@property (readonly, nonatomic, strong) NSURL *link;
@property (readonly, nonatomic, strong) NSArray *trackerList;
@property (readonly, nonatomic, assign) BOOL forceURLLanding;

- (instancetype)initWithTarget:(nullable id)target action:(nullable SEL)action NS_UNAVAILABLE;

- (instancetype)initWithTarget:(id)target action:(SEL)action link:(id<GFPNativeAdInfoLinkPresentable>)aLink NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
