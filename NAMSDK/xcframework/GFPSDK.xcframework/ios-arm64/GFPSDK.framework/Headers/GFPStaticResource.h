//
//  GFPStaticResource.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

#import "GFPTrackingURLs.h"

@class GFPError;
@class DDXMLElement;


typedef NS_OPTIONS(NSInteger, GFPRemindType) {
    GFPRemindNone = 1 << 0,
    GFPRemindBanner = 1 << 1,
    GFPRemindText = 1 << 2
};


typedef NS_OPTIONS(NSInteger, GFPResourceCode) {
    GFPResourceNone = 1 << 0,
    GFPResourceElection = 1 << 1,
    GFPResourceProviderNotice = 1 << 2,
    GFPResourceAdProviderNotice = 1 << 3,
    GFPResourceAlert = 1 << 4,
};


NS_ASSUME_NONNULL_BEGIN


// MARK: - StaticResource
@interface BaseStaticResource : NSObject

@property (readonly, nonatomic, strong) NSString *creativeType;
@property (readonly, nonatomic, strong) NSString *content;

- (instancetype)initWithElement:(DDXMLElement *)aElement error:(GFPError *_Nullable * _Nullable)aError;

@end



@interface StaticResource : BaseStaticResource

@property (readonly, nonatomic, assign) GFPRemindType type;

- (instancetype)initWithResourceElement:(DDXMLElement *)aElement error:(GFPError *_Nullable * _Nullable)aError;

@end



// MARK: - Icon
@interface Icon : GFPTrackingPresentable


@property (readonly, nonatomic, assign) BOOL hasDuration;
@property (readonly, nonatomic, assign) NSTimeInterval offset;
@property (readonly, nonatomic, assign) NSTimeInterval duration;
@property (readonly, nonatomic, strong) NSString *xPosition;
@property (readonly, nonatomic, strong) NSString *yPosition;
@property (readonly, nonatomic, strong) NSString *apiFramework;
@property (readonly, nonatomic, strong) BaseStaticResource *resource;

@property (readonly, nonatomic, assign) GFPResourceCode code;
@property (readonly, nonatomic, strong) NSString *value; // 문구


- (instancetype)initWithDomElement:(DDXMLElement *)aElement duration:(NSTimeInterval)aDuration error:(GFPError *_Nullable * _Nullable)aError;

+ (NSArray <Icon *> *)iconWithDomElement:(DDXMLElement *)aElement duration:(NSTimeInterval)aDuration error:(GFPError *_Nullable *_Nullable)aError;

@end




NS_ASSUME_NONNULL_END
