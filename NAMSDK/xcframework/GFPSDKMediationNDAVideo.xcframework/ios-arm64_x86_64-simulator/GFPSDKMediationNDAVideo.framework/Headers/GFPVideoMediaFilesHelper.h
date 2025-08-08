//
//  GFPVideoMediaFilesHelper.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>
@import NaverAdsServices;


@class GFPNDAVastMediaFile;
@class GFPVideoAdRenderingSetting;

NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoMediaFilesHelper : NSObject

+ (GFPNDAVastMediaFile * _Nullable)selectMediaFileWithMediaFiles:(NSArray <GFPNDAVastMediaFile *> *)mediaFiles
                                                renderingSetting:(nullable GFPVideoAdRenderingSetting *)renderingSetting;


+ (GFPVastMediaFile * _Nullable)selectNASMediaFileWithMediaFiles:(GFPVastMediaFiles *)mediaFiles
                                                renderingSetting:(nullable GFPVideoAdRenderingSetting *)renderingSetting;


@end

NS_ASSUME_NONNULL_END
