//
//  MainViewManager+UnitID.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

extension MainViewManager {
    
    func loadMainViewSettingsFromMemory() {
        self.adType = UserDefaults.adType
        if self.adType != nil {
            self.unitID = UserDefaults.unitID(forAdType: self.adType!)
        }
        self.wfMatcher = UserDefaults.wfMatcher
    }
    
    func loadUnitID() {
        self.defaultUnitIDList = loadDefaultUnitIDListFromFile()
        self.previousDefaultUnitIDList = UserDefaults.previousDefaultUnitIDList
        
        if self.previousDefaultUnitIDList != nil && self.defaultUnitIDList.isEqual(to: self.previousDefaultUnitIDList) {
            self.unitIDList = UserDefaults.unitIDList
            if self.unitIDList == nil {
                self.unitIDList = self.defaultUnitIDList
            }
        } else {
            self.unitIDList = self.defaultUnitIDList
            self.previousDefaultUnitIDList = self.defaultUnitIDList
            
            guard let adType = self.adType else { return }
            guard let unitID = self.unitID else { return }
            if !self.unitIDList[adType.title]!.contains(unitID) {
                self.unitID = nil
            }
        }
    }
    
    private func loadDefaultUnitIDListFromFile() -> UnitIDList? {
        guard let path = Bundle.main.path(forResource: "AdUnitIDList", ofType: "plist") else { print("MainViewManager: plist for default Ad Unit IDs not found"); return nil }
        
        let url = URL(fileURLWithPath: path)
        guard let data = try? Data(contentsOf: url) else { print("MainViewManager - Failed to load default Ad Unit ID data:"); return nil }
        
        return try? PropertyListSerialization.propertyList(from: data, options: [], format: nil) as? [String:[String]]
    }
}
