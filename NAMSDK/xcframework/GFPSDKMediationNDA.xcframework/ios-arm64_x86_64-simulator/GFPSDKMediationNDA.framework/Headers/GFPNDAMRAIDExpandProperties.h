//
//  GFPNDAMRAIDExpandProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import <UIKit/UIKit.h>

@interface GFPNDAMRAIDExpandProperties : NSObject

+ (GFPNDAMRAIDExpandProperties *)expandPropertiesFromQueryProperties:(NSDictionary *)mraidDict;

- (instancetype)initWithWidth:(CGFloat)width
                       height:(CGFloat)height
                          URL:(NSURL *)URL
               useCustomClose:(BOOL)useCustomClose;

@property (nonatomic, readonly, assign) CGFloat width;
@property (nonatomic, readonly, assign) CGFloat height;
@property (nonatomic, readonly, strong) NSURL *URL;

//custom indicator resource 사용 여부 
@property (nonatomic, readonly, assign) BOOL useCustomClose;

@property (nonatomic, readonly, assign) BOOL isInvalid;

@property (nonatomic, readonly, assign) CGSize validSize;

@end
