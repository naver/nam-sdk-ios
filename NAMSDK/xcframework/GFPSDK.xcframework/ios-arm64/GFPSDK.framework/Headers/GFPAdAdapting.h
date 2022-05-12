//
//  GFPAdAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class GFPError;
@class GFPAdAdaptor;
@class GFPLoadEvent;
@class GFPEventExtraInfo;

NS_ASSUME_NONNULL_BEGIN

typedef void (^GFPAdAdaptorLoadCompletionHandler)(GFPError *_Nullable error, GFPLoadEvent *loadEvent, GFPEventExtraInfo *_Nullable loadInfo);

@protocol GFPAdAdapting <NSObject>

@required
- (void)loadAdWithCompletionHandler:(GFPAdAdaptorLoadCompletionHandler)completionHandler;



@end

NS_ASSUME_NONNULL_END
