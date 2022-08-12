# Amazon Publisher Services SDK (v3.4.6)

## Summary

Amazon Publisher Services (APS) provides a suite of cloud-based services that enable web, mobile app, and advanced TV publishers to grow their businesses. Used by thousands of leading publishers throughout the world, our Transparent Ad Marketplace (TAM) service enables you to increase monetization by adding many leading sources of advertising demand, through one server-to-server integration. Learn more at: https://aps.amazon.com/aps/solutions-for-mobile-app-developers/

## Requirements

iOS 9.0 and above

## Installation

To get started:

1. Install the CocoaPods command line tool.
2. Navigate to your iOS application's root directory. The root directory should contain the `*.xcodeproj` file.
3. Create a new Podfile with the following text:

```
target 'iOSSampleApp' do
  pod 'AmazonPublisherServicesSDK', '3.4.6'
end
```

If you are using AdMob, include another pod for the adapters.

```
target 'iOSSampleApp' do
  pod 'AmazonPublisherServicesSDK', '3.4.6'
  pod 'AmazonPublisherServicesAdMobAdapter', '1.6.0'
end
```

If you are using MoPub, include another pod for the adapters.

```
target 'iOSSampleApp' do
  pod 'AmazonPublisherServicesSDK', '3.4.6'
  pod 'AmazonPublisherServicesMoPubAdapter', '1.3.0'
end
```

Once you have inserted all your pods, from the command line, execute the following command:

```
pod install
```

By executing this command, CocoaPods will integrate the APS SDK into the app project automatically.
Your application project should now be configured with the APS SDK. Open the project with the `*.xcworkspace` file in Xcode instead of the `*.xcodeproj` file to begin development.

Note that the command `pod 'AmazonPublisherServicesSDK'` will look for the latest `AmazonPublisherServicesSDK` framework when searching for the artifact. Alternatively, you can specify a particular version to be downloaded such as:

```
pod 'AmazonPublisherServicesSDK', '3.4.6'
```

## License
This software is licensed as "Program Materials" under the Amazon Publisher Services Agreement, which is available at https://ams.amazon.com/webpublisher/apsmanaged/apsagreement.html (the "License"). See the License for the specific language governing permissions and limitations under the License.

These materials may include third party software that is copyrighted by other parties and is subject to separate license terms. Information on that software and the applicable copyright notices and license terms are included in the separate NOTICE.txt accompanying the applicable materials. You acknowledge and agree that your license to use and distribute these materials is conditioned on your providing to your users the notices and disclaimers that are specified by such license terms.

These materials are distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

## Notice
Licenses to the Google Mobile Ads SDK are governed by the Google Terms of Service at https://policies.google.com/terms?gl=US&hl=en and the Google API Terms of Service at https://developers.google.com/terms/

Information about the Google Mobile Ads SDK for iOS is available here: https://developers.google.com/mobile-ads-sdk/docs/dfp/ios/download

Information about the Google Mobile Ads SDK for Android is available here: https://developers.google.com/mobile-ads-sdk/docs/dfp/android/sdk

License to the 5.0 MoPub SDK is governed by the following terms:

MoPub's terms are available here: https://www.mopub.com/legal/sdk-license-agreement/

MOAT's terms are available here: https://moat.com/terms and here: https://moat.com/third_party_software_attribution

IAS's terms are available here: https://integralads.com/sdk-license-agreement/

Information about the MoPub iOS SDK is available here: https://developers.mopub.com/docs/ios/getting-started/

Information about the MoPub Android SDK is available here: https://bintray.com/mopub/mopub-android-sdk/mopub-android-sdk/5.0.0#read
