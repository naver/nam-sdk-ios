//
//  GFPContentInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPContentInfo : NSObject

/**
 * Communication Ad - Source Type
 */
@property (readwrite, nonatomic, copy) NSString *st;

/**
 * Communication Ad - Source Subtype
 */
@property (readwrite, nonatomic, copy) NSString *sst;

/**
 * Communication Ad - Source ID
 */
@property (readwrite, nonatomic, copy) NSString *si;

@property (readonly) BOOL isValid;

@property (readonly) NSDictionary<NSString *, NSString *> *dict;

- (instancetype)initWithSourceType:(NSString *)st subtype:(NSString *)sst sourceId:(NSString *)si;

@end

NS_ASSUME_NONNULL_END
