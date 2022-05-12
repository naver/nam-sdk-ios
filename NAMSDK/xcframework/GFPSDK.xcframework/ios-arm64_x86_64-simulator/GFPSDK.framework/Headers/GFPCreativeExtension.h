//
//  GFPCreativeExtension.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


@class GFPError;
@class DDXMLElement;


typedef NS_OPTIONS(NSInteger, GFPCreativeType) {
    GFPCreativeNone = 0,
    GFPCreativeLoudness = 1,
    GFPCreativeNonLinear = 2,
};
 

NS_ASSUME_NONNULL_BEGIN

@interface GFPCreativeExtension : NSObject


@property (readonly, nonatomic, assign) GFPCreativeType creativeType;
@property (readonly, nonatomic, strong) NSString *type;
@property (readonly, nonatomic, strong) NSDictionary *dict;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement error:(GFPError * _Nullable * _Nullable)aError;


+ (NSArray <GFPCreativeExtension *> * _Nullable)creativeExtension:(DDXMLElement *)aElement error:(GFPError * _Nullable *_Nullable)aError;

@end

NS_ASSUME_NONNULL_END
