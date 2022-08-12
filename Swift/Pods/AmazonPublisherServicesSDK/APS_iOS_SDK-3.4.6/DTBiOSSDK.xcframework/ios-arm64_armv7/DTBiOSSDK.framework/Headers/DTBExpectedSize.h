//
//  DTBExpectedSize.h
//  DTBiOSSDK
//
//  Created by Krivopaltsev, Eugene on 7/19/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DTBExpectedSize <NSObject>

@property(nonatomic)NSNumber * _Nullable expectedWidth;
@property(nonatomic)NSNumber * _Nullable expectedHeight;

@end

NS_ASSUME_NONNULL_END
