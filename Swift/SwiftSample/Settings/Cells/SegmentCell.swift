//
//  SettingsSegmentCell.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit


final class SegmentCell: BaseCell {

    private var segment = UISegmentedControl()

    private var valueProvider: (() -> Int)? = nil

    private var onSegmentChange: ((Int) -> Void)? = nil

    func configure<EnumType: SettingsEnumProtocol>(withTitle title: String, enumType: EnumType.Type, valueProvider: @escaping () -> Int, onSegmentChange: @escaping (Int) -> Void) {
        super.configure(withTitle: title)
        self.valueProvider = valueProvider
        self.onSegmentChange = onSegmentChange

        segment = UISegmentedControl(items: EnumType.allCases.map {$0.title})
        segment.selectedSegmentIndex = valueProvider()
        segment.addTarget(self, action: #selector(valueChanged(_:)), for: .valueChanged)
        self.accessoryView = segment

        SettingsManager.observeSettingsChanged { [weak self] _ in
            guard let self = self else {return}
            guard let newValue = self.valueProvider?() else {return}
            self.segment.selectedSegmentIndex = newValue
        }
    }

    @objc private func valueChanged(_ sender:UISegmentedControl) {
        onSegmentChange?(sender.selectedSegmentIndex)
    }
}
