//
//  SettingsDetailCell.swift
//  SwiftSample
//
//  Created by USER on 2023/04/25.
//

import UIKit
import SnapKit


class DetailCell: UITableViewCell {

    static let identifier = UUID().uuidString

    var title: String = "" {
        didSet {
            textLabel?.text = title
        }
    }

    var label: String = "" {
        didSet {
            labelView.text = label
        }
    }

    private var labelView = UILabel()

    func configure(withTitle title: String, label: String = "") {
        self.title = title
        self.label = label

        configure()
    }

    private func configure() {
        self.selectionStyle = .default
        if #available(iOS 13.0, *) {
            self.backgroundColor = .secondarySystemGroupedBackground
            self.labelView.textColor = .secondaryLabel
        }

        var imageView = UIImageView()
        if #available(iOS 13.0, *) {
            imageView = UIImageView(image: UIImage(systemName: "chevron.right"))
            imageView.tintColor = .secondaryLabel
        }
        self.accessoryView = imageView

        imageView.addSubview(self.labelView)
        self.labelView.snp.makeConstraints { make in
            make.centerY.equalTo(imageView)
            make.right.equalTo(imageView.snp.left).offset(-5)
        }
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
    }

    init() {
        super.init(style: .default, reuseIdentifier: Self.identifier)
    }
}
