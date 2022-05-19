//
//  MainViewController+Styles.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

let ControlPaneliPadMaxWidth: CGFloat = 800 * GlobalLayoutScale
let ControlPanelVerticalPadding: CGFloat = 11 * GlobalLayoutScale
let SpaceBetweenRows: CGFloat = 8 * GlobalLayoutScale
let SpaceBetweenButtons: CGFloat = 12 * GlobalLayoutScale
let LogsHorizontalPadding: CGFloat = 36 * GlobalLayoutScale
let LogsBottomPadding: CGFloat = 30 * GlobalLayoutScale

extension MainViewController {
    func setupStyles() {
        setupAppearances()
        setViewOptions()
        setupAutoLayoutCommon()
        if (UIDevice.current.userInterfaceIdiom == .pad) {
            setupAutoLayoutiPad()
        }
    }
    
    func setupConstraintsiPhonePortrait() {
        NSLayoutConstraint.deactivate(self.constraintsiPhoneLandscape)
        NSLayoutConstraint.activate(self.constraintsiPhonePortrait)
    }
    
    func setupConstraintsiPhoneLandscape() {
        NSLayoutConstraint.deactivate(self.constraintsiPhonePortrait)
        NSLayoutConstraint.activate(self.constraintsiPhoneLandscape)
    }
    
    func setupAppearances() {
        self.adView.backgroundColor = .Background.tertiary
        self.logsView.backgroundColor = .Background.secondary
        self.callHistoryTextView.backgroundColor = .Background.secondary
    }
    
    func setViewOptions() {
        self.controlPanel.translatesAutoresizingMaskIntoConstraints = false
        self.unitIDButton.translatesAutoresizingMaskIntoConstraints = false
        self.unitIDLabel.translatesAutoresizingMaskIntoConstraints = false
        self.loadButton.translatesAutoresizingMaskIntoConstraints = false
        self.loadWithoutImpressionButton.translatesAutoresizingMaskIntoConstraints = false
        self.unloadButton.translatesAutoresizingMaskIntoConstraints = false
//        self.adTypeOptionsButton.translatesAutoresizingMaskIntoConstraints = false
        self.adView.translatesAutoresizingMaskIntoConstraints = false
        self.verticalSplitView.translatesAutoresizingMaskIntoConstraints = false
        self.callHistoryTextView.translatesAutoresizingMaskIntoConstraints = false
        
        // iPad-specific
        self.controlPanelExtended?.translatesAutoresizingMaskIntoConstraints = false
        self.controlPanelDetailView?.translatesAutoresizingMaskIntoConstraints = false
        
        self.controlPanelExtended?.isUserInteractionEnabled = false
    }
    
