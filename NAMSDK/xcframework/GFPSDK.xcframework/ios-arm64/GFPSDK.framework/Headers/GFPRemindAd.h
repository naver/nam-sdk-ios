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
@property (readonly, nonatomic, strong) NSString *clickThrough;
@property (readonly, nonatomic, strong) NSString *clickTracking;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement error:(GFPError * _Nullable * _Nullable)aError;

@end


// MARK: - RemindAd
@interface GFPRemindAd : GFPTrackingPresentable

@property (readonly, nonatomic, strong) NonLinear *nonLinear;
@property (readonly, nonatomic, strong) NonlinearInfo *nonLinearInfo;

@property (readonly, nonatomic, strong) NSString *nonLinearID;
@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readonly, nonatomic, assign) NSInteger offset;
@property (readonly, nonatomic, assign) BOOL isBanner;
@property (readonly, nonatomic, strong, nullable) NSURL *bannerURL;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement nonLinear:(NonLinear *)aNonLinear info:(NonlinearInfo *)aInfo error:(GFPError * _Nullable * _Nullable)aError;


@end

NS_ASSUME_NONNULL_END
