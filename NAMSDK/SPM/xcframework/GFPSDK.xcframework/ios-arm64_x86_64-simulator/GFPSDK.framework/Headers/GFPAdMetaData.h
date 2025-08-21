//
//  GFPEncAdMeta.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdMetaData: NSObject
/**
 (참고) 메타 정보
 광고주 정보
 광고 정보
 가격 정보
 */
@property (readwrite, nonatomic, strong, nullable) NSString *adContext;
@property (readwrite, nonatomic, assign, nullable) NSNumber *slotIndex;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype _Nullable)initWithAdContextString:(NSString *_Nullable)adContext NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
