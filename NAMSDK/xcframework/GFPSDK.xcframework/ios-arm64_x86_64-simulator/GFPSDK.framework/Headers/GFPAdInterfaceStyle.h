//
//  GFPAdInterfaceStyle.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

extern NSString *const kGFPAdInterfaceStyleChanged;

typedef NS_OPTIONS(NSInteger, GFPAdInterfaceStyle) {
    GFPAdInterfaceStyleSystem = 1 << 0,
    GFPAdInterfaceStyleLight = 1 << 1,
    GFPAdInterfaceStyleDark = 1 << 2,
};
