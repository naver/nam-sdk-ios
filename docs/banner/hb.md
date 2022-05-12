## 헤더비딩

**Amazon Publisher Services**(이하 "APS"라고 칭함)을 통한 HeaderBidding을 지원합니다.

APS의 경우 아마존에서 제공하는 **3.4.6 버전**을 기준으로, 샘플 개발 및 QA 검증이 완료 되었으므로 참고 부탁드립니다.

```text
source 'https://github.com/CocoaPods/Specs.git'

target 'MyApplication' do
    pod 'AmazonPublisherServicesSDK', '3.4.6'
end
```

## APS 연동

APS을 통한 헤더비딩 연동은 **배너 광고에 한해 지원**합니다.

아래 가이드는 NAMSDK 연동과 관련된 내용을 다루고 있습니다. APS에 대한 자세한 내용은 [공식 가이드를 참고](https://ams.amazon.com/webpublisher/uam/docs/aps-mobile/ios/sdk-initialization)해주시기 바랍니다.

### APS 설정

NAMSDK 에서는 **MRAID 1.0, 2.0, 3.0 스펙** 을 지원합니다. 아래의 MRAID 설정은 반드시 따라주시기 바랍니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
DTBAds.sharedInstance().setAppKey("appKey 입력")
//testAppKey: "c5f20fe6e37146b08749d09bb2b6a4dd"

DTBAds.sharedInstance().mraidPolicy = CUSTOM_MRAID
DTBAds.sharedInstance().mraidCustomVersions = ["1.0", "2.0", "3.0"]
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
```
</p>
[[DTBAds sharedInstance] setAppKey: @"appKey 입력"];
//testAppKey: "c5f20fe6e37146b08749d09bb2b6a4dd"

[[DTBAds sharedInstance] setMraidPolicy:CUSTOM_MRAID];
[[DTBAds sharedInstance] setMraidCustomVersions:@[@"1.0", @"2.0", @"3.0"]];
</details>

### APS 정보 요청

자세한 내용은 [APS 공식 가이드](https://ams.amazon.com/webpublisher/uam/docs/aps-mobile/ios/banner-ads)를 참고해주세요.


<details open><summary>Example-swift</summary>   
<p>
```swift
let dtbAdSize = DTBAdSize(bannerAdSizeWithWidth: 320, height: 50, andSlotUUID: "slotUUID 입력")
//testSlotUUID: "88e6293b-0bf0-43fc-947b-925babe7bf3f"

let dtbAdLoader = DTBAdLoader()
dtbAdLoader.setAdSizes([dtbAdSize])
dtbAdLoader.loadAd(self)
```
```swift
func onFailure(_ error: DTBAdError) {
    /**Please implement the logic to send ad request without our parameters if you want to
     show ads from other ad networks when Amazon ad request fails**/
}

func onSuccess(_ adResponse: DTBAdResponse!) {
    /**Build the ad request to your ad server. This portion will differ depending on your 
     ad server**/
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
DTBAdSize *dtbAdSize = [[DTBAdSize alloc] initBannerAdSizeWithWidth:320 height:50 andSlotUUID:@"slotUUID 입력"];
//testSlotUUID: "88e6293b-0bf0-43fc-947b-925babe7bf3f"

DTBAdLoader *adLoader = [DTBAdLoader new];
[adLoader setSizes:dtbAdSize, nil];
[adLoader loadAd:self];
```
```objective-c
#pragma mark - DTBAdCallback
- (void)onFailure: (DTBAdError)error {
    NSLog(@"Failed to load ad :(");
    /**Please implement the logic to send ad request without our parameters if you want to
     show ads from other ad networks when Amazon ad request fails**/
}

- (void)onSuccess: (DTBAdResponse *)adResponse {
    /**Build the ad request to your ad server. This portion will differ depending on your 
     ad server**/
}
```
</p>
</details>


### AdParam 설정 & 배너 로드

- DTBAdCallback의 onSuccess 수신 시, APS 정보를 `GFPAPSAdParam`에 세팅 후, `AdParam의 apsParam`에 설정합니다.
- AdParam을 GFPBannerView에 설정한 후 광고를 요청합니다.
  - (주의) [광고 요청 전, 이전 데이터 초기화 필요] AdParam을 재사용 한다면, onFailure 수신 시 AdParam의 apsParam을 리셋해주어야 합니다. 


<details open><summary>Example-swift</summary>   
<p>

```swift
func onSuccess(_ adResponse: DTBAdResponse!) {
    let adParam = GFPAdParam()
    adParam.gender = .female
    adParam.yearOfBirth = 1995

    let apsParam = GFPAPSAdParam()
    apsParam.crid = adResponse.crid
    apsParam.size = CGSize(width: adResponse.adSize.width, height: adResponse.adSize.height)

    if let customTargeting = adResponse.customTargeting().map as? [String : NSObject] {
        apsParam.apsHBParam = customTargeting
    }
    
    apsParam.skAdNetworkParams = adResponse.skAdNetworkParams;

    adParam.apsParam = apsParam;

    //TODO: banner 광고 요청
}
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
- (void)onSuccess: (DTBAdResponse *)adResponse {
    GFPAdParam *adParam = [[GFPAdParam alloc] init];
    adParam.gender = GFPAdParamGenderTypeFemale;
    adParam.yearOfBirth = 1995;
    
    GFPAPSAdParam *apsParam = [[GFPAPSAdParam alloc] init];
    apsParam.crid = adResponse.crid;
    apsParam.size = CGSizeMake(adResponse.adSize.width, adResponse.adSize.height);
    apsParam.apsHBParam = adResponse.customTargeting;
    apsParam.skAdNetworkParams = adResponse.skAdNetworkParams;

    adParam.apsParam = apsParam;
    
    //TODO: banner 광고 요청
}
```
</p>
</details>

### MRAID 3.0 Unload
MRAID 3.0의 Unload 호출 시에 발생하는 이벤트를 알리기 위해 다음 메서드가 GFPBannerViewDelegate에 추가되었습니다.

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
