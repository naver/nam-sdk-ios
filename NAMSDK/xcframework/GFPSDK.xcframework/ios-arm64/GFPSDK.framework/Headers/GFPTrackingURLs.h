//
//  GFPTrackingURLs.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


@class DDXMLElement;


NS_ASSUME_NONNULL_BEGIN


@interface GFPTrackingURLs : NSObject

@property (readonly, nonatomic, strong) NSArray <NSString *> *viewTrackings;
@property (readonly, nonatomic, strong) NSArray <NSString *> *errorTrackings;
@property (readonly, nonatomic, strong) NSString *clickThrough;
@property (readonly, nonatomic, strong) NSArray <NSString *> *clickTrackings;


- (instancetype)initWithIconElement:(DDXMLElement *)aElemnt;
- (instancetype)initWithInlineElement:(DDXMLElement *)aElement linearElement:(DDXMLElement *)aLinearElement;

- (instancetype)initWithViewTrackings:(NSArray *)aViewTrackings
                       errorTrackings:(NSArray *)aErrorTrackings
                         clickThrough:(NSString *)aClickThrough
                        clickTracking:(NSArray *)aClickTrackings;

- (void)appendWith:(GFPTrackingURLs *)trackingURLs;

@end


@interface GFPTrackingPresentable : NSObject <NSCopying>


@property (readonly, nonatomic, strong, nonnull) GFPTrackingURLs *trackingURLs;


@end


NS_ASSUME_NONNULL_END
