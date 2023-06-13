//
//  SliderCell.swift
//  SwiftSample
//
//  Created by USER on 2023/05/03.
//

import UIKit


final class SliderCell: BaseCell {

    private var valueProvider: (() -> Float)? = nil

    private var onSliderChange: ((Float) -> Void)? = nil

    private var range: ClosedRange<Float> = 0...1

    private var step: Int = 0

    private var slider = UISlider()

    private var label = UILabel()

    private var valueText: String = "" {
        didSet {
            label.text = valueText
            label.sizeToFit()
        }
    }

    func configure(withTitle title: String, range: ClosedRange<Float>, step: Int = 0, valueProvider: @escaping () -> Float, onSliderChange: @escaping (Float) -> Void) {
        super.configure(withTitle: title)
        self.range = range
        self.step = step
        self.valueProvider = valueProvider
        self.onSliderChange = onSliderChange

        slider.minimumValue = range.lowerBound
        slider.maximumValue = range.upperBound

        slider.addTarget(self, action: #selector(sliderChanged(_:)), for: .valueChanged)
        slider.frame = .init(x: 0, y: 0, width: 150, height: 50)
        self.accessoryView = slider

        slider.addSubview(label)
        valueText = String(describing: valueProvider())
        label.snp.makeConstraints { make in
            make.centerX.equalTo(slider)
            make.top.equalTo(slider.snp.top)
        }

        slider.setValue(valueProvider(), animated: true)

        if step >= 0 {
            valueText = String(describing: Int(slider.value))
        }

        SettingsManager.observeSettingsChanged { [weak self] _ in
            guard let self = self else {return}
            guard let newValue = self.valueProvider?() else {return}
            self.slider.setValue(newValue, animated: true)
            self.valueText = String(newValue)
        }
    }

    @objc private func sliderChanged(_ sender: UISlider) {
        if self.step > 0 {
            var value = (sender.value - self.range.lowerBound) / Float(step)
            value = value.rounded(.toNearestOrEven)
            value = value * Float(step) + self.range.lowerBound
            value = min(self.range.upperBound, value)
            value = max(self.range.lowerBound, value)

            sender.setValue(value, animated: false)
            valueText = String(describing: Int(value))
            onSliderChange?(value)
        } else {
            onSliderChange?(sender.value)
            valueText = String(describing: sender.value)
        }


    }
}
