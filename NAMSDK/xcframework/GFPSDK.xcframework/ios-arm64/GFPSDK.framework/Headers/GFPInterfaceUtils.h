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

/// style 이 System 일 때 traitCollection 의 userInterfaceStyle 로 판정한다. Light/Dark 는 traitCollection 과 무관하게 고정값.
+ (BOOL)isDarkModeWith:(GFPAdInterfaceStyle)style traitCollection:(UITraitCollection * _Nullable)traitCollection;

// 씬 기반 keyWindow / interfaceOrientation 조회는 NAS 의 GFPDeviceUtils(keyWindow, interfaceOrientation, interfaceOrientationForView:) 를 사용한다. (GFPSDK-1804)

/// 현재 기기가 iPhone Duo(폴더블, 모델 식별자 iPhone19,4) 인지. 실기기는 uname 의 hw.machine, 시뮬레이터는 SIMULATOR_MODEL_IDENTIFIER 로 판정하며 결과는 캐시된다.
+ (BOOL)isDuoDevice NS_SWIFT_NAME(isDuoDevice());

/// 모델 식별자 문자열로 iPhone Duo 여부를 판정한다. 테스트·주입용.
+ (BOOL)isDuoDeviceWithModelIdentifier:(NSString * _Nullable)modelIdentifier NS_SWIFT_NAME(isDuoDevice(modelIdentifier:));

@end

NS_ASSUME_NONNULL_END
