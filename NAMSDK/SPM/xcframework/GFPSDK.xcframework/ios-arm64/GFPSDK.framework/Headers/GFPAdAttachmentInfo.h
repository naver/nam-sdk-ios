//
//  GFPAdAttachmentInfo.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GFPAdAttachmentInfo : NSObject

@property (readonly, atomic, assign) BOOL isLoaded;
@property (readonly, atomic, assign) BOOL isAttached;
@property (readonly, atomic, assign) BOOL isAttachImpressioned;

- (void)updateLoadedWith:(BOOL)isLoaded;

- (void)markedAttachedOnSuperView;
- (void)markedAttachImpressioned;

- (BOOL)canSendAttachedEvnet;

@end

NS_ASSUME_NONNULL_END
