//
//  GFPNDASearchKeywordView.h
//  GFPSDKMediationNDAVideo
//
//  Created by sodam on 2022/07/22.
//  Copyright © 2022 Naver. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Icon;
@class GFPTrackingURLs;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDASearchKeywordDelegate <NSObject>

- (void)clickKeywordWith:(GFPTrackingURLs *)tracking;

@end


static const CGFloat kSearchKeywordViewHeight = 26.0;


@interface GFPNDASearchKeywordView : UIView

@property (nonatomic, strong, readonly) Icon *data;

@property (nonatomic, assign, readonly) BOOL isClicked;

@property (nonatomic, weak) id <GFPNDASearchKeywordDelegate> delegate;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame 
                         icon:(Icon *)data NS_DESIGNATED_INITIALIZER;

- (void)changeKeywordStyleWith:(BOOL)isEnable;

@end

NS_ASSUME_NONNULL_END
