## 배너 광고
배너 광고는 앱에 레이아웃 내에 표시되는 직사각형 이미지 형태의 광고로서 WebView 로 구현된 광고형태입니다.

![네이버 배너 광고](./images/banner_sample.png)



## NAMSDK Banner Tutorial

### GFPSDK Import
GFPSDK 모듈을 import 합니다.

<details open><summary>Example-swift</summary>   
<p>

```swift
import GFPSDK
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
@import GFPSDK;
```
</p>
</details>

### 배너 광고 제공자 초기화
연동할 배너광고 제공자의 Pod이 프로젝트에 추가된 상태에서 GFPAdManager를 통해 초기화 합니다. (앱이 구동되는 시점에 한번만 수행)

- GFPBannerProviderOptionDFP : 구글 DFP 배너 광고
- GFPBannerProviderOptionNDA : 네이버 디스플레이 배너 광고
- GFPBannerProviderOptionInMobi : 인모비 배너 광고
- GFPBannerProviderOptionFAN : 페이스북 배너 광고


<details open><summary>Example-swift</summary>   
<p>

```swift
// DFP, NDA, Inmobi, Facebook 배너 광고를 연동하려는 경우 cocoapods 의존성 추가.
GFPAdManager.setup(withPublisherCd: "publisherCd") { (error : GFPError?) in
    print("Setup Eror: \(String(describing: error?.description))")
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
// DFP, NDA, Inmobi, Facebook 배너 광고를 연동하려는 경우 cocoapods 의존성 추가.
[GFPAdManager setupWithPublisherCd:@"publisherCd" completionHandler:^(GFPError * _Nullable error) {
    NSLog(@"Setup ERROR: %@", error);
}];
```
</p>
</details>

### 뷰 컨트롤러 작성
뷰 컨트롤러(MyViewController)를 만들고, 헤더파일(MyViewController.h)에 아래 작업을 수행합니다.

1. 뷰 컨트롤러에 GFPAdLoader *adLoader 프로퍼티를 선언합니다.
2. 뷰 컨트롤러에 GFPAdLoaderDelegate 프로토콜을 구현합니다.
3. 뷰 컨트롤러에 GFPBannerView *bannerView 프로퍼티를 선언합니다.
4. 뷰 컨트롤러에 GFPBannerViewDelegate 프로토콜을 구현합니다.

> GFPAdLoaderDelegate는 배너 (및 네이티브) 광고 로드 관련 이벤트를, GFPBannerViewDelegate 로드된 배너 객체의 노출, 클릭, 렌더링 에러등의 이벤트를 전달합니다.



<details open><summary>Example-swift</summary>   
<p>

```swift
// MyViewController.h
import GFPSDK

class MyViewController : UIViewController, GFPAdLoaderDelegate, GFPBannerViewDelegate {
    private var adLoader : GFPAdLoader?
    private var bannerView : GFPBannerView?
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
// MyViewController.h

@import GFPSDK;

@interface MyViewController : UIViewController <GFPAdLoaderDelegate, GFPBannerViewDelegate>

@property (nonatomic) GFPAdLoader *adLoader;
@property (nonatomic) GFPBannerView *bannerView;

@end
```
</p>
</details>


### GFPAdLoader 생성 및 광고 요청

 MyViewController.m의 viewDidLoad 메소드에서 **GFPAdLoader**의 인스턴스를 생성하고, **광고를 요청**합니다.   

- GFPAdLoader 인스턴스를 생성할 때, 발급받으신 **광고유닛 ID**와 함께, **GFPAdParam** 에서 사용자 정보를 세팅해주세요.  GFPAdParam은 광고 효과를 높이기 위한 타게팅에 사용됩니다.



<details open><summary>Example-swift</summary>   
<p>

