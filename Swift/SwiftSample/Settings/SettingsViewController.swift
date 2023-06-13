//
//  SettingViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import GFPSDK
import AppTrackingTransparency
import AdSupport
import Network

final class SettingsViewController: BaseTableVC {

    private static let manager: SettingsManager = .shared

    fileprivate struct Section {
        var title: String
        var rows: [Row]
    }

    private var sections: [Section] = [
        Section(title: "SDK_Settings".localized, rows: [
            .phase,
            .userParams,
            .initializeSdk,
            .deduplication,
            .displayAgent,
            .useImageCache,
            .clearImageCache
        ]),
        Section(title: "App_Settings".localized, rows: [
            .darkMode,
            .language,
        ]),
        Section(title: "GFPAdParam Settings", rows: [
            .headerBidding,
            .deviceIp
        ]),
        Section(title: "Ad Request Timeout (60.0 seconds by default)", rows:[
            .timeoutDisplayAd,
            .timeoutVideoAd,
            .timeoutRewardedAd,
            .timeoutInterstitialAd
        ]),
        Section(title: "TestMode_Settings".localized, rows: [
            .testModeGoogle,
            .testModeFacebook,
            .testModeOMID,
            .testModeUnity
        ]),
        Section(title: "Setting_Info".localized, rows: [
            .sdkVersion,
            .deviceAdInfo,
            .attPermission,
            .resetAll
        ])
    ]

    fileprivate enum Row: Int, CaseIterable {
        case darkMode
        case language
        case attPermission

        case phase
        case userParams
        case initializeSdk
        case deduplication
        case displayAgent
        case headerBidding
        case deviceIp
        case useImageCache
        case clearImageCache

        case timeoutDisplayAd
        case timeoutVideoAd
        case timeoutRewardedAd
        case timeoutInterstitialAd

        case testModeFacebook
        case testModeGoogle
        case testModeOMID
        case testModeUnity

        case sdkVersion
        case deviceAdInfo
        case resetAll

        var title : String {
            switch self {
            case .userParams: return "User Params"
            case .initializeSdk: return "Initialize SDK"
            case .language: return "Setting_Language".localized
            case .deduplication: return "Setting_Deduplication".localized
            case .displayAgent: return "Display Agent Type"
            case .useImageCache: return "Image Cache for Native Normal Ad"
            case .clearImageCache: return "Clear Image Cache"

            case .phase: return "Setting_Phase".localized
            case .darkMode: return "Setting_Dark_Mode".localized

            case .headerBidding: return "Header Bidding"
            case .deviceIp: return "Device IP"

            case .timeoutDisplayAd: return "Display"
            case .timeoutVideoAd: return "Video"
            case .timeoutRewardedAd: return "Rewarded"
            case .timeoutInterstitialAd: return "Interstitial"

            case .testModeFacebook: return "Setting_Test_Facebook".localized
            case .testModeGoogle: return "Setting_Test_Google".localized
            case .testModeOMID: return "Setting_Test_OMID".localized
            case .testModeUnity: return "Setting_Test_Unity".localized

            case .sdkVersion: return "App : \(Bundle.currentVersion) - GFPSDK version : \(manager.sdkVersion)"
            case .deviceAdInfo: return "IDFA / IDFV / SKAN"
            case .attPermission: return "ATT Permission"
            case .resetAll: return "Reset All Settings"
            }
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.configure()
    }

    
    //MARK: - Private
    
    func configure() {
        self.title = "Settings";
        if #available(iOS 13.0, *) {
            self.view.backgroundColor = .systemGroupedBackground
        }

        if UIDevice.current.userInterfaceIdiom == .phone {
            self.configureNavBarDoneButton()
        }
    }

    // MARK: - Table view data source
    override func numberOfSections(in tableView: UITableView) -> Int {
        sections.count
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        self.sections[section].title
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        sections[section].rows.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]

