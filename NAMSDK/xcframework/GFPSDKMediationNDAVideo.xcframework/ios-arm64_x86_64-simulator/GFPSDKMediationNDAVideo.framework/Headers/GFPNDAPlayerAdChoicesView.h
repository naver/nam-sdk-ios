//
//  GFPNDAPlayerAdChoicesView.h
//  GFPSDKMediationNDAVideo
//
//  Created by sodam on 2022/12/29.
//  Copyright © 2022 Naver. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GFPLanguageType.h"

@class GFPAdChoiceInfo;
@class GFPNDAPlayerAdChoicesView;

@class Icon;

NS_ASSUME_NONNULL_BEGIN


static const CGFloat kPlayerAdChociesWidthHeight = 30.0;
static const CGFloat kRewardedPlayerAdChociesWidthHeight = 16.0;


@protocol GFPNDAPlayerAdChoicesDelegate <NSObject>

- (void)adChoicesView:(GFPNDAPlayerAdChoicesView *)aAdChoicesView didAdPrivacyTapped:(NSString *)aURL;

@end

@interface GFPNDAPlayerAdChoicesView : UIView

@property (nonatomic, weak) id<GFPNDAPlayerAdChoicesDelegate> delegate;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)aFrame
                     iconList:(NSArray<Icon *> *)aIconList
                 adChoiceInfo:(nullable GFPAdChoiceInfo *)adChoiceInfo
                 languageType:(GFPLanguageType)languageType NS_DESIGNATED_INITIALIZER;

- (void)showViewComponent;

@end


NS_ASSUME_NONNULL_END
