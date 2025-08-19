//
//  GFPNDAAdMuteReasonView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdChoiceResourceUtils.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAAdMuteReasonView;
@class GFPAdChoiceText;

typedef NS_OPTIONS(NSInteger, GFPNDAAdMuteReasonLayoutType) {
    GFPNDAAdMuteReasonLayoutTypeRow1ColumnN,
    GFPNDAAdMuteReasonLayoutTypeRow3Column2,
    GFPNDAAdMuteReasonLayoutTypeRowNColumn1,
};

@protocol GFPNDAAdMuteReasonDelegate <NSObject>

- (void)reasonView:(GFPNDAAdMuteReasonView *)view reasonWasClicked:(NSString *)reasonCode;

@end


@interface GFPNDAAdMuteReasonView : UIView <GFPNDAAdChoiceResourcePresentable>

@property (nonatomic, weak) id <GFPNDAAdMuteReasonDelegate> delegate;

@property (nonatomic, assign, readonly) GFPNDAAdMuteReasonLayoutType layoutType;

- (instancetype)initWithFrame:(CGRect)frame
                     textInfo:(GFPAdChoiceText *)textInfo
                resourceUtils:(GFPNDAAdChoiceResourceUtils *)resourceUtils;

- (void)focusVoiceOver;

@end

NS_ASSUME_NONNULL_END
