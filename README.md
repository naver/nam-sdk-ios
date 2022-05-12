# Naver Ad Manager SDK for iOS
![iOS badge](https://img.shields.io/badge/iOS-11.0%2B-green?style=plastic)
![Pods](https://img.shields.io/cocoapods/v/NAMSDK?style=plastic)
![XCode](https://img.shields.io/badge/Xcode-12%2B-yellow?style=plastic)

Naver Ad Manager는 높은 단가의 ‘네이버 성과형 광고 플랫폼’(네이버SSP에서만 물량 제공)을 비롯해 국내/외 대표적인 DSP를 모두 확보하고 있어 매체 수익화를 위한 최적의 환경을 제공합니다.

## Getting Started
### Cocoapods Dependency
pod init 이후 생성된 Podfile에 NAMSDK를 추가합니다.
NAMSDK Pod과 함께 연동하고 싶은 광고 제공자들의 Mediation Pod을 추가로 설정합니다.

```sh
source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '11.0'

target 'MyApplication' do
    pod 'NAMSDK'               # SDK 본체
    pod 'NAMSDK/MediationNDA'  # 네이버 광고
    pod 'NAMSDK/MediationDFP'  # 구글 DFP
    pod 'NAMSDK/MediationFAN'  # 페이스북 FAN
    pod 'NAMSDK/MediationInMobi'  # 인모비
    pod 'NAMSDK/MediationUnity'  # 유니티
end
```
#### 지원 중인 광고 제공자 목록
| 광고 제공자 이름  | 지원되는 광고 타입 | cocoapods설정 |
| ------------- | ------------- |------------- |
|네이버|	배너, 네이티브(NS, NN) |	pod NAMSDK/MediationNDA|
|구글 DFP|	배너, 네이티브, 전면형, 보상형	| pod NAMSDK/MediationDFP|
|페이스북|	배너, 네이티브, 전면형, 보상형	|pod NAMSDK/MediationFAN|
|인모비|	배너, 네이티브	|pod NAMSDK/MediationInMobi|
|유니티|	배너, 전면형, 보상형	|pod NAMSDK/MediationUnity|

### ATS(App Transport Security) 설정
iOS 9부터 도입 된 App Transport Security (ATS)는 앱이 HTTPS를 통해서만 네트워크 요청을 하도록 기본설정 되어있습니다. HTTP를 사용하는 광고파트너들의 광고동작를 허용하기 위해, Info.plist 파일에 아래내용을 추가합니다.

```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

### Google DFP 연동시 주의사항
구글 DFP를 연동 하시는 경우, 아래 내용을 추가로 Info.plist 파일에 추가해야 합니다. 그렇지 않을 경우, “The Google Mobile Ads SDK was initialized incorrectly.“와 같은 메시지와 함께 동작이 중단됩니다.

```xml
<key>GADIsAdManagerApp</key>
<true/>
```

### GFPSDK 광고매니저 설정
#### 광고제공자 초기화
광고를 요청하기 전에 SDK초기화(앱 전체 라이프 사이클에서 한번)가 수행되어야 합니다.
cocoapods의 의존성이 추가되어 있으면, 각 광고 제공자별 광고 타입별 광고가 자동으로 초기화 됩니다. 다만, 여기서 초기화되지 않은 광고 제공자로부터의 광고는 이후 서버로부터의 응답결과와 관계없이 처리되지 않습니다.

SDK 초기화 호출 시 GFP Admin 에서 발급한 퍼블리셔 코드(publihserCd)를 넘겨주어야 합니다.

초기화 성공 여부는 **GFPAdManager**의 **isSdkInitialized** property값을 통해 알 수 있습니다.

<details open><summary>Example-swift</summary>   
<p>

```swift
import GFPSDK

/* 
배너 : DFP, NDA, FAN, INMOBI, MOPUB
비디오 : IMA, NDA
네이티브 : DFP, NDA, FAN, INMOBI, MOPUB
*/

/*
GFPAdConfiguration(광고 설정) 없이 초기화.
*/
GFPAdManager.setup(withPublisherCd: "publisherCd" target:self) { (error : GFPError?) in
    print("Setup Eror: \(String(describing: error?.description))")
}

/*
광고 초기화 성공 여부
*/
GFPAdManager.isSdkInitialized()

/*
GFPAdConfiguration 설정 초기 : 광고 테스트 모드, 타임아웃, 로그 레벨, 렌더링 타임 설정 가능.
*/

let configuration = GFPAdConfiguration()
GFPAdManager.setup(withPublisherCd: "publisherCd", target:self configuration: configuration) { (error : GFPError?) in
    print("Setup Eror: \(String(describing: error?.description))")
}    
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
    @import GFPSDK;

/* 
배너 : DFP, NDA, FAN, INMOBI, MOPUB
비디오 : IMA, NDA
네이티브 : DFP, NDA, FAN, INMOBI, MOPUB
*/

/*
GFPAdConfiguration(광고 설정) 없이 초기화.
*/
[GFPAdManager setupWithPublisherCd:@"publisherCd" target:self completionHandler:^(GFPError * _Nullable error) {
    NSLog(@"Setup ERROR: %@", error);
}];

/*
광고 초기화 성공 여부
*/
[GFPAdManager isSdkInitialized];

/*
GFPAdConfiguration 설정 초기 : 광고 테스트 모드, 타임아웃, 로그 레벨, 렌더링 타임 설정 가능.
*/
GFPAdConfiguration *configuration = [[GFPAdConfiguration alloc] init];

[GFPAdManager setupWithPublisherCd:@"publisherCd" configuration:configuration target:self completionHandler:^(GFPError * _Nullable error) {
    NSLog(@"Setup ERROR: %@", error);
}];
```
</p>
</details>


>GFPAdManagerDelegate는 필수적으로 구현되어야해야 합니다.
ATTFramework를 통해 서비스에서 광고 추적 여부를 구현 후, GFPAdManagerDelegate를 통하여 Status를 SDK에 제공해줘야 합니다.
초기화 API의 target Parameter에 id<GFPAdManagerDelegate> 를 구현해서 넣어야합니다.

#### GFPAdManagerDelegate 설정 및 Example
```objective-c
@protocol GFPAdManagerDelegate <NSObject>

- (GFPATTAuthorizationStatus)attStatus;

@end

typedef NS_ENUM(NSInteger, GFPATTAuthorizationStatus) {
    GFPATTAuthorizeNotDetermined = 0,          // 사용자의 승인 미요청 상태
    GFPATTAuthorizeRestricted,             // 사용자의 기기가 제한된 상태. 
    GFPATTAuthorizeDenied,                 // 사용자의 IDFA 요청 거절 상태.
    GFPATTAuthorizeAuthorized              // 사용자의 IDFA 요청 승인 상태. 
};    
```   
    
<details open><summary>Example-swift</summary>   
<p>

```swift
func attStatus() -> GFPATTAuthorizationStatus {
    if #available(iOS 14.5, *) {
        return ATTrackingManager.trackingAuthorizationStatus
    } else {
        if ASIdentifierManager.shared().isAdvertisingTrackingEnabled {
            return GFPATTAuthorizeAuthorized
        }
        return GFPATTAuthorizeNotDetermined
    }
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (GFPATTAuthorizationStatus)attStatus {
     if (@available(iOS 14.5, *)) {
        return ATTrackingManager.trackingAuthorizationStatus;
    } else {
        if ([[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled]) {
            return GFPATTAuthorizeAuthorized;
        }
        
        return GFPATTAuthorizeNotDetermined;
    }
}
```
</p>
</details>

### 기본값 설정
GFPAdConfiguration 통해 앱 전역에서 사용할 기본값 등의 설정이 가능합니다.
자세한 내용은 GFPAdConfiguration.h 파일을 참고해 주세요.

#### GFPAdConfiguration에 설정 가능한 내용들
- 배너광고 요청 타임아웃 설정 (기본값: 60초)
- 비디오광고 요청 타임아웃 설정 (기본값: 60초)
- 네이티브광고 요청 타임아웃 설정(기본값: 60초)
- DFP 테스트 광고 송출 여부 설정 (기본값: NO)
- FAN 테스트 광고 송출 여부 설정 (기본값: NO)
- NAMSDK 로그레벨 설정 (기본값: 출력하지 않음)
- Default UA 사용 여부 설정 (기본값: NO)
    
    
### 테스트 모드 설정
GFPAdProviderSetting을 통해 각 광고 제공자의 테스트 모드 설정이 가능합니다.
Google, Facebook, 테스트 모드 지원.
    
### 광고 요청 정보
**GFPAdParam**을 통해서 광고 요청 시 공통으로 사용되는 정보를 함께 전달할 수 있습니다. (optional)
데모(성별,나이)와 기타 부가정보 등을 제공하면, 광고 타게팅 효과를 높일 수 있습니다.
헤더비딩 파라미터를 사용하여 APS(=Amazon Publisher Services)에서 제공하는 헤더비딩을 사용할 수 있습니다.

- [GFPAdParam Guide](docs/common/ad_param.md)

### 각 광고별 설정 가이드
- [배너 광고](docs/banner/guide.md)
- [네이티브 일반 광고](docs/native/native_normal_guide.md)
- [네이티브 심플 광고](docs/native/native_simple_guide.md)
- [보상형 광고](docs/rewarded/guide.md)
- [전면형 광고](docs/interstitial/guide.md)

----
    
## License
NAM(Naver Ad Manager) SDK의 저작권은 네이버(주)에 있습니다.

```
NAM(Naver Ad Manager) SDK for iOS
Copyright 2022-present NAVER Corp.
All rights reserved.
Unauthorized use, modification and redistribution of this software are strongly prohibited.
```
