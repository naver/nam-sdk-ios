//
//  GFPInterfaceUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <UIKit/UIKit.h>
#import "Swift-Enum.h"
NS_ASSUME_NONNULL_BEGIN

@interface GFPInterfaceUtils : NSObject

+ (BOOL)isDarkModeWith:(GFPAdInterfaceStyle)style;

// 씬 기반 keyWindow / interfaceOrientation 조회는 NAS 의 GFPDeviceUtils(keyWindow, interfaceOrientation, interfaceOrientationForView:) 를 사용한다. (GFPSDK-1804)

@end

NS_ASSUME_NONNULL_END
