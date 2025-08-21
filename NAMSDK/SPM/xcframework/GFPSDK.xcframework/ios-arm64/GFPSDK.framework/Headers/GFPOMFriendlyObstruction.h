//
//  GFPOMFriendlyObstruction.h
//  GFPSDK
//
//  Created by Yeonah on 2021/06/02.
//  Copyright © 2021 Naver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GFPFriendlyObstructionType) {
    GFPFriendlyObstructionTypeMediaControls,
    GFPFriendlyObstructionTypeCloseAd,
    GFPFriendlyObstructionTypeNotVisible,
    GFPFriendlyObstructionTypeOther
};

@interface GFPOMFriendlyObstruction : NSObject

@property (nonatomic, readonly, strong) UIView *view;
@property (nonatomic, readonly, assign) GFPFriendlyObstructionType purpose;
@property (nonatomic, readonly, strong) NSString *reason;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWith:(UIView *)aView purpose:(GFPFriendlyObstructionType)aPurpose reason:(NSString *)aReason NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
