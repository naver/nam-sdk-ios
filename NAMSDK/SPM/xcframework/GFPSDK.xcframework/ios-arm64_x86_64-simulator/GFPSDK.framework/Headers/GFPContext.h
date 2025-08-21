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

@property (nonatomic, strong) NSUUID *logId;
@property (nullable, nonatomic, weak) id <GFPS2SAdClickDelegate> clickDelegate;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithLogId:(NSUUID *)logId;
- (instancetype)initWithClickDelegate:(nullable id <GFPS2SAdClickDelegate>)clickDelegate logId:(NSUUID *)logId;

@end

NS_ASSUME_NONNULL_END
