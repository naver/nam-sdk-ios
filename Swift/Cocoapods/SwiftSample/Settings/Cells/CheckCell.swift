//
//  SettingsCheckCell.swift
//  SwiftSample
//
//  Created by USER on 2023/04/28.
//

import UIKit


class CheckCell: UITableViewCell {

    static let identifier = UUID().uuidString

    var title: String = "" {
        didSet {
            textLabel?.text = title
        }
    }

    override var isSelected: Bool {
        didSet {
            if isSelected {
                if #available(iOS 13.0, *) {
                    self.accessoryView = UIImageView(image: UIImage(systemName: "checkmark"))
                } else {
                    self.backgroundColor = .systemBlue.withAlphaComponent(0.3)
                }
            } else {
                if #available(iOS 13.0, *) {
                    self.accessoryView = nil
                } else {
                    self.backgroundColor = .clear
                }
            }
        }
    }

    func configure(withTitle title: String) {
        self.title = title
        self.selectionStyle = .default

        if #available(iOS 13.0, *) {
            self.backgroundColor = .secondarySystemGroupedBackground
        } else {
            self.backgroundColor = .clear
        }

        self.textLabel?.minimumScaleFactor = 0.7
        self.textLabel?.numberOfLines = 0
        self.textLabel?.lineBreakMode = .byCharWrapping
    }

    init() {
        super.init(style: .default, reuseIdentifier: Self.identifier)
    }

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
