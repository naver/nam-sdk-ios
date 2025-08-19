//
//  CustomTemplateView.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

import Foundation
import UIKit

import NaverAdsServices

import GFPSDK

@objc(CustomTemplateView)
@objcMembers
public class CustomTemplateView: UIView {

    public var mediaViewMaxHeight: CGFloat = 0.0

    //MARK: - data
    private weak var asset: GFPNativeAssetProtocol?
    private var isDarkMode: Bool = false

    //MARK: - constant
    @IBOutlet weak var topContainerHeight: NSLayoutConstraint!
    @IBOutlet weak var bodyContainerHeight: NSLayoutConstraint!
    
    @IBOutlet weak var mediaViewHeight: NSLayoutConstraint!
    @IBOutlet weak var ctaContainerHeight: NSLayoutConstraint!
    @IBOutlet weak var mediaBodyMargin: NSLayoutConstraint!
    @IBOutlet weak var iconLeadingMargin: NSLayoutConstraint!
    @IBOutlet weak var adChoicesTrailingMargin: NSLayoutConstraint!
    
    static let leftRightMargin: CGFloat = 16.0
    static let topAssetSpacing: CGFloat = 4.0

    static let bodyLabelLineHeight: CGFloat = 23.0

    //MARK: - view
    @IBOutlet weak var iconView: UIImageView!
    @IBOutlet weak var adBadgeImage: UIImageView!

    /**
     * title > advertiser 우선 순위로 top에 노출함.
     * - 내부 상품의 경우 sponsor가 아이콘 옆에 노출됨.
     *   - 내부 상품은 nativeData.title 의 데이터가 존재하지 않음.
     * - 일부 C2S(=DFP)의 경우 title 에셋이 필수 요소이므로, 노출이 필요함.
     */
    private var topLabel: UILabel {
        if let asset = self.asset {
            return !GFPStringUtils.isEmpty(asset.title) ? self.titleLabel : self.advertiserLabel
        } else {
            return self.titleLabel
        }
    }

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var advertiserLabel: UILabel!

    @IBOutlet weak var bodyLabel: UILabel!

    @IBOutlet weak var ctaContainer: UIView!
    @IBOutlet weak var ctaBorderLine: UIView!
    @IBOutlet weak var callToActionLabel: UILabel!
    @IBOutlet weak var ctaLabelRichtImage: UIImageView!
    
    @IBOutlet weak var mediaView: GFPMediaView!
    @IBOutlet weak var adChoicesView: UIView!
    
    public override func awakeFromNib() {
        super.awakeFromNib()
        
        self.setup()
    }

    public override func layoutSubviews() {
        super.layoutSubviews()

        self.adjustSizeAndLayout()
    }

    private func setup() {
        self.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        self.clipsToBounds = true

        self.iconView.clipsToBounds = true
        self.iconView.layer.masksToBounds = true
        self.iconView.layer.cornerRadius = 10.0

        self.titleLabel.lineBreakMode = .byTruncatingTail
        self.titleLabel.numberOfLines = 1

        self.advertiserLabel.lineBreakMode = .byTruncatingTail
        self.advertiserLabel.numberOfLines = 1
        
        self.bodyLabel.lineBreakMode = .byTruncatingTail
        self.bodyLabel.numberOfLines = 2

        self.mediaView.clipsToBounds = true

        self.iconLeadingMargin.constant = CustomTemplateView.leftRightMargin
        self.adChoicesTrailingMargin.constant = CustomTemplateView.leftRightMargin
    }
    
