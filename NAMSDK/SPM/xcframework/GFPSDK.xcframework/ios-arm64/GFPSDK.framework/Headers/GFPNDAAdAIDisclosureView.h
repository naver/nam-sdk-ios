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

/// 배지의 접근성 유형. 클릭 URL(curl)이 있어 랜딩하면 "버튼", 없으면 문구("AI 활용")만 읽힌다 (결정안 2026-10-27).
/// 랜딩이 없으면 터치도 받지 않아 탭이 아래 광고 클릭 영역으로 통과하고, VoiceOver 이중 탭은 아무 동작을 하지 않는다.
- (void)updateAccessibilityWithLanding:(BOOL)hasLanding;

@end

NS_ASSUME_NONNULL_END
