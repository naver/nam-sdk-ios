//
//  GFPNativeSimpleAdView.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

#import <UIKit/UIKit.h>

#import "GFPNativeBaseView.h"

#import "GFPNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface GFPNativeSimpleAdView : GFPNativeBaseView

@property (nonatomic, strong, nullable) GFPNativeSimpleAd *nativeAd;

- (void)reLayoutSpecialRich:(BOOL)isForce;
- (void)removePlaceholders;

/**
 * Notify the SDK that the hosting layout has changed and force a full re-layout pass
 * for rich ads: the media view width is recalculated from the current view bounds,
 * the rich ad layout is rebuilt for that width, the ad is restored to the default
 * layout state, and the resulting ad size is re-notified via
 * `nativeSimpleAd:didChangeRichAdSizeWith:`.
 *
 * Call this after the hosting view's layout has settled
 * (e.g. after a device rotation transition completes), since the re-layout
 * is based on the current bounds. Does nothing for non-rich ads.
 */
- (void)restoreRichAdLayout;

@end

NS_ASSUME_NONNULL_END
