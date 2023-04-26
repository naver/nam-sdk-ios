//
//  GFPInternalUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface GFPWaterfallAdSize : NSObject

@property (nonatomic, readonly, assign) CGFloat width;
@property (nonatomic, readonly, assign) CGFloat height;

@property (nonatomic, readonly, assign) CGSize size;

- (instancetype)initWith:(NSDictionary *)aDict;

@end


@interface GFPInternalUtils : NSObject

+ (NSArray <GFPWaterfallAdSize *> *) adResponseSizeWithDictionary:(NSDictionary *) preloadWfDict;
+ (NSArray <GFPWaterfallAdSize *> *) adResponseSizeWithString:(NSString *) preloadWfString;
+ (NSArray <GFPWaterfallAdSize *> *) adResponseSizeWithData:(NSData *) preloadWfData;

@end

NS_ASSUME_NONNULL_END
