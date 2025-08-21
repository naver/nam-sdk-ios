//
//  GFPNDAMRAIDResizeProperties.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
#import "GFPNDAMRAIDUtil.h"

@interface GFPNDAMRAIDResizeProperties : NSObject

+ (GFPNDAMRAIDResizeProperties *)resizePropertiesFromQueryProperties:(NSDictionary *)mraidDict;

- (instancetype)initWithWidth:(CGFloat)width
                       height:(CGFloat)height
                      offsetX:(CGFloat)offsetX
                      offsetY:(CGFloat)offsetY
          customClosePosition:(GFPNDAMRAIDCustomClosePosition)customClosePosition
               allowOffscreen:(BOOL)allowOffscreen;

@property (nonatomic, readonly, assign) CGFloat width;
@property (nonatomic, readonly, assign) CGFloat height;
@property (nonatomic, readonly, assign) CGFloat offsetX;
@property (nonatomic, readonly, assign) CGFloat offsetY;
@property (nonatomic, readonly, assign) GFPNDAMRAIDCustomClosePosition customClosePosition;
@property (nonatomic, readonly, assign) BOOL allowOffscreen;

@end
