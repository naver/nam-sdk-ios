//
//  GFPProviding.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdAdapting.h"
#import "GFPProvider.h"

@class GFPAdAdaptor;
@class GFPAdAdaptorParam;
@class GFPExtraRequestParam;
@class GFPAdInitProviderInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol GFPProviding <NSObject>


@optional

@property (readonly, nonatomic, strong, nullable) GFPExtraRequestParam *extraRequestParam;

- (void)initializeSDKWith:(GFPAdInitProviderInfo *)providerInfo;
- (BOOL)isSDKinitialize;

- (GFPExtraRequestParam * _Nullable)extraRequestParamWith:(NSString * _Nullable)adUnitId;

@required

@property (nonatomic, assign) BOOL isBlacklisted;

- (NSString *)providerType;

- (NSArray <GFPProviderRenderType> *)providerRenderTypes;

/**
 * 초기화에 실패하면 nil 리턴
 * @param param 어댑터 파라미터
 * @return 광고 어댑터
 */
- (nullable GFPAdAdaptor <GFPAdAdapting> *)createAdAdaptorWithParam:(GFPAdAdaptorParam *)param
                                                              error:(GFPError *_Nullable *_Nullable)error;


@end

NS_ASSUME_NONNULL_END
