//
//  VerticalSplitView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

protocol VerticalSplitViewDelegate {
    func splitterDragged(by: CGFloat)
}

final class VerticalSplitView: UIView {
    
    var delegate: VerticalSplitViewDelegate?
    
    private(set) weak var upperView: UIView?
    private(set) weak var lowerView: UIView?
    
    private(set) var splitter: UIView!
    private var dragAffordance: UIView!

    private(set) var splitterCenterY: NSLayoutConstraint!
    
    private var isSplitterInitialPos: Bool = true
    
    required init(coder aDecoder: NSCoder) {
        fatalError("This class does not support NSCoding")
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    
        self.splitter = UIView()
        self.dragAffordance = UIView()
        self.addSubview(self.splitter)
        self.splitter.addSubview(self.dragAffordance)
        
        self.setupLayout()
        self.addActions()
    }
    
    convenience init() {
        self.init(frame: CGRect.zero)
    }
    
    public func setUpperView(_ view:UIView) {
        self.upperView?.removeFromSuperview()
        self.addSubview(view)
        self.upperView = view
        setupLayout()
    }
    
    public func setLowerView(_ view:UIView) {
        self.lowerView?.removeFromSuperview()
        self.addSubview(view)
        self.lowerView = view
        setupLayout()
    }
    
    public func removeUpperView() {
        self.upperView?.removeFromSuperview()
        self.upperView = nil
        setupLayout()
    }
    
    public func removeLowerView() {
        self.lowerView?.removeFromSuperview()
        self.lowerView = nil
        setupLayout()
    }
    
    public func openLowerView() {
        let movedY = -(self.frame.height - SplitterTopMargin)

        self.splitterCenterY.constant = movedY
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
        
        if self.isSplitterInitialPos == true {
            self.isSplitterInitialPos = false
        }
    }
    
    public func closeLowerView() {
        let movedY = -(self.frame.height - SplitterTopMargin)

        self.splitterCenterY.constant = movedY
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
    }
}

let DraggableSplitterHeight: CGFloat = 29 * GlobalLayoutScale
let DragAffordanceWidth: CGFloat = 32 * GlobalLayoutScale
let DragAffordanceHeight: CGFloat = 5.5 * GlobalLayoutScale
let DragAffordanceCornerRadius: CGFloat = 2.3 * GlobalLayoutScale
let DragAffordanceColor = UIColor(white:0.6, alpha: 1)
let SplitterTopMargin:CGFloat = 30 * GlobalLayoutScale
let SplitterBottomMargin:CGFloat = 40 * GlobalLayoutScale
let SplitterInitialY:CGFloat = 100 * GlobalLayoutScale

extension VerticalSplitView {
    private func setupLayout() {
        clearAutoLayoutContraints()
        enableAutoLayoutProgrammatically()
        setupAutoLayouts()
        setupAppearances()
    }
    
    private func clearAutoLayoutContraints() {
        self.splitter.removeConstraints(self.splitter.constraints)
        self.dragAffordance.removeConstraints(self.dragAffordance.constraints)
        self.upperView?.removeConstraints(self.upperView?.constraints ?? [])
        self.lowerView?.removeConstraints(self.lowerView?.constraints ?? [])
    }
    
    private func enableAutoLayoutProgrammatically() {
        self.splitter.translatesAutoresizingMaskIntoConstraints = false
        self.dragAffordance.translatesAutoresizingMaskIntoConstraints = false
        self.upperView?.translatesAutoresizingMaskIntoConstraints = false
        self.lowerView?.translatesAutoresizingMaskIntoConstraints = false
    }
    
