//
//  VideoAdExample.swift
//  SwiftSample
//
//  Created by USER on 2023/05/30.
//

import GFPSDK

class VideoAdExample: AdViewController {

    var videoAdManager: GFPVideoAdManager?

    var videoView = UIView()

    override func viewDidLoad() {
        super.viewDidLoad()

        configure()
    }

    private func configure() {
        self.view.addSubview(videoView)
        videoView.snp.makeConstraints { make in
            make.width.top.centerX.equalToSuperview()
            make.height.equalTo(200)
        }
    }

    override func loadAd() {
        guard let videoAdManager = configureSDKBySwiftSample() else {return}
        self.videoAdManager = videoAdManager
        videoAdManager.load()
    }

    private func configureSDKBySwiftSample() -> GFPVideoAdManager? {
        guard let unitId = self.unitId else {
            addLog("No unitId specified.")
            return nil
        }

        let adParam = SettingsManager.shared.adParam
        let videoAdManager = GFPVideoAdManager(
            adUnitID: unitId,
            videoView: self.videoView,
            adParam: adParam
        )

        videoAdManager.renderingSetting = SettingsManager.shared.videoRenderingSetting
        videoAdManager.playerSetting = SettingsManager.shared.videoPlayerSetting
        videoAdManager.requestTimeoutInterval = SettingsManager.shared.timeout(forType: .videoAd)
        videoAdManager.adParam = SettingsManager.shared.adParam
        videoAdManager.volume = 1.0
        videoAdManager.rootViewController = self
        videoAdManager.delegate = self
        videoAdManager.qoeDelegate = self
        videoAdManager.pipDelegate = self

        return videoAdManager
    }
}

extension VideoAdExample: GFPVideoAdManagerDelegate {
    func videoAdManagerDidLoadAd(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad Did Load. Provider:\(videoAdManager.adInfo.adProviderName), url:\(videoAdManager.adInfo.url?.absoluteString ?? ""), ResponseInfo:\(videoAdManager.responseInfo)")

        videoAdManager.start()
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, didFailWithError error: GFPError, responseInfo : GFPLoadResponseInfo) {
        addLog("Video Ad Failed with Error:\(error.localizedDescription), ResponseInfo:\(videoAdManager.responseInfo)")
    }

    func videoAdManagerDidStartAd(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad did Start.")
    }

    func videoAdManagerDidCompleteAd(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad Did Complete.")
    }

    func videoAdWasClicked(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad was Clicked.")
    }

    func videoAdManagerDidPauseAd(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad did Pause Ad.")
    }

    func videoAdManagerDidResumeAd(_ videoAdManager: GFPVideoAdManager) {
        addLog("Video Ad did Resume Ad.")
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, didChangeCurrentTime mediaTime: TimeInterval, totalTime: TimeInterval) {
        addLog("Video Ad did Change Current Time \(String(format: "%.1f", mediaTime))/\(String(format: "%.1f", totalTime))")
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, playControlWillShow duration: TimeInterval) {
        addLog("Video Ad Play Control Will Show.")
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, playControlWillHide duration: TimeInterval) {
        addLog("Video Ad Play Control Will Hide.")
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, didReceive accessLog: AVPlayerItemAccessLog) {
        addLog("Video Ad AccessLog:\(accessLog)")
    }

    func videoAdManager(_ videoAdManager: GFPVideoAdManager, didReceive accessLogEvents: [AVPlayerItemAccessLogEvent]) {
    }
}


extension VideoAdExample: GFPVideoAdQoeDelegate {

}

extension VideoAdExample: GFPVideoAdPIPDelegate {

}
