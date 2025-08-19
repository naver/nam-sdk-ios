//
//  GFPSchemeCommand.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

NS_ASSUME_NONNULL_BEGIN


extern NSString *const kSchemeGLAD;
extern NSString *const kSchemeMraid;
extern NSString *const kSchemeAbout;
extern NSString *const kSchemeGFPTag;

@interface GFPSchemeComponent : NSObject

@property (nonatomic, readonly, strong) NSString *command;
@property (nonatomic, readonly, strong) NSDictionary *component;

@property (nonatomic, readonly, assign) BOOL isResize;
@property (nonatomic, readonly, assign) BOOL isExposureChangeSetting;
@property (nonatomic, readonly, assign) BOOL isAdMetaChanged;

@property (nonatomic, readonly, assign) BOOL isHostEnable;

@property (nonatomic, readonly, assign) BOOL isLoaded;

@property (nonatomic, readonly, assign) BOOL isLoadFailed;


@property (nonatomic, readonly, assign) CGSize size;

- (instancetype)initWith:(NSURL*)aURL;

- (CGFloat)sizeWith:(NSString *)aKey;

@end


@interface GFPSchemeCommand : NSObject

@property (nonatomic, readonly, strong) NSURL *url;
@property (nonatomic, readonly, strong) NSString *scheme;

@property (nonatomic, readonly, strong) GFPSchemeComponent *component;

@property (nonatomic, readonly, assign) BOOL isGLADScheme;
@property (nonatomic, readonly, assign) BOOL isMraid;
@property (nonatomic, readonly, assign) BOOL isAbout;
@property (nonatomic, readonly, assign) BOOL isJsTag;

- (instancetype)initWith:(NSURL *)aURL;

@end


NS_ASSUME_NONNULL_END
