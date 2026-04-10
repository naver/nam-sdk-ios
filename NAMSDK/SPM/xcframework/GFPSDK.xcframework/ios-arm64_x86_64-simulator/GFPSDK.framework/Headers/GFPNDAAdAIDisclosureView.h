//
//  GFPNDAAdAIDisclosureView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS(NSInteger, GFPNDAAdAIDisclosureViewType) {
    GFPNDAAdAIDisclosureViewTypeNone = 1 << 0,
    GFPNDAAdAIDisclosureViewTypeUsageBadge = 1 << 1
};

@class GFPAdEventObject;

@protocol GFPNDAAdAIDisclosureViewDelegate <NSObject>

- (void)aiUsageBadgeWasClicked:(UIView *)aiUsageView;

@end

@interface GFPNDAAdAIDisclosureView : UIView

@property (nonatomic, weak) id <GFPNDAAdAIDisclosureViewDelegate> delegate;
@property (nonatomic, assign, readonly) GFPNDAAdAIDisclosureViewType type;

- (instancetype)initWithFrame:(CGRect)frame type:(GFPNDAAdAIDisclosureViewType)type;

@end

NS_ASSUME_NONNULL_END
