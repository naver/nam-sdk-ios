//
//  SettingsSwitchCell.swift
//  SwiftSample
//
//  Created by USER on 2023/03/20.
//

import UIKit
import SnapKit
import GFPSDK


final class SwitchCell: BaseCell {

    private var toggle = UISwitch()

    private var valueProvider: (() -> Bool)? = nil

    private var onSwtichChange: ((Bool) -> Void)? = nil

    func configure(withTitle title: String, valueProvider: @escaping () -> Bool, onSwtichChange: @escaping (Bool) -> Void) {
        super.configure(withTitle: title)
        self.onSwtichChange = onSwtichChange
        self.valueProvider = valueProvider

        toggle.setOn(valueProvider(), animated: false)
        toggle.addTarget(self, action: #selector(valueChanged(_:)), for: .valueChanged)
        self.accessoryView = toggle

        SettingsManager.observeSettingsChanged { [weak self] _ in
            guard let self = self else {return}
            guard let newValue = self.valueProvider?() else {return}
            self.toggle.setOn(newValue, animated: true)
        }
    }

    @objc private func valueChanged(_ sender:UISwitch) {
        self.onSwtichChange?(sender.isOn)
    }
}
