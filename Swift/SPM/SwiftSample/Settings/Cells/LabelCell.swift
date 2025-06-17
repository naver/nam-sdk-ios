//
//  LabelCell.swift
//  SwiftSample
//
//  Created by USER on 2023/05/02.
//

import UIKit

class LabelCell: BaseCell {

    var label: String = "" {
        didSet {
            labelView.text = label
        }
    }

    private(set) var labelView = UILabel()

    func configure(withTitle title: String, label: String = "") {
        super.configure(withTitle: title)
        self.label = label

        if #available(iOS 13.0, *) {
            self.labelView.textColor = .secondaryLabel
        }

        labelView.sizeToFit()
        self.accessoryView = labelView
    }

}