```swift
override func viewDidLoad() {
    super.viewDidLoad()
        
    let adParam = GFPAdParam()
    adParam.yearOfBirth = 1990
    adParam.gender = .male
    ...
        
    self.adLoader = GFPAdLoader(unitID: "UnitId", rootViewController: self, adParam: adParam)
        
    let bannerOption = GFPAdBannerOptions()
    bannerOption.layoutType = .fluidWidth
    self.adLoader?.setBannerDelegate(self, bannerOptions: bannerOption)

    self.adLoader?.delegate = self
    self.adLoader?.loadAd()
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    GFPAdParam *adParam = [[GFPAdParam alloc] init];
    adParam.yearOfBirth = 1990;
    adParam.gender = GFPAdParamGenderTypeMale;
    ...
    
    self.adLoader = [[GFPAdLoader alloc] initWithUnitID:@"UnitId"
                                             rootViewController:self
                                                        adParam:adParam];
        
    GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
    bannerOptions.layoutType = GFPBannerViewLayoutTypeFluidWidth;
    [self.adLoader setBannerDelegate:self bannerOptions:bannerOptions];
    
    // 광고 요청
    self.adLoader.delegate = self;
    [self.adLoader loadAd];
}
```
</p>
</details>


> 배너 광고 요청 성공 시 GFPAdLoaderDelegate의 **adLoader:didReceiveBannerAd:** 메소드가 호출됩니다. GFPBannerView는 일반적인 뷰 객체(UIView)이므로, 뷰 계층구조에 포함될 수 있습니다.

### 추가 설정 가능 요소들

#### 광고 렌더링 타입 (기본값 GFPDisplayAgentTypeInApp)
광고 클릭 시, Safari로 이동, In-App 이동(Mopub 지원을 위함), Scheme을 통한 이동을 지원하는 설정입니다.    
광고 Banner, Native, Video 옵션 설정 후 세팅해 주시면 됩니다.

Scheme Type 설정 후 아래 AppScheme 해당하는 String 값을 설정해 주시면 됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
// Safari로 이동 옵션.
let displayAgent = GFPRenderDisplayAgent(type: .displayAgentTypeNativeSafari)
GFPAdManager.adConfiguration().displayAgent = displayAgent

// 별도의 App scheme 설정 옵션.
let displayAgent = GFPRenderDisplayAgent(type: .displayAgentTypeScheme, scheme: "AppScheme")
GFPAdManager.adConfiguration().displayAgent = displayAgent
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
// Safari로 이동 옵션.
GFPRenderDisplayAgent *displayAgent = [[GFPRenderDisplayAgent alloc] initWithType: GFPDisplayAgentTypeNativeSafari];
[GFPAdManager adConfiguration].displayAgent = displayAgent;

// 별도의 App scheme 설정 옵션.
GFPRenderDisplayAgent *displayAgent = [[GFPRenderDisplayAgent alloc] initWithType: GFPDisplayAgentTypeScheme scheme: @"AppScheme"];
[GFPAdManager adConfiguration].displayAgent = displayAgent;
```
</p>
</details>

#### 광고 요청 타임아웃 (기본값 60초)
광고요청 이후 지정한 시간(초)경과 까지 광고 응답을 얻지 못하면 기존 요청이 무효화되며, GFPAdLoaderDelegate의 `adLoader:didFailWithError:responseInfo:` 메소드가 호출됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
self.adLoader?.requestTimeoutInterval = ...
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
self.adLoader.requestTimeoutInterval = ...
```
</p>
</details>

#### 네이티브 광고 동시 로드
배너 광고를 로드할때, 배너 또는 네이티브 광고 중 하나를 응답받을 수 있도록 설정할 수 있습니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let nativeOption = GFPAdNativeOptions()
nativeOption.renderingSetting = ... // 로드될 네이티브 일반형 광고 렌더링 설정
self.adLoader?.setNativeDelegate(self, nativeOptions: nativeOption)

