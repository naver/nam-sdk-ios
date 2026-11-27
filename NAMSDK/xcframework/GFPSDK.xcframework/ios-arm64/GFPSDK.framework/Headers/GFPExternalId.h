//
//  GFPExternalId.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * External Id
 * - 하나의 source 에 여러 개의 id 를 설정할 경우 같은 source 로 여러 개를 생성한다.
 *   ex) Google PAIR ID 복수 설정
 */
@interface GFPExternalId : NSObject

/**
 * 식별자 제공처 ex) liveramp.com, google.com
 */
@property (nonatomic, copy, readonly) NSString *source;

/**
 * 식별자 값 ex) LiveRamp Envelope, Google PAIR ID
 */
@property (nonatomic, copy, readonly) NSString *identifier NS_SWIFT_NAME(id);

- (instancetype)initWithSource:(NSString *)source
                    identifier:(NSString *)identifier NS_SWIFT_NAME(init(source:id:)) NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
