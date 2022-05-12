//
//  GFPNativeBaseView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNativeBaseView : UIView

@property (nonatomic, weak, nullable) IBOutlet GFPMediaView *mediaView;

@end

NS_ASSUME_NONNULL_END
