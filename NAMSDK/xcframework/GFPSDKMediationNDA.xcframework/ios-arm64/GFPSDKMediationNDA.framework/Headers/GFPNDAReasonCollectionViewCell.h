//
//  GFPNDAReasonCollectionViewCell.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>
#import "GFPNDAAdChoiceResourceUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNDAReasonCollectionViewCell : UICollectionViewCell <GFPNDAAdChoiceResourcePresentable>

- (void)updateText:(NSString *)text;

+ (NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
