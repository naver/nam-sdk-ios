//
//  SettingsAdParamDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/04/25.
//

import UIKit
import GFPSDK

class SettingsAdParamDetailVC: BaseTableVC {

    fileprivate enum Row: Int, CaseIterable {
        case gender
        case yob
        case country
        case userId

        var title: String {
            switch self {
            case .gender: return "Gender"
            case .yob: return "Year of Birth"
            case .country: return "Country Code"
            case .userId: return "User ID"
            }
        }

        var cell: UITableViewCell {
            switch self {
            case .gender:
                let cell = SegmentCell()
                cell.configure(
                    withTitle: self.title,
                    enumType: GFPUserParamGenderType.self) {
                        SettingsManager.shared.gender.rawValue
                    } onSegmentChange: { gender in
                        SettingsManager.shared.gender = GFPUserParamGenderType(rawValue: gender) ?? .female
                    }
                return cell

            case .yob:
                let cell = DoubleValueCell()
                cell.configure(
                    withTitle: self.title) {
                        Double(SettingsManager.shared.yearOfBirth)
                    } onValueChange: { value in
                        let value = UInt(value)
                        SettingsManager.shared.yearOfBirth = value
                    }
                cell.maximumFractionDigits = 0
                return cell

            case .country:
                let cell = TextFieldCell()
                cell.configure(
                    withTitle: self.title) {
                        SettingsManager.shared.userCountryCode
                    } onTextChange: { text in
                        SettingsManager.shared.userCountryCode = text
                    }
                return cell

            case .userId:
                let cell = TextFieldCell()
                cell.configure(
                    withTitle: self.title) {
                        SettingsManager.shared.userID
                    } onTextChange: { text in
                        SettingsManager.shared.userID = text
                    }
                return cell
            }
        }
    }

    fileprivate var rows = Row.allCases

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "User Params";
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        rows.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let row = rows[indexPath.row]
        return row.cell
    }
}
