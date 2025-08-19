//
//  GFPVideoCastingView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

  


NS_ASSUME_NONNULL_BEGIN

@class GFPVideoDisplayMode;
@interface GFPVideoCastingView : UIView

@property (nonatomic, strong) GFPVideoDisplayMode *mode;

- (instancetype)initWithMode:(GFPVideoDisplayMode *)aMode;

@end

NS_ASSUME_NONNULL_END
