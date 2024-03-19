//
//  GFPNativeAdInfoProtocol.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import "Swift-Enum.h"


NS_ASSUME_NONNULL_BEGIN

@class GFPNativeLinkInfo;
@class GFPNativeExtensionInfo;
@class GFPNativeMediaExtensionInfo;
@class GFPNativeStyleInfo;
@class GFPLabelOption;
@class GFPAdStyleOption;

@protocol GFPNativeAdInfoLinkPresentable <NSObject>

@property (readonly, nonatomic, assign) GFPNativeAdDataType dataType;

@property (readonly, nonatomic, strong) GFPNativeLinkInfo *link;
@property (readonly, nonatomic, assign) BOOL unclickable;

@end


@protocol GFPNativeAdInfoSourcePresentable <NSObject>

@property (readonly, nonatomic, strong) NSURL *source;
@property (readonly, nonatomic, strong, nullable) NSString *body;
@property (readonly, nonatomic, strong, nullable) NSURL *tsource;

@end


@protocol GFPNativeAdInfoExtensionPresentable <NSObject>

@property (readonly, nonatomic, strong, nullable) GFPNativeMediaExtensionInfo *extensionInfo;

@end


@protocol GFPNativeAdInfoLabelPresentable <NSObject>

@property (nonatomic, readonly, strong) NSString *text;
@property (nonatomic, readonly, assign) BOOL isValid;

@end


@protocol GFPNativeAdInfoExtStylePresentable <NSObject>

@property (readonly, nonatomic, strong, nullable) GFPNativeExtensionInfo *extensionInfo;

@end


@protocol GFPNativeAdLabelOptionPresentable <GFPNativeAdInfoExtStylePresentable>

- (GFPLabelOption *)labelOptionWith:(BOOL)isDarkMode;

@end


@protocol GFPNativeAdStyleOptionPresentable <GFPNativeAdInfoExtStylePresentable>

- (GFPAdStyleOption *)adStyleOptionWith:(BOOL)isDarkMode;

@end


@protocol GFPNativeAdInfoSource <NSObject>

- (void)updateSourceDownload;

@end


NS_ASSUME_NONNULL_END
