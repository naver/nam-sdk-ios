//
//  GFPNDAAdChoiceView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNativeAdRenderingSetting.h"
#import "GFPNDAAdMuteView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNDAAdChoiceViewType) {
    GFPNDAAdChoiceViewTypeNone = 1 << 0,
    GFPNDAAdChoiceViewTypeAdPrivacy = 1 << 1,
    GFPNDAAdChoiceViewTypeAdPrivacyCustom = 1 << 2,
    GFPNDAAdChoiceViewTypeAdMuteX = 1 << 3,     //for nn
    GFPNDAAdChoiceViewTypeAdMuteADX = 1 << 4,   //for ns
    GFPNDAAdChoiceViewTypeAdMuteI = 1 << 5,     //for nn
    GFPNDAAdChoiceViewTypeAdMuteIX = 1 << 6,    //for ns
    GFPNDAAdChoiceViewTypeAdMuteCustom = 1 << 7,
};

@class GFPNDAAdPrivacyIconView;
@class GFPAdChoiceInfo;
@class GFPAdEventObject;


@protocol GFPNDAAdChoiceViewDelegate <NSObject>

- (void)adPrivacyWasClicked:(UIView *)adPrivacyView;

- (void)adMuteWasClicked:(GFPNDAAdMuteView *)adMuteView eventTracking:(GFPAdEventObject *)eventTracking;
- (void)adMuteWasCanceled:(GFPNDAAdMuteView *)adMuteView;
- (void)adMute:(GFPNDAAdMuteView *)adMuteView didChangeState:(GFPNDAAdMuteState)state;


@end


@interface GFPNDAAdChoiceView : UIView

@property (nonatomic, weak) id <GFPNDAAdChoiceViewDelegate> delegate;
@property (nonatomic, assign, readonly) GFPNDAAdChoiceViewType type;

- (instancetype)initWithFrame:(CGRect)frame adChoiceInfo:(GFPAdChoiceInfo *)adChoiceInfo renderAdBadge:(BOOL)renderAdBadge;

- (void)updateViewWith:(UIView *)adView renderingSetting:(GFPNativeBaseRenderingSetting *)renderingSetting adMuteState:(GFPNDAAdMuteState)adMuteState;

@end

NS_ASSUME_NONNULL_END
