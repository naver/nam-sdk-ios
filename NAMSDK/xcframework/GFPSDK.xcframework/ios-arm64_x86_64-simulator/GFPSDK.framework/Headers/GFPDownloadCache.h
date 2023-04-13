//
//  GFPDownloadCache.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <Foundation/Foundation.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ImageDownloadCompletionHandler)(UIImage *_Nullable image, NSURL *_Nullable url, NSError *_Nullable error);
typedef void (^DownloadCompletionHandler)(NSData *_Nullable data, NSURL *_Nullable url, NSError *_Nullable error);
typedef void (^ImageCompletionHandler)(UIImage *_Nullable image, NSError *_Nullable error);
typedef void (^ImageFullCompletionHandler)(UIImage *_Nullable image, NSURL *_Nullable url, NSError *_Nullable error);

@interface GFPDownloadCache : NSObject

@property (class, readonly, nonatomic) GFPDownloadCache *sharedInstance;

- (UIImage *)imageWithURL:(NSURL *)aURL;
- (void)updateDataWithURL:(NSURL *)aURL;

- (void)dataWithURL:(NSURL * _Nullable)aURL completion:(DownloadCompletionHandler)aComletion;
- (void)imageWithURL:(NSURL * _Nullable)aURL completion:(ImageCompletionHandler)aCompletion;
- (void)imageWithURL:(NSURL * _Nullable)aURL fullCompletion:(ImageFullCompletionHandler)aCompletion;
- (void)imageWithURL:(NSURL * _Nullable)aURL timeoutInterval:(NSTimeInterval)timeoutInterval fullCompletion:(ImageFullCompletionHandler)aCompletion;

- (void)clearCache;

@end

NS_ASSUME_NONNULL_END
