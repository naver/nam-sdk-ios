//
//  GFPNDAPlayerTopControlView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPStaticResource.h"

@class GFPNDAPlayerTopControlView;
@class GFPAdChoiceInfo;

typedef NS_ENUM(NSInteger, GFPNDAPlayerTopViewType) {
    GFPNDAPlayerTopViewTypeNone = 0,
    GFPNDAPlayerTopViewTypeMore,
    GFPNDAPlayerTopViewTypeElection,
    GFPNDAPlayerTopViewTypeALL
};


NS_ASSUME_NONNULL_BEGIN


@protocol GFPNDAPlayerTopDelegate <NSObject>

- (void)topView:(GFPNDAPlayerTopControlView *)aTopView didMoreTapped:(NSString *)aURL;
- (void)topView:(GFPNDAPlayerTopControlView *)aTopView didElectionTapped:(NSString *)aURL;

@end


@interface GFPNDAPlayerTopControlView : UIView

@property (nonatomic, weak) id<GFPNDAPlayerTopDelegate> delegate;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)aFrame
                 clickThrough:(NSString *)aClickThrough
                     iconList:(NSArray<Icon *> *)aIconList NS_DESIGNATED_INITIALIZER;

- (void)showTopViewComponent;
- (IBAction)moreTappedByService:(id)sender;

@end

NS_ASSUME_NONNULL_END
