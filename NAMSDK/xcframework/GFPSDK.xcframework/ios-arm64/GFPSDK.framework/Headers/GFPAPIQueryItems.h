//
//  GFPAPIQueryItems.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class GFPAdParam;
@class GFPVideoAdParam;
@class GFPExtraRequestParam;
@class GFPAdScheduleParam;
@class GFPAdInitReqInfo;
@class GFPSKAdNetworkData;
@class GFPLogReqInfo;
@class GFPCachedAdParam;

static NSString * const kGFPAAPParamKeyAmazon = @"amznhb"; // old: "ha"
static NSString * const kGFPAAPParamKeyPrebid = @"prebid"; // old: "hb"
static NSString * const kGFPAAPParamKeyFAN = @"fb";
static NSString * const kGFPAAPParamKeyVungle = @"vungle";
static NSString * const kGFPAAPParamKeyKeyChartBoost = @"cb";
static NSString * const kGFPAAPParamKeyBidMachine = @"bm";
static NSString * const kGFPAAPParamKeyPangle = @"pangle";
static NSString * const kGFPAAPParamKeyDigitalTurbine = @"dt";
static NSString * const kGFPAAPParamKeyMoloco = @"moloco";
static NSString * const kGFPAAPParamKeyMagnite = @"magnite";


@interface GFPAPIQueryItems : NSObject

@property (nonatomic, readonly, strong) NSArray <NSURLQueryItem *> *items;
@property (nonatomic, readonly, strong, nullable) NSData *data;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWith:(NSString *)aUnitID
                 adParam:(GFPAdParam * _Nullable)aAdParam
              videoParam:(GFPVideoAdParam *_Nullable)aVideoAdParam
              extraParam:(GFPExtraRequestParam *_Nullable)aExtraParam;

- (instancetype)initWith:(NSString *)aScheduleID scheduleParam:(GFPAdScheduleParam *)aScheduleParam;

- (instancetype)initWith:(GFPAdInitReqInfo *)aInitInfo;

- (instancetype)initWithData:(NSData *)data;

- (instancetype)initWithLog:(GFPLogReqInfo *)aLogInfo;

- (instancetype)initWithRewardVerification:(NSString *)verificationInfo;

/**
 * dw/dh 용 화면 스냅샷 갱신. 광고 요청 진입 시점에 호출한다. 메인 스레드면 활성 씬 화면, 아니면 UIScreen.main 을 저장한다.
 * 쿼리 조립(addDeviceInfo)은 백그라운드 큐에서 실행되므로 GFPDeviceUtils.keyWindow(UIApplication.connectedScenes, 메인 전용)를
 * 직접 읽지 않고 이 스냅샷만 읽는다.
 */
+ (void)updateScreenSnapshot;


@end


NS_ASSUME_NONNULL_END
