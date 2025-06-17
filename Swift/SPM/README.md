# Swift Ads Sample

Swift Ads Sample 은 NAM SDK 구현에 참고할 수 있도록 고안된 코드입니다.

## 참고 코드

- AdGFPSDKManager.swift: [NAM SDK 초기 셋업](https://naver.github.io/nam-sdk-guide/ios/common/get_started), [광고 요청 정보](https://naver.github.io/nam-sdk-guide/ios/common/ad_param)

- DisplayAdViewController.swift: [배너 광고](https://naver.github.io/nam-sdk-guide/ios/banner/), [네이티브 광고](https://naver.github.io/nam-sdk-guide/ios/native/)

- RewardedAdViewController.swift: [보상형 광고](https://naver.github.io/nam-sdk-guide/ios/rewarded/)

- InterstitialAdViewController.swift: [전면형 광고](https://naver.github.io/nam-sdk-guide/ios/interstitial/interstitial_guide)

## Default Ad Unit ID 리스트 설정 방법

- SwiftAdsSample/Resource/AdUnitIDList.plist 에서 값을 변경하고 다시 빌드하면 앱에 바로 반영됩니다.

앱 내에서 Ad Unit ID 리스트를 수정한 값은 UserDefaults 에 저장되어 앱을 삭제하기 전까지 설정이 유지됩니다.

하지만 여러개의 기기나 시뮬레이터에 동일한 값을 설정해야 하는 경우 등에는 AdUnitIDList.plist 를 활용하면 됩니다.