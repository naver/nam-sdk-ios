//
//  SettingsSKANDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/05/02.
//

import UIKit

class SettingsSKANDetailVC: BaseTableVC {

    fileprivate struct Section {
        var title: String
        var rows: [Row]
    }

    private lazy var sections: [Section] = [
        Section(title: "IDFA (ADID as in Android)", rows: [
            .idfa
        ]),
        Section(title: "IDFV", rows:[
            .idfv
        ]),
        Section(title: "SKAdNetwork", rows: [
            .skanAvailability,
            .skanVersion,
            .copyAllskanIds
        ]),
        Section(
            title: "SKAdNetwork Identifiers",
            rows: Array(repeating: .skanId, count: skanIds.count)
        ),
    ]

    fileprivate enum Row: Int, CaseIterable {
        case idfa
        case idfv
        case skanAvailability
        case skanVersion
        case copyAllskanIds
        case skanId

        var title: String {
            switch self {
            case .idfa: return SettingsManager.shared.idfa
            case .idfv: return SettingsManager.shared.idfv
            case .skanAvailability: return "SKAdNetwork"
            case .skanVersion: return "SKAdNetwork Version"
            case .copyAllskanIds: return "Copy all identifiers"
            case .skanId: return ""
            }
        }
    }

    private var skanIds: [String] = SettingsManager.shared.skAdNetworkIdList

    private var rows = Row.allCases

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "AD Identifiers";
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        sections.count
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        sections[section].title
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        sections[section].rows.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {

        case .idfa, .idfv, .copyAllskanIds:
            let cell = ButtonCell()
            cell.configure(withTitle: row.title)
            return cell

        case .skanAvailability:
            let cell = LabelCell()
            cell.configure(withTitle: row.title, label: SettingsManager.shared.skAdNetworkAvailability)
            return cell

        case .skanVersion:
            let cell = LabelCell()
            cell.configure(withTitle: row.title, label: SettingsManager.shared.skAdNetworkVersion)
            return cell

        case .skanId:
            let cell = BaseCell()
            let title = skanIds[indexPath.row]
            cell.configure(withTitle: title)
            return cell
        }
    }


    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {
        case .idfa, .idfv:
            let alert = UIAlertController(title: "Copy to clipboard?", message: nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
            alert.addAction(UIAlertAction(title: "Copy", style: .default, handler: { _ in
                UIPasteboard.general.string = row.title
            }))
            self.present(alert, animated: true, completion: nil)

        case .copyAllskanIds:
            let alert = UIAlertController(title: "Copy to clipboard?", message: nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
            alert.addAction(UIAlertAction(title: "Copy", style: .default, handler: { [weak self] _ in
                guard let self = self else {return}
                UIPasteboard.general.string = self.skanIds.joined(separator: ",")
            }))
            self.present(alert, animated: true, completion: nil)

        default: break
        }
    }
}

extension SettingsSKANDetailVC: UIAlertViewDelegate {

}
