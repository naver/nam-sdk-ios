//
//  GFPWaterfallList.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPProvider.h"
#import "GFPAdAdaptor.h"

@class GFPAd;
@class GFPAdEvent;
@class GFPAdEventObject;
@class GFPAdInfo;
@class GFPAdInfoSize;
@class GFPAdInfoStyle;
@class GFPError;
@class GFPAdHTML;
@class GFPAdSkipData;
@class GFPAdSkipInfo;
@class GFPNativeAdInfo;
@class GFPWaterfallDedup;
@class GFPSKAdNetworkInfo;
@class GFPAdChoiceInfo;
@class GFPAdImpressionInfo;
@class GFPRewardedAdInfo;
@class GFPAutoPlayInfo;

NS_ASSUME_NONNULL_BEGIN


@interface GFPWaterfallExtra : NSObject

@property (readonly, nonatomic, strong, nullable) NSNumber *randomNumber;
@property (readonly, nonatomic, strong, nullable) GFPWaterfallDedup *dedup;


- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)dict error:(GFPError *_Nullable *_Nullable)error NS_DESIGNATED_INITIALIZER;

@end


@interface GFPWaterfallConfig : NSObject

@property (readonly, nonatomic, strong) NSNumber *sdkInitLastUpdateMillis;
@property (readonly, nonatomic, strong) GFPAdImpressionInfo *impressionInfo;
@property (readonly, nonatomic, strong) GFPAutoPlayInfo *autoPlayInfo;

@property (readonly, nonatomic, assign) BOOL needAdChoice;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)dict error:(GFPError *_Nullable *_Nullable)error NS_DESIGNATED_INITIALIZER;

@end


/**
 * GFPWaterfallList
 */
@interface GFPWaterfallList : NSObject

@property (readonly, nonatomic, copy, nullable) NSDictionary *originalDict;
@property (readonly, nonatomic, strong, nullable) NSString *requestID;
@property (readonly, nonatomic, strong, nullable) NSString *adUnit;
@property (readonly, nonatomic, strong, nullable) GFPAdEvent *eventTracking;
@property (readonly, nonatomic, strong, nullable) GFPAdSkipData *skipData;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAd *> *ads;

@property (readonly, nonatomic, strong, nullable) GFPWaterfallConfig *config;
@property (readonly, nonatomic, strong, nullable) GFPWaterfallExtra *extra;

@property (readonly, nonatomic, strong, nullable) NSString *skadnToken;
@property (readonly, nonatomic, assign) BOOL shouldRegister;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)dict error:(GFPError *_Nullable *_Nullable)error NS_DESIGNATED_INITIALIZER;

@end


/**
 * GFPAdImpressionInfo
 */
@interface GFPAdImpressionInfo : NSObject

@property (readonly, nonatomic, strong, nullable) NSNumber *ratio;
@property (readonly, nonatomic, strong, nullable) NSNumber *ms;
@property (readonly, nonatomic, assign) BOOL isSmallerThan;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)dict NS_DESIGNATED_INITIALIZER;
- (instancetype _Nullable)initWithRatio:(NSNumber *)ratio ms:(NSNumber *)ms NS_DESIGNATED_INITIALIZER;
- (instancetype _Nullable)initWithRatio:(NSNumber *)ratio ms:(NSNumber *)ms isSmallerThan:(BOOL)isSmallerThan;

@end


/**
 * GFPAutoPlayInfo
 */

@interface GFPAutoPlayInfo : NSObject

@property (readonly, nonatomic, strong, nullable) NSNumber *time; //sec
@property (readonly, nonatomic, strong, nullable) NSNumber *controlType;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)dict NS_DESIGNATED_INITIALIZER;

@end


/**
 * GFPAdEvent
 */
@interface GFPAdEvent : NSObject

@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *ackImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *renderedImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *viewableImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *clicks;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *loadErrors;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *startErrors;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *attachImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *completeImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *lazyRenderMediaFailedImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *mutes;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *closeImpressions;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *bounce;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)eventTrackingDict NS_DESIGNATED_INITIALIZER;
@end