    func setupAutoLayoutCommon() {
        let safeArea = self.view.safeAreaLayoutGuide
        let isPad = UIDevice.current.userInterfaceIdiom == .pad
        
        if isPad {
            self.verticalSplitView.topAnchor.constraint(equalTo: self.controlPanelExtended!.bottomAnchor).isActive = true
        } else {
            self.verticalSplitView.topAnchor.constraint(equalTo: self.controlPanel.bottomAnchor).isActive = true
        }
        
        let controlPanelInset = UILayoutGuide()
        let adTypeRow = UILayoutGuide()
        let adUnitIDRow = UILayoutGuide()
        let wfMatcherRow = UILayoutGuide()
        let loadButtonsRow = UILayoutGuide()
        self.controlPanel.addLayoutGuide(controlPanelInset)
        self.controlPanel.addLayoutGuide(adTypeRow)
        self.controlPanel.addLayoutGuide(adUnitIDRow)
        self.controlPanel.addLayoutGuide(wfMatcherRow)
        self.controlPanel.addLayoutGuide(loadButtonsRow)
        
        self.controlPanel.bottomAnchor.constraint(equalTo: loadButtonsRow.bottomAnchor, constant: ControlPanelVerticalPadding).isActive = true
        if !isPad {
            self.controlPanel.topAnchor.constraint(equalTo: safeArea.topAnchor).isActive = true
            self.controlPanel.widthAnchor.constraint(equalTo: safeArea.widthAnchor).isActive = true
            self.controlPanel.centerXAnchor.constraint(equalTo: safeArea.centerXAnchor).isActive = true
        }
        
        controlPanelInset.centerXAnchor.constraint(equalTo: self.controlPanel.centerXAnchor).isActive = true
        controlPanelInset.widthAnchor.constraint(equalTo: self.controlPanel.widthAnchor, constant: -46).isActive = true
        controlPanelInset.topAnchor.constraint(equalTo: self.controlPanel.topAnchor, constant: ControlPanelVerticalPadding).isActive = true
        controlPanelInset.bottomAnchor.constraint(equalTo: loadButtonsRow.bottomAnchor).isActive = true

        // Ad Unit Row
        adUnitIDRow.centerXAnchor.constraint(equalTo: controlPanelInset.centerXAnchor).isActive = true
        adUnitIDRow.widthAnchor.constraint(equalTo: controlPanelInset.widthAnchor).isActive = true
        adUnitIDRow.heightAnchor.constraint(equalTo: self.unitIDButton.heightAnchor).isActive = true
        if isPad {
            adUnitIDRow.topAnchor.constraint(equalTo: controlPanel.topAnchor, constant:ControlPanelVerticalPadding).isActive = true
        } else {
            self.constraintsiPhonePortrait.append(adUnitIDRow.topAnchor.constraint(equalTo: controlPanel.topAnchor, constant: ControlPanelVerticalPadding))
            self.constraintsiPhoneLandscape.append(adUnitIDRow.bottomAnchor.constraint(equalTo: self.view.topAnchor))
        }
        
        self.unitIDButton.widthAnchor.constraint(equalToConstant: self.unitIDButton.bounds.size.width).isActive = true
        self.unitIDButton.heightAnchor.constraint(equalToConstant: self.unitIDButton.bounds.size.height).isActive = true
        self.unitIDButton.centerYAnchor.constraint(equalTo: adUnitIDRow.centerYAnchor).isActive = true
        self.unitIDButton.leftAnchor.constraint(equalTo: adUnitIDRow.leftAnchor).isActive = true
        
        self.unitIDLabel.centerYAnchor.constraint(equalTo: adUnitIDRow.centerYAnchor).isActive = true
        self.unitIDLabel.leftAnchor.constraint(equalTo: self.unitIDButton.rightAnchor, constant: 6 * GlobalLayoutScale).isActive = true
//        self.unitIDLabel.rightAnchor.constraint(equalTo: adTypeOptionsButton.leftAnchor, constant: -SpaceBetweenButtons ).isActive = true
        self.unitIDLabel.rightAnchor.constraint(equalTo: adUnitIDRow.rightAnchor, constant: 6 * GlobalLayoutScale).isActive = true
        
//        self.adTypeOptionsButton.widthAnchor.constraint(equalToConstant: self.adTypeOptionsButton.bounds.size.width).isActive = true
//        self.adTypeOptionsButton.heightAnchor.constraint(equalToConstant: self.adTypeOptionsButton.bounds.size.height).isActive = true
//        self.adTypeOptionsButton.centerYAnchor.constraint(equalTo: adUnitIDRow.centerYAnchor).isActive = true
//        self.adTypeOptionsButton.rightAnchor.constraint(equalTo: adUnitIDRow.rightAnchor).isActive = true

        // Load Buttons Row
        loadButtonsRow.centerXAnchor.constraint(equalTo: controlPanelInset.centerXAnchor).isActive = true
        loadButtonsRow.leftAnchor.constraint(equalTo: self.loadButton.leftAnchor).isActive = true
        loadButtonsRow.rightAnchor.constraint(equalTo: self.unloadButton.rightAnchor).isActive = true
        loadButtonsRow.heightAnchor.constraint(equalTo: self.loadButton.heightAnchor).isActive = true
        if isPad {
            loadButtonsRow.topAnchor.constraint(equalTo: adUnitIDRow.bottomAnchor, constant: SpaceBetweenRows).isActive = true
        } else {
            self.constraintsiPhonePortrait.append(loadButtonsRow.topAnchor.constraint(equalTo: adUnitIDRow.bottomAnchor, constant: SpaceBetweenRows))
            self.constraintsiPhoneLandscape.append(loadButtonsRow.topAnchor.constraint(equalTo: safeArea.topAnchor))
        }
        
        self.loadButton.widthAnchor.constraint(equalToConstant: self.loadButton.bounds.size.width).isActive = true
        self.loadButton.heightAnchor.constraint(equalToConstant: self.loadButton.bounds.size.height).isActive = true
        self.loadButton.centerYAnchor.constraint(equalTo: loadButtonsRow.centerYAnchor).isActive = true
        self.loadButton.leftAnchor.constraint(equalTo: loadButtonsRow.leftAnchor).isActive = true
        
        self.loadWithoutImpressionButton.widthAnchor.constraint(equalToConstant: self.loadWithoutImpressionButton.bounds.size.width).isActive = true
        self.loadWithoutImpressionButton.heightAnchor.constraint(equalToConstant: self.loadWithoutImpressionButton.bounds.size.height).isActive = true
        self.loadWithoutImpressionButton.centerYAnchor.constraint(equalTo: loadButtonsRow.centerYAnchor).isActive = true
        self.loadWithoutImpressionButton.leftAnchor.constraint(equalTo: self.loadButton.rightAnchor, constant: SpaceBetweenButtons).isActive = true
        
        self.unloadButton.widthAnchor.constraint(equalToConstant: self.unloadButton.bounds.size.width).isActive = true
        self.unloadButton.heightAnchor.constraint(equalToConstant: self.unloadButton.bounds.size.height).isActive = true
        self.unloadButton.centerYAnchor.constraint(equalTo: loadButtonsRow.centerYAnchor).isActive = true
        self.unloadButton.leftAnchor.constraint(equalTo: self.loadWithoutImpressionButton.rightAnchor, constant: SpaceBetweenButtons).isActive = true
        
        // Vertical Splitter View
        self.verticalSplitView.leftAnchor.constraint(equalTo: safeArea.leftAnchor).isActive = true
        self.verticalSplitView.rightAnchor.constraint(equalTo: safeArea.rightAnchor).isActive = true
        self.verticalSplitView.bottomAnchor.constraint(equalTo: safeArea.bottomAnchor).isActive = true
        
        // Logs View
        self.callHistoryTextView.leftAnchor.constraint(equalTo: self.logsView.leftAnchor, constant: LogsHorizontalPadding).isActive = true
        self.callHistoryTextView.rightAnchor.constraint(equalTo: self.logsView.rightAnchor, constant: -LogsHorizontalPadding).isActive = true
        self.callHistoryTextView.topAnchor.constraint(equalTo: self.logsView.topAnchor).isActive = true
        self.callHistoryTextView.bottomAnchor.constraint(equalTo: self.logsView.bottomAnchor, constant: -LogsBottomPadding).isActive = true
    }
    
    
    func setupAutoLayoutiPad() {
        let safeArea = self.view.safeAreaLayoutGuide
        
        let panelLeft = UILayoutGuide()
        let panelRight = UILayoutGuide()
        self.view.addLayoutGuide(panelLeft)
        self.view.addLayoutGuide(panelRight)
        
        if (UIScreen.main.bounds.width < ControlPaneliPadMaxWidth) {
            self.controlPanelExtended!.widthAnchor.constraint(equalTo: safeArea.widthAnchor).isActive = true
        } else {
            self.controlPanelExtended!.widthAnchor.constraint(equalToConstant: ControlPaneliPadMaxWidth).isActive = true
        }
        self.controlPanelExtended!.topAnchor.constraint(equalTo: safeArea.topAnchor).isActive = true
        self.controlPanelExtended!.heightAnchor.constraint(equalToConstant: 350).isActive = true
        self.controlPanelExtended!.centerXAnchor.constraint(equalTo: safeArea.centerXAnchor).isActive = true
        
        panelLeft.leftAnchor.constraint(equalTo: self.controlPanelExtended!.leftAnchor).isActive = true
        panelLeft.rightAnchor.constraint(equalTo: self.controlPanelExtended!.centerXAnchor).isActive = true
        panelLeft.heightAnchor.constraint(equalTo: self.controlPanelExtended!.heightAnchor).isActive = true
        panelLeft.centerYAnchor.constraint(equalTo: self.controlPanelExtended!.centerYAnchor).isActive = true
        
        panelRight.leftAnchor.constraint(equalTo: self.controlPanelExtended!.centerXAnchor).isActive = true
        panelRight.rightAnchor.constraint(equalTo: self.controlPanelExtended!.rightAnchor).isActive = true
        panelRight.heightAnchor.constraint(equalTo: self.controlPanelExtended!.heightAnchor).isActive = true
        panelRight.centerYAnchor.constraint(equalTo: self.controlPanelExtended!.centerYAnchor).isActive = true
        
        self.controlPanel.leftAnchor.constraint(equalTo: panelLeft.leftAnchor).isActive = true
        self.controlPanel.rightAnchor.constraint(equalTo: panelLeft.rightAnchor).isActive = true
        self.controlPanel.centerYAnchor.constraint(equalTo: panelLeft.centerYAnchor).isActive = true
        
        self.controlPanelDetailView!.leftAnchor.constraint(equalTo: panelRight.leftAnchor).isActive = true
        self.controlPanelDetailView!.rightAnchor.constraint(equalTo: panelRight.rightAnchor).isActive = true
        self.controlPanelDetailView!.topAnchor.constraint(equalTo: panelRight.topAnchor).isActive = true
        self.controlPanelDetailView!.bottomAnchor.constraint(equalTo: panelRight.bottomAnchor).isActive = true
    }
}
