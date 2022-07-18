//
//  MainViewManager+UnitID.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

extension MainViewManager {
    
    func loadSelectionsFromMemory() {
        self.adType = UserDefaults.adType
        if self.adType != nil {
            self.unitID = UserDefaults.unitID(forAdType: self.adType!)
        }
        self.wfMatcher = UserDefaults.wfMatcher
        self.isCustomUnitIDList = UserDefaults.isCustomUnitIDList ?? false
    }
    
    func loadDefaultUnitIDListFromFile() {
        guard let path = Bundle.main.path(forResource: "default_unitID_test", ofType: "plist") else { print("MainViewManager: plist for default Ad Unit IDs not found"); return }
        
        let url = URL(fileURLWithPath: path)
        guard let data = try? Data(contentsOf: url) else { print("MainViewManager - Failed to load default Ad Unit ID data:"); return }
        
        self.defaultUnitIDList = try? PropertyListSerialization.propertyList(from: data, options: [], format: nil) as? [String:[String]]
    }
    
    func refreshCustomUnitIDList() {
        if let listInMemory = UserDefaults.customUnitIDList {
            self.customUnitIDList = listInMemory
            return
        }
        
        copyDefaultUnitIDListToCustom()
    }
    
    private func copyDefaultUnitIDListToCustom() {
        for (k, v) in self.defaultUnitIDList {
            self.customUnitIDList[k] = v.map{$0.copy()} as? [String] ?? [String]()
        }
    }
}
