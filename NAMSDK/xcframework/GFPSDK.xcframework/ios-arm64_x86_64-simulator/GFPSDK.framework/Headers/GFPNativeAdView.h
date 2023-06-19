//
//  GFPNativeAdView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPNativeBaseView.h"
#import "GFPNativeAd.h"


NS_ASSUME_NONNULL_BEGIN


@interface GFPNativeAdView : GFPNativeBaseView

@property (nonatomic, strong, nullable) GFPNativeAd *nativeAd;

@property (nonatomic, weak, nullable) IBOutlet UIImageView *iconView;
@property (nonatomic, weak, nullable) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak, nullable) IBOutlet UILabel *bodyLabel;
@property (nonatomic, weak, nullable) IBOutlet UILabel *advertiserLabel;
@property (nonatomic, weak, nullable) IBOutlet UILabel *socialContextLabel;
@property (nonatomic, weak, nullable) IBOutlet UILabel *callToActionLabel;
@property (nonatomic, weak, nullable) IBOutlet UIView *adChoicesView;
@property (nonatomic, weak, nullable) IBOutlet UILabel *adBadgeLabel;

@end

NS_ASSUME_NONNULL_END
