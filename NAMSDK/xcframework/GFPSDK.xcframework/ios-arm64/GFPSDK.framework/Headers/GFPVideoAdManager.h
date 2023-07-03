//
//  GFPVideoAdManager.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

  


#import <Foundation/Foundation.h>
#import "GFPVideoAdManagerDelegate.h"
#import "GFPVideoAdQoeDelegate.h"
#import "GFPVideoAdPIPDelegate.h"
#import "GFPVideoAdPlacement.h"
#import "GFPS2SAdClickDelegate.h"

@class GFPAdParam;
@class GFPVideoAdParam;
@class GFPVideoAdInfo;
@class GFPVideoAdPlayerSetting;
@class GFPVideoAdRenderingSetting;
@class GFPVideoDisplayMode;

@class AVPlayer;
@class UIView;
@class UIViewController;

@protocol GFPS2SAdClickDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface GFPVideoAdManager : NSObject

@property (nonatomic, weak) id <GFPVideoAdManagerDelegate> delegate;
@property (nonatomic, weak) id <GFPVideoAdQoeDelegate> qoeDelegate;
@property (nonatomic, weak) id <GFPVideoAdPIPDelegate> pipDelegate;

/**
 * 광고 요청에 사용할 파라미터
 */
@property (readwrite, nonatomic, strong, nullable) GFPAdParam *adParam;

/**
 * 광고 요청이후 로드 완료시점까지 타임아웃 (Optional)
 */
@property (readwrite, nonatomic, assign) NSTimeInterval requestTimeoutInterval;

/**
* 광고 재생 관련 Option. (Audio, Background 관련 Play 동작)
*/
@property (readwrite, nonatomic, strong, nullable) GFPVideoAdPlayerSetting *playerSetting;

/**
 * 광고 렌터링 세팅 (Optional)
 */
@property (readwrite, nonatomic, strong, nullable) GFPVideoAdRenderingSetting *renderingSetting;

/**
 * 광고 볼륨  세팅 (Optional)
 * From 0 (muted) to 1 (loudest). Default value is 1.
*/
@property (readwrite, nonatomic, assign) float volume;

/**
 * 광고 재생 전, 재생 도중 관련
 */
@property (readwrite, nonatomic, strong, nullable) GFPVideoDisplayMode *displayMode;

/**
 * 광고 로드 후  광고 정보 (없으면 nil)
*/
@property (readonly, nonatomic, strong) GFPVideoAdInfo *adInfo;

/**
 * 구글 광고 로드를 위해서는 필수 조건 (View hierachy가 있는 ViewController.)
*/
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

/**
 * 광고 응답 객체
 */
@property (readonly, nonatomic, strong) GFPLoadResponseInfo *responseInfo;

/**
 *
 * @param adUnitID              비디오 광고 유닛 아이디
 * @param videoView             컨텐츠 플레이어가 렌더링될 UIView
 * @param adParam               광고요청에 사용할 파라미터
 * @return 비디오 광고 매니저
 */
- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                       videoView:(UIView *)videoView
                         adParam:(nullable GFPAdParam *)adParam;

/**
 *
 * @param adUnitID              비디오 광고 유닛 아이디
 * @param videoView             컨텐츠 플레이어가 렌더링될 UIView
 * @param adParam                 광고요청에 사용할 파라미터
 * @param placementType    광고 위치 (pre: 전광고, mid : 중간광고, post : 후광고)
 * @return 비디오 광고 매니저
 */
- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                       videoView:(UIView *)videoView
                   placementType:(GFPVideoPlacementType)placementType
                         adParam:(GFPAdParam *)adParam
                    videoAdParam:(GFPVideoAdParam * _Nullable)videoParam;

/**
 * 광고를 요청합니다.
 * 응답결과는 GFPVideoAdManagerDelegate 를 통해 받으실 수 있습니다.
 */
- (void)load;

/**
 * 광고를 재생합니다.
 * (광고가 성공적으로 르드된 경우에 호출해주세요.)
 */
- (void)start;

/**
 * 광고 재생을 중지합니다.
 */
- (void)pause;

/**
 * 광고 재생을 재개합니다.
 */
- (void)resume;

/**
 * 광고 매니저를 종료 시킵니다.
 * (재생중 화면 전환이 발생하거나, 어플리케이션 동작과정에서 로드된 광고매니저의 리소스를 해제할 필요가 있는 경우)
 */
- (void)destroy;

/**
 * 광고 영상 위의 Overlay를 노출합니다.
 * (광고 재생 중, 광고 영상만 노출해야 할 경우)
*/
- (void)showOverlay;


/**
 * 광고 영상 위의 Overlay를 숨김니다.
 * (광고 재생 중, 광고 영상을 숨겨야 할 경우)
*/
- (void)hideOverlay;


/**
 * 광고 Skip 버튼 클릭을 원하는 경우, action 연결.
 */
- (IBAction)skipButtonTapped:(id)sender;


/**
 * 광고 더보기 버튼 클릭을 원하는 경우, action 연결.
 */
- (IBAction)moreButtonTapped:(id)sender;


@end

NS_ASSUME_NONNULL_END
