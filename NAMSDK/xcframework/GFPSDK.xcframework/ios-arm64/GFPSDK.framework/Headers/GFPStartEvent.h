//
//  GFPStartEvent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPEvent.h"

@class GFPErrorEventInfo;


@interface GFPStartEvent : GFPEvent

@property (nonatomic, strong) GFPErrorEventInfo *errorEventInfo;

+ (GFPStartEvent *)errorEventInfoWithErrorInfo:(GFPErrorEventInfo *)errorEventInfo;

@end
