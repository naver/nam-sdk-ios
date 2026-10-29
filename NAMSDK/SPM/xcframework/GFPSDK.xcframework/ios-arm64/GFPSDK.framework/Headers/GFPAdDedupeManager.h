//
//  GFPAdDedupeManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPAdLoader;

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdDedupeManager : NSObject

@property (readonly, nonatomic, assign) NSInteger numAdsDeduped;

/**
 * 청크 자동 교체 여부 (기본값 YES)
 *
 * YES: 청크에 numAdsDeduped 만큼 광고 요청이 차면 다음 요청부터 자동으로 새 청크를 생성한다 (기존 동작).
 * NO : numAdsDeduped 가 차도 청크를 교체하지 않고, resetChunk 를 호출할 때만 새 청크를 생성한다.
 *      이 경우 numAdsDeduped 는 청크 교체 뒤에도 이어서 중복 제어할 이전 응답 이력 크기(numAdsDeduped * 2 개 응답분)에만 쓰인다.
 */
@property (nonatomic, assign, getter=isChunkAutoResetEnabled) BOOL chunkAutoResetEnabled;

- (instancetype)initWithNumAdsDeduped:(NSInteger)numAdsDeduped;

- (void)loadAdWith:(GFPAdLoader *)adLoader;

/**
 * 현재 중복 제어 청크를 강제로 끝내고 새 청크를 생성
 *
 * numAdsDeduped 만큼 광고 요청이 차지 않았더라도 이후 loadAdWith: 요청은 새 청크에서 중복 제어된다.
 * - 이전 청크에서 이미 요청·대기 중인 로더는 그대로 이전 청크에서 처리된다.
 * - 이전 청크들이 누적한 중복 키·광고주 도메인 이력(numAdsDeduped * 2 개 응답분)은 유지되어 새 청크에도 적용된다.
 * - 아직 광고 요청이 한 건도 없는 청크는 이미 초기 상태이므로 아무 동작도 하지 않는다.
 */
- (void)resetChunk;

@end

NS_ASSUME_NONNULL_END
