//
//  GFPDecorationView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * POC 추가 렌더링(쿠폰·CTA·가격 등) 뷰들이 놓이는 컨테이너.
 *
 * - 컨테이너 자신은 터치를 받지 않고 아래 뷰(미디어 등)로 통과시킵니다.
 * - 내부 subview는 각자의 `userInteractionEnabled` 값에 따라 개별적으로 터치를 받습니다.
 *   (subview가 터치를 받으려면 이 컨테이너의 `userInteractionEnabled`는 YES여야 합니다. 기본값 YES)
 */
@interface GFPDecorationView : UIView

@end

NS_ASSUME_NONNULL_END
