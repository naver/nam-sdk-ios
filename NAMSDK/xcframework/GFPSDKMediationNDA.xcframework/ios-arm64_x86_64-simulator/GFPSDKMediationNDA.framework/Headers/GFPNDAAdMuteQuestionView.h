//
//  GFPNDAAdMuteQuestionView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdChoiceResourceUtils.h"
#import "GFPNDAAdMuteReasonView.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAAdMuteQuestionView;

typedef NS_OPTIONS(NSInteger, GFPNDAAdMuteQuestionType) {
    GFPNDAAdMuteQuestionTypeNormal,
    GFPNDAAdMuteQuestionTypeIX,
};

@protocol GFPNDAAdMuteQuestionDelegate <NSObject>

- (void)questionViewWasAgreed:(GFPNDAAdMuteQuestionView *)view;
- (void)questionViewWasDenied:(GFPNDAAdMuteQuestionView *)view;

- (GFPNDAAdMuteReasonLayoutType)layoutTypeForQuestionView;

@optional
- (void)questionViewBackButtonWasClicked:(GFPNDAAdMuteQuestionView *)view;
- (void)questionView:(GFPNDAAdMuteQuestionView *)view landingWasClicked:(NSString *)url; //for IXQuestionView

@end


@interface GFPNDAAdMuteQuestionView : UIView <GFPNDAAdChoiceResourcePresentable>

@property (nonatomic, weak) id <GFPNDAAdMuteQuestionDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame
                         type:(GFPNDAAdMuteQuestionType)type
                          url:(NSString *)url
                resourceUtils:(GFPNDAAdChoiceResourceUtils *)resourceUtils;

- (void)focusVoiceOver;

@end

NS_ASSUME_NONNULL_END
