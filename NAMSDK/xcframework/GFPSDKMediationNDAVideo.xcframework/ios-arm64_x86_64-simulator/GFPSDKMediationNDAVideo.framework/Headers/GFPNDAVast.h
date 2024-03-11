//
//  GFPNDAVast.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class GFPError;
@class GFPNDAVastMediaFile;
@class GFPAdSkipInfo;
@class Icon;
@class GFPRemindAd;
@class GFPCreativeExtension;
@class DDXMLElement;
@class GFPNDAVastControlInfo;
@class GFPLoudnessNormalization;
@class GFPTrackingURLs;
@class BaseStaticResource;
@class DDXMLElement;
@class GFPVastCompanionAd;
@class HTMLResource;
@class GFPNDAVast;
NS_ASSUME_NONNULL_BEGIN


@interface GFPNDAVastProgressEvent : NSObject

@property(readonly, nonatomic, assign) NSTimeInterval progressSeconds;
@property(readonly, nonatomic, strong) NSString *eventUrl;

- (instancetype)initWithProgressSeconds:(NSTimeInterval)progressSeconds
                               eventUrl:(NSString *)eventUrl;

@end


@interface GFPNDAVastTracking : NSObject

@property(readonly, nonatomic, strong) NSArray<NSString *> *loaded;
@property(readonly, nonatomic, strong) NSArray<NSString *> *start;
@property(readonly, nonatomic, strong) NSArray<NSString *> *firstQuartile;
@property(readonly, nonatomic, strong) NSArray<NSString *> *midpoint;
@property(readonly, nonatomic, strong) NSArray<NSString *> *thirdQuartile;
@property(readonly, nonatomic, strong) NSArray<NSString *> *complete;
@property(readonly, nonatomic, strong) NSArray<NSString *> *skip;
@property(readonly, nonatomic, strong) NSArray<NSString *> *mute;
@property(readonly, nonatomic, strong) NSArray<NSString *> *unmute;
@property(readonly, nonatomic, strong) NSArray<NSString *> *pause;
@property(readonly, nonatomic, strong) NSArray<NSString *> *resume;
@property(readonly, nonatomic, strong) NSArray<NSString *> *rewind;
@property(readonly, nonatomic, strong) NSArray<NSString *> *otherAdInteraction;
@property(readonly, nonatomic, strong) NSArray<NSString *> *creativeView;

@property(readonly, nonatomic, strong) NSDictionary<NSString *, NSArray<NSString *> *> *progressDict;


- (instancetype)initWithVastTracking:(GFPNDAVastTracking *)vastTracking;

- (void)appendWith:(GFPNDAVastTracking *)vastTracking;

- (NSArray <GFPNDAVastProgressEvent *> *)progressEventWithDuration:(NSTimeInterval)aDuration;


@end


@interface GFPNDAVastAd : NSObject

@property (readonly, nonatomic, strong) GFPNDAVast *inLineVast;

@end


//TODO: change GFPNDAVastInline
@interface GFPNDAVast : NSObject


@property (readonly, nonatomic, strong) GFPNDAVastTracking *trackingInfo;
@property (readonly, nonatomic, strong) GFPTrackingURLs *trackingURLs;

@property (readonly, nonatomic, strong) NSArray<GFPNDAVastMediaFile *> *mediaFiles;
@property (readonly, nonatomic, strong) GFPNDAVastControlInfo *controlInfo;

@property (readonly, nonatomic, strong, nullable) NSArray <Icon *> *icons;

@property (readonly, nonatomic, strong, nullable) NSArray <GFPRemindAd *> *remindAdList;
@property (readonly, nonatomic, strong, nullable) GFPLoudnessNormalization *loudness;

@property (readonly, nonatomic, strong, nullable) NSString *ctaText;

//all, any, or none.
@property (nonatomic, strong, nullable) NSString *companionRequired;
@property (nonatomic, strong, nullable) NSArray <GFPVastCompanionAd *> * companions;

- (NSTimeInterval)videoDuration;

- (instancetype)initWithInlineElement:(DDXMLElement *)inlineElem skipInfo:(GFPAdSkipInfo *_Nullable)skipInfo error:(GFPError * _Nullable *_Nullable)error;

@end


@interface GFPNDAVastMediaFile : NSObject

@property (readonly, nonatomic, strong) NSString *delivery;
@property (readonly, nonatomic, strong) NSString *type;
@property (readonly, nonatomic, strong) NSNumber *bitrate;
@property (readonly, nonatomic, strong) NSString *urlString;
@property (readonly, nonatomic, assign) CGSize size;

@property (readonly, nonatomic, assign) BOOL isHLS;
@property (readonly, nonatomic, assign) BOOL isValidSize;

@property (readonly, nonatomic, strong) NSURL *url;


- (instancetype)initWithDomElement:(DDXMLElement *)aElement;

+ (NSArray <GFPNDAVastMediaFile *> * _Nullable)mediaFilesWithDomElement:(DDXMLElement *)aElement error:(GFPError *_Nullable *_Nullable)error;

@end


@interface GFPNDAVastWrapper : NSObject

@property (readonly, nonatomic, strong) NSString *adStytem;
@property (readonly, nonatomic, strong) NSString *vastAdTagURI;

@property (readonly, nonatomic, strong) GFPNDAVastTracking *trackingInfo;
@property (readonly, nonatomic, strong) GFPTrackingURLs *trackingURLs;

- (instancetype)initWithWrapperElement:(DDXMLElement *)aElement error:(GFPError *_Nullable*_Nullable)error;

@end

@interface GFPVastCompanionAd : NSObject

//Attribute
@property (nonatomic, assign) NSInteger width; //Required
@property (nonatomic, assign) NSInteger height; //Required
@property (nonatomic, strong) NSString *companionId;
@property (nonatomic, assign) NSInteger assetWidth;
@property (nonatomic, assign) NSInteger assetHeight;
@property (nonatomic, assign) NSInteger expandedWidth;
@property (nonatomic, assign) NSInteger expandedHeight;
@property (nonatomic, strong) NSString *apiFramework;
@property (nonatomic, strong) NSString *adSlotId;
@property (nonatomic, assign) NSInteger pxratio;
@property (nonatomic, strong) NSString *renderingMode;

//Element
@property (nonatomic, strong) BaseStaticResource *staticResource; // Required
@property (nonatomic, strong) BaseStaticResource *iFrameResource; // Required
@property (nonatomic, strong) HTMLResource *htmlResource; // Required
@property (nonatomic, strong, readonly) NSString *companionClickThrough;
@property (readonly, nonatomic, strong) NSMutableArray<NSString *> *companionClickTracking;
@property (nonatomic, strong, readonly) NSString *altText;
@property (readonly, nonatomic, strong) GFPNDAVastTracking *trackingInfo;


+ (NSArray <GFPVastCompanionAd *> * _Nullable)companionAds:(NSArray <DDXMLElement *> *)companionAdsElems error:(GFPError *_Nullable*_Nullable)aError;

- (float)getBestScore:(CGSize)containerSize;

@end


NS_ASSUME_NONNULL_END
