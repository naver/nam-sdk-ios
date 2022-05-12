//
//  GFPNonLinearAdView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPTextAdViewAttribute.h"

@class GFPRemindAd;


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
@property (nonatomic, strong) GFPRemindAd *remindAd;

@property (nonatomic, assign) GFPNonLinearContainerType containerType;
@property (nonatomic, strong) GFPTextAdViewAttribute *attribute; // Only for RemindText.

@property (nonatomic, readonly, assign) BOOL isBanner;
@property (nonatomic, readonly, assign) BOOL isRemindLoaded;

@property (nonatomic, readonly, assign) BOOL wasShown;


- (instancetype)initWithFrame:(CGRect)frame remindAd:(GFPRemindAd *)aRemindAd;


- (void)reportViewTracking;
- (void)updateRemindAd;

- (void)wasClicked:(id)sender;
- (IBAction)close:(id)sender;

@end

NS_ASSUME_NONNULL_END