    private func setupAppearances() {
        self.dragAffordance.isUserInteractionEnabled = false
        self.dragAffordance.backgroundColor = DragAffordanceColor
        self.dragAffordance.centerXAnchor.constraint(equalTo: self.splitter.centerXAnchor).isActive = true
        self.dragAffordance.centerYAnchor.constraint(equalTo: self.splitter.centerYAnchor).isActive = true
        self.dragAffordance.widthAnchor.constraint(equalToConstant: DragAffordanceWidth).isActive = true
        self.dragAffordance.heightAnchor.constraint(equalToConstant: DragAffordanceHeight).isActive = true
        self.dragAffordance.layer.cornerRadius = DragAffordanceCornerRadius
    }
    
    private func setupAutoLayouts() {
        self.splitter.heightAnchor.constraint(equalToConstant: DraggableSplitterHeight).isActive = true
        self.splitter.leftAnchor.constraint(equalTo: self.leftAnchor).isActive = true
        self.splitter.rightAnchor.constraint(equalTo: self.rightAnchor).isActive = true
        self.splitterCenterY = self.splitter.centerYAnchor.constraint(equalTo: self.bottomAnchor, constant:-SplitterInitialY)
        self.splitterCenterY.isActive = true
        
        self.upperView?.topAnchor.constraint(equalTo: self.topAnchor).isActive = true
        self.upperView?.leftAnchor.constraint(equalTo: self.leftAnchor).isActive = true
        self.upperView?.rightAnchor.constraint(equalTo: self.rightAnchor).isActive = true
        self.upperView?.bottomAnchor.constraint(equalTo: self.splitter.topAnchor).isActive = true
        
        self.lowerView?.topAnchor.constraint(equalTo: self.splitter.bottomAnchor).isActive = true
        self.lowerView?.leftAnchor.constraint(equalTo: self.leftAnchor).isActive = true
        self.lowerView?.rightAnchor.constraint(equalTo: self.rightAnchor).isActive = true
        self.lowerView?.bottomAnchor.constraint(equalTo: self.bottomAnchor).isActive = true
    }
}

extension VerticalSplitView {
    private func addActions() {
        let dragSplitterRecognizer = UIPanGestureRecognizer(target: self, action: #selector(dragSplitter(_:)))
        self.splitter.addGestureRecognizer(dragSplitterRecognizer)
        
        let openOrCloseBottomViewRecognizer = UITapGestureRecognizer(target: self, action: #selector(openOrCloseBottomView(_:)))
        self.splitter.addGestureRecognizer(openOrCloseBottomViewRecognizer)
    }
    
    @IBAction private func dragSplitter(_ sender: UIPanGestureRecognizer) {
        if self.isSplitterInitialPos == true {
            self.isSplitterInitialPos = false
        }
        
        let gestureY = sender.location(in: self).y
        
        let movedY: CGFloat
        if (gestureY < SplitterTopMargin) { // Reached top.
            movedY = SplitterTopMargin
        } else if (self.frame.height - SplitterBottomMargin < gestureY) { // Reached bottom.
            movedY = self.frame.height - SplitterBottomMargin
        } else { // Splitter is within movable area.
            movedY = gestureY
        }
        
        self.splitterCenterY.constant = -(self.frame.height - movedY) // Offset from the bottom anchor of self
        
        if self.delegate != nil {
            let movedOffset = (movedY - self.splitter.frame.height/2) - self.upperView!.frame.height
            if movedOffset != 0 {
                self.delegate!.splitterDragged(by: movedOffset)
            }
        }
        
        self.layoutIfNeeded()
    }
    
    @IBAction private func openOrCloseBottomView(_ sender: UITapGestureRecognizer) {
        if self.isSplitterInitialPos == true {
            self.isSplitterInitialPos = false
        }
        
        let gestureY = self.splitterCenterY.constant
        
        let movedY: CGFloat
        if (self.isSplitterInitialPos || gestureY >= -SplitterBottomMargin) { // Open the lower view
            movedY = -(self.frame.height - SplitterTopMargin)
        } else { // Close the lower view
            movedY = -SplitterBottomMargin
        }
        
        self.splitterCenterY.constant = movedY
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
        
    }
}