@interface GFPAdInfoEvent : GFPAdEvent

@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *vimp1px;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *vimp100;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdEventObject *> *vimp100p;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)eventTrackingDict NS_DESIGNATED_INITIALIZER;

@end

/**
 * GFPAdEventObject
 */
@interface GFPAdEventObject : NSObject

@property (readonly, nonatomic, strong, nullable) NSString *url;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithUrl:(NSString *)url NS_DESIGNATED_INITIALIZER;
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)eventTrackingObjectDict NS_DESIGNATED_INITIALIZER;

+ (NSArray <GFPAdEventObject *> *)eventObjectsWithDict:(NSDictionary *)eventTrackingDict;

@end

/**
 * GFPAd
 */
@interface GFPAd : NSObject

@property (readonly, nonatomic, strong, nullable) NSString *encrypted;
@property (readonly, nonatomic, strong, nullable) NSString *connectionType;
@property (readonly, nonatomic, strong, nullable) NSString *adProviderName;
@property (readonly, nonatomic, strong, nullable) NSString *renderType;
@property (readonly, nonatomic, strong, nullable) NSString *layoutType;
@property (readwrite, nonatomic, strong, nullable) NSString *creativeType;
@property (readonly, nonatomic, strong, nullable) NSNumber *vastMaxRedirect;
@property (readonly, nonatomic, strong, nullable) GFPAdSkipInfo *skipInfo;
@property (readonly, nonatomic, strong, nullable) GFPAdInfoEvent *eventTracking;
@property (readonly, nonatomic, strong, nullable) GFPAdInfo *adInfo;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)adDict
                                        data:(GFPAdSkipData * _Nullable)data
                       needAdChoiceForRender:(BOOL)needAdChoiceForRender NS_DESIGNATED_INITIALIZER;

@end

/**
 * GFPAdInfo
 */
@interface GFPAdInfo : NSObject

@property (readonly, nonatomic, strong, nullable) NSString *requestURL;
@property (readonly, nonatomic, strong, nullable) NSArray<GFPAdInfoSize *> *requestSizes;
@property (readonly, nonatomic, strong, nullable) GFPAdInfoSize *responseSize;
@property (readonly, nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *sdkRequestInfo;
@property (readonly, nonatomic, assign, nullable) NSNumber *timeout; // milliseconds

@property (readonly, nonatomic, strong, nullable) NSString *bidPrice;

@property (readonly, nonatomic, strong, nullable) GFPAdHTML *adHTML;
@property (readonly, nonatomic, strong, nullable) GFPNativeAdInfo *nativeInfo;
@property (readonly, nonatomic, strong, nullable) GFPSKAdNetworkInfo *skAdNetworkInfo;
@property (readonly, nonatomic, strong, nullable) GFPAdChoiceInfo *adChoiceInfo;

@property (readonly, nonatomic, strong, nullable) NSString *baseUrl;

@property (readonly, nonatomic, strong, nullable) NSNumber *videoloadTimeout; // milliseconds
@property (readonly, nonatomic, strong, nullable) NSNumber *expireTime; // seconds

@property (readonly, nonatomic, strong, nullable) GFPRewardedAdInfo *rewardedAdInfo;


- (instancetype)init NS_UNAVAILABLE;
    
- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)adInfoDict
                                    skipInfo:(GFPAdSkipInfo * _Nullable)skipInfo
                       needAdChoiceForRender:(BOOL)needAdChoiceForRender NS_DESIGNATED_INITIALIZER;

@end


/**
 * GFPAdInfoSize
 */
@interface GFPAdInfoSize : NSObject

@property (readonly, nonatomic, strong, nullable) NSNumber *width;
@property (readonly, nonatomic, strong, nullable) NSNumber *height;
@property (readonly, nonatomic) CGSize size;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithDictionary:(NSDictionary *_Nullable)adInfoSizeDict NS_DESIGNATED_INITIALIZER;

@end


NS_ASSUME_NONNULL_END
