
Pod::Spec.new do |s|

  s.name         = "NAMSDK"
  s.version      = "4.3.0"
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
  
  s.ios.deployment_target = "11.0"
  s.source       = { :git => "https://github.com/naver/nam-sdk-ios", :tag => "#{s.version.to_s}" }

  s.default_subspecs = "GFPSDK"
  
  s.subspec 'GFPSDK' do |sdk|
    sdk.vendored_frameworks = "NAMSDK/xcframework/GFPSDK.xcframework"
    sdk.dependency 'KissXML', '~> 5.2'
    sdk.resources = ['NAMSDK/ResourceBundle/GFPSDKResource.bundle']
  end

  s.subspec 'GFPSDKInternal' do |internal|
    internal.vendored_frameworks = "NAMSDK/xcframework/GFPSDKInternal.xcframework"
    internal.dependency 'NAMSDK/GFPSDK'
  end

  s.subspec 'MediationDFP' do |dfp|
    dfp.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationDFP.xcframework"
    dfp.dependency 'NAMSDK/GFPSDK'
    dfp.dependency 'Google-Mobile-Ads-SDK', '8.12.0'
  end
  
  s.subspec 'MediationNDA' do |nda|
    nda.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationNDA.xcframework"
    nda.dependency 'NAMSDK/GFPSDK'    
    nda.resources = ['NAMSDK/ResourceBundle/GFPNDAMraidResource.bundle', 'NAMSDK/ResourceBundle/GFPNDANativeResource.bundle']    
  end
  
  s.subspec 'MediationFAN' do |fan|
    fan.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationFAN.xcframework"
    fan.dependency 'NAMSDK/GFPSDK'    
    fan.dependency 'FBAudienceNetwork', '6.9.0'
  end
  
  s.subspec 'MediationInMobi' do |inMobi|
    inMobi.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationInMobi.xcframework"
    inMobi.dependency 'NAMSDK/GFPSDK'
    inMobi.dependency 'InMobiSDK', '10.0.1'
  end
  
  s.subspec 'MediationUnity' do |unity|
    unity.vendored_frameworks = "NAMSDK/xcframework/GFPSDKMediationUnity.xcframework"
    unity.dependency 'NAMSDK/GFPSDK'
    unity.dependency 'UnityAds', '4.2.1'
  end
  
  s.frameworks = 'UIKit', 'Foundation', 'QuartzCore', 'AdSupport', 'AVFoundation', 'AVKit', 'CoreServices', 'SystemConfiguration', 'WebKit', 'CoreLocation'
  
  s.requires_arc = true
  
  s.static_framework = true
  s.swift_versions = ['5.0']

end
