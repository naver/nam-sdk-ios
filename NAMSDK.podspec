
Pod::Spec.new do |s|
  s.name         = "NAMSDK"
  s.version      = "8.9.0"
  s.summary      = "Naver Mobile Ads Mediation SDK"
  s.description  = <<-DESC
                    NAM wiil find the best available ad network to fill your ad slots.
                   DESC
  s.homepage     = "https://github.com/naver/nam-sdk-ios"
  s.license      = { :type => "Naver", :text => "Copyright 2022 NAVER Corp." } 
  s.author       = { "Sanghun.han" => "sanghun.han@navercorp.com",
                     "Sodam.kim" => "sodam.k@navercorp.com",
                     "Dojin.park" => "dojin.park@navercorp.com",
                     "Sangeun.yoon" => "sangeun.yoon@navercorp.com"
                   }
  
  s.ios.deployment_target = "13.0"
  s.source       = { :git => "https://github.com/naver/nam-sdk-ios", :tag => "#{s.version.to_s}" }
  s.default_subspecs = "GFPSDK"

  s.subspec 'GFPSDK' do |sdk|
    sdk.vendored_frameworks = "NAMSDK/xcframework/GFPSDK.xcframework", "NAMSDK/xcframework/libraries/OMSDK_Navercorp.xcframework"
    sdk.dependency 'KissXML', '~> 5.2'
    sdk.dependency 'Naver-Ads-Services', '~> 1.1.2'
    sdk.resources = ["NAMSDK/ResourceBundle/GFPSDKResource.bundle"]
  end

  s.subspec 'AdRenderer' do |sdk|
    sdk.vendored_frameworks = "NAMSDK/xcframework/GFPSDKAdRenderer.xcframework"
    sdk.resources = ["NAMSDK/ResourceBundle/GFPSDKRendererResource.bundle"]
    sdk.dependency 'NAMSDK/GFPSDK'
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
  
  s.frameworks = 'UIKit', 'Foundation', 'QuartzCore', 'AdSupport', 'AVFoundation', 'AVKit', 'MobileCoreServices', 'SystemConfiguration', 'WebKit', 'CoreLocation'
  
  s.requires_arc = true
  s.static_framework = true

  s.resource_bundles = { "NAMSDKResources" => "NAMSDK/xcframework/GFPSDK.xcframework/ios-arm64/GFPSDK.framework/PrivacyInfo.xcprivacy" }    

  s.swift_versions = ['5.0']
  
  s.pod_target_xcconfig  = { 'OTHER_LDFLAGS' => '-ObjC', 'GCC_PREPROCESSOR_DEFINITIONS' => 'NAM=1', 'OTHER_SWIFT_FLAGS' => '-D NAM' }
end
