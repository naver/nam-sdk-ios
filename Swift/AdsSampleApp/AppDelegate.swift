//
//  AppDelegate.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import GFPSDK

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        self.updateAdConfig()
        
        AdGFPSDKManger.shared.setupGFPSDK()
        let _ = MainViewManager.shared
        let _ = SettingManager.shared
        
        return true
    }
    
    private func updateAdConfig() {
        SettingConfigManager.reviseConfig()
        SettingTimeoutManager.reviseTimeout()
    }
}

