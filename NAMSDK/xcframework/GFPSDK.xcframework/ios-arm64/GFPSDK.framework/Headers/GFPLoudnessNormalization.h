//
//  GFPLoudnessNormalization.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPCreativeExtension.h"

@import NaverAdsServices;

@class DDXMLElement;
@class GFPProperties;
@class GFPError;

NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS(NSInteger, GFPLoudnessMode) {
    GFPLoudnessGaudio = 0,          // Loudness 분석 data가 있으면 data를 이용하여 재생, 없으면 client mode 로 재생
    GFPLoudnessTransparent = 1,     // GAUDIO SDK 원음 재생 모드.Volume Control
};


// MARK: - GFPLoudnessNormalization
@interface GFPLoudnessNormalization : GFPCreativeExtension


@property (readonly, nonatomic, assign) BOOL enabled;
@property (readonly, nonatomic, strong) NSString *version;
@property (readonly, nonatomic, strong) NSString *contentType;
@property (readonly, nonatomic, strong) NSString *contentEncoding;
@property (readonly, nonatomic, strong) NSString *dataString;
@property (readonly, nonatomic, strong, nullable) GFPProperties *properties;

@property (readonly, nonatomic, strong) NSDictionary *referDict;

- (instancetype)initWithDomElement:(DDXMLElement *)aElement error:(GFPError *_Nullable *_Nullable)aError;
- (instancetype)initWithCreativeExtension:(GFPVastExtension *)extension error:(GFPError *_Nullable *_Nullable)aError;


@end


// MARK: - GFPProperties
@interface GFPProperties : NSObject

@property (readonly, nonatomic, assign) float targetLoudness;
@property (readonly, nonatomic, assign) GFPLoudnessMode mode;

- (instancetype)initWithDict:(NSDictionary *)aDict;

@end

NS_ASSUME_NONNULL_END
