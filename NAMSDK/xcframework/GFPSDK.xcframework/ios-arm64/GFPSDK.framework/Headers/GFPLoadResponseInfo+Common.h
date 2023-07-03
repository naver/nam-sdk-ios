//
//  GFPLoadResponseInfo+Common.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPLoadResponseInfo.h"

NS_ASSUME_NONNULL_BEGIN


@class GFPLoadResponseInfo;
@class GFPLoadEvent;


@protocol GFPResponseInfoPresentable <NSObject>

@property (nonatomic, strong) GFPLoadResponseInfo *responseInfo;

@end



@interface GFPInternalResponseInfo (Common)

- (void)recordAdaptorName:(NSString *)adaptorName;

- (void)recordLoadEmptyTime;
- (void)recordLoadEndTime:(NSNumber *)endTime;

- (void)updateLoadErrorMessage:(NSString *)errorMessage errorTime:(NSNumber *)errorTime;

@end


@interface GFPLoadResponseInfo (Common)

- (void)recordRequestID:(NSString *)requestID;

- (void)recordLoadStartTime;
- (void)recordLoadEndime;

- (void)recordLoadEmptyTime:(GFPInternalResponseInfo *)aLoadResponseInfo;

- (void)recordErrorResponseInfo:(GFPInternalResponseInfo *)aLoadResponseInfo
                          event:(GFPLoadEvent *)aLoadEvent;

- (void)recordSuccessResponseInfo:(GFPInternalResponseInfo *)aLoadResponseInfo
                          endTime:(NSNumber *)aEndTime;

@end

NS_ASSUME_NONNULL_END
