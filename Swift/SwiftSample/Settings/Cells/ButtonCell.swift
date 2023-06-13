//
//  ButtonCell.swift
//  SwiftSample
//
//  Created by USER on 2023/05/02.
//

import Foundation

class ButtonCell: LabelCell {

    override func configure(withTitle title: String) {
        super.configure(withTitle: title)

        configure()
    }

    override func configure(withTitle title: String, label: String = "") {
        super.configure(withTitle: title, label: label)

        configure()
    }

    private func configure() {
        selectionStyle = .default
        textLabel?.textColor = .systemBlue
    }
}
