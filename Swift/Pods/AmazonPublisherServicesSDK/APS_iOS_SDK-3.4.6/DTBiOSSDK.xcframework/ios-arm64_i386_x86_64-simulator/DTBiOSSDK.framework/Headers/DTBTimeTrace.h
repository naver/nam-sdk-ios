//
//  DTBTimeTrace.h
//  DTBiOSSDK
//
//  Created by Krivopaltsev, Eugene on 1/10/19.
//  Copyright © 2019 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTBTimeTracePhase : NSObject

@property (nonatomic) NSString *name;

@property (nonatomic) NSDate *date;

-(instancetype)initWithName:(NSString * _Nonnull)name;

@end

@interface DTBTimeTrace : NSObject

@property (nonatomic)NSArray *phases;

#define TIMETRACE_BID_START @"Bid requested"

#define TIMETRACE_BID_SUCCEEDED @"Bid succeeded"

#define TIMETRACE_BID_FAILED @"Bid failed"

#define TIMETRACE_AD_REQUESTED @"Request Ad"

#define TIMETRACE_CUSTOM_EVENT_ACCEPTED @"Custom event accepted"

#define TIMETRACE_CUSTOM_EVENT_IGNORED @"Custom event ignored"

#define TIMETRACE_AD_DISPLAY_FAILED @"AD display failed"

#define TIMETRACE_AD_DISPLAY_SUCCEEDED @"AD displayed"

+(DTBTimeTrace *)sharedInstance;


-(void)addPhase:(NSString *)name;

-(void)start;

-(void)stop;




@end

NS_ASSUME_NONNULL_END
