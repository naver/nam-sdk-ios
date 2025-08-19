//
//  TableViewAdExample.swift
//  SwiftSample
//
//  Created by USER on 2023/05/12.
//

import UIKit
import GFPSDK

class TableViewAdExample: AdViewController {

    private var tableView = UITableView()

    private var dedupManager = GFPAdDedupeManager()

    private var indexByAdLoader: [GFPAdLoader : IndexPath] = .init()
    private var adViewByIndex: [IndexPath : UIView] = .init()

    var numberOfRows: Int = 30

    var adAtEveryNumberOfCells: Int = 5

    private func shouldBeAdCell(forIndexPath indexPath: IndexPath) -> Bool {
        (indexPath.row + 1) % adAtEveryNumberOfCells == 0
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.addSubview(tableView)
        tableView.delegate = self
        tableView.dataSource = self
        if #available(iOS 13.0, *) {
            tableView.backgroundColor = .systemGroupedBackground
        }
        tableView.snp.makeConstraints { make in
            make.centerX.centerY.width.height.equalToSuperview()
        }

        tableView.register(AdCell.self, forCellReuseIdentifier: AdCell.identifier)
        tableView.register(MockContentCell.self, forCellReuseIdentifier: "asdf")
    }

    override func loadAd() {
        super.loadAd()

        indexByAdLoader.removeAll()
        adViewByIndex.removeAll()

        numberOfRows = 30
    }


}

extension TableViewAdExample: UITableViewDelegate, UITableViewDataSource {

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        numberOfRows
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        100
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if shouldBeAdCell(forIndexPath: indexPath) {
            let cell = tableView.dequeueReusableCell(withIdentifier: AdCell.identifier) as? AdCell ?? AdCell()

            if let adView = adViewByIndex[indexPath] {
                cell.adView = adView
            } else {
                let adParam = SettingsManager.shared.adParam
                let adLoader = GFPAdLoader.init(unitID: self.unitId ?? "", rootViewController: self, adParam: adParam)
                adLoader.setBannerDelegate(self, bannerOptions: SettingsManager.shared.bannerOptions)
                adLoader.setNativeDelegate(self, nativeOptions: SettingsManager.shared.nativeOptions)
                adLoader.setNativeSimpleDelegate(self, nativeSimpleOptions: SettingsManager.shared.nativeSimpleOptions)
                adLoader.delegate = self
                adLoader.loadAd()

                indexByAdLoader[adLoader] = indexPath
            }

            return cell

        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "asdf") as? MockContentCell ?? MockContentCell()

            cell.configure(withIndexPath: indexPath)

            return cell
        }
    }

    func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        if indexPath.row == numberOfRows - 1 {
            DispatchQueue.main.async { [weak self] in
                self?.numberOfRows += 30
                tableView.reloadData()
            }
        }
    }
}

extension TableViewAdExample: GFPAdLoaderDelegate {
    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceiveBannerAd bannerView: GFPBannerView!) {
        guard let indexPath = indexByAdLoader[unifiedAdLoader] else {return}
        bannerView.showDebugBorder(withColor: .red)
        indexByAdLoader[unifiedAdLoader] = nil
        adViewByIndex[indexPath] = bannerView
        self.tableView.reloadRows(at: [indexPath], with: .automatic)

        addLog("BannerAd loaded, \(indexPath)")
    }

    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeAd: GFPNativeAd!) {
        guard let indexPath = indexByAdLoader[unifiedAdLoader] else {return}
        indexByAdLoader[unifiedAdLoader] = nil
        guard let nativeAdView = UIView.loadWithBundle(aBundle: .main, nibName: "GFPNativeAdView") as? GFPNativeAdView else {return}
        nativeAdView.showDebugBorder(withColor: .blue)
        adViewByIndex[indexPath] = nativeAdView
        self.tableView.reloadRows(at: [indexPath], with: .automatic)

        addLog("NativeAd loaded, \(indexPath)")
    }

    func adLoader(_ unifiedAdLoader: GFPAdLoader!, didReceive nativeSimpleAd: GFPNativeSimpleAd!) {
        guard let indexPath = indexByAdLoader[unifiedAdLoader] else {return}
        indexByAdLoader[unifiedAdLoader] = nil
        guard let nativeSimpleAd = UIView.loadWithBundle(aBundle: .main, nibName: "GFPNativeSimpleAdView") as? GFPNativeSimpleAdView else {return}
        nativeSimpleAd.showDebugBorder(withColor: .green)
        adViewByIndex[indexPath] = nativeSimpleAd
        self.tableView.reloadRows(at: [indexPath], with: .automatic)

        addLog("NativeSimpleAd loaded, \(indexPath)")
    }
}

extension TableViewAdExample: GFPBannerViewDelegate {
    func bannerView(_ bannerView: GFPBannerView, didChangeWith size: GFPBannerAdSize) {
        guard let indexPath = adViewByIndex.first(where: { $0.value == bannerView })?.key else {return}
        adViewByIndex[indexPath] = bannerView
        self.tableView.reloadRows(at: [indexPath], with: .automatic)
    }
}

extension TableViewAdExample: GFPNativeAdDelegate {

}

extension TableViewAdExample: GFPNativeSimpleAdDelegate {

}