    private func adjustSizeAndLayout() {
        let width = self.bounds.width
        
        // Top
        
        self.topLabel.sizeToFit()

        let isHiddenIconView = self.iconView.isHidden

        if isHiddenIconView {
            let topLabelMaxWidth = width - (CustomTemplateView.leftRightMargin * 2 + self.adChoicesView.sizeWidth() + self.adBadgeImage.sizeWidth() + CustomTemplateView.topAssetSpacing * 2)

            let topLabelWidth = (topLabelMaxWidth <= self.topLabel.sizeWidth()) ? topLabelMaxWidth : self.topLabel.sizeWidth()

            self.topLabel.updateSizeWith(type: .width, value: topLabelWidth)

            self.topLabel.alignCenter(type: .vertical, view: self.iconView)
            self.topLabel.moveToTypeWith(type: .left, margin: CustomTemplateView.leftRightMargin)

            self.adBadgeImage.alignCenter(type: .vertical, view: self.topLabel)
            self.adBadgeImage.moveToTypeWith(type: .right, view: self.topLabel, gap: CustomTemplateView.topAssetSpacing)
        } else {
            let topLabelMaxWidth = width - (CustomTemplateView.leftRightMargin * 2 + self.iconView.sizeWidth() + self.adChoicesView.sizeWidth() + self.adBadgeImage.sizeWidth() + CustomTemplateView.topAssetSpacing * 3)

            let topLabelWidth = (topLabelMaxWidth <= self.topLabel.sizeWidth()) ? topLabelMaxWidth : self.topLabel.sizeWidth()

            self.topLabel.updateSizeWith(type: .width, value: topLabelWidth)

            self.topLabel.alignCenter(type: .vertical, view: self.iconView)
            self.topLabel.moveToTypeWith(type: .right, view: self.iconView, gap: CustomTemplateView.topAssetSpacing)

            self.adBadgeImage.alignCenter(type: .vertical, view: self.iconView)
            self.adBadgeImage.moveToTypeWith(type: .right, view: self.topLabel, gap: CustomTemplateView.topAssetSpacing)
        }

        // Body

        self.bodyLabel.numberOfLines = 1
        self.bodyLabel.sizeToFit()

        let bodyMaxWidth = width - (CustomTemplateView.leftRightMargin * 2)
        let bodyLabelWidth = round(self.bodyLabel.sizeWidth())

        let lineBodyHeight = CustomTemplateView.bodyLabelLineHeight
        var bodyHeight = (bodyMaxWidth <= bodyLabelWidth) ? lineBodyHeight * 2 : lineBodyHeight
        bodyHeight = GFPStringUtils.isEmpty(self.bodyLabel.text) ? 0 : bodyHeight

        self.bodyLabel.numberOfLines = Int(bodyHeight / lineBodyHeight)
        self.bodyLabel.updateSizeWith(aSize: CGSizeMake(bodyMaxWidth, bodyHeight))

        self.bodyLabel.moveWith(type: .horizontal)
        self.bodyLabel.moveToTypeWith(type: .left, margin: CustomTemplateView.leftRightMargin)

        self.bodyContainerHeight.constant = bodyHeight


        // Media
        
        if let mediaData = self.asset?.mediaData {
            let mediaViewWidth: CGFloat = width
            var aspectRatio = (mediaData.aspectRatio > 0) ? mediaData.aspectRatio : 16/9

            if mediaData.mediaType == .carousel {
                let preferredHeight = round(mediaData.preferredHeightWithFixedWidth(mediaViewWidth))
                aspectRatio = (preferredHeight > 0 ) ? mediaViewWidth/preferredHeight : aspectRatio
            }

            var mediaViewHeight = round(mediaViewWidth / aspectRatio)
            mediaViewHeight = (self.mediaViewMaxHeight > 0 && self.mediaViewMaxHeight < mediaViewHeight) ? self.mediaViewMaxHeight : mediaViewHeight

            self.mediaViewHeight.constant = mediaViewHeight
        }
    }

    private func changeCallToActionStyle(isDarkMode: Bool) {
        let ctaRightArrow = isDarkMode ? "template_nn_cta_arrow_withBG" : "template_nn_cta_arrow"
        self.ctaLabelRichtImage.image = UIImage(named: ctaRightArrow)

        self.callToActionLabel.textColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0xFFFFFF) : UIColor.gfpColor(rgbInt: 0x353434)
        self.ctaContainer.backgroundColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0x252528) : UIColor.gfpColor(rgbInt: 0xFFFFFF)
        self.ctaBorderLine.backgroundColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0xFFFFFF, alpha: 0.08) : UIColor.gfpColor(rgbInt: 0x000000, alpha: 0.04)
    }
}

