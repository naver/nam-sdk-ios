//
//  GFPAPSAdParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPAPSAdParam : NSObject


/**
 * Amazon 광고  quality 측정을 위한 광고 소재 crid 값.
 */
@property (readwrite, nonatomic, copy, nullable) NSString *crid;

/**
 * Amazon 광고 response AdSize.
 */
@property (readwrite, nonatomic, assign) CGSize size;

/**
 * Amazon  헤더 비딩 파라미터 (주의! Dictionary 의 Key는 문자열, Values는 NSString 혹은 NSArray<NSString *> 타입이어야 합니다.)
 */
@property (readwrite, nonatomic, copy, nullable) NSDictionary <NSString *, NSObject *> *apsHBParam;

/**
 * Amazon 광고 SKAdNetowrkParams.
 */
@property (readwrite, nonatomic, copy, nullable) NSDictionary *skAdNetworkParams;


@end

NS_ASSUME_NONNULL_END
