//
//  GFPVastExtensionInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DDXMLElement;

@interface GFPVastExtensionInfo : NSObject

@property (nonatomic, readonly, strong) NSString *type;
@property (nonatomic, readonly, strong) NSString *value;

- (instancetype)initWithElement:(DDXMLElement *)elem;
- (NSString * _Nullable)getGfpCtaText;
+ (NSArray <GFPVastExtensionInfo *> * _Nullable)extensionInfos:(DDXMLElement *)extensionElems;
@end

NS_ASSUME_NONNULL_END
