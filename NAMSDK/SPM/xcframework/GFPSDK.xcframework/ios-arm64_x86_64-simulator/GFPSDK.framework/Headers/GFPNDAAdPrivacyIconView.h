//
//  GFPNDAAdPrivacyIconView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdChoiceResourceUtils.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPNDAAdPrivacyIconType) {
    GFPNDAAdPrivacyIconTypeI = 1 << 0,
    GFPNDAAdPrivacyIconTypeCustom = 1 << 1,    // Custom Icon
};

@class GFPNDAAdPrivacyIconView;

@protocol GFPNDAAdPrivayClickDelegate <NSObject>

- (void)adPrivacyMarkWasClicked:(UIView *)adPrivacyView;

@end

@interface GFPNDAAdPrivacyIconView : UIButton <GFPNDAAdChoiceResourcePresentable>

@property (nonatomic, weak) id <GFPNDAAdPrivayClickDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *privacyURL;

- (instancetype)initWithFrame:(CGRect)frame
                          url:(NSString *)url
                         type:(GFPNDAAdPrivacyIconType)type
                resourceUtils:(GFPNDAAdChoiceResourceUtils *)resourceUtils;

@end

NS_ASSUME_NONNULL_END