let nativeSimpleOption = GFPAdNativeSimpleOptions()
nativeSimpleOption.simpleAdRenderingSetting = ... // 로드될 네이티브 이미지형 광고 렌더링 설정
self.adLoader?.setNativeSimpleDelegate(self, nativeSimpleOptions: nativeSimpleOption)

self.adLoader?.delegate = self
self.adLoader?.loadAd()
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdNativeOptions *nativeOptions = [[GFPAdNativeOptions alloc] init];
nativeOptions.renderingSetting = ...; // 로드될 네이티브 일반형 광고 렌더링 설정
[self.adLoader setNativeDelegate:self nativeOptions:nativeOptions];

GFPAdNativeSimpleOptions *nativeSimpleOptions =  [[GFPAdNativeSimpleOptions alloc] init];
nativeSimpleOptions.simpleAdRenderingSetting = ...; // 로드될 네이티브 이미지형 광고 렌더링 설정
[self.adLoader setNativeSimpleDelegate:self nativeSimpleOptions:nativeSimpleOptions];

self.adLoader.delegate = self;
[self.adLoader loadAd];
```
</p>
</details>

> 네이티브 일반형 광고가 로드된 경우, GFPAdLoaderDelegate의 `adLoader:didReceiveNativeAd:` 메서드가 호출됩니다.
> 네이티브 이미지형 광고가 로드된 경우, GFPAdLoaderDelegate의 `adLoader:didReceiveNativeSimpleAd:` 메서드가 호출됩니다.  

#### 배너 레이아웃 타입 설정

레이아웃을 설정하지 않은 경우 기본 값은 고정형(GFPBannerViewLayoutTypeFixed) 입니다.

> - GFPBannerView.adSize 를 통해 광고 소재의 사이즈 정보를 얻으실 수 있습니다.
> - 고정형을 제외한 레이아웃 타입(=확장형)을 설정할 경우, **가로 확장형 레이아웃 설정을 권장**합니다.

##### 고정형 레이아웃 설정 (Fixed)
- 서비스에서 설정한 광고 컨테이너 크기에 관계 없이 광고 영역의 크기가 고정된 형태입니다.

<details open><summary>Example-swift</summary>   
<p>

```swift
let bannerOption = GFPAdBannerOptions()
bannerOption.layoutType = GFPBannerViewLayoutType(rawValue: 0)
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
bannerOptions.layoutType = GFPBannerViewLayoutTypeFixed;
```
</p>
</details>

##### 가로 확장형 레이아웃 설정 (FluidWidth)

- 배너광고의 가로 폭을 직접 설정할 수 있습니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let bannerOption = GFPAdBannerOptions()
bannerOption.layoutType = .fluidWidth
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
bannerOptions.layoutType = GFPBannerViewLayoutTypeFluidWidth;
```
</p>
</details>

- 가로 확장형으로 레이아웃 타입을 설정하여 광고를 요청하고, 광고 요청 성공 시 응답으로 받은 GFPBannerView의 가로 크기를 원하는 크기로 조절합니다.

<details open><summary>Example-swift</summary>   
<p>

```swift
self.bannerView?.translatesAutoresizingMaskIntoConstraints = false
self.bannerView?.widthAnchor.constraint(equalToConstant: SUPERVIEW_SIZE.width).isActive = true
```
```swift
/*
원하는 가로 크기만큼 bannerView frame 세팅.
*/
let frame = CGRect(x: /*원하는 X 좌표*/, y: /*원하는 Y 좌표*/, width: /*원하는 가로 크기*/, height: /*원하는 세로 크기*/)
self.bannerView?.frame = frame
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
self.bannerView.translatesAutoresizingMaskIntoConstraints = NO;
[self.bannerView.widthAnchor constraintEqualToConstant:SUPERVIEW_SIZE.width].active = YES;
```
```objective-c
/*
원하는 가로 크기만큼 bannerView frame 세팅.
*/
CGRect frame = CGRectMake(/*원하는 X 좌표*/, /*원하는 Y 좌표*/, /*원하는 가로 크기*/, /*원하는 세로 크기*/);
[self.bannerView setFrame: frame];
```
</p>
</details>

