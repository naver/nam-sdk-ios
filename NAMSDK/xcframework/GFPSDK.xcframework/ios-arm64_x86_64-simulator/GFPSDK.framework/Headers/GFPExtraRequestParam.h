//
//  GFPExtraRequestParam.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface GFPExtraRequestParam : NSObject

@property (readonly, nonatomic, strong, nullable) NSDictionary *dict;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype _Nullable)initWith:(NSDictionary * _Nonnull)aDict;
- (GFPExtraRequestParam *)combinedWith: (GFPExtraRequestParam *)requestParam;

@end


NS_ASSUME_NONNULL_END
