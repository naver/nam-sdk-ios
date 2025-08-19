//
//  GFPNDAAdChoiceViewUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdChoiceView.h"
#import "GFPNDAAdMuteIconView.h"
#import "GFPNDAAdPrivacyIconView.h"

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kAdPrivacyViewWidth;
extern CGFloat const kAdMuteADWidth;
extern CGFloat const kAdMuteADHeight;

extern CGFloat const kAdMuteIWidthHeight;

extern CGFloat const kAdChoiceViewTopBottomGap;
extern CGFloat const kAdChoiceViewLeftRightGap;

@class GFPNativeBaseRenderingSetting;

@interface GFPNDAAdChoiceViewUtils : NSObject

+ (GFPNDAAdChoiceViewType)typeWith:(BOOL)enableAdPrivacy enableAdMute:(BOOL)enableAdMute renderAdMuteForNS:(BOOL)renderAdMuteForNS useCustomIcon:(BOOL)useCustomIcon;

+ (GFPNDAAdMuteIconType)adMuteIconTypeWith:(GFPNDAAdChoiceViewType)type;
+ (GFPNDAAdPrivacyIconType)adPrivacyIconTypeWith:(GFPNDAAdChoiceViewType)type;

+ (CGSize)sizeWith:(GFPNDAAdChoiceViewType)type
           setting:(GFPNativeBaseRenderingSetting *)setting;

@end

NS_ASSUME_NONNULL_END
