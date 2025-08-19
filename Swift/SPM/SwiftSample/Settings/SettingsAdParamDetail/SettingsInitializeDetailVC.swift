//
//  SettingsInitializeDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/05/08.
//

import UIKit

final class SettingsInitializeDetailVC: BaseTableVC {

    struct Section {
        var title: String
        var rows: [Row]
    }

    enum Row: CaseIterable {
        case isInit
        case initNaver
        case initLineWebtoon
        case initVapp
        case initZepeto
        case initSnow
        case errorMessage

        var title: String {
            switch self {
            case .isInit: return "SDK initialized"
            case .initNaver: return "Naver Sample"
            case .initLineWebtoon: return "LineWebtoon Dev"
            case .initVapp: return "Vapp"
            case .initZepeto: return "Zepepto"
            case .initSnow: return "Snow"
            case .errorMessage: return ""
            }
        }
    }

    private var sections: [Section] = [
        Section(title: "", rows: [
            .isInit
        ]),
        Section(title: "Request SDK intialization", rows: [
            .initNaver,
            .initLineWebtoon,
            .initVapp,
            .initZepeto,
            .initSnow,
        ]),
        Section(title: "Error Message", rows: [
            .errorMessage
        ])
    ]

    override func numberOfSections(in tableView: UITableView) -> Int {
        sections.count
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        sections[section].title
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        sections[section].rows.count
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        if row == .errorMessage {
            return 200
        } else {
            return super.tableView(tableView, heightForRowAt: indexPath)
        }
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {
        case .isInit:
            let cell = LabelCell()
            cell.configure(withTitle: row.title, label: SettingsManager.shared.isSdkInitialized ? "Yes" : "No")
            return cell

        case .initNaver, .initLineWebtoon, .initVapp, .initZepeto, .initSnow:
            let label = publisherCd(forRow: row)?.rawValue ?? ""
            let cell = ButtonCell()
            cell.configure(withTitle: row.title, label: label)
            return cell

        case .errorMessage:
            let cell = BaseCell()
            cell.configure(withTitle: SettingsManager.shared.initializeErrorDesc)
            return cell
        }
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]
        let cell = tableView.cellForRow(at: indexPath)
        tableView.deselectRow(at: indexPath, animated: true)

        if let publisherCd = publisherCd(forRow: row) {
            SettingsManager.shared.initializeSDK(withPublisherCd: publisherCd) { error in
                DispatchQueue.main.async {
                    tableView.reloadRows(at: [
                        .init(row: 0, section: 0),
                        .init(row: 0, section: 2)
                    ], with: .automatic)
                }
            }
        }
    }

    private func publisherCd(forRow: Row) -> PublisherCode? {
        switch forRow {
        case .initNaver: return .naverSample
        case .initLineWebtoon: return .lineWebtoonDev
        case .initVapp: return .vapp
        case .initZepeto: return .zepeto
        case .initSnow: return .snow
        default: return nil
        }
    }
}
