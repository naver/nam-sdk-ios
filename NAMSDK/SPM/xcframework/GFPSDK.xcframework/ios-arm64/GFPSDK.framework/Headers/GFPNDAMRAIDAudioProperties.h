//
//  GFPNDAMRAIDAudioProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAMRAIDAudioProperties : NSObject

@property (nonatomic, readonly, assign) NSInteger volume;
@property (nonatomic, readonly, assign) BOOL isUpdatedVolumeSound;

@end

NS_ASSUME_NONNULL_END
