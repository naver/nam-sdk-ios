//
//  GFPVideoDisplayMode.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS (NSInteger, GFPVideoDisplayType) {
    GFPVideoDisplayNormal = 1 << 0,
    GFPVideoDisplayCasting = 1 << 1,
    GFPVideoDisplayPIP = 1 << 2
};

@interface GFPVideoDisplayMode : NSObject

@property (nonatomic, readonly, assign) GFPVideoDisplayType mode;

@property (nonatomic, readonly, assign) BOOL isCasting;
@property (nonatomic, readonly, strong, nullable) NSString *text; //for casting mode.

@property (nonatomic, readonly, assign) BOOL isPIP;
@property (nonatomic, readonly, weak, nullable) UIView *customTopView; //for pip mode.

- (instancetype)init NS_UNAVAILABLE;

+ (GFPVideoDisplayMode *)normal;
+ (GFPVideoDisplayMode *)castingWith:(NSString *)aText;

+ (GFPVideoDisplayMode *)pip;
+ (GFPVideoDisplayMode *)pipWith:(UIView *)customTopView;

@end

NS_ASSUME_NONNULL_END
