//
//  GFPNDAAdMuteView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAAdMuteView;
@class GFPNDAAdMuteQuestionBaseView;
@class GFPNDAAdMuteReasonView;
@class GFPNDAAdChoiceResourceUtils;
@class GFPAdChoiceInfo;
@class GFPAdChoiceText;

@protocol GFPNDAAdPrivayClickDelegate;

typedef NS_OPTIONS(NSInteger, GFPNDAAdMuteState) {
    GFPNDAAdMuteStateNone,      //AdMuteView 가 노출되지 않는 상태. (= AdMuteIconView 가 노출됨.)
    GFPNDAAdMuteStateQuestion,  //AdMuteView 가 노출되고, QuestionView 가 보이는 상태.
    GFPNDAAdMuteStateReason,    //AdMuteView 가 노출되고, ReasonView 가 보이는 상태.
    GFPNDAAdMuteStateComplete   //AdMuteView 가 노출되고, CompleteView 가 보이는 상태.
};

@protocol GFPNDAAdMuteViewDelegate <NSObject>

- (void)adMuteView:(GFPNDAAdMuteView *)adMuteView didChangeState:(GFPNDAAdMuteState)state;
- (void)adMuteWasClicked:(GFPNDAAdMuteView *)adMuteView reasonCode:(NSString *)reasonCode;

@end


@interface GFPNDAAdMuteView : UIView

@property (nonatomic, weak) id <GFPNDAAdMuteViewDelegate> delegate;
@property (nonatomic, weak) id <GFPNDAAdPrivayClickDelegate> adPrivacyDelegate;

@property (nonatomic, assign, readonly) GFPNDAAdMuteState state;

- (instancetype)initWithFrame:(CGRect)frame
                         info:(GFPAdChoiceInfo *)info
                resourceUtils:(GFPNDAAdChoiceResourceUtils *)resourceUtils;

- (void)updateState:(GFPNDAAdMuteState)state;

@end


NS_ASSUME_NONNULL_END
