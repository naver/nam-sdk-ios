//
//  AdControlVC.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit
import SnapKit

import GFPSDK

final class AdControlVC: UIViewController {

    lazy var vm: AdControlVC.ViewModel = .shared

    var adType: AdType

    var settingsButton: UIBarButtonItem!

    let controlVC = UIViewController()

    let controlStack = UIStackView()

    let unitIdStack = UIStackView()
    let unitIdButton = UIButton.gray1(withTitle: "UnitID")
    let unitIdLabel = UILabel()
    //    var adTypeSpecificOptionsButton = UIButton.gray1

    let loadButtonsStack = UIStackView()
    let loadButton = UIButton.load(withTitle: " Load ")
    let loadWithoutImpressionButton = UIButton.load(withTitle: "out of visibility")
    let resetButton = UIButton.reset(withTitle: "Reset")

    let verticalSplitView = VerticalSplitView()
    
    let adContainerScrollView = UIScrollView()

    weak var adViewController: UIViewController?

    let logsView = UIView()
    let callHistoryTextView = CallHistoryTextView()

    init(adType: AdType) {
        self.adType = adType
        super.init(nibName: nil, bundle: nil)
        self.title = adType.title
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        vm.configure(withViewController: self, adType: self.adType)
        configureViews()
        if UIDevice.current.userInterfaceIdiom == .pad {
            configureiPadViews()
        }
        configureLayout()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        configureSpliiterView()
    }

    private func configureSpliiterView() {
        switch vm.adType {
        case .rewarded, .interstitial:
            self.verticalSplitView.openLowerView()
        case .tableViewAd:
            self.verticalSplitView.splitterClosedHeight = 35
            self.verticalSplitView.closeLowerView()
        default:
            break
        }
    }

    private func configureViews() {
        self.navigationItem.rightBarButtonItem = self.settingsButton

        self.addChild(self.controlVC)
        self.view.addSubview(self.controlVC.view)
        self.controlVC.view.addSubview(self.controlStack)
        self.view.addSubview(self.verticalSplitView)
        self.verticalSplitView.setUpperView(self.adContainerScrollView)
        self.verticalSplitView.setLowerView(self.logsView)
        self.logsView.addSubview(self.callHistoryTextView)

        self.view.backgroundColor = .Background.primary

        self.controlStack.backgroundColor = .Background.primary
        self.controlStack.axis = .vertical
        self.controlStack.alignment = .center // axis 와 수직인 방향
        self.controlStack.spacing = 15.0
        [self.unitIdStack,
         self.loadButtonsStack
        ].forEach {
            self.controlStack.addArrangedSubview($0)
        }

        self.unitIdStack.axis = .horizontal
        self.unitIdStack.alignment = .center
        self.unitIdStack.distribution = .fill
        self.unitIdStack.isLayoutMarginsRelativeArrangement = true
        self.unitIdStack.layoutMargins = .init(top: 0, left: 10, bottom: 0, right: 10)
        self.unitIdStack.spacing = 10.0
        [self.unitIdButton,
         self.unitIdLabel,
//         self.adTypeSpecificOptionsButton,
        ].forEach {
            self.unitIdStack.addArrangedSubview($0)
        }

        [self.loadButton,
         self.loadWithoutImpressionButton,
         self.resetButton,
        ].forEach {
            self.loadButtonsStack.addArrangedSubview($0)
        }
        self.loadButtonsStack.axis = .horizontal
        self.loadButtonsStack.alignment = .center
        self.loadButtonsStack.distribution = .equalSpacing
        self.loadButtonsStack.spacing = 10.0


        self.adContainerScrollView.backgroundColor = .Background.secondary
        self.logsView.backgroundColor = .Background.secondary
        self.callHistoryTextView.backgroundColor = .Background.secondary

        self.verticalSplitView.delegate = self
    }
    
    /* iPad-specific */
    let splitVC = UISplitViewController()
    var unitIdVC: UINavigationController?
    var settingsVC: UINavigationController?
    
    private func configureiPadViews() {
        let unitIdVC = UINavigationController(rootViewController: UnitIDViewController(adControlViewModel: vm))
        self.unitIdVC = unitIdVC
        let settingsVC = UINavigationController(rootViewController: SettingsViewController())
        self.settingsVC = settingsVC

        self.addChild(self.splitVC)
        self.view.addSubview(self.splitVC.view)
        self.splitVC.view.backgroundColor = .Background.primary
        self.splitVC.preferredDisplayMode = .oneBesideSecondary
        self.splitVC.preferredPrimaryColumnWidthFraction = 1.5/3.0
        self.splitVC.viewControllers = [
            self.controlVC,
            unitIdVC
        ]
    }

    private func configureLayout() {
        self.unitIdButton.snp.makeConstraints { make in
            make.left.equalTo(self.view.safeAreaLayoutGuide).inset(10)
            let width = self.unitIdButton.sizeThatFits(.init(width: 1000, height: 1000)).width
            make.width.equalTo(width)
        }

        self.controlStack.snp.makeConstraints { make in
            make.centerY.left.right.equalTo(self.controlVC.view)
        }

        self.callHistoryTextView.snp.makeConstraints { make in
            make.left.right.top.bottom.equalTo(logsView)
        }

        if UIDevice.current.userInterfaceIdiom == .phone {
            self.controlVC.view.snp.makeConstraints { make in
                make.top.left.right.equalTo(self.view.safeAreaLayoutGuide)
                make.height.equalTo(self.controlStack).offset(10)
            }

            self.verticalSplitView.snp.makeConstraints { make in
                make.top.equalTo(controlVC.view.snp.bottom)
                make.left.right.bottom.equalTo(self.view.safeAreaLayoutGuide)
            }

            self.verticalSplitView.splitterClosedHeight = 300
            self.view.layoutSubviews()
            self.verticalSplitView.splitterOffset = 300

        } else if UIDevice.current.userInterfaceIdiom == .pad {
            self.splitVC.view.snp.makeConstraints { make in
                make.top.left.right.equalTo(self.view.safeAreaLayoutGuide)
                make.height.equalTo(self.view.safeAreaLayoutGuide.layoutFrame.height * 0.5)
            }

            self.verticalSplitView.snp.makeConstraints { make in
                make.top.equalTo(self.splitVC.view.snp.bottom)
                make.left.right.bottom.equalTo(self.view.safeAreaLayoutGuide)
            }

            self.verticalSplitView.splitterClosedHeight = 350
            self.view.layoutSubviews()
            self.verticalSplitView.splitterOffset = 350
        }
    }
}

extension AdControlVC: VerticalSplitViewDelegate {
    func splitterDragged(by: CGFloat) {
        // sticks to adView's content offset's bottom
        if adContainerScrollView.contentOffset.y + adContainerScrollView.frame.height + 60 >= adContainerScrollView.contentSize.height {
            let currentOffset = self.adContainerScrollView.contentOffset
            let newOffsetY = max(currentOffset.y - by, adContainerScrollView.contentSize.height - (verticalSplitView.splitter.frame.minY - adContainerScrollView.frame.minY))
            let newOffset = CGPoint(x: currentOffset.x, y: newOffsetY)

            self.adContainerScrollView.setContentOffset(newOffset, animated: false)
        }
    }
}
