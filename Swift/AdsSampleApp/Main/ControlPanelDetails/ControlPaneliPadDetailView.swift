//
//  ControlPaneliPadDetailView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

class ControlPaneliPadDetailView: UIView {
    private weak var presentingView: UIView?
    
    required init(coder aDecoder: NSCoder) {
        fatalError("This class does not support NSCoding")
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    convenience init() {
        self.init(frame: CGRect.zero)
    }
    
    public func present(_ view: UIView?) {
        if (view == nil) {
            return
        }
        if (self.presentingView != nil) {
            self.presentingView!.removeFromSuperview()
            self.presentingView = nil
        }
        self.presentingView = view
        self.addSubview(self.presentingView!)
        self.presentingView!.translatesAutoresizingMaskIntoConstraints = false
        self.presentingView!.topAnchor.constraint(equalTo: self.topAnchor, constant: 0.5).isActive = true
        self.presentingView!.bottomAnchor.constraint(equalTo: self.bottomAnchor).isActive = true
        self.presentingView!.leftAnchor.constraint(equalTo: self.leftAnchor).isActive = true
        self.presentingView!.rightAnchor.constraint(equalTo: self.rightAnchor).isActive = true
    }
    
}
