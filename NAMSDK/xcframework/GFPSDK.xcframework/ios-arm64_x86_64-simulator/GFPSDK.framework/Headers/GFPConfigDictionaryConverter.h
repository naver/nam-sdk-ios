//
//  GFPConfigDictionaryConverter.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAdConfiguration;

NS_ASSUME_NONNULL_BEGIN

@interface GFPConfigDictionaryConverter : NSObject


@property (nonatomic, readonly, strong) NSDictionary <NSString *, NSString *> *dict;


- (instancetype)initWithConfiguration:(GFPAdConfiguration *)aConfiguration;


@end

NS_ASSUME_NONNULL_END
