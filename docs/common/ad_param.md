
## GFPAdParam을 통해 전달 가능한 정보들

yearOfBirth : 출생년도
gender : 성별
userCountryCode : 지역코드 (“Country"와는 다른 param)
currentPageUrl: 현재 페이지를 나타내는 URL
keywords : 컨텐츠를 설명하는 키워드 목록
referrerPageUrl : Referrer URL
userID : 유저 식별값
opt-out : (0: 미설정, 1: 설정)
customUserParam : 직접 정의한 커스텀 파라미터
apsParam : Amazon 헤더비딩 파라미터

<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
adParam.gender = .female
adParam.yearOfBirth = 1995
adParam.keywords = ["KWD_1", "KWD_2"]
adParam.currentPageUrl = "https://naver.com"
adParam.customUserParam = ["key1":"value1"]
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
adParam.gender = GFPAdParamGenderTypeFemale;
adParam.yearOfBirth = 1995;
adParam.keywords = @[@"KWD_1", @"KWD_2"];
adParam.currentPageUrl = @"https://naver.com";
adParam.customUserParam = @{@"key1": @"value1"};
```
</p>
</details>

## Parameter 설명

광고 요청시에 사용되는 GFPAdParam 내의 parameter 들은 각각의 역할이 있습니다.
parameter 에 대한 설명은 아래를 참고하시면 됩니다.

### Year of Birth
(optional) Integer 값으로 출생년도 또는 나이에 해당됩니다. 


<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
...
adParam.yearOfBirth = 1995
```
</p>
</details>

<details  open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.yearOfBirth = 1995;
```
</p>
</details>

### Country
(optional) User 의 용자의 국적(거주지)에 대한 값에 해당됩니다. [ISO 3166-1 alpha-2](https://ko.wikipedia.org/wiki/ISO_3166-1) 에 해당하는 값을 할당합니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
...
adParam.userCountryCode = "KO"
...
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.userCountryCode = @"KO";
...
```
</p>
</details>


### Gender
(optional) User 의 성별에 해당됩니다.

아래 `GFPAdParamGenderType` Enum 에 선언된 값 중 하나를 선택해서 할당합니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
typedef NS_ENUM(NSInteger, GFPAdParamGenderType) {
    GFPAdParamGenderTypeMale = 1,   // 남자
    GFPAdParamGenderTypeFemale = 2, // 여자
    GFPAdParamGenderTypeOther = 3,  // 모름
};

let adParam = GFPAdParam()
...
adParam.gender = .female
...
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
typedef NS_ENUM(NSInteger, GFPAdParamGenderType) {
    GFPAdParamGenderTypeMale = 1,   // 남자
    GFPAdParamGenderTypeFemale = 2, // 여자
    GFPAdParamGenderTypeOther = 3,  // 모름
};

GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.gender = GFPAdParamGenderTypeFemale;
...
```
</p>
</details>


### Current Page URL
(optional) 현재 화면을 표현하는 page 의 url 에 해당됩니다. 

해당 값은 타겟팅 목적의 parameter 로 외부 demand(광고사) 의 광고 요청시에 사용됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
...
adParam.currentPageUrl = "https://naver.com"
...

```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.currentPageUrl = @"https://naver.com";
...
```
</p>
</details>

### Keyword 
(optional) 현재 화면과 관련된 keyword 에 해당됩니다. Array<String> 형태로 복수개의 keyword 를 할당할 수 있습니다.

해당 값은 타겟팅 목적의 parameter 로 외부 demand 의 광고 요청시에 사용됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
...
adParam.keywords = ["KWD_1", "KWD_2"]
...
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.keywords = @[@"KWD_1", @"KWD_2"];
...
```
</p>
</details>


### User Parameter
(optional) GFP admin 에서 사용되는 parameter 로 세부적인 타게팅 및 리포팅을 위해서 사용됩니다.

key와 value 모두 String으로 세팅되는 Dictionary 형태로 세팅하면 됩니다.


<details open><summary>Example-swift</summary>   
<p>

```swift
let adParam = GFPAdParam()
...
adParam.customUserParam = ["key1":"value1", "language":"ko"]
```
</p>
</details>

<details open><summary>Example-ObjC</summary>   
<p>

```objective-c
GFPAdParam *adParam = [[GFPAdParam alloc] init];
...
adParam.customUserParam = @{@"key1": @"value1", @"language":@"ko"};
```
</p>
</details>

### HeaderBidding Parameter
(Optional) HeaderBidding 파라미터를 이용하여 APS(=Amazon Publisher Services) 에서 제공하는 헤더비딩을 사용할 수 있습니다.

- apsParam (`GFPAPSAdParam` 참조숮)
  - APS를 통해 얻은 정보를 설정합니다. (crid, size, apsHBParam)

> APS를 이용한 헤더비딩 파라미터 설정 방법은 [가이드](/docs/banner/hb.md)를 참고해주세요.

