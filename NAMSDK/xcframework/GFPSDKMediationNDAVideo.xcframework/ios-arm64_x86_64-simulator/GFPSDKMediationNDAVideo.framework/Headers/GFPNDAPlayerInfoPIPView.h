//
//  GFPNDAPlayerInfoPIPView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAPlayerInfoView.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAPlayerInfoPIPView;
@class GFPNDAVastControlInfo;


typedef NS_ENUM(NSInteger, GFPNDAPlayerInfoPIPViewType) {
    GFPNDAPlayerInfoPIPViewTypeNone = 0,
    GFPNDAPlayerInfoPIPViewTypeSkipMore,
};


@protocol GFPNDAPlayerPIPViewInfoDelegate <NSObject>

- (void)infoView:(GFPNDAPlayerInfoPIPView *)aInfoView didSkipTapped:(UIButton *)aSender;
- (void)infoView:(GFPNDAPlayerInfoPIPView *)aInfoView didMoreTapped:(NSString *)aURL;

@end



@interface GFPNDAPlayerInfoPIPView : UIView

@property (nonatomic, assign) id<GFPNDAPlayerPIPViewInfoDelegate> delegate;

@property (nonatomic, readonly, assign) BOOL clickableSkip;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame controlInfo:(GFPNDAVastControlInfo *)aControlInfo clickThrough:(NSString *)clickThrough NS_DESIGNATED_INITIALIZER;

- (void)updateCurrentTime:(NSTimeInterval)aCurrentTime;

- (void)showInfoView;
- (void)hideInfoView;

@end

NS_ASSUME_NONNULL_END