- 가로 확장이 지원되는 광고가 로드된 경우 지정하신 GFPBannerView의 가로 크기에 맞게 꽉 채워지도록 광고가 그려지고, 고정형 광고가 로드된 경우 가로 양쪽에 남는 크기는 여백으로(가운데 정렬됨) 그려집니다.

##### 세로 확장형 레이아웃 설정 (FluidHeight)
- 세로 확장형으로 레이아웃 타입을 설정하여, 배너 광고의 세로 폭을 직접 설정할 수 있습니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let bannerOption = GFPAdBannerOptions()
bannerOption.layoutType = .fluidHeight
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
bannerOptions.layoutType = GFPBannerViewLayoutTypeFluidHeight;
```
</p>
</details>

##### 확장형 레이아웃 설정 (Fluid)
- 확장형으로 레이아웃 타입을 설정하여, 배너 광고의 가로/세로 폭을 직접 설정할 수 있습니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let bannerOption = GFPAdBannerOptions()
bannerOption.layoutType = .fluid
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
bannerOptions.layoutType = GFPBannerViewLayoutTypeFluid;
```
</p>
</details>

#### 광고 전달 데이터 설정
hostMeta(매채와 광고간의 약속된 데이터)를 설정하여 광고 소재에 필요한 데이터를 전달합니다. hostMeta의 Key/Value는 모두 문자열 타입입니다.

