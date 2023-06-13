//
//  OtherExtensions.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

extension Bundle {
    
    static var currentVersion : String {
        return self.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? ""
    }
    
    static var buildVersion : String {
        return self.main.infoDictionary?["CFBundleVersion"] as? String ?? ""
    }
}

extension Calendar {
    
    static var currentYear : Int {
        return Calendar.current.component(Calendar.Component.year, from: Date())
    }
    
}

extension Locale {
    
    static var countryCode : String {
        return Locale.current.regionCode ?? ""
    }
    
}

extension UIApplication {
    
    static var isStatusBarLandscape : Bool {
        get {
            return UIApplication.shared.statusBarOrientation.isLandscape
        }
    }
    
}

extension UIButton {
    
    static var reloadButton: UIButton {
        let button = UIButton.init(frame: CGRect.zero)
        button.setTitle("Reload", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.frame.size = .init(width: 70, height: 60)
        return button
    }
    
}

extension UIView {
    func showDebugBorder(withColor color: UIColor) {
        self.layer.borderColor = color.cgColor
        self.layer.borderWidth = 1.0
    }
}
