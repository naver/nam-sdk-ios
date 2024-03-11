//
//  GFPNonLinearAdView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
  


#import <UIKit/UIKit.h>
#import "GFPS2SAdClickDelegate.h"
#import "Swift-Enum.h"

@class GFPRemindAd;
@class GFPClickLandingUtil;
@class GFPTextAdViewAttribute;

@protocol GFPS2SAdClickDelegate;

typedef NS_OPTIONS(NSInteger, GFPRemindTextType) {
    GFPRemindNormal = 0,
    GFPRemindFoldable = 1
};


NS_ASSUME_NONNULL_BEGIN


@class GFPNonLinearAdView;

@protocol NonLinearViewDelegate <NSObject>

- (void)nonLinearView:(GFPNonLinearAdView *)aView didClose:(UIButton *)sender;

- (void)nonLinearViewWasClicked:(GFPNonLinearAdView *)aView;
- (void)nonLinearViewOnActiveImpression:(GFPNonLinearAdView *)aView;

@end


@interface GFPNonLinearAdView : UIView


@property (nonatomic, weak) id<NonLinearViewDelegate> delegate;
@property (nonatomic, strong, nullable) GFPRemindAd *remindAd;

@property (nonatomic, strong, readonly) GFPClickLandingUtil *landingUtil;

@property (nonatomic, assign) GFPNonLinearContainerType containerType;
@property (nonatomic, strong) GFPTextAdViewAttribute *attribute; // Only for RemindText.

@property (nonatomic, readonly, assign) BOOL isBanner;
@property (nonatomic, readonly, assign) BOOL isRemindLoaded;

@property (nonatomic, readonly, assign) BOOL wasShown;


- (instancetype)initWithFrame:(CGRect)frame remindAd:(GFPRemindAd *)aRemindAd;


- (void)reportViewTracking;
- (void)updateRemindAd;
- (void)updateClickDelegate:(id <GFPS2SAdClickDelegate>)clickDelegate;

- (void)wasClicked:(id)sender;
- (IBAction)close:(id)sender;

@end

NS_ASSUME_NONNULL_END
