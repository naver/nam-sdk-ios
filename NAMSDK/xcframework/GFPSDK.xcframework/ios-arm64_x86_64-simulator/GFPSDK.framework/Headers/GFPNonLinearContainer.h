//
//  GFPNonLinearContainer.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPTextAdViewAttribute.h"
#import "GFPNonLinearDelegate.h"

@class GFPNonLinearAdView;


NS_ASSUME_NONNULL_BEGIN


@interface GFPNonLinearContainer : UIView

@property (nonatomic, weak) id<GFPNonLinearDelegate> delegate;

@property (nonatomic, strong) GFPNonLinearAdView *nonLinearView;

@property (nonatomic, strong) GFPTextAdViewAttribute *textAdAttribute;

@property (nonatomic, readonly, assign) BOOL canStartReady;
@property (nonatomic, readonly, assign) BOOL isShowing;

- (void)show;
- (void)show:(GFPNonLinearContainerType)aType;
- (void)hide;
- (void)replaceOuterContainer;

@end


NS_ASSUME_NONNULL_END
