//
//  SettingsCell.swift
//  SwiftSample
//
//  Created by SettingsCell on 2023/04/17.
//

import UIKit
import SnapKit


class BaseCell: UITableViewCell {

    var title: String = "" {
        didSet {
            textLabel?.text = title
        }
    }

    func configure(withTitle title: String) {
        self.title = title
        self.selectionStyle = .none
        if #available(iOS 13.0, *) {
            self.backgroundColor = .secondarySystemGroupedBackground
        }
    }

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
