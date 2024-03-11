//
//  GFPNDAVideoAdEvent.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GFPNDAVideoAdEventType){
    GFPNDAVideoAdEventSTARTED = 1,
    GFPNDAVideoAdEventCOMPLETED,
    GFPNDAVideoAdEventSKIPED,
    GFPNDAVideoAdEventCLICKED,
    GFPNDAVideoAdEventPAUSED,
    GFPNDAVideoAdEventRESUMED,
    GFPNDAVideoAdEventRESET, //for outstream
    GFPNDAVideoAdEventCLOSED, //for pip
    GFPNDAVideoAdEventRETURNED, // for pip
    GFPNDAVideoAdEventAdPrivacyCLICKED
};

@interface GFPNDAVideoAdEvent : NSObject

@property(readonly, nonatomic, assign) GFPNDAVideoAdEventType type;

- (instancetype)initWithType:(GFPNDAVideoAdEventType)type;

@end

NS_ASSUME_NONNULL_END
