//
//  GFPImpressionTracker.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <UIKit/UIKit.h>

@class UIView;
@class GFPImpressionTrackingTarget;

typedef NS_OPTIONS(NSInteger, GFPImpressionType) {
    GFPImpressionTypeRender = 1 << 0,
    GFPImpressionTypeViewable = 1 << 1,
    GFPImpressionTypeCustom = 1 << 2,
};

NS_ASSUME_NONNULL_BEGIN

@interface GFPImpressionTrackView : NSObject

@property (readonly, nonatomic, weak) UIView *viewToBeTracked;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithViewToBeTracked:(UIView *)viewToBeTracked NS_DESIGNATED_INITIALIZER;

@end

@interface GFPImpressionTrackThreshold : NSObject
@property(readonly, nonatomic, assign) CGFloat visibleRate;
@property(readonly, nonatomic, assign) NSTimeInterval durationSec;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVisibleRate:(CGFloat)visibleRate
                        durationSec:(NSTimeInterval)durationSec NS_DESIGNATED_INITIALIZER;

@end


typedef void(^GFPImpressionTrackCompletionHandler)(GFPImpressionTrackingTarget *target);

@interface GFPImpressionTrackingTarget : NSObject
@property (readonly, nonatomic, strong) GFPImpressionTrackView *trackView;
@property(readonly, nonatomic, strong) GFPImpressionTrackThreshold *trackThreshold;
@property(readonly, nonatomic, copy) GFPImpressionTrackCompletionHandler completionHandler;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithTrackView:(GFPImpressionTrackView *)trackView
                   trackThreshold:(GFPImpressionTrackThreshold *)trackThreshold
                completionHandler:(GFPImpressionTrackCompletionHandler)completionHandler NS_DESIGNATED_INITIALIZER;
@end


@interface GFPImpressionTracker : NSObject
@property(class, readonly, nonatomic) GFPImpressionTracker *sharedInstance;

/*
 * GFPImpressionTrackingTarget 의 참조는 외부에서 유지되어야 합니다.
 */
- (void)startTracking:(GFPImpressionTrackingTarget *)target;

- (void)stopTracking:(GFPImpressionTrackingTarget *)target;

@end

NS_ASSUME_NONNULL_END
