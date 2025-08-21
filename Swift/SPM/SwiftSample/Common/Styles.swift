//
//  Styles.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

extension CGFloat {
    struct Styles {
        static let FontSize: CGFloat = 15
        static let ButtonCornerRadius: CGFloat = 10
    }
}

extension UIEdgeInsets {
    struct Styles {
        static let button: UIEdgeInsets = .init(top: 7, left: 8, bottom: 7, right: 8)
    }
}

extension UIColor {
    struct Button {
        static let gray1 = UIColor(white: 0.6, alpha: 1)
        static let gray2 = UIColor(white: 0.75, alpha: 1)
        static let load = UIColor(red: 0, green: 0.7, blue: 0, alpha: 0.8)
        static let unload = UIColor(red: 0.8, green: 0.15, blue: 0.15, alpha: 0.8)
    }

    struct Title {
        static let gray1 = UIColor(white: 0.99, alpha: 1)
        static let gray2 = UIColor(white: 0.99, alpha: 1)
        static let load = UIColor(white: 0.99, alpha: 1)
        static let unload = UIColor(white: 0.99, alpha: 1)
    }
    
    struct Background {
        static var primary: UIColor {
            if #available(iOS 13.0, *) {
                return .systemBackground
            } else {
                return UIColor.white
            }
        }
        static var secondary: UIColor {
            if #available(iOS 13.0, *) {
                return .secondarySystemBackground
            } else {
                return UIColor(white: 0.96, alpha: 1)
            }
        }
        static var tertiary: UIColor {
            if #available(iOS 13.0, *) {
                return .tertiarySystemBackground
            } else {
                return UIColor(white: 0.8, alpha: 1)
            }
        }
    }
}

extension UIButton {
    static func load(withTitle title: String) -> UIButton {
        let button = UIButton()
        button.layer.cornerRadius = CGFloat.Styles.ButtonCornerRadius
        button.setTitleColor(.Title.load, for: .normal)
        button.backgroundColor = .Button.load
        button.setTitle(title, for: .normal)
        button.contentEdgeInsets = .Styles.button
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static func reset(withTitle title: String) -> UIButton {
        let button = UIButton()
        button.layer.cornerRadius = CGFloat.Styles.ButtonCornerRadius
        button.setTitleColor(.Title.unload, for: .normal)
        button.backgroundColor = .Button.unload
        button.setTitle(title, for: .normal)
        button.contentEdgeInsets = .Styles.button
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static func gray1(withTitle title: String) -> UIButton {
        let button = UIButton()
        button.layer.cornerRadius = CGFloat.Styles.ButtonCornerRadius
        button.setTitleColor(.Title.gray1, for: .normal)
        button.backgroundColor = .Button.gray1
        button.setTitle(title, for: .normal)
        button.contentEdgeInsets = .Styles.button
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static func gray2(withTitle title: String) -> UIButton {
        let button = UIButton()
        button.layer.cornerRadius = CGFloat.Styles.ButtonCornerRadius
        button.setTitleColor(.Title.gray2, for: .normal)
        button.backgroundColor = .Button.gray2
        button.setTitle(title, for: .normal)
        button.contentEdgeInsets = .Styles.button
        UIButton.addTapHighlightActions(button)
        
        return button
    }
    
    static func edit() -> UIButton {
        let button = UIButton()
        button.setTitle("Edit", for: .normal)
        button.setTitle("Done", for: .selected)
        
        button.setTitleColor(.systemBlue, for: .normal)
        button.setTitleColor(.systemBlue.withAlphaComponent(0.6), for: .highlighted)
        button.setTitleColor(.systemGray, for: .disabled)
        
        UIButton.addTapHighlightActions(button)
        return button
    }
    
    static func addTapHighlightActions(_ target:UIButton) {
        target.addTarget(target, action: #selector(buttonHighlight), for: .touchDown)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchCancel)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchUpInside)
        target.addTarget(target, action: #selector(buttonNormal), for: .touchUpOutside)
    }
    
    @IBAction private func buttonHighlight() {
        var alpha: CGFloat = 0
        
        self.backgroundColor?.getRed(nil, green: nil, blue: nil, alpha: &alpha)
        self.backgroundColor = self.backgroundColor?.withAlphaComponent(alpha / 1.75)
    }
    
    @IBAction private func buttonNormal() {
        var alpha: CGFloat = 0
        
        self.backgroundColor?.getRed(nil, green: nil, blue: nil, alpha: &alpha)
        self.backgroundColor = self.backgroundColor?.withAlphaComponent(alpha * 1.75)
    }
}

extension UILabel {
    func fitSizeTo(fontSize:CGFloat) {
        self.font = self.font.withSize(fontSize)
        let size = self.sizeThatFits(CGSize(width: 10000, height: 10000))
        self.frame = CGRect(x: 0, y: 0, width: size.width + 8, height: size.height)
    }
}

extension UITextField {
    static func sampleAppTextField() -> UITextField {
        let textField = UITextField()
        textField.borderStyle = .roundedRect
        textField.layer.cornerRadius = 6
        textField.layoutMargins = .init(top: 0, left: 10, bottom: 0, right: 10)
        return textField
    }
}

extension UIViewController {
    func configureNavBarDoneButton() {
        let button = UIBarButtonItem(barButtonSystemItem: UIBarButtonItem.SystemItem.done, target: nil, action: #selector(dismissViewController))
        self.navigationItem.setLeftBarButton(button, animated: true)
    }
    
    @IBAction private func dismissViewController() {
        self.navigationController?.popViewController(animated: true)
        self.dismiss(animated: true, completion: nil)
    }
}
