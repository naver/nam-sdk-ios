//
//  GFPVastMacroProvider.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

#import <Foundation/Foundation.h>
@import NaverAdsServices;


NS_ASSUME_NONNULL_BEGIN

extern NSString *const kGFPAdBreakPositionPreRoll;
extern NSString *const kGFPAdBreakPositionMidRoll;
extern NSString *const kGFPAdBreakPositionPostRoll;
extern NSString *const kGFPAdBreakPositionStandAlone;
extern NSString *const kGFPAdBreakPositionUnKnwon;

@protocol GFPVastMacroProviderHelperDelegate <NSObject>
- (NSTimeInterval)getCurrentTime;
@end
@interface GFPVastMacroProvider : NSObject <NASVastMacroDataSource>

@property (nonatomic, weak, nullable) id<GFPVastMacroProviderHelperDelegate> delegate;
@property (nonatomic, weak, nullable) GFPVastAd *nasVastAd;
@property (nonatomic, weak, nullable) GFPVastMediaFile *nasMediaFile;
@property (nonatomic, strong, nullable) NSString *adBreakPosition;

/*
1: for pre-roll
2: for mid-roll
3: for post-roll
4: for standalone
0: for none of the above/other
*/
- (instancetype)initWith:(NSString *)adBreakPosition;

@end

NS_ASSUME_NONNULL_END
