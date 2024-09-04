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
@class GFPAdImpressionInfo;

typedef NS_OPTIONS(NSInteger, GFPImpressionType) {
    GFPImpressionTypeRender = 1 << 0,
    GFPImpressionTypeViewable = 1 << 1,
    GFPImpressionTypeCustom = 1 << 2,
    GFPImpressionTypeSlot = 1 << 3,
    GFPImpressionTypeBounce = 1 << 4,
};

NS_ASSUME_NONNULL_BEGIN

@interface GFPImpressionTrackView : NSObject

@property (readonly, nonatomic, weak) UIView *viewToBeTracked;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithViewToBeTracked:(UIView *)viewToBeTracked NS_DESIGNATED_INITIALIZER;

@end

@interface GFPExposedInfo : NSObject

@property (readonly, nonatomic, assign) CGRect exposedRect;
@property (readonly, nonatomic, assign) CGFloat exposedRate;

- (instancetype)initWithExposedRect:(CGRect)exposedRect exposedRate:(CGFloat)exposedRate;

@end


@interface GFPImpressionTrackThreshold : NSObject
@property(readonly, nonatomic, assign) CGFloat visibleRate;
@property(readonly, nonatomic, assign) NSTimeInterval durationSec;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVisibleRate:(CGFloat)visibleRate
                        durationSec:(NSTimeInterval)durationSec NS_DESIGNATED_INITIALIZER;

+ (GFPImpressionTrackThreshold *)makeImpressionTrackThresholdWith:(GFPImpressionType)impType;
+ (GFPImpressionTrackThreshold *)makeImpressionTrackThresholdWith:(GFPImpressionType)impType
                                                 adImpressionInfo:(GFPAdImpressionInfo * _Nullable)adImpressionInfo;

@end


typedef void(^GFPImpressionTrackCompletionHandler)(GFPImpressionTrackingTarget *target);
typedef void(^GFPImpressionTrackCustomCheckHandler)(GFPImpressionTrackingTarget *target);
typedef BOOL(^GFPImpressionTrackCustomCompleteCheckHandler)(void);
typedef NSArray<UIView *> *_Nullable(^GFPImpressionTrackCustomViews)(void);

@interface GFPImpressionTrackingTarget : NSObject
@property (readonly, nonatomic, strong) GFPImpressionTrackView *trackView;
@property(readonly, nonatomic, strong) GFPImpressionTrackThreshold *trackThreshold;
@property(readonly, nonatomic, copy) GFPImpressionTrackCompletionHandler completionHandler;
@property(readonly, nonatomic, copy) GFPImpressionTrackCustomCompleteCheckHandler customCompleteCheckHandler;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithTrackView:(GFPImpressionTrackView *)trackView
                   trackThreshold:(GFPImpressionTrackThreshold *)trackThreshold
                completionHandler:(GFPImpressionTrackCompletionHandler)completionHandler NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithTrackView:(GFPImpressionTrackView *)trackView
                   trackThreshold:(GFPImpressionTrackThreshold *)trackThreshold
                completionHandler:(GFPImpressionTrackCompletionHandler)completionHandler
             completeCheckHandler:(GFPImpressionTrackCustomCompleteCheckHandler)customCompleteCheckHandler;

@end


@interface GFPImpressionTracker : NSObject
@property(class, readonly, nonatomic) GFPImpressionTracker *sharedInstance;

/*
 * GFPImpressionTrackingTarget 의 참조는 외부에서 유지되어야 합니다.
 */
- (void)startTracking:(GFPImpressionTrackingTarget *)target;

- (void)stopTracking:(GFPImpressionTrackingTarget *)target;

+ (GFPExposedInfo *)exposedInfoInScreen:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
