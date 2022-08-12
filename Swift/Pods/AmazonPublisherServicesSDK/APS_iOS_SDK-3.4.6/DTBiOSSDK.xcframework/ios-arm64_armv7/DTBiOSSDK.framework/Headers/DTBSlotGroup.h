//
//  DTBSlotGroup.h
//  DTBiOSSDK
//
//  Created by Krivopaltsev, Eugene on 6/17/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DTBAdSize.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum
{
    SLOT_320_50 = 0,
    SLOT_300_250 = 1,
    SLOT_728_90 = 2,
    SLOT_SMART = 3
} DTBSlotType;

NSString* NSStringFromSlotType(DTBSlotType slotType);
DTBSlotType slotTypeFromCGSize(CGSize slotCGSize);

@interface DTBSlotGroup : NSObject

- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic) NSString * _Nonnull name;

-(instancetype)initWithName:(NSString * _Nonnull) name;

-(void)addSize:(DTBAdSize * _Nonnull) size;

-(DTBAdSize * _Nullable) sizeByWidth:(NSInteger)width height:(NSInteger)height;

-(DTBAdSize * _Nullable) sizeByWidth:(NSInteger)width height:(NSInteger)height type:(ADType) type;

-(DTBAdSize * _Nullable) sizeByUUID:(NSString * _Nonnull)slotUUID;

-(DTBAdSize * _Nullable) sizeBySlotType:(DTBSlotType) type;

@end

NS_ASSUME_NONNULL_END
