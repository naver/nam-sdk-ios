//
//  GFPNativeTemplateOptions.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>

#import "GFPNativeProtocol.h"

@class GFPAdNativeOptions;

NS_ASSUME_NONNULL_BEGIN

@interface GFPNativeTemplateOptions : NSObject

/**
 * `네이티브 광고 템플릿 적용` 설정.
 * (기본값은 NO)
 */
@property (nonatomic, readonly, assign) BOOL useNativeTemplate;

/**
 * 네이티브 템플릿으로 로드되는 네이티브 광고 설정
 */
@property (nonatomic, readonly, strong) GFPAdNativeOptions *nativeOptions;

/**
 * custom template 사용 시 설정
 * - key: visual key
 * - value: GFPNativeTemplateViewProtocol 을 conform 하는 customView
 */
@property (nonatomic, readonly, strong) NSDictionary <NSString *, UIView <GFPNativeTemplateViewProtocol> *> *customTemplates;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithUseNativeTemplate:(BOOL)useNativeTemplate
                            nativeOptions:(GFPAdNativeOptions * _Nullable)nativeOptions;

- (instancetype)initWithUseNativeTemplate:(BOOL)useNativeTemplate
                          customTemplates:(NSDictionary <NSString *, UIView <GFPNativeTemplateViewProtocol> *> *)customTemplates;

- (instancetype)initWithUseNativeTemplate:(BOOL)useNativeTemplate
                            nativeOptions:(GFPAdNativeOptions * _Nullable)nativeOptions
                          customTemplates:(NSDictionary <NSString *, UIView <GFPNativeTemplateViewProtocol> *> *)customTemplates;

- (void)addTemplateWith:(NSString *)key templateView:(UIView <GFPNativeTemplateViewProtocol> *)templateView;
- (void)removeTemplateWith:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