**hostMeta를 이용하여 광고 스타일을 설정**할 수 있습니다. [InterfaceStyle 전역 설정](/glad-sdk-guide/ko/ios/common/get_started/#interfacestyle-설정)과 별개로, 특정 화면에서 UI 모드가 다를 때 개별 설정을 통해 아이콘 스타일을 맞출 수 있습니다.
'광고 별 설정 > 전역 설정'의 우선 순위에 따라 적용되며, 광고 별 style 설정이 없을 경우 전역 설정을 따라갑니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
//example
let bannerOption = GFPAdBannerOptions()
bannerOption.hostMeta = ["light":"theme"]
bannerOption.hostMeta = ["dark":"theme"]
bannerOption.hostMeta = ["system":"theme"] // 아이폰 설정의 style을 따라갑니다.
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
//example
GFPAdBannerOptions *bannerOptions = [[GFPAdBannerOptions alloc] init];
bannerOptions.hostMeta = [NSDictionary dictionaryWithObjectsAndKeys:@"light", @"theme", nil];
bannerOptions.hostMeta = [NSDictionary dictionaryWithObjectsAndKeys:@"dark", @"theme", nil];
bannerOptions.hostMeta = [NSDictionary dictionaryWithObjectsAndKeys:@"system", @"theme", nil]; // 아이폰 설정의 style을 따라갑니다.
```
</p>
</details>

## GFPAdLoaderDelegate 구현
**GFPAdLoaderDelegate**를 구현하시면, 해당 메서드를 통해 광고 로드 관련 이벤트를 받으실 수 있습니다.

### 로드 성공 및 실패
#### 배너 로드 성공시
배너 광고 로드가 성공하면, 광고를 원하는 위치에 게제하고, 필요한 경우 적절하게 constraint를 설정합니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceiveBannerAd bannerView: GFPBannerView!) {
    self.view.addSubview(bannerView)
    // constraint 설정
    ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didReceiveBannerAd:(GFPBannerView *)bannerView {
    [self.view addSubview:bannerView];
    // constraint 설정
    ...
}
```
</p>
</details>

#### 로드 실패시

<details open><summary>Example-swift</summary>   
<p>

```swift
func adLoader(_ unifiedAdLoader: GFPAdLoader!, didFailWithError error: GFPError!, responseInfo: GFPLoadResponseInfo!) {
    // ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)adLoader:(GFPAdLoader *)unifiedAdLoader didFailWithError:(GFPError *)error responseInfo:(GFPLoadResponseInfo *)responseInfo {
    // ...
}
```
</p>
</details>


#### 네이티브 광고 로드 성공시
GFPAdLoader에 `nativeSimpleOption` 혹은 `nativeOption`을 설정한 경우인 경우, 배너 혹은 네이티브 광고가 내려올 수 있습니다.  


## GFPBannerViewDelegate 구현
**GFPBannerViewDelegate**를 구현하시면, 해당 메서드를 통해 이벤트를 받으실 수 있습니다.

### MRAID 3.0 적용 시 소재에서 Unload 호출 시 
MRAID 3.0 에서 추가된 스펙인 Unload 호출 시 호출되는 메서드로, 메서드 이후에 GFPBannerView 는 자동으로 SuperView에서 제거됩니다.

<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerShouldUnload(_ bannerView: GFPBannerView) {
    // ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerShouldUnload:(GFPBannerView *)bannerView{
    // ...
}
```
</p>
</details>


### 로드 이후 발생되는 이벤트
자세한 내용은 **GFPBannerViewDelegate.h** 파일을 참고해 주세요.

#### 광고 노출 이벤트 발생시

<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerAdWasSeen(_ bannerView: GFPBannerView) {
    ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerAdWasSeen:(GFPBannerView *)bannerView {
    ...
}
```
</p>
</details>

#### 클릭 이벤트 발생시

<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerAdWasClicked(_ bannerView: GFPBannerView) {
    ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerAdWasClicked:(GFPBannerView *)bannerView {
    ...
}
```
</p>
</details>


#### 광고 사이즈 변경 시

광고 소재에 의해 사이즈 변경 시 호출됩니다.

광고 사이즈가 변경시 호출되었을 때 먼저 GFPBannerSizeType을 통해 Fixed인지 Fluid인지 판단하여 Fluid라면 원하는 사이즈로 변경이 가능합니다.
(**GFPBannerAdSize.h 파일 참조**)

- FluidWidth 일 경우 size.width = -1 이므로 원하는 Width 값 변경 필요.
- FluidHeight 일 경우 size.height = -1 이므로 원하는 Height 값 변경 필요.
- Fluid 일 경우 size.width = -1, size.height = -1 이므로 원하는 Width, Height 값 변경 필요.



<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerView(_ bannerView: GFPBannerView, didChangeWith size: GFPBannerAdSize) {
    ...
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerView:(GFPBannerView *)bannerView didChangeWith:(GFPBannerAdSize *)size {
    ...
}
```
</p>
</details>

#### 광고 Meta 데이터 변경 시

광고 소재에 의해 광고 Meta 데이터 변경 시 호출됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerView(_ bannerView: GFPBannerView, didChangeAdMeta adMeta: [String : String]) {
    ...
    //adMeta example: ["bgcolor":"#000000", "fontcolor":"#FFFFFF"]
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerView:(GFPBannerView *)bannerView didChangeAdMeta:(NSDictionary <NSString *, NSString *>*)adMeta {
    ...
    //adMeta example: { 'bgcolor':'#000000', 'fontcolor':'#FFFFFF' };
}
```
</p>
</details>

#### 광고가 사용자에 의해 Mute 되었을 때
광고가 Mute 되었을 때, 서비스에 콜백을 통해 Mute 를 알립니다. 
Mute 후 GFPSDK에서는 "이 광고는 더 이상 보이지 않습니다." 라는 화면을 노출하고 있으며, **서비스의 정책**에 따라 광고를 화면에서 없앨 지/그대로 노출할 지를 정합니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
func bannerAdWasMuted(_ bannerView: GFPBannerView) {
    
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)bannerAdWasMuted:(GFPBannerView *)bannerView {

}
```
</p>
</details>
