//
//  GFPNDAAdMuteIconView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdMuteView.h"
#import "GFPNDAAdChoiceResourceUtils.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNDAAdMuteIconType) {
    GFPNDAAdMuteIconTypeX = 1 << 0,         // AdMute only (for nn)
    GFPNDAAdMuteIconTypeADX = 1 << 1,       // AdMark + AdMute (for ns)
    GFPNDAAdMuteIconTypeI = 1 << 2,         // AdPrivacy(=Optout) + AdMute (for nn)
    GFPNDAAdMuteIconTypeIX = 1 << 3,        // AdPrivacy(=Optout) + AdMute (for ns)
    GFPNDAAdMuteIconTypeCustom = 1 << 4,    // Custom Icon
};

@protocol GFPNDAAdMuteViewDelegate;
@protocol GFPNDAAdPrivayClickDelegate;

@class GFPAdChoiceInfo;

@interface GFPNDAAdMuteIconView : UIView <GFPNDAAdChoiceResourcePresentable>

@property (nonatomic, weak) id <GFPNDAAdMuteViewDelegate> delegate;
@property (nonatomic, weak) id <GFPNDAAdPrivayClickDelegate> adPrivacyDelegate;

@property (nonatomic, strong, readonly) GFPNDAAdMuteView *adMuteView;
@property (nonatomic, strong, readonly) UIButton *markButton;

- (instancetype)initWithFrame:(CGRect)frame
                       adView:(UIView *)adView
                         type:(GFPNDAAdMuteIconType)type
                         info:(GFPAdChoiceInfo *)info
                resourceUtils:(GFPNDAAdChoiceResourceUtils *)resourceUtils
                  adMuteState:(GFPNDAAdMuteState)adMuteState;

@end

NS_ASSUME_NONNULL_END
