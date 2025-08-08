//
//  GFPRemindAd.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "GFPCreativeExtension.h"
#import "GFPTrackingURLs.h"

@import NaverAdsServices;

@class UIImage;
@class GFPError;
@class GFPTrackingURLs;
@class StaticResource;
@class DDXMLElement;


@protocol TrackingPresentable;


NS_ASSUME_NONNULL_BEGIN


// MARK: - NonlinearInfo
@interface NonlinearInfo : GFPCreativeExtension

@property (readonly, nonatomic, strong) NSString *targetID;
@property (readonly, nonatomic, assign) NSInteger offset;
@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readonly, nonatomic, assign) BOOL isPlayOnce;


@end


// MARK: - NonLinear
@interface NonLinear : NSObject

@property (readonly, nonatomic, strong) NSString *nonLinearID;
@property (readonly, nonatomic, assign) CGSize size;
@property (readonly, nonatomic, strong) NSString *apiFramework;
@property (readonly, nonatomic, strong) StaticResource *resource;
@property (readonly, nonatomic, strong) GFPVastBaseResource *nasResource;
@property (readonly, nonatomic, strong) NSString *clickThrough;
@property (readonly, nonatomic, strong) NSString *clickTracking;
@property (readonly, nonatomic, strong) NSArray *nasClickTracking;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement error:(GFPError * _Nullable * _Nullable)aError;
- (instancetype)initWithNasVast:(GFPVastNonLinearAd *)nonLinearVastAd error:(GFPError * _Nullable * _Nullable)aError;
@end


// MARK: - RemindAd
@interface GFPRemindAd : GFPTrackingPresentable

@property (readonly, nonatomic, strong) NonLinear *nonLinear;
@property (readonly, nonatomic, strong) NonlinearInfo *nonLinearInfo;
@property (readonly, nonatomic, strong) GFPNasNonLinearRemind *nasNonLinearInfo;

@property (readonly, nonatomic, strong) NSString *nonLinearID;
@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readonly, nonatomic, assign) NSInteger offset;
@property (readonly, nonatomic, assign) BOOL isBanner;
@property (readonly, nonatomic, strong, nullable) NSURL *bannerURL;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement nonLinear:(NonLinear *)aNonLinear info:(NonlinearInfo * _Nullable)aInfo error:(GFPError * _Nullable * _Nullable)aError;
- (instancetype)initWithNasVast:(GFPVastNonLinearAd *)nonLinearVastAd nonLinear:(NonLinear *)aNonLinear info:(GFPNasNonLinearRemind * _Nullable)aInfo error:(GFPError * _Nullable * _Nullable)aError;


@end

NS_ASSUME_NONNULL_END
