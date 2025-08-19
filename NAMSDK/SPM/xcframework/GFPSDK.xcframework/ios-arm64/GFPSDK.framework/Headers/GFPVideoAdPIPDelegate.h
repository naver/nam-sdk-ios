//
//  GFPVideoAdPIPDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPVideoAdManager;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPVideoAdPIPDelegate <NSObject>
@optional

/**
 * PIP 영역 상단의 닫기 버튼 클릭 시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdCloseBtnTappedInPIP:(GFPVideoAdManager *)videoAdManager;


/**
 * PIP 영역 상단의 리턴 버튼 클릭 시 호출됩니다.
 * @param videoAdManager 비디오 광고 매니저
 */
- (void)videoAdReturnBtnTappedInPIP:(GFPVideoAdManager *)videoAdManager;

@end

NS_ASSUME_NONNULL_END
