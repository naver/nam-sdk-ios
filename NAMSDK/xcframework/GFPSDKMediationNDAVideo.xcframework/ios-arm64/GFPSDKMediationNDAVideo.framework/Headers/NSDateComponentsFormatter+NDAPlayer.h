//
//  NSDateComponentsFormatter+NDAPlayer.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDateComponentsFormatter (NDAPlayer)

+ (NSDateComponentsFormatter *)timeFormatter:(NSTimeInterval)aDuration;

@end

NS_ASSUME_NONNULL_END
