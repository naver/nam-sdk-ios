//
//  GFPDictionaryUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (GFPUtils)


- (id)objectWithKey:(id)key;
- (id)objectWithKey:(id)key returnType:(Class)returnType;

- (BOOL)boolWithKey:(id)key;

+ (BOOL)isEmpty:(NSDictionary *)aDict;


@end

NS_ASSUME_NONNULL_END
