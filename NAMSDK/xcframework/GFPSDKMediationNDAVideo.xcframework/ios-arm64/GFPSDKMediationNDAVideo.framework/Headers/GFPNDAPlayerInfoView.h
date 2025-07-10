//
//  GFPNDAPlayerInfoView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

@class GFPNDAVastControlInfo;
@class GFPNDAPlayerInfoView;
@class GFPTrackingURLs;
@class GFPVideoAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDAPlayerViewInfoDelegate <NSObject>

- (void)infoView:(GFPNDAPlayerInfoView *)aInfoView didSkipTapped:(UIButton *)aSender;
- (void)infoView:(GFPNDAPlayerInfoView *)aInfoView didPostAdTapped:(NSString *)aURL;
- (void)infoView:(GFPNDAPlayerInfoView *)aInfoView didShowSkipButton:(UIButton *)aSender;

@end


typedef NS_ENUM(NSInteger, GFPNDAPlayerInfoViewType) {
    GFPNDAPlayerInfoViewTypeNone = 0,
    GFPNDAPlayerInfoViewTypeSkipAndIcon,
    GFPNDAPlayerInfoViewTypePostAd
};

static const CGFloat kPlayerInfoViewMaxHeight = 56.0;


@interface GFPNDAPlayerInfoView : UIView


@property (nonatomic, assign) id<GFPNDAPlayerViewInfoDelegate> delegate;

@property (nonatomic, readonly, assign) BOOL showSkipButton;
@property (nonatomic, readonly, strong) UILabel *adProviderLabel;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame 
                  controlInfo:(GFPNDAVastControlInfo *)aControlInfo
             renderingSetting:(nullable GFPVideoAdRenderingSetting *)renderingSetting NS_DESIGNATED_INITIALIZER;

- (void)updateCurrentTime:(NSTimeInterval)aCurrentTime;

- (void)showOverlayView;
- (void)hideOverlayView;

- (void)updateInfoViewWith:(GFPNDAPlayerInfoViewType)viewType;

- (IBAction)skipTappedByService:(id)sender;

- (void)start;

@end

NS_ASSUME_NONNULL_END
