//
//  GFPNDAVastLoader.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPError;
@class GFPAdSkipInfo;

@class GFPVastEvent;

@class GFPNDAVast;
@class GFPNDAVastLoader;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPNDAVastLoaderDelegate <NSObject>

- (void)vastLoader:(GFPNDAVastLoader *)vastLoader didLoadVast:(GFPNDAVast *)vast;
- (void)vastLoader:(GFPNDAVastLoader *)vastLoader didFailWithError:(GFPError * _Nullable)error;

@end


@interface GFPNDAVastLoader : NSObject

@property (nonatomic, weak) id <GFPNDAVastLoaderDelegate> delegate;

@property (nonatomic, strong, readonly) GFPNDAVast *vast;
@property (nonatomic, strong, readonly) GFPVastEvent *vastEvent;

- (instancetype)initWithVastMaxRedirect:(NSNumber *)vastMaxRedirect skipInfo:(GFPAdSkipInfo * _Nullable)skipInfo;
- (instancetype)initWithVastMaxRedirect:(NSNumber *)vastMaxRedirect skipInfo:(GFPAdSkipInfo * _Nullable)skipInfo vastTimeOut:(CFTimeInterval)vastTimeOut;

- (void)loadVastWithXMLString:(NSString *)xmlString;

@end

@interface GFPNDAVastAdLoader : NSObject


@end

NS_ASSUME_NONNULL_END
