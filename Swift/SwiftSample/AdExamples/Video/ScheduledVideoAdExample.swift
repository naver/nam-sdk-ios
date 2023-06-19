//
//  ScheduledVideoAdExample.swift
//  SwiftSample
//
//  Created by USER on 2023/05/30.
//

import GFPSDK
import SnapKit

class ScheduledVideoAdExample: AdViewController {

    var scheduleManager: GFPVideoAdScheduleManager?

    var player = AVPlayer()

    var playerVc = CustomPlayerVC()

    var duration: CMTime = .init(seconds: 60, preferredTimescale: .max)

    private let TestVideoURL: URL = .init(string: "http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/ElephantsDream.mp4")!

    override func viewDidLoad() {
        super.viewDidLoad()

        configure()
    }

    private func configure() {
        let player = AVPlayer(url: TestVideoURL)
        self.player = player
        self.duration = player.currentItem?.duration ?? .zero

        let playerVc = CustomPlayerVC()
        self.playerVc = playerVc
        self.addChild(playerVc)
        playerVc.didMove(toParent: self)
        self.view.addSubview(playerVc.view)
        playerVc.player = player
        playerVc.view.snp.makeConstraints { make in
            make.width.centerX.top.equalTo(self.view)
            make.height.equalTo(300)
        }
    }

    override func loadAd() {
        super.loadAd()

        guard let scheduleManager = configureSDKBySwiftSample() else { return }
        self.scheduleManager = scheduleManager

        scheduleManager.loadSchedule()
    }

    private func configureSDKBySwiftSample() -> GFPVideoAdScheduleManager? {
        guard let unitId = self.unitId else {
            addLog("No unitId specified.")
            return nil
        }

        let scheduleParam = GFPAdScheduleParam(
            placementPolicy: .pre,
            duration: CMTimeGetSeconds(duration),
            param: SettingsManager.shared.adParam)

        let scheduleManager = GFPVideoAdScheduleManager(
            adScheduleID: unitId,
            contentPlayer: player,
            videoView: self.playerVc.view,
            scheduleParam: scheduleParam)

        scheduleManager.renderingSetting = SettingsManager.shared.videoRenderingSetting
        scheduleManager.playerSetting = SettingsManager.shared.videoPlayerSetting
        scheduleManager.volume = 1.0
        scheduleManager.rootViewController = self
        scheduleManager.delegate = self
        scheduleManager.qoeDelegate = self
        scheduleManager.pipDelegate = self

        return scheduleManager
    }

    override func didMove(toParent parent: UIViewController?) {
        super.didMove(toParent: parent)
        if parent == nil {
            self.playerVc.view.removeFromSuperview()
            self.playerVc.removeFromParent()
            self.playerVc.didMove(toParent: nil)
        }
    }
}

extension ScheduledVideoAdExample: AVPlayerPlaybackCoordinatorDelegate {
    
}

extension ScheduledVideoAdExample: GFPVideoAdScheduleManagerDelegate {
    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didLoadedSchedule aAdBreak: [GFPVideoAdBreak]?) {
        addLog("Schedule Manager Did Load Schedule.")
        self.duration = self.player.currentItem?.duration ?? .init(seconds: 0, preferredTimescale: .max)
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didStartReadyAd aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Can Start Ad.")

        self.scheduleManager?.start(with: true)
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didStartAd aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Did Start Ad.")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didSkipAdWith info: GFPVideoAdQoeInfo) {
        addLog("Schedule Manager Did Skip Ad.")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didCompleteAd aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Did End Ad.")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, wasClicked aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Did Click Ad.")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didPauseAd aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Did Pause Ad.")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didResumeAd aResult: GFPVideoAdBreakResult) {
        addLog("Schedule Manager Did Resume Ad.")
    }
    
    func scheduleManagerContentResumeRequest(_ aScheduleAdManager: GFPVideoAdScheduleManager) {
        addLog("Schedule Manager Will Resume Content")

        player.play()
    }

}

extension ScheduledVideoAdExample: GFPVideoAdScheduleManagerQoeDelegate {
    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didReciveAdErrorForQoe error: GFPError) {
        addLog("- [QOE] Did Recieve Error -\n\(error.localizedDescription)")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didCompleteAdWitQoeInfo info: GFPVideoAdQoeInfo) {
        addLog("- [QOE] Did Complete with QOE -\n\(info.description)")
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didReceiveAdClickEventWitQoeInfo info: GFPVideoAdQoeInfo) {
        addLog("- [QOE] Did Click with QOE -\n\(info.description)")
    }
}

extension ScheduledVideoAdExample: GFPVideoAdScheduleManagerPIPDelegate {
    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didTappedCloseBtnInPIP aResult: GFPVideoAdBreakResult) {
        self.view.removeFromSuperview()
        self.removeFromParent()
        self.didMove(toParent: nil)
    }

    func scheduleManager(_ aScheduleAdManager: GFPVideoAdScheduleManager, didTappedReturnBtnInPIP aResult: GFPVideoAdBreakResult) {
        self.playerVc.isPip = false
    }
}
