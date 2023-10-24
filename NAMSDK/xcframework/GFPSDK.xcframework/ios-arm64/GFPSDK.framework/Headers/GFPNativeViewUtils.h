//
//  GFPNativeViewUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "Swift-Enum.h"
#import "GFPNativeAdRenderingSetting.h"
#import "GFPNativeLanguageType.h"

@import NaverAdsServices;

NS_ASSUME_NONNULL_BEGIN

@interface GFPCornerInfo : NSObject

@property (nonatomic, assign) GFPAlignment leftRightType;
@property (nonatomic, assign) GFPAlignment topBottomType;

@end



@interface GFPNativeViewUtils : NSObject

+ (GFPCornerInfo *)cornerInfoWith:(GFPAdChoicesViewPosition)position;

+ (CGRect)adChoicesViewFrameWith:(CGRect)frame;

@end



@interface GFPNativeLanguageUtils : NSObject

+ (NSString * _Nullable)languageCodeWith:(GFPNativeLanguageType)languageType;

@end

NS_ASSUME_NONNULL_END
