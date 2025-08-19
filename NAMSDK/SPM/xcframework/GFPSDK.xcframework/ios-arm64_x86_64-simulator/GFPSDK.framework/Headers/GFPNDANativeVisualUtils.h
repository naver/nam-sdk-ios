//
//  GFPNDANativeVisualUtils.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
#import "GFPNDAMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDANativeVisualUtils : NSObject

+ (BOOL)supportCarouselViewWith:(GFPNDAMediaViewType)viewType;

+ (GFPNDAMediaViewType)convertViewTypeWithVisualKey:(NSString *)visaulKey;

@end

NS_ASSUME_NONNULL_END
