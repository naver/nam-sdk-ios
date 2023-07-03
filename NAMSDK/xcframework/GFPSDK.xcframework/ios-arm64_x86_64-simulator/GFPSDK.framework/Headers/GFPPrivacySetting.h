//
//  GFPPrivacySetting.h
//  GFPSDK
//
//  Created by sodam on 2022/06/29.
//  Copyright © 2022 Naver. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPPrivacySetting : NSObject

@property (class, nonatomic, strong, readonly) NSString *IAB_TCString; //for GDPR
@property (class, nonatomic, strong, readonly) NSString *IAB_USPString; //for CCPA

/**
 * 성인이 아닌 사용자에 대한 광고 요청 여부 (기본값: NO)
 */
@property (nonatomic, assign) BOOL underAgeOfConsent;

/**
 * 아동 온라인 개인정보 보호법 (COPPA) 에 의거하여 페이지 또는 앱이 아동 대상 서비스로 취급 되어야 하는지 여부 (기본값: NO)
 */
@property (nonatomic, assign) BOOL childDirected;

- (instancetype)initWithUnderAgeOfConsent:(BOOL)underAgeOfConsent
                            childDirected:(BOOL)childDirected;

@end

NS_ASSUME_NONNULL_END
