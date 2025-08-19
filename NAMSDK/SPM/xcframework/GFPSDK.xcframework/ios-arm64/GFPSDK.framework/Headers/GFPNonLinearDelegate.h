//
//  GFPNonLinearDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPStaticResource.h"


@class UIButton;


@protocol GFPNonLinearDelegate <NSObject>

@optional

/**
 * Remind 광고가 사라지면 호출됩니다. (상황 : Duration 시간이 지난 이후,  가로 세로 화면 전환시, Close 버튼 클릭 시).
 * @param type GFPRemindType
*/
- (void)nonLinearDidHide:(GFPRemindType)type;


/**
 * Remind 광고 클릭시 호출됩니다.
 * @param type GFPRemindType
*/
- (void)nonLinearWasClicked:(GFPRemindType)type;


/**
 * Remind 광고가 사용자에게 보여질 경우 호출됩니다..
 * @param type GFPRemindType
*/
- (void)nonLinearOnActiveImpression:(GFPRemindType)type;

@end
