//
//  GFPVideoAdapting.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
#import "GFPAdAdapting.h"

@protocol GFPVideoAdaptorDelegate;

@class GFPVideoAdQoeInfo;
@class GFPVideoAdInfo;
@class GFPVideoDisplayMode;
@class GFPVideoAdPlayerSetting;

@protocol GFPVideoAdapting <GFPAdAdapting>

@property (nonatomic, weak) id <GFPVideoAdaptorDelegate> _Nullable delegate;

@property (readonly, nonatomic, strong) GFPVideoAdInfo *_Nullable adInfo;
@property (readonly, nonatomic, strong) GFPVideoAdQoeInfo * _Nullable qoeInfo;

@property (nonatomic, strong, nullable) GFPVideoAdPlayerSetting *playerSetting;
@property (nonatomic, assign) float volume;

@property (nonatomic, strong, nullable) GFPVideoDisplayMode *displayMode;

- (void)start;

- (void)pause;

- (void)resume;

- (void)contentComplete;

- (void)destroy;

@optional

- (void)showOverlay;

- (void)hideOverlay;

- (void)tapControlPIPUI;

- (IBAction)skipButtonTapped:(id _Nullable)sender;
- (IBAction)moreButtonTapped:(id _Nullable)sender;

@end
