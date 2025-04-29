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
@class GFPNDAVastVerification;

typedef NS_OPTIONS(NSInteger, GFPVastExtensionType) {
    GFPVastExtensionTypeNone,
    GFPVastExtensionTypeGFP,
    GFPVastExtensionTypeAdVerification
};

@interface GFPVastExtensionInfo : NSObject

@property (nonatomic, readonly, assign) GFPVastExtensionType type;

@property (nonatomic, readonly, nullable) NSString *ctaText;
@property (nonatomic, readonly, nullable) NSArray <GFPNDAVastVerification *> *verifications;

- (instancetype)initWithElement:(DDXMLElement *)elem;

+ (NSArray <GFPVastExtensionInfo *> * _Nullable)extensionInfos:(DDXMLElement *)extensionElems;

@end

NS_ASSUME_NONNULL_END
