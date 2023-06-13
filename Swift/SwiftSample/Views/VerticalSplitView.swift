//
//  VerticalSplitView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import SnapKit

protocol VerticalSplitViewDelegate {
    func splitterDragged(by: CGFloat)
}

typealias CGFloatSplitMargin = CGFloat

extension CGFloatSplitMargin {
    static let defaultClosedHeight: CGFloatSplitMargin = 30
    static let defaultOpenHeight: CGFloatSplitMargin = 40
}

final class VerticalSplitView: UIView {

    var delegate: VerticalSplitViewDelegate?

    var splitterTopMargin: CGFloatSplitMargin = .defaultClosedHeight
    var splitterBottomMargin: CGFloatSplitMargin = .defaultOpenHeight
    var splitterClosedHeight: CGFloatSplitMargin = .defaultClosedHeight
    var splitterOpenHeight: CGFloatSplitMargin = .defaultOpenHeight

    private var splitterCenterY: ConstraintMakerEditable!
    private var storedSplitterOffset: CGFloatSplitMargin = .defaultOpenHeight
    var splitterOffset: CGFloat {
        get {
            self.storedSplitterOffset
        }
        set {
            var offset = newValue
            offset = min(self.frame.height - self.splitterTopMargin, offset) // Reached top.
            offset = max(self.splitterBottomMargin, offset) // Reached bottom.
            self.storedSplitterOffset = offset
            self.splitterCenterY.constraint.update(inset: offset)
        }
    }

    private(set) weak var upperView: UIView?
    private(set) weak var lowerView: UIView?

    private(set) var splitter: UIView!
    private var dragAffordance: UIView!
    
    required init(coder aDecoder: NSCoder) {
        fatalError("This class does not support NSCoding")
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    
        self.splitter = UIView()
        self.dragAffordance = UIView()
        self.addSubview(self.splitter)
        self.splitter.addSubview(self.dragAffordance)

        self.configure()
        self.configureActions()
    }
    
    convenience init() {
        self.init(frame: CGRect.zero)
    }

    private func configure() {
        self.splitter.snp.makeConstraints { make in
            make.height.equalTo(DraggableSplitterHeight)
            make.left.right.equalTo(self)
            self.splitterCenterY = make.centerY.equalTo(self.snp.bottom).inset(self.splitterClosedHeight)
        }

        self.dragAffordance.snp.makeConstraints { make in
            make.centerX.centerY.equalTo(self.splitter)
            make.width.equalTo(DragAffordanceWidth)
            make.height.equalTo(DragAffordanceHeight)
        }

        self.dragAffordance.layer.cornerRadius = DragAffordanceCornerRadius
        self.dragAffordance.backgroundColor = DragAffordanceColor
        self.splitter.backgroundColor = .Background.primary
    }
    
    public func setUpperView(_ view:UIView) {
        self.upperView?.removeFromSuperview()
        self.addSubview(view)
        self.upperView = view

        view.snp.remakeConstraints { make in
            make.top.left.right.equalTo(self)
            make.bottom.equalTo(self.splitter.snp.top)
        }
    }
    
    public func setLowerView(_ view:UIView) {
        self.lowerView?.removeFromSuperview()
        self.addSubview(view)
        self.lowerView = view

        view.snp.remakeConstraints { make in
            make.bottom.left.right.equalTo(self)
            make.top.equalTo(self.splitter.snp.bottom)
        }
    }
    
    public func removeUpperView() {
        self.upperView?.removeFromSuperview()
        self.upperView = nil
    }
    
    public func removeLowerView() {
        self.lowerView?.removeFromSuperview()
        self.lowerView = nil
    }
    
    public func openLowerView() {
        let movedY = self.frame.height - self.splitterBottomMargin

        self.splitterOffset = movedY
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
    }
    
    public func closeLowerView() {
        let movedY = self.splitterBottomMargin

        self.splitterOffset = movedY
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
    }
}

private let DraggableSplitterHeight: CGFloat = 29
private let DragAffordanceWidth: CGFloat = 32
private let DragAffordanceHeight: CGFloat = 5.5
private let DragAffordanceCornerRadius: CGFloat = 2.3
private let DragAffordanceColor = UIColor(white:0.6, alpha: 1)
private let SplitterInitialY:CGFloat = 100

extension VerticalSplitView {
    private func configureActions() {
        let dragSplitterRecognizer = UIPanGestureRecognizer(target: self, action: #selector(dragSplitter(_:)))
        self.splitter.addGestureRecognizer(dragSplitterRecognizer)
        
        let openOrCloseBottomViewRecognizer = UITapGestureRecognizer(target: self, action: #selector(openOrCloseBottomView(_:)))
        self.splitter.addGestureRecognizer(openOrCloseBottomViewRecognizer)
    }
    
    @IBAction private func dragSplitter(_ sender: UIPanGestureRecognizer) {
        let gestureY = sender.location(in: self).y

        self.splitterOffset = self.frame.height - gestureY

        if let delegate = self.delegate {
            let movedOffset = (self.splitterOffset - self.splitter.frame.height/2) - self.upperView!.frame.height
            if movedOffset != 0 {
                delegate.splitterDragged(by: movedOffset)
            }
        }
        
        self.layoutIfNeeded()
    }
    
    @IBAction private func openOrCloseBottomView(_ sender: UITapGestureRecognizer) {
        let gestureY = self.splitterOffset

        if gestureY == self.splitterClosedHeight { // Open the lower view
            self.splitterOffset = self.frame.height - self.splitterOpenHeight
        } else { // Close the lower view
            self.splitterOffset = self.splitterClosedHeight
        }
        
        UIView.animate(withDuration: 0.2, delay: 0, usingSpringWithDamping: 1, initialSpringVelocity: 0, options: .curveEaseOut, animations: {
            self.layoutIfNeeded()
        }) { _ in }
        
    }
}
