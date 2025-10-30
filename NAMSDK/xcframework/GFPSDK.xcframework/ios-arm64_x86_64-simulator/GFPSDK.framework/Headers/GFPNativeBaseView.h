//
//  GFPNativeBaseView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@class GFPNativeStyleInfo;

@interface GFPNativeBaseView : UIView

@property (nonatomic, weak, nullable) IBOutlet GFPMediaView *mediaView;
/**
 * 리치 광고의 추가 렌더링 광고를 위한 뷰 전달 옵션입니다.
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, UIView *> *additionalRenderingViewDict;

/**
 * 리치 광고의 추가 렌더링 뷰들의 터치 이벤트 전달
 */
- (void)additionalRenderingViewClicked:(UIView *)clickedView;

- (void)removePlaceholders;

@end

NS_ASSUME_NONNULL_END
