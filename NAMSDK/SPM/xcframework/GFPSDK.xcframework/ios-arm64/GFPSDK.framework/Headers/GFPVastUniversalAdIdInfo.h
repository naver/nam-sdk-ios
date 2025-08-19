//
//  GFPVastUniversalAdIdInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DDXMLElement;

@interface GFPVastUniversalAdIdInfo : NSObject

@property (nonatomic, readonly, strong) NSString *idRegistry;
@property (nonatomic, readonly, strong) NSString *value;

- (instancetype) initWithValue:(NSString *)value idRegistry:(NSString *)idRegistry;
+ (NSArray <GFPVastUniversalAdIdInfo *> *)universalAdIds:(NSArray <DDXMLElement *> *)universalIdElems;
@end

NS_ASSUME_NONNULL_END

