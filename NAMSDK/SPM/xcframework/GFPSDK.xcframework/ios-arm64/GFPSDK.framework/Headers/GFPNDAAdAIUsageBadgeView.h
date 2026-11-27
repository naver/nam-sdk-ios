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

/// 클릭 URL(curl) 유무. 기본 YES. NO 면 "버튼" 유형을 떼고, VoiceOver 이중 탭도 아무 동작을 하지 않는다.
@property (nonatomic, assign) BOOL hasLanding;

@end

NS_ASSUME_NONNULL_END
