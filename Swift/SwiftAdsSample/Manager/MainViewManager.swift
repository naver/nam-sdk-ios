//
//  MainViewManager.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import GFPSDK

final class MainViewManager {
    static var shared = MainViewManager()
    
    public var adType: AdType? {
        didSet {
            self.adTypeLabel?.text = adType?.title
            UserDefaults.adType = self.adType
            
            if self.adType != nil {
                self.unitID = UserDefaults.unitID(forAdType: self.adType!)
            }
        }
    }
    
    public var unitID: String? {
        didSet {
            self.unitIDLabel?.text = self.unitID
            
            if self.adType != nil {
                UserDefaults.setUnitID(forAdType: self.adType!, unitID: self.unitID)
            }
        }
    }
    
    public var wfMatcher: String? {
        didSet {
            self.wfMatcherLabel?.text = wfMatcher
            UserDefaults.wfMatcher = self.wfMatcher
        }
    }
    
    var previousDefaultUnitIDList: UnitIDList! = UnitIDList() {
        didSet { UserDefaults.previousDefaultUnitIDList = self.previousDefaultUnitIDList}
    }
    var defaultUnitIDList: UnitIDList! = UnitIDList()
    var unitIDList: UnitIDList! = UnitIDList() {
        didSet { UserDefaults.unitIDList = self.unitIDList }
    }
    
    func addHistory(_ aText:String) {
        self.callHistory?.updateContent(content: aText)
    }
    
    func resetHistory() {
        self.callHistory?.reset()
    }
    
    init() {
        loadMainViewSettingsFromMemory()
        loadUnitID()
    }
    
    private weak var adTypeLabel: UILabel?
    private weak var unitIDLabel: UILabel?
    private weak var wfMatcherLabel: UILabel?
    private weak var callHistory: CallHistoryTextView?
    
    func linkMainViewController(_ vc:MainViewController) {
        self.unitIDLabel = vc.unitIDLabel
        self.callHistory = vc.callHistoryTextView
        
        self.unitIDLabel?.text = self.unitID
    }
}

extension UserDefaults {
    static var adType: AdType? {
        get {
            if UserDefaults.standard.object(forKey: "adType") == nil {
                return nil
            }
            
            let raw = UserDefaults.standard.integer(forKey: "adType")
            return AdType(rawValue: raw)
        }
        set {
            if newValue == nil {
                UserDefaults.standard.removeObject(forKey: "adType")
                return
            }
            UserDefaults.standard.set(newValue!.rawValue, forKey: "adType")
        }
    }
    
    static func unitID(forAdType adType:AdType) -> String? {
        if UserDefaults.standard.object(forKey: String(adType.rawValue)+"unitID") == nil {
            return nil
        }
        
        return UserDefaults.standard.string(forKey: String(adType.rawValue)+"unitID")
    }
    
    static func setUnitID(forAdType adType:AdType, unitID:String?) {
        if unitID == nil {
            UserDefaults.standard.removeObject(forKey: String(adType.rawValue)+"unitID")
            return
        }
        UserDefaults.standard.set(unitID, forKey: String(adType.rawValue)+"unitID")
    }
    
    static var wfMatcher: String? {
        get {
            if UserDefaults.standard.object(forKey: "wfMatcher") == nil {
                return nil
            }
            
            return UserDefaults.standard.string(forKey: "wfMatcher")
        }
        set {
            if newValue == nil {
                UserDefaults.standard.removeObject(forKey: "wfMatcher")
            }
            
            UserDefaults.standard.set(newValue, forKey: "wfMatcher")
        }
    }
    
    static var isCustomUnitIDList: Bool? {
        get {
            if UserDefaults.standard.object(forKey: "isCustomUnitIDList") == nil {
                return nil
            }
            
            return UserDefaults.standard.bool(forKey: "isCustomUnitIDList")
        }
        set {
            if newValue == nil {
                UserDefaults.standard.set(newValue, forKey: "isCustomUnitIDList")
            }
            
            UserDefaults.standard.set(newValue, forKey: "isCustomUnitIDList")
            
        }
    }
    
    static var previousDefaultUnitIDList: UnitIDList? {
        get { return UserDefaults.standard.object(forKey: "previousDefaultUnitIDList") as? UnitIDList }
        set { UserDefaults.standard.set(newValue, forKey: "previousDefaultUnitIDList") }
    }
    
    static var unitIDList: UnitIDList? {
        get { return UserDefaults.standard.object(forKey: "unitIDList") as? UnitIDList }
        set { UserDefaults.standard.set(newValue, forKey: "unitIDList") }
    }
}
