
Pod::Spec.new do |s|

  s.name         = "NAMSDK"
  s.version      = "7.9.4"
  s.summary      = "Naver Mobile Ads Mediation SDK"
  s.description  = <<-DESC
                    NAM wiil find the best available ad network to fill your ad slots.
                   DESC
  s.homepage     = "https://github.com/naver/nam-sdk-ios"
  s.license      = { :type => "Naver", :text => "Copyright 2022 NAVER Corp." } 
  s.author       = { "Sanghun.han" => "sanghun.han@navercorp.com",
                     "Sodam.kim" => "sodam.k@navercorp.com",
                     "Dojin.park" => "dojin.park@navercorp.com"
                   }
  
  s.ios.deployment_target = "13.0"
  s.source       = { :git => "https://github.com/naver/nam-sdk-ios", :tag => "#{s.version.to_s}" }
  s.default_subspecs = "GFPSDK"

  s.subspec 'GFPSDK' do |sdk|
    sdk.vendored_frameworks = "NAMSDK/xcframework/GFPSDK.xcframework", "NAMSDK/xcframework/libraries/OMSDK_Navercorp.xcframework"
    sdk.dependency 'KissXML', '~> 5.2'
    sdk.dependency 'Naver-Ads-Services', '~> 1.0.8'
    sdk.resources = ["NAMSDK/ResourceBundle/GFPSDKResource.bundle"]
  end

  s.subspec 'AdRenderer' do |sdk|
    sdk.vendored_frameworks = "NAMSDK/xcframework/GFPSDKAdRenderer.xcframework"
    sdk.resources = ["NAMSDK/ResourceBundle/GFPSDKRendererResource.bundle"]
    sdk.dependency 'NAMSDK/GFPSDK'
  end
  
  s.subspec 'MediationDFP' do |dfp|
    dfp.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationDFP.xcframework"
    dfp.dependency 'NAMSDK/GFPSDK'
    dfp.dependency 'Google-Mobile-Ads-SDK', '11.3.0'
  end
  
  s.subspec 'MediationNDA' do |nda|
    nda.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationNDA.xcframework"
    nda.dependency 'NAMSDK/GFPSDK'    
    nda.resources = ['NAMSDK/ResourceBundle/GFPNDAMraidResource.bundle', 'NAMSDK/ResourceBundle/GFPNDANativeResource.bundle']    
  end

  s.subspec 'MediationNDAVideo' do |ndaVideo|
    ndaVideo.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationNDAVideo.xcframework"
    ndaVideo.resources = ['NAMSDK/ResourceBundle/GFPNDAVideoResource.bundle']
    ndaVideo.dependency 'NAMSDK/GFPSDK'
    ndaVideo.dependency 'NAMSDK/MediationNDA'

  end
  
  s.subspec 'MediationNDARich' do |ndaRich|
    ndaRich.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationNDARich.xcframework"
    ndaRich.dependency 'NAMSDK/GFPSDK'
    ndaRich.dependency 'NAMSDK/MediationNDA'
    ndaRich.dependency 'NAMSDK/MediationNDAVideo'
    ndaRich.dependency 'NAMSDK/AdRenderer'
  end
  

  s.subspec 'MediationFAN' do |fan|
    fan.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationFAN.xcframework"
    fan.dependency 'NAMSDK/GFPSDK'    
    fan.dependency 'FBAudienceNetwork', '6.15.1'
  end
  
  s.subspec 'MediationInMobi' do |inMobi|
    inMobi.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationInMobi.xcframework"
    inMobi.dependency 'NAMSDK/GFPSDK'
    inMobi.dependency 'InMobiSDK', '10.7.2'
  end
  
  s.subspec 'MediationUnity' do |unity|
    unity.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationUnity.xcframework"
    unity.dependency 'NAMSDK/GFPSDK'
    unity.dependency 'UnityAds', '4.12.0'
  end
  
  s.subspec 'MediationAppLovin' do |appLovin|
    appLovin.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationAppLovin.xcframework"
    appLovin.dependency 'NAMSDK/GFPSDK'
    appLovin.dependency 'AppLovinSDK', '12.5.0'
  end

  s.subspec 'MediationVungle' do |vungle|
    vungle.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationVungle.xcframework"
    vungle.dependency 'NAMSDK/GFPSDK'
    vungle.dependency 'VungleAds', '7.3.2'
  end

  s.subspec 'MediationDT' do |dt|
    dt.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationDT.xcframework"
    dt.dependency 'NAMSDK/GFPSDK'
    dt.dependency 'Fyber_Marketplace_SDK', '8.2.8'
  end

  s.subspec 'MediationIronSource' do |ironSource|
    ironSource.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationIronSource.xcframework"
    ironSource.dependency 'NAMSDK/GFPSDK'
    ironSource.dependency 'IronSourceSDK', '8.1.0'
  end

  s.subspec 'MediationAPS' do |aps|
    aps.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationAPS.xcframework"
    aps.dependency 'NAMSDK/GFPSDK'
    aps.dependency 'AmazonPublisherServicesSDK', '4.9.3'
  end

  s.subspec 'MediationLAN' do |lan|
    lan.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationLAN.xcframework"
    lan.dependency 'NAMSDK/GFPSDK'
    lan.dependency 'FiveAd', '2.8.20240612'
  end

  s.frameworks = 'UIKit', 'Foundation', 'QuartzCore', 'AdSupport', 'AVFoundation', 'AVKit', 'MobileCoreServices', 'SystemConfiguration', 'WebKit', 'CoreLocation'
  
  s.requires_arc = true
  
  s.static_framework = true

  s.resource_bundles = { "NAMSDKResources" => "NAMSDK/xcframework/GFPSDK.xcframework/ios-arm64/GFPSDK.framework/PrivacyInfo.xcprivacy" }    

  s.swift_versions = ['5.0']
  
  s.pod_target_xcconfig  = { 'OTHER_LDFLAGS' => '-ObjC', 'GCC_PREPROCESSOR_DEFINITIONS' => 'NAM=1', 'OTHER_SWIFT_FLAGS' => '-D NAM' }
end
