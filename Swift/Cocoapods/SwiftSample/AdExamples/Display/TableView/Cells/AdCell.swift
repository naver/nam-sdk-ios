//
//  BannerAdCell.swift
//  SwiftSample
//
//  Created by USER on 2023/05/12.
//

import UIKit
import GFPSDK

class AdCell: UITableViewCell {

    static let identifier = UUID().uuidString

    private let MaxFluidBannerWidth: CGFloat = 414
    private let MaxFluidBannerHeight: CGFloat = 300

    weak var adView: UIView? = nil {
        didSet {
            guard let adView = adView else {return}

            if let bannerAdView = adView as? GFPBannerView {
                self.bannerAdView = bannerAdView
                return
            }

            if let nativeAdView = adView as? GFPNativeAdView {
                self.nativeAdView = adView as? GFPNativeAdView
                return
            }

            if let nativeSimpleAdView = adView as? GFPNativeSimpleAdView {
                self.nativeSimpleAdView = adView as? GFPNativeSimpleAdView
                return
            }
        }
    }

    weak var bannerAdView: GFPBannerView? = nil {
        didSet {
            guard let adView = bannerAdView else {return}

            resetViews()

            self.addSubview(adView)

            let adSize = adView.adSize

            switch adView.adSize.type {
            case .fixed:
                adView.snp.makeConstraints { make in
                    make.size.equalTo(adSize.size)
                }

            case .fluid:
                adView.snp.makeConstraints { make in
                    make.width.equalTo(min(self.frame.width, MaxFluidBannerWidth))
                    make.height.equalTo(min(self.frame.height, MaxFluidBannerHeight))
                }

            case .fluidWidth:
                adView.snp.makeConstraints { make in
                    make.width.equalTo(min(self.frame.width, MaxFluidBannerWidth))
                    make.height.equalTo(adSize.size.height)
                }

            case .fluidHeight:
                adView.snp.makeConstraints { make in
                    make.width.equalTo(adSize.size.width)
                    make.height.equalTo(min(self.frame.height, MaxFluidBannerHeight))
                }

            default:
                break
            }
        }
    }

    weak var nativeAdView: GFPNativeAdView? = nil {
        didSet {
            guard let adView = nativeAdView else {return}

            resetViews()

            self.addSubview(adView)

            adView.snp.remakeConstraints { make in
                make.centerX.centerY.width.height.equalToSuperview()
            }
        }
    }


    weak var nativeSimpleAdView: GFPNativeSimpleAdView? = nil {
        didSet {
            guard let adView = nativeSimpleAdView else {return}

            resetViews()

            self.addSubview(adView)

            adView.snp.remakeConstraints { make in
                make.centerX.centerY.width.height.equalToSuperview()
            }
        }
    }

    init() {
        super.init(style: .default, reuseIdentifier: Self.identifier)
    }

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        self.selectionStyle = .none
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    private func resetViews() {
        bannerAdView?.removeFromSuperview()
        nativeAdView?.removeFromSuperview()
        nativeSimpleAdView?.removeFromSuperview()

        bannerAdView = nil
        nativeAdView = nil
        nativeSimpleAdView = nil
    }
}
