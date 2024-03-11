//
//  GFPNDAVideoUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPLanguageType.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAVideoUtils : NSObject


@property (readonly, nonatomic, strong) NSBundle *bundle;


+ (GFPNDAVideoUtils *)sharedInstance;

/**
 * GFPNDAVideoResource
 */
- (UIView *)loadNibWithName:(NSString *)aName;
- (UIImage *)imageWith:(NSString *)aName;

- (NSString *)resourceStringWith:(NSString *)aMeesageKey;
- (NSString *)resourceStringWith:(NSString *)aMeesageKey languageType:(GFPLanguageType)languageType;

- (NSString *)stringWith:(NSString *)aKey message:(NSString *)aMeesage;
- (NSString *)stringWith:(NSString *)aKey message:(NSString *)aMeesage languageType:(GFPLanguageType)languageType;

@end

NS_ASSUME_NONNULL_END
