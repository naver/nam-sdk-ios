//
//  NibLoadable.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation


protocol NibLoadable: AnyObject {
    
    static var nibId: String { get }

}


extension NibLoadable {
    
    static var nibId: String {
        return String(describing: self)
    }
    
    var nibId: String {
        return String(describing: type(of: self))
    }
    
}

