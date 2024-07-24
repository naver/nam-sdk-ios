//
//  GFPNDAPlayerKeywordView.h
//  GFPSDKMediationNDAVideo
//
//  Created by sodam on 2022/07/19.
//  Copyright © 2022 Naver. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class GFPNDAPlayerKeywordView;
@class GFPTrackingURLs;

@class Icon;
@class GFPNDAVastControlInfo;


@protocol GFPNDAPlayerKeywordViewDelegate <NSObject>

- (void)keywordView:(GFPNDAPlayerKeywordView *)keywordView didKeywordTapped:(GFPTrackingURLs *)trackingUrls;

@end

static const NSTimeInterval kKeywordAnimationDuration = 0.5;

@interface GFPNDAPlayerKeywordView : UIView

@property (nonatomic, weak) id <GFPNDAPlayerKeywordViewDelegate> delegate;

@property (nonatomic, assign, readonly) CGFloat estimateHeight;
@property (nonatomic, assign, readonly) BOOL isComponentHidden;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame 
                  controlInfo:(GFPNDAVastControlInfo *)aControlInfo NS_DESIGNATED_INITIALIZER;

- (void)updateCurrentTime:(NSTimeInterval)currentTime;

- (void)showOverlayView;
- (void)hideOverlayView;

@end

NS_ASSUME_NONNULL_END
