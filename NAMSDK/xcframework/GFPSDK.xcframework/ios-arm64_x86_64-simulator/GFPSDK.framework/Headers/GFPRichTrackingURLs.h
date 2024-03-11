//
//  GFPRichTrackingURLs.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

@class GFPRichDetailInfo;

NS_ASSUME_NONNULL_BEGIN

@interface GFPRichTrackingURLs : NSObject

- (instancetype)initWithTrackingArr:(NSArray *)richTrackingArr;
- (GFPRichDetailInfo * _Nullable)trackingWithKey:(NSString *)key;
@end

NS_ASSUME_NONNULL_END
