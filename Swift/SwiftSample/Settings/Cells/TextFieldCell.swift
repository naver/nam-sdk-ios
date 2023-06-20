//
//  SettingsStringCell.swift
//  SwiftSample
//
//  Created by USER on 2023/04/27.
//
import UIKit
import SnapKit
import GFPSDK

final class TextFieldCell: BaseCell {

    var maximumFractionDigits: Int = 1

    private var textField = UITextField()

    private var valueProvider: (() -> String)? = nil

    private var onTextChange: ((String) -> Void)? = nil

    func configure(withTitle title: String, valueProvider: @escaping () -> String, onTextChange: @escaping (String) -> Void) {
        super.configure(withTitle: title)
        self.valueProvider = valueProvider
        self.onTextChange = onTextChange

        self.accessoryView = textField
        textField.frame = .init(x: 0, y: 0, width: 150, height: self.frame.height)
        textField.font = .systemFont(ofSize: 17)
        if #available(iOS 13.0, *) {
            textField.textColor = .secondaryLabel
        }
        textField.textAlignment = .right
        textField.delegate = self

        let toolbar = UIToolbar()
        let doneBtn = UIBarButtonItem(barButtonSystemItem: .done, target: nil, action: #selector(done))
        let space = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        toolbar.sizeToFit()
        toolbar.setItems([space, doneBtn], animated: true)
        textField.inputAccessoryView = toolbar

        // Initial value.
        if let value = self.valueProvider?() {
            textField.text = value
        }

        SettingsManager.observeSettingsChanged { [weak self] _ in
            guard let self = self else {return}
            guard let text = self.valueProvider?() else {return}
            self.textField.text = text
        }
    }

    @objc func done() {
        textField.endEditing(true)
    }
}

extension TextFieldCell: UITextFieldDelegate {
    func textFieldDidEndEditing(_ textField: UITextField) {
        onTextChange?(textField.text ?? "")
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.endEditing(true)
        return true
    }
}
