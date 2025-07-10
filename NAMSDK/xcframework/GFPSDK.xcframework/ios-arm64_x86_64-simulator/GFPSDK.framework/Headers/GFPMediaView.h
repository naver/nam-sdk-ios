//
//  GFPMediaView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.

#import <UIKit/UIKit.h>
#import "Swift-Enum.h"
#import "GFPPlaceholderHandler.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPMediaView : UIView

- (void)showPlaceholderWith:(GFPPlaceholderHandler _Nullable)placeholderSetter;

@end

NS_ASSUME_NONNULL_END
