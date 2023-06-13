//
//  SettingsTimeoutCell.swift
//  SwiftSample
//
//  Created by USER on 2023/04/20.
//

import UIKit
import SnapKit
import GFPSDK

final class DoubleValueCell: BaseCell {

    var maximumFractionDigits: Int = 1

    private var lastText: String = ""

    private var textField = UITextField()

    private var valueProvider: (() -> Double)? = nil

    private var onValueChange: ((Double) -> Void)? = nil

    func configure(withTitle title: String, valueProvider: @escaping () -> Double, onValueChange: @escaping (Double) -> Void) {
        super.configure(withTitle: title)
        self.valueProvider = valueProvider
        self.onValueChange = onValueChange

        self.accessoryView = textField
        textField.frame = .init(x: 0, y: 0, width: 150, height: self.frame.height)
        textField.font = .systemFont(ofSize: 17)
        if #available(iOS 13.0, *) {
            textField.textColor = .secondaryLabel
        }
        textField.textAlignment = .center
        textField.textAlignment = .right
        textField.keyboardType = .decimalPad
        textField.delegate = self

        let toolbar = UIToolbar()
        let doneBtn = UIBarButtonItem(barButtonSystemItem: .done, target: nil, action: #selector(done))
        let space = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        toolbar.sizeToFit()
        toolbar.setItems([space, doneBtn], animated: true)
        textField.inputAccessoryView = toolbar

        // Initial value.
        if let value = self.valueProvider?() {
            lastText = String(describing: value)
            textField.text = lastText
            _ = textField.round(maximumFractionDigits: maximumFractionDigits)
        }

        SettingsManager.observeSettingsChanged { [weak self] manager in
            guard let self = self else {return}
            guard let value = self.valueProvider?() else {return}
            textField.text = String(describing: value)
            _ = textField.round(maximumFractionDigits: maximumFractionDigits)
        }
    }

    @objc func done() {
        textField.endEditing(true)
    }
}

extension DoubleValueCell: UITextFieldDelegate {

    func textFieldDidBeginEditing(_ textField: UITextField) {
        if let text = textField.text {
            lastText = text
            textField.text = ""
        }
    }

    func textFieldDidEndEditing(_ textField: UITextField) {
        if let doubleValue = textField.round(maximumFractionDigits: maximumFractionDigits).doubleValue {
            onValueChange?(doubleValue)
        } else { // Fall-back to last valid string
            textField.text = lastText
        }
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.endEditing(true)
        return true
    }
}


fileprivate extension UITextField {

    var doubleValue : Double? {
        guard let text = self.text else { return nil }
        guard let nsNumber = NumberFormatter().number(from: text) else {

            self.text = ""
            return nil
        }
        return nsNumber.doubleValue
    }

    func round(maximumFractionDigits: Int) -> Self {
        let numberFormatter = NumberFormatter()
        numberFormatter.roundingMode = .floor
        numberFormatter.maximumFractionDigits = maximumFractionDigits

        guard let text = self.text else {
            return self
        }

        self.text = numberFormatter.string(for: self.doubleValue)

        return self
    }

}
