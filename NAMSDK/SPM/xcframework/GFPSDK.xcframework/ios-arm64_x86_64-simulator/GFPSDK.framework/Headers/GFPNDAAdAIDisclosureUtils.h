//
//  GFPNDAAdAIDisclosureUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>

#import "GFPNDAAdAIDisclosureView.h"

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kAdAIUsageBadgeWidth;
extern CGFloat const kAdAIUsageBadgeHeight;

extern CGFloat const kAdAIDisclosureTopBottomGap;
extern CGFloat const kAdAIDisclosureLeftRightGap;

extern CGFloat const kAdAIDisclosureAssetsMargin;

@interface GFPNDAAdAIDisclosureUtils : NSObject

+ (CGSize)sizeWith:(GFPNDAAdAIDisclosureViewType)type;

+ (CGPoint)nsPositionWith:(CGRect)imagePos
    overlapsAdChoicesView:(BOOL)overlapsAdChoicesView
        adChoiceViewFrame:(CGRect)adChoiceViewFrame
               inFullView:(BOOL)inFullView;


@end

NS_ASSUME_NONNULL_END
