//
//  GFPNDAPlayerControlView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GFPVideoAdPlacement.h"
#import "GFPNDAPlayerView.h"
#import "GFPNDAPlayerControlViewDelegate.h"


@class GFPNDAVast;
@class GFPAdChoiceInfo;
@class GFPVideoAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAPlayerControlView : UIView <GFPNDAPlayerControlViewPresentable>

@property (nonatomic, readonly, strong) NSString *clickURL;

- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame
                         vast:(GFPNDAVast *)aVast
                placementType:(GFPVideoPlacementType)aType
                 adChoiceInfo:(nullable GFPAdChoiceInfo *)adChoiceInfo
             renderingSetting:(nullable GFPVideoAdRenderingSetting *)renderingSetting NS_DESIGNATED_INITIALIZER;

- (IBAction)skipTappedByService:(id)sender;
- (IBAction)moreTappedByService:(id)sender;

- (void)start;

@end


NS_ASSUME_NONNULL_END
