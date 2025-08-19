//
//  CallHistoryTextView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import GFPSDK

class CallHistoryTextView: UITextView {

    private var contentList: [String] = []
    
    override init(frame: CGRect, textContainer: NSTextContainer?) {
        super.init(frame: frame, textContainer: textContainer)
        
        setupView()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //MARK: - Public
    
    func append(content: String) {
        self.contentList.append(content)
        
        var newContent = ""
        for (index, string) in self.contentList.enumerated() {
            newContent.append("\(index) : \(string)\n")
        }
        
        self.text = newContent
        sizeToFit()
    }
    
    func reset() {
        self.contentList = []
        self.text = ""
    }
    
    //MARK: - Private
    private func setupView() {
        self.isEditable = false
        self.isScrollEnabled = true
        self.textAlignment = .left
        self.font = UIFont.systemFont(ofSize: 17.0)
    }
    
    
}
