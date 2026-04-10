//
//  GFPNDAAdAIUsageBadgeView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDAAdAIUsageBadgeDelegate <NSObject>

- (void)aiUsageBadgeWasClicked:(UIView *)aiUsageBadge;

@end

@interface GFPNDAAdAIUsageBadgeView : UIButton

@property (nonatomic, weak) id <GFPNDAAdAIUsageBadgeDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
