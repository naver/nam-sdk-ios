//
//  ContentCell.swift
//  SwiftSample
//
//  Created by USER on 2023/05/12.
//

import UIKit

class MockContentCell: UITableViewCell {

    static let identifier = UUID().uuidString

    init() {
        super.init(style: .default, reuseIdentifier: Self.identifier)
    }
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func configure(withIndexPath indexPath: IndexPath) {
        self.textLabel?.text = "Section: \(indexPath.section), Row: \(indexPath.row)"
        self.selectionStyle = .none
    }
}