        switch row {
        case .phase:
            let cell = SegmentCell()
            cell.configure(
                withTitle: row.title,
                enumType: GFPPhaseType.self) {
                    Self.manager.phase.rawValue - 1
                } onSegmentChange: { value in
                    Self.manager.phase = GFPPhaseType(rawValue: value + 1)
                }
            return cell

        case .userParams:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            return cell

        case .initializeSdk:
            let cell = DetailCell()
            cell.configure(withTitle: row.title, label: SettingsManager.shared.isSdkInitialized ? "Initialized" : "Not Initialized")
            return cell

        case .deduplication:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            cell.label = SettingsManager.shared.dedupEnabled ? "Enabled" : "Disabled"
            return cell

        case .displayAgent:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            cell.label = SettingsManager.shared.displayAgent.title
            return cell

        case .useImageCache:
            let cell = SwitchCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.useImageCache
            } onSwtichChange: { value in
                SettingsManager.shared.useImageCache = value
            }
            return cell

        case .darkMode:
            let cell = SegmentCell()
            cell.configure(
                withTitle: row.title,
                enumType: DarkModeType.self) {
                    Self.manager.darkMode.rawValue - 1
                } onSegmentChange: { segment in
                    Self.manager.darkMode = DarkModeType(rawValue: segment + 1) ?? .system
                }
            return cell

        case .language:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            cell.label = Self.manager.language.title
            return cell

        case .clearImageCache:
            let cell = ButtonCell()
            cell.configure(withTitle: row.title)
            return cell

        case .headerBidding:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            return cell

