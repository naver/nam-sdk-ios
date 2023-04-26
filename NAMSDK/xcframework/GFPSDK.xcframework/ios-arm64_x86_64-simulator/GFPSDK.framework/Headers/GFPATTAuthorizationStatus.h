//
//  GFPATTAuthorizationStatus.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#ifndef GFPATTAuthorizationStatus_h
#define GFPATTAuthorizationStatus_h

/**
 * ATTrackingManagerAuthorizationStatus 와 값을 동일하게 맵핑. (value를 변경하지 말아야함.)
 */

typedef NS_ENUM(NSInteger, GFPATTAuthorizationStatus) {
    GFPATTAuthorizeNotDetermined = 0,          // 사용자의 승인 미요청 상태.
    GFPATTAuthorizeRestricted,             // 사용자의 기기가 제한된 상태.
    GFPATTAuthorizeDenied,                 // 사용자의 IDFA 요청 거절 상태.
    GFPATTAuthorizeAuthorized              // 사용자의 IDFA 요청 승인 상태.
};


#endif /* GFPATTAuthorizationStatus_h */
