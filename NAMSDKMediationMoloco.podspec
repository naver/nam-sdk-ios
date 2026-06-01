Pod::Spec.new do |s|
  s.name         = "GFPSDKMediationMoloco"
  s.version      = "4.6.1.0"
  s.summary      = "Naver Mobile Ads Mediation SDK for Moloco"
  s.description  = <<-DESC
                    GFP wiil find the best available ad network to fill your ad slots.
                   DESC
  s.homepage     = "https://oss.navercorp.com/da-ssp-app-sdk/gfp-sdk-ios"
  s.license      = { :type => "Naver", :text => "Copyright 2018 NAVER Corp." }
  s.author       = { "Sanghun.han" => "sanghun.han@navercorp.com",
                     "Sodam.kim" => "sodam.k@navercorp.com",
                     "Dojin.park" => "dojin.park@navercorp.com",
                     "Sangeun.yoon" => "sangeun.yoon@navercorp.com"
  }

  s.ios.deployment_target = "13.0"
  s.source       = { :git => "https://oss.navercorp.com/da-ssp-app-sdk/gfp-sdk-ios", :branch => "master", :submodules => true }

  s.vendored_frameworks = "MediationSDK/Moloco/#{s.version.to_s}/GFPSDKMediationMoloco.xcframework"

  s.dependency 'NAMSDK/GFPSDK', '>= 8.22.0'
  s.dependency 'MolocoSDKiOS', '4.6.1'

  s.frameworks = 'UIKit', 'Foundation', 'QuartzCore', 'AdSupport', 'AVFoundation', 'AVKit', 'CoreServices', 'SystemConfiguration', 'WebKit', 'CoreLocation', 'Network'

  s.requires_arc = true
  s.static_framework = true

  s.swift_versions = ['5.0']

  s.pod_target_xcconfig  = { 'OTHER_LDFLAGS' => '-ObjC', 'GCC_PREPROCESSOR_DEFINITIONS' => 'NAM=1', 'OTHER_SWIFT_FLAGS' => '-D NAM' }

end