        case .deviceIp:
            let cell = TextFieldCell()
            cell.configure(withTitle: row.title) {
                SettingsManager.shared.deviceIp
            } onTextChange: { text in
                if #available(iOS 12.0, *) {
                    if IPv4Address(text) != nil {
                        SettingsManager.shared.deviceIp = text
                    }
                } else {
                    SettingsManager.shared.deviceIp = text
                }
                tableView.reloadRows(at: [indexPath], with: .automatic)
            }
            return cell


            // Ad Request Timeout
        case .timeoutDisplayAd:
            let cell = DoubleValueCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.timeout(forType: .displayAd)
                } onValueChange: { value in
                    Self.manager.setTimeout(value, forType: .displayAd)
                }
            return cell

        case .timeoutVideoAd:
            let cell = DoubleValueCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.timeout(forType: .videoAd)
                } onValueChange: { value in
                    Self.manager.setTimeout(value, forType: .videoAd)
                }
            return cell

        case .timeoutRewardedAd:
            let cell = DoubleValueCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.timeout(forType: .rewardedAd)
                } onValueChange: { value in
                    Self.manager.setTimeout(value, forType: .rewardedAd)
                }
            return cell

        case .timeoutInterstitialAd:
            let cell = DoubleValueCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.timeout(forType: .interstitialAd)
                } onValueChange: { value in
                    Self.manager.setTimeout(value, forType: .interstitialAd)
                }
            return cell



            // Test Modes
        case .testModeGoogle:
            let cell = SwitchCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.isTestMode(forType: .DFP)
                } onSwtichChange: { isOn in
                    Self.manager.setTestMode(isOn, forType: .DFP)
                }
            return cell

        case .testModeFacebook:
            let cell = SwitchCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.isTestMode(forType: .FAN)
                } onSwtichChange: { isOn in
                    Self.manager.setTestMode(isOn, forType: .FAN)
                }
            return cell

        case .testModeOMID:
            let cell = SwitchCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.isTestMode(forType: .OMID)
                } onSwtichChange: { isOn in
                    Self.manager.setTestMode(isOn, forType: .OMID)
                }
            return cell

        case .testModeUnity:
            let cell = SwitchCell()
            cell.configure(
                withTitle: row.title) {
                    Self.manager.isTestMode(forType: .unity)
                } onSwtichChange: { isOn in
                    Self.manager.setTestMode(isOn, forType: .unity)
                }
            return cell

            // Info
        case .sdkVersion:
            let cell = BaseCell()
            cell.configure(withTitle: row.title)
            return cell

        case .deviceAdInfo:
            let cell = DetailCell()
            cell.configure(withTitle: row.title)
            return cell

        case .attPermission:
            if SettingsManager.shared.attStatus() == .notDetermined {
                let cell = ButtonCell()
                cell.configure(withTitle: row.title, label: SettingsManager.shared.attStatus().title)
                return cell
            } else {
                let cell = LabelCell()
                cell.configure(withTitle: row.title, label: SettingsManager.shared.attStatus().title)
                return cell
            }

        case .resetAll:
            let cell = ButtonCell()
            cell.configure(withTitle: row.title)
            return cell
        }

    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let section = sections[indexPath.section]
        let row = section.rows[indexPath.row]
        let cell = tableView.cellForRow(at: indexPath) as? DetailCell

        var viewController: UIViewController? = nil

        switch row {
        case .language:
            viewController = SettingsSelectorDetailVC(
                withTitle: row.title,
                enumType: SettingsLanguageType.self) {
                    Self.manager.language
                } onValueChange: { value in
                    Self.manager.language = value
                    cell?.label = value.title
                }

        case .attPermission:
            if #available(iOS 14, *) {
                ATTrackingManager.requestTrackingAuthorization { status in
                    let desc: String = {
                        switch status {
                        case .notDetermined: return "Not Determined"
                        case .restricted: return "Restricted"
                        case .denied: return "Denied"
                        case .authorized: return "Authorized"
                        @unknown default: return "Unknown Status"
                        }}()
                    cell?.label = desc
                    DispatchQueue.main.async {
                        tableView.reloadRows(at: [indexPath], with: .none)
                    }
                }
            } else {
                attNotSupportedAlert()
            }

        case .userParams:
            viewController = SettingsAdParamDetailVC()

        case .initializeSdk:
            viewController = SettingsInitializeDetailVC()

        case .headerBidding:
            viewController = SettingsHeaderBiddingDetailVC()

        case .deduplication:
            viewController = SettingsDedupeDetailVC()

        case .displayAgent:
            viewController = SettingsSelectorDetailVC(
                withTitle: row.title,
                enumType: GFPRenderDisplayAgentType.self) {
                    Self.manager.displayAgent
                } onValueChange: { value in
                    Self.manager.displayAgent = value
                    cell?.label = value.title
                }

        case .clearImageCache:
            SettingsManager.shared.clearImageCache()

        case .deviceAdInfo:
            viewController = SettingsSKANDetailVC()

        case .resetAll:
            resetAlert()

        case .darkMode, .phase, .deviceIp, .useImageCache, .timeoutDisplayAd, .timeoutVideoAd, .timeoutRewardedAd, .timeoutInterstitialAd, .testModeFacebook, .testModeGoogle, .testModeOMID, .testModeUnity, .sdkVersion:
            break
        }

        if let viewController = viewController {
            self.definesPresentationContext = true
            viewController.modalPresentationStyle = .overCurrentContext
            self.navigationController?.pushViewController(viewController, animated: true)
        }
        viewController = nil

        tableView.deselectRow(at: indexPath, animated: true)
    }

    private func resetAlert() {
        let alert = UIAlertController(title: "Reset All Settings?", message: nil, preferredStyle: .actionSheet)

        let cancelAction = UIAlertAction(title: "cancel", style: UIAlertAction.Style.cancel, handler: nil)
        let destructiveAction = UIAlertAction(title: "reset", style: UIAlertAction.Style.destructive){(_) in
            Self.manager.resetAllSettings()
        }

        alert.addAction(cancelAction)
        alert.addAction(destructiveAction)

        self.present(alert, animated: true)
    }

    private func attNotSupportedAlert() {
        let alert = UIAlertController(title: "Apple App Tracking Transperancy is not supported for iOS below 14.0.", message: nil, preferredStyle: .alert)

        let closeAction = UIAlertAction(title: "close", style: UIAlertAction.Style.cancel, handler: nil)

        alert.addAction(closeAction)

        self.present(alert, animated: true)
    }
}
