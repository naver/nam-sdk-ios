//
//  GFPContext.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//
  


#import <Foundation/Foundation.h>
#import "GFPS2SAdClickDelegate.h"

NS_ASSUME_NONNULL_BEGIN
@protocol GFPS2SAdClickDelegate;

@interface GFPContext : NSObject

@property (nonatomic, weak) id <GFPS2SAdClickDelegate> clickDelegate;

@end

NS_ASSUME_NONNULL_END
