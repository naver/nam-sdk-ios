//
//  UnitIDList.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation

typealias UnitIDList = [String : [String]]

extension UnitIDList {
    func isEqual(to: UnitIDList) -> Bool {
        var checked = 0
        for (k, v) in to {
            if self[k] == v {
                checked += 1
            } else {
                return false
            }
        }
        
        if checked != self.count {
            return false
        } else {
            return true
        }
    }
}
