//
//  GFPVideoAdPlacement.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


extern NSString *const kGFPVideoAdPlacementTypePreRoll;
extern NSString *const kGFPVideoAdPlacementTypeMidRoll;
extern NSString *const kGFPVideoAdPlacementTypePostRoll;
extern NSString *const kGFPVideoAdPlacementTypeUnknown;


typedef NS_OPTIONS(NSInteger, GFPVideoPlacementType) {
    GFPVideoPlacementTypeUnknown = 1 << 0, // GFPAdvertiseParams(=adURL) 사용 시 설정.
    GFPVideoPlacementTypePre = 1 << 1,
    GFPVideoPlacementTypeMid = 1 << 2,
    GFPVideoPlacementTypePost = 1 << 3,
};


@interface GFPVideoAdPlacement : NSObject

+ (NSString *)placementTypeWithTimeOffset:(NSTimeInterval)timeOffset;
+ (NSString *)placementTypeWith:(GFPVideoPlacementType)aType;
+ (GFPVideoPlacementType)placementTypeWithDict:(NSDictionary *)aDict;

@end

NS_ASSUME_NONNULL_END
