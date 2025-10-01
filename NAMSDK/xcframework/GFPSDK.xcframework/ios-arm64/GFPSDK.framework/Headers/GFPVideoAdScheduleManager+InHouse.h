//
//  GFPVideoAdScheduleManager+InHouse.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import "GFPVideoAdScheduleManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoAdScheduleManager ()

/**
 * s2s 광고 클릭 지원. delegate 설정 후 openURL:landingDelegate: 구현 시 클릭에 관한 커스톰 동작이 가능합니다.
 */
@property (nonatomic, weak, nullable) id <GFPS2SAdClickDelegate> s2sClickDelegate;

@end

NS_ASSUME_NONNULL_END
