//
//  SettingsDedupeDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/05/02.
//

import UIKit

class SettingsDedupeDetailVC: BaseTableVC {

    struct Section {
        var title: String
        var rows: [Row]
    }

    enum Row: CaseIterable {
        case enable
        case slider

        var title: String {
            switch self {
            case .enable: return "Enabled"
            case .slider: return "Recommended 2~5"
            }
        }
    }

    private var sections: [Section] = [
        Section(title: "", rows: [.enable]),
        Section(title: "Minimum Sequence of Non-duplicate Ads", rows: [.slider])
    ]

    private var rows = Row.allCases

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "Ad Deduplication"
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        sections.count
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        let section = sections[section]
        return section.title
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        sections[section].rows.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {

        case .enable:
            let cell = SwitchCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.dedupEnabled
            } onSwtichChange: { value in
                SettingsManager.shared.dedupEnabled = value
            }
            return cell

        case .slider:
            let cell = SliderCell()
            cell.configure(
                withTitle: row.title,
                range: 2.0...5.0,
                step: 1
            ) {
                Float(SettingsManager.shared.dedupNumber)
            } onSliderChange: { value in
                SettingsManager.shared.dedupNumber = Int(value)
            }
            return cell

        }
    }
}
