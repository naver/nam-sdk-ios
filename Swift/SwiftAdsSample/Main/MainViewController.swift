//
//  MainViewController.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

import GFPSDK

final class MainViewController: UIViewController {

    var settingsButton: UIBarButtonItem!
    
    var controlPanel: UIView!
    var unitIDButton: UIButton!
    var unitIDLabel: UILabel!
    var loadButton: UIButton!
    var loadWithoutImpressionButton: UIButton!
    var unloadButton: UIButton!
//    var adTypeOptionsButton: UIButton!
        
    var verticalSplitView: VerticalSplitView!
    
    var adView: UIScrollView!
    var adViewController: UIViewController?
    
    var logsView: UIView!
    var callHistoryTextView: CallHistoryTextView!
    
    var constraintsiPhonePortrait: [NSLayoutConstraint]! = [NSLayoutConstraint]()
    var constraintsiPhoneLandscape: [NSLayoutConstraint]! = [NSLayoutConstraint]()
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    override func viewDidLoad() {
        self.title = MainViewManager.shared.adType?.title
        setupSubviews()
        if (UIDevice.current.userInterfaceIdiom == .pad) {
            self.initiPadSubviews()
        }
        setupButtonTitles()
        setupStyles()
        setupActions()
        MainViewManager.shared.linkMainViewController(self)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        openLogsViewIfVideoAd()
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        if self.unitIDLabel.text == nil {
            self.unitIDLabel.text = "⇦ Select An Unit ID"
        }
        
        if UIDevice.current.userInterfaceIdiom == .phone {
            if UIDevice.current.orientation.isPortrait {
                setupConstraintsiPhonePortrait()
            } else { // isLandscape == true
                setupConstraintsiPhoneLandscape()
            }
        }
    }
    
    private func setupSubviews() {
        self.controlPanel = UIView()
//        self.adTypeOptionsButton = UIButton.gray1
        self.unitIDButton = UIButton.gray1
        self.unitIDLabel = UILabel()
        self.loadButton = UIButton.load
        self.loadWithoutImpressionButton = UIButton.load
        self.unloadButton = UIButton.unload
        self.verticalSplitView = VerticalSplitView()
        self.adView = UIScrollView()
        self.logsView = UIView()
        self.callHistoryTextView = CallHistoryTextView.init(frame: CGRect.zero)
        
        self.view.addSubview(self.controlPanel)
//        self.view.addSubview(self.adTypeOptionsButton)
        self.view.addSubview(self.unitIDButton)
        self.view.addSubview(self.unitIDLabel)
        self.view.addSubview(self.loadButton)
        self.view.addSubview(self.loadWithoutImpressionButton)
        self.view.addSubview(self.unloadButton)
        self.view.addSubview(self.verticalSplitView)
        self.verticalSplitView.setUpperView(self.adView)
        self.verticalSplitView.setLowerView(self.logsView)
        self.logsView.addSubview(self.callHistoryTextView)
        
        self.verticalSplitView.delegate = self
    }
    
    private func setupButtonTitles() {
//        self.adTypeOptionsButton.setTitle("options", for: .normal)
        self.unitIDButton.setTitle("UnitID", for: .normal)
        self.loadButton.setTitle(" Load ", for: .normal)
        self.loadWithoutImpressionButton.setTitle("without impression", for: .normal)
        self.unloadButton.setTitle("Unload", for: .normal)
        
//        self.adTypeOptionsButton.fitSizeTo(fontSize: FontSize)
        self.unitIDButton.fitSizeTo(fontSize: FontSize)
        self.loadButton.fitSizeTo(fontSize: FontSize)
        self.loadWithoutImpressionButton.fitSizeTo(fontSize: FontSize)
        self.unloadButton.fitSizeTo(fontSize: FontSize)
    }
    
    private func openLogsViewIfVideoAd() {
        switch MainViewManager.shared.adType {
        case .rewarded, .interstitial:
            self.verticalSplitView.openLowerView()
        default:
            break
        }
    }
    
    /* iPad-specific */
    var controlPanelExtended: UIView?
    var controlPanelDetailView: ControlPaneliPadDetailView?
    var unitIdVC: UnitIDViewController?
    var settingVC: SettingViewController?
    
    private func initiPadSubviews() {
        self.controlPanelExtended = UIView()
        self.controlPanelDetailView = ControlPaneliPadDetailView()
        self.unitIdVC = UnitIDViewController()
        self.settingVC = SettingViewController()
        
        self.view.addSubview(self.controlPanelExtended!)
        self.view.addSubview(self.controlPanelDetailView!)
        self.addChild(self.unitIdVC!)
        self.addChild(self.settingVC!)
    }
}

extension MainViewController: VerticalSplitViewDelegate {
    func splitterDragged(by: CGFloat) {
        print("test:", adView.frame.maxY, verticalSplitView.splitter.frame.minY, adView.contentSize.height - (adView.frame.maxY - verticalSplitView.splitter.frame.minY), adView.contentSize.height)
        // sticks to adView's content offset's bottom
        if adView.contentOffset.y + adView.frame.height + 60 >= adView.contentSize.height {
            let currentOffset = self.adView.contentOffset
            let newOffsetY = max(currentOffset.y - by, adView.contentSize.height - (verticalSplitView.splitter.frame.minY - adView.frame.minY))
            let newOffset = CGPoint(x: currentOffset.x, y: newOffsetY)
        
            self.adView.setContentOffset(newOffset, animated: false)
        }
    }
}
