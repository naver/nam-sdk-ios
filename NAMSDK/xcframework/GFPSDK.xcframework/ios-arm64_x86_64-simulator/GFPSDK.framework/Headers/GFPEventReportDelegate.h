//
//  GFPEventReportDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


// CHECK: - Logging 확인을 위한 부분으로 Project target으로 빌드하고, 배포도 Private이다.
//          (샘플앱에서는 Public으로 변경해서 빌드.)
@protocol GFPEventReportDelegate <NSObject>

@optional

- (void)reportTrackingAckImp:(NSString * _Nullable)aURL;
- (void)reportTrackingViewableImp:(NSString * _Nullable)aURL;
- (void)reportTrackingRenderedImp:(NSString * _Nullable)aURL;
- (void)reportTrackingAttachedImp:(NSString * _Nullable)aURL;
- (void)reportTrackingClickEvent:(NSString * _Nullable)aURL;
- (void)reportTrackingMuteEvent:(NSString *_Nullable)aURL;

- (void)reportTrackingLoadError:(NSString *)loadEventInfo;
- (void)reportTrackingStartError:(NSString *)startEventInfo;


@end


NS_ASSUME_NONNULL_END
