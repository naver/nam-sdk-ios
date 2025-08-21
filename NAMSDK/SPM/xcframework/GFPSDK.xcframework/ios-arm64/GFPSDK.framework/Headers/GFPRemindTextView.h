//
//  GFPRemindTextView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "GFPNonLinearAdView.h"


NS_ASSUME_NONNULL_BEGIN

@interface GFPRemindTextView : GFPNonLinearAdView

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame remindAd:(GFPRemindAd *)aRemindAd logId:(NSUUID *)logId;

@end

NS_ASSUME_NONNULL_END
