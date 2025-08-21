//
//  GFPNDAMRAIDPositionProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAMRAIDPositionProperties : NSObject

@property (nonatomic, readonly, assign) CGRect defaultPos;
@property (nonatomic, readonly, assign) CGRect currentPos;

@property (nonatomic, readonly, assign) BOOL isUpdatedDefaultPosition;
@property (nonatomic, readonly, assign) BOOL isUpdatedCurrentPosition;


- (instancetype)initWithRootView:(UIView *)rootView;

@end

NS_ASSUME_NONNULL_END
