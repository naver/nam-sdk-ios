
Pod::Spec.new do |s|
  s.name         = "NAMSDKMediationLAN"
  s.version      = "2.9.20250512.1"
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
  s.source       = { :git => "https://github.com/naver/nam-sdk-ios", :branch => "main" }
  
  s.vendored_frameworks = "MediationSDK/LAN/#{s.version.to_s}/GFPSDKMediationLAN.xcframework"

  s.dependency 'NAMSDK/GFPSDK', '>= 8.8.0'
  s.dependency 'FiveAd', '2.9.20250512'

  s.frameworks = 'UIKit', 'Foundation', 'QuartzCore', 'AdSupport', 'AVFoundation', 'AVKit', 'MobileCoreServices', 'SystemConfiguration', 'WebKit', 'CoreLocation'
  
  s.requires_arc = true
  s.static_framework = true

  s.swift_versions = ['5.0']
  
  s.pod_target_xcconfig  = { 'OTHER_LDFLAGS' => '-ObjC', 'GCC_PREPROCESSOR_DEFINITIONS' => 'NAM=1', 'OTHER_SWIFT_FLAGS' => '-D NAM' }
end