extension CustomTemplateView: GFPNativeTemplateViewProtocol {
    //MARK: GFPNativeAssetViewProtocol
    public func mediaContainerView() -> GFPMediaView? {
        self.mediaView
    }
    public func iconContainerView() -> UIImageView? {
        self.iconView
    }

    public func titleAssetView() -> UILabel? {
        self.titleLabel
    }

    public func advertiseAssetView() -> UILabel? {
        self.advertiserLabel
    }

    public func bodyAssetView() -> UILabel? {
        self.bodyLabel
    }

    public func ctaAssetView() -> UILabel? {
        self.callToActionLabel
    }

    public func adChoicesContainerView() -> UIView? {
        self.adChoicesView
    }

    public func serviceAdBadgeContainerView() -> UIView? {
        self.adBadgeImage
    }

    //MARK: GFPNativeTemplateViewProtocol
    public static func createView() -> UIView? {
        let view = Bundle.main.loadNibNamed("CustomTemplateView", owner: nil)?.first
        return view as? UIView
    }

    public func bind(with asset: (any GFPNativeAssetProtocol)?) {
        guard let asset = asset else { self.asset = nil; return }
        
        self.asset = asset

        if asset.hasIconImage {
            self.iconView.isHidden = false
        } else {
            self.iconView.isHidden = true
        }

        self.titleLabel.text = asset.title
        self.advertiserLabel.text = asset.advertiser

        // topLabel은 title > sponsor 우선 순위
        let isHiddenTitle = GFPStringUtils.isEmpty(asset.title)

        self.titleLabel.isHidden = isHiddenTitle
        self.advertiserLabel.isHidden = !isHiddenTitle

        if GFPStringUtils.isEmpty(asset.body) {
            self.bodyContainerHeight.constant = 0
        } else {
            self.bodyLabel.text = asset.body
        }
        
        if GFPStringUtils.isEmpty(asset.callToAction) {
            self.ctaContainerHeight.constant = 0
        } else {
            self.callToActionLabel.text = asset.callToAction
        }

        self.adjustSizeAndLayout()
    }

    public func changeStyle(with isDarkMode: Bool) {
        self.isDarkMode = isDarkMode

//        self.backgroundColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0x39393C) : UIColor.gfpColor(rgbInt: 0xFFFFFF)
        self.backgroundColor = UIColor.red //custom template's testColor

        let adBadgeName = isDarkMode ? "template_ad_badge_dark" : "template_ad_badge"
        self.adBadgeImage?.image = UIImage(named: adBadgeName)

        self.titleLabel.textColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0x929294) : UIColor.gfpColor(rgbInt: 0x757575)
        self.advertiserLabel.textColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0x929294) : UIColor.gfpColor(rgbInt: 0x757575)
        
        self.bodyLabel.textColor = isDarkMode ? UIColor.gfpColor(rgbInt: 0xE5E5E5) : UIColor.gfpColor(rgbInt: 0x2A2A2C)

        self.changeCallToActionStyle(isDarkMode: isDarkMode)
    }

    public func estimateHeight() -> CGFloat {
        return self.topContainerHeight.constant + self.bodyContainerHeight.constant + self.mediaBodyMargin.constant + self.mediaViewHeight.constant + self.ctaContainerHeight.constant
    }
}

extension CustomTemplateView : GFPUserInterestDelegate {
    public func ad(_ ad: NSObject!, didChangeUserInterest userInterest: Bool) {
        if userInterest {
            UIView.animate(withDuration: 0.4) {
                if let highlightBgColor = self.asset?.callToActionOption?.highlightBgColor {
                    self.ctaContainer.backgroundColor = highlightBgColor
                } else {
                    self.ctaContainer.backgroundColor = GFPLabelOption.defaultHighlightBgColor
                }

                self.ctaLabelRichtImage.image = UIImage(named: "template_nn_cta_arrow_withBG")
                self.callToActionLabel.textColor = UIColor.gfpColor(rgbInt: 0xFFFFFF)
                self.ctaBorderLine.backgroundColor = UIColor.gfpColor(rgbInt: 0xFFFFFF, alpha: 0.08)
            }
        } else {
            self.changeCallToActionStyle(isDarkMode: self.isDarkMode)
        }
    }
}
