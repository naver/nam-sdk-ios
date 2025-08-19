//
//  SettingsSelectorDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/04/27.
//

import UIKit

final class SettingsSelectorDetailVC<EnumType: SettingsEnumProtocol>: BaseTableVC {

    private var valueProvider: (() -> EnumType)

    private var onValueChange: ((EnumType) -> Void)

    var rows: [EnumType]

    init(
        withTitle title: String,
        enumType: EnumType.Type,
        valueProvider: @escaping (() -> EnumType),
        onValueChange: @escaping ((EnumType) -> Void)
    ) {
        rows = EnumType.allCases as! [EnumType]
        self.valueProvider = valueProvider
        self.onValueChange = onValueChange

        super.init(nibName: nil, bundle: nil)

        self.title = title
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        rows.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let row = rows[indexPath.row]
        let cell = CheckCell()
        cell.configure(withTitle: row.title)

        let initialValue = valueProvider()
        if row == initialValue {
            cell.isSelected = true
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        let row = rows[indexPath.row]
        let cell = tableView.cellForRow(at: indexPath)
        cell?.isSelected = true

        tableView.deselectRow(at: indexPath, animated: true)

        onValueChange(row)

        let indexPaths = Array(0...tableView.numberOfRows(inSection: indexPath.section)).map { IndexPath(row: $0, section: indexPath.section) }
        tableView.reloadRows(at: indexPaths, with: .automatic)
    }
}
