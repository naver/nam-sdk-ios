//
//  GFPNDAUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "GFPLanguageType.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAUtils : NSObject


@property (readonly, nonatomic, strong) NSBundle *mraidBundle;
@property (readonly, nonatomic, strong) NSBundle *nativeBundle;


+ (GFPNDAUtils *)sharedInstance;


/**
 * GFPNDAMraidResource
 */
- (NSString *)mraidFileContentsPath:(NSString *)name extension:(NSString *)extension;
- (NSString *)mraidFileContentsByPath:(NSString *)name extension:(NSString *)extension;

+ (NSString *)mraidJavascript;

/**
 * GFPNDANativeResource
 */
- (UIImage *)nativeImageWith:(NSString *)aName;

- (NSString *)nativeResourceStringWith:(NSString *)aMessageKey;
- (NSString *)nativeResourceStringWith:(NSString *)aMessageKey languageType:(GFPLanguageType)languageType;

- (UIView * _Nullable)nativeLoadNibWithName:(NSString *)aName index:(NSInteger)index;

+ (NSAttributedString * _Nullable)ctaChangedText:(NSString *)originText fontSize:(CGFloat)fontSize;


/**
 * for customAsset utils
 */
+ (UIImage *)customImageWith:(NSString *)name inBundle:(NSBundle * _Nullable)bundle;

@end

NS_ASSUME_NONNULL_END
