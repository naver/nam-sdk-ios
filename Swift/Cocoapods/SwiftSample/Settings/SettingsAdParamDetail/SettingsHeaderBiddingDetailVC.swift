//
//  SettingsHeaderBiddingDetailVC.swift
//  SwiftSample
//
//  Created by USER on 2023/05/08.
//

import UIKit
import GFPSDK

final class SettingsHeaderBiddingDetailVC: BaseTableVC {
    struct Section {
        var title: String
        var rows: [Row] = []
    }

    enum Row: CaseIterable {
        case prebidEnabled
        case prebidAccountId
        case prebidConfigId
        case prebidBidPrice
        case prebidBidPriceAppNexus

        case apsEnabled
        case apsTestMode
        case apsAppKeyList
        case apsSlotInfoList

        var title: String {
            switch self {
            case .prebidEnabled: return "Enabled"
            case .prebidAccountId: return "Account ID"
            case .prebidConfigId: return "Config ID"
            case .prebidBidPrice: return "Bid Price"
            case .prebidBidPriceAppNexus: return "Bid Price AppNexus"

            case .apsEnabled: return "Enabled"
            case .apsTestMode: return "TestMode"
            case .apsAppKeyList: return "Application Key"
            case .apsSlotInfoList: return "Slot UUID"
            }
        }
    }

    var sections: [Section] = [
        Section(title: "Prebid", rows: [
            .prebidEnabled,
            .prebidBidPrice,
            .prebidBidPriceAppNexus,
        ]),
        Section(
            title: "Prebid Acoount ID",
            rows: Array(repeating: .prebidAccountId, count: SettingsManager.shared.prebidAccountIdList.count)
        ),
        Section(
            title: "Prebid Config ID",
            rows: Array(repeating: .prebidConfigId, count: SettingsManager.shared.prebidConfigList.count)
        ),

        Section(title: "Amazon Publisher Services", rows: [
            .apsEnabled,
            .apsTestMode
        ]),
        Section(
            title: "App Key",
            rows: Array(repeating: .apsAppKeyList, count: SettingsManager.shared.apsAppKeyList.count)
        ),
        Section(
            title: "Slot UUID",
            rows: Array(repeating: .apsSlotInfoList, count: SettingsManager.shared.apsSlotInfoList.count)
        ),
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

        switch row {
        case .prebidAccountId, .prebidConfigId, .apsAppKeyList, .apsSlotInfoList:
            return super.tableView(tableView, heightForRowAt: indexPath) * 1.3

        default:
            return super.tableView(tableView, heightForRowAt: indexPath)
        }
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {
        case .prebidEnabled:
            let cell = SwitchCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.prebidEnabled
            } onSwtichChange: { value in
                SettingsManager.shared.prebidEnabled = value
            }
            return cell

        case .prebidAccountId:
            let idx = indexPath.row
            guard idx < SettingsManager.shared.prebidAccountIdList.count else {return BaseCell()}
            let accountId = SettingsManager.shared.prebidAccountIdList[idx]
            let cell = CheckCell()
            cell.configure(withTitle: accountId)
            cell.isSelected = SettingsManager.shared.prebidAccountId == accountId
            return cell

        case .prebidConfigId:
            let idx = indexPath.row
            guard idx < SettingsManager.shared.prebidConfigList.count else {return BaseCell()}
            let configId = SettingsManager.shared.prebidConfigList[idx]
            let cell = CheckCell()
            cell.configure(withTitle: "\(configId.size), \(configId.configId)")
            cell.isSelected = SettingsManager.shared.prebidConfig == configId
            return cell

        case .prebidBidPrice:
            let cell = DoubleValueCell()
            cell.configure(withTitle: row.title) {
                Double(SettingsManager.shared.prebidPrice)
            } onValueChange: { value in
                SettingsManager.shared.prebidPrice = Float(value)
            }
            return cell

        case .prebidBidPriceAppNexus:
            let cell = DoubleValueCell()
            cell.configure(withTitle: row.title) {
                Double(SettingsManager.shared.prebidPriceAppNexus)
            } onValueChange: { value in
                SettingsManager.shared.prebidPriceAppNexus = Float(value)
            }
            return cell

        case .apsEnabled:
            let cell = SwitchCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.apsEnabled
            } onSwtichChange: { value in
                SettingsManager.shared.apsEnabled = value
            }
            return cell

        case .apsTestMode:
            let cell = SwitchCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.apsTestMode
            } onSwtichChange: { value in
                SettingsManager.shared.apsTestMode = value
            }
            return cell

        case .apsAppKeyList:
            let idx = indexPath.row
            let list = SettingsManager.shared.apsAppKeyList
            guard idx < list.count else {return BaseCell()}
            let appKey = list[idx]
            let cell = CheckCell()
            cell.configure(withTitle: appKey)
            cell.isSelected = SettingsManager.shared.apsAppKey == appKey
            return cell

        case .apsSlotInfoList:
            let idx = indexPath.row
            let list = SettingsManager.shared.apsSlotInfoList
            guard idx < list.count else {return BaseCell()}
            let slotInfo = list[idx]
            let cell = CheckCell()
            cell.configure(withTitle: "[\(slotInfo.desc)] (\(slotInfo.width)x\(slotInfo.height), \(slotInfo.slotUUID)")
            cell.isSelected = SettingsManager.shared.apsSlotInfo == slotInfo
            return cell
        }
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {
        case .prebidAccountId:
            let idx = indexPath.row
            let list = SettingsManager.shared.prebidAccountIdList
            guard idx < list.count else {return}
            let selection = list[idx]
            SettingsManager.shared.prebidAccountId = selection

        case .prebidConfigId:
            let idx = indexPath.row
            let list = SettingsManager.shared.prebidConfigList
            guard idx < list.count else {return}
            let selection = list[idx]
            SettingsManager.shared.prebidConfig = selection

        case .apsAppKeyList:
            let idx = indexPath.row
            let list = SettingsManager.shared.apsAppKeyList
            guard idx < list.count else {return}
            let selection = list[idx]
            SettingsManager.shared.apsAppKey = selection

        case .apsSlotInfoList:
            let idx = indexPath.row
            let list = SettingsManager.shared.apsSlotInfoList
            guard idx < list.count else {return}
            let selection = list[idx]
            SettingsManager.shared.apsSlotInfo = selection

        default: break
        }

        tableView.reloadData()
    }
}
