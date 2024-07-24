//
//  GFPNDAVastControlInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPStaticResource.h"
#import "GFPLanguageType.h"

@class GFPAdSkipInfo;

NS_ASSUME_NONNULL_BEGIN


@interface Icon (GFPNDA)

- (NSString *)contentDescription;

@end

typedef NS_OPTIONS(NSInteger, GFPNDAVastIconType) {
    GFPNDAVastIconProvider = 1 << 0,
    GFPNDAVastIconPostAdAlert = 1 << 1,
    GFPNDAVastIconSearchKeyword = 1 << 2,
};

@interface GFPNDAVastControlInfo : NSObject

@property (readonly, nonatomic) BOOL isSkippable;
@property (readonly, nonatomic) NSTimeInterval skipOffset;
@property (readonly, nonatomic) NSTimeInterval duration;
@property (readonly, nonatomic, strong) NSArray <Icon *> *iconList;

- (instancetype)initWithIconList:(NSArray<Icon *> *)aIconList skipOffset:(NSString * _Nullable)aSkipOffset duration:(NSTimeInterval)aDuration skipInfo:(GFPAdSkipInfo * _Nullable)aSkipInfo;

- (BOOL)canShowWith:(GFPNDAVastIconType)iconType currentTime:(NSTimeInterval)aCurrentTime;

- (Icon *)providerIcon;
- (Icon *)postAdAlertIcon;
- (Icon *)adChoiceIcon;
- (NSArray <Icon *> *)keywordIcons;

@end

NS_ASSUME_NONNULL_END
