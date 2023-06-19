//
//  CustomPlayerView.swift
//  SwiftSample
//
//  Created by USER on 2023/05/31.
//

import GFPSDK
import UIKit
import AVKit
import SnapKit

fileprivate extension String {
    static let MuteKey: String = "CustomPlayerVC.Mute"
}

class CustomPlayerVC: AVPlayerViewController {

    lazy var overlay: UIView = {
        let overlay = UIView()
        self.view.addSubview(overlay)
        overlay.backgroundColor = .lightGray.withAlphaComponent(0.3)
        overlay.snp.remakeConstraints { make in
            make.width.height.centerX.centerY.equalToSuperview()
        }
        return overlay }()

    lazy var playPauseButton: UIButton = {
        let playPauseButton = UIButton()
        overlay.addSubview(playPauseButton)
        playPauseButton.setImage(UIImage(named: "play.fill"), for: .normal)
        playPauseButton.setImage(UIImage(named: "pause"), for: .selected)
        playPauseButton.imageView?.contentMode = .scaleAspectFit
        playPauseButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.65)
        }
        playPauseButton.snp.makeConstraints { make in
            make.width.height.equalTo(50)
            make.centerX.centerY.equalToSuperview()
        }
        return playPauseButton }()

    lazy var fullscreenButton: UIButton = {
        let fullscreenButton = UIButton()
        overlay.addSubview(fullscreenButton)
        fullscreenButton.setImage(UIImage(named: "square"), for: .normal)
        fullscreenButton.imageView?.contentMode = .scaleAspectFit
        fullscreenButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.7)
        }
        fullscreenButton.snp.makeConstraints { make in
            make.width.height.equalTo(30)
            make.top.equalToSuperview().offset(10)
            make.right.equalToSuperview().offset(-10)
        }
        return fullscreenButton }()

    lazy var pipButton: UIButton = {
        let pipButton = UIButton()
        overlay.addSubview(pipButton)
        pipButton.setImage(UIImage(named: "square.split.bottomrightquarter"), for: .normal)
        pipButton.imageView?.contentMode = .scaleAspectFit
        pipButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.7)
        }
        return pipButton }()

    lazy var muteButton: UIButton = {
        let muteButton = UIButton()
        overlay.addSubview(muteButton)
        muteButton.setImage(UIImage(named: "speaker.fill"), for: .normal)
        muteButton.setImage(UIImage(named: "speaker.slash.fill"), for: .selected)
        muteButton.imageView?.contentMode = .scaleAspectFit
        muteButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.5)
        }
        muteButton.snp.makeConstraints { make in
            make.width.height.equalTo(30)
            make.top.equalToSuperview().offset(10)
            make.left.equalToSuperview().offset(10)
        }
        return muteButton
    }()

    lazy var goforwardButton: UIButton = {
        let goforwardButton = UIButton()
        overlay.addSubview(goforwardButton)
        goforwardButton.setImage(UIImage(named: "goforward.15"), for: .normal)
        goforwardButton.imageView?.contentMode = .scaleAspectFit
        goforwardButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.65)
        }
        let overlayLeftHalf = UILayoutGuide()
        overlay.addLayoutGuide(overlayLeftHalf)
        overlayLeftHalf.snp.makeConstraints { make in
            make.width.equalTo(overlay.snp.width).multipliedBy(1.0/4.0)
            make.left.equalTo(overlay.snp.centerX)
        }
        goforwardButton.snp.makeConstraints { make in
            make.width.height.equalTo(45)
            make.centerY.equalTo(playPauseButton)
            make.centerX.equalTo(overlayLeftHalf.snp.right)
        }
        return goforwardButton }()

    lazy var gobackwardButton: UIButton = {
        let gobackwardButton = UIButton()
        overlay.addSubview(gobackwardButton)
        gobackwardButton.setImage(UIImage(named: "gobackward.15"), for: .normal)
        gobackwardButton.imageView?.contentMode = .scaleAspectFit
        gobackwardButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.65)
        }
        let overlayRightHalf = UILayoutGuide()
        overlay.addLayoutGuide(overlayRightHalf)
        overlayRightHalf.snp.makeConstraints { make in
            make.width.equalTo(overlay.snp.width).multipliedBy(1.0/4.0)
            make.right.equalTo(overlay.snp.centerX)
        }
        gobackwardButton.snp.makeConstraints { make in
            make.width.height.equalTo(45)
            make.centerY.equalTo(playPauseButton)
            make.centerX.equalTo(overlayRightHalf.snp.left)
        }
        return gobackwardButton }()

    lazy var progressBar: UIView = {
        let progressBar = UIView()
        overlay.addSubview(progressBar)
        progressBar.snp.makeConstraints { make in
            make.left.bottom.right.equalToSuperview()
            make.height.equalTo(30)
        }
        return progressBar }()

    lazy var currentTimeLabel: UILabel = {
        let currentTimeLabel = UILabel()
        progressBar.addSubview(currentTimeLabel)
        currentTimeLabel.font = .systemFont(ofSize: 12)
        currentTimeLabel.textColor = .white
        currentTimeLabel.textAlignment = .center
        currentTimeLabel.text = "0:00"
        currentTimeLabel.snp.makeConstraints { make in
            make.centerY.equalToSuperview()
            make.left.equalToSuperview().offset(5)
            make.width.equalTo(60)
        }
        return currentTimeLabel }()

    lazy var durationTimeLabel: UILabel = {
        let durationTimeLabel = UILabel()
        progressBar.addSubview(durationTimeLabel)
        durationTimeLabel.font = .systemFont(ofSize: 12)
        durationTimeLabel.textColor = .white
        durationTimeLabel.textAlignment = .center
        durationTimeLabel.text = "0:00"
        durationTimeLabel.snp.makeConstraints { make in
            make.centerY.equalToSuperview()
            make.right.equalToSuperview().offset(-5)
            make.width.equalTo(60)
        }
        return durationTimeLabel }()

    lazy var slider: UISlider = {
        let slider = UISlider()
        slider.tintColor = .white
        slider.setThumbImage(UIImage(), for: .disabled)
        progressBar.addSubview(slider)
        return slider }()

    // MARK: - for PiP
    lazy var closePipButton: UIButton = {
        let closePipButton = UIButton()
        overlay.addSubview(closePipButton)
        closePipButton.setImage(UIImage(named: "xmark"), for: .normal)
        closePipButton.contentMode = .scaleAspectFit
        closePipButton.imageView?.snp.makeConstraints { make in
            make.width.height.equalToSuperview().multipliedBy(0.5)
        }
        closePipButton.snp.makeConstraints { make in
            make.width.height.equalTo(30)
            make.top.left.equalToSuperview().offset(10)
        }
        return closePipButton
    }()

    override var player: AVPlayer? {
        didSet {
            slider.minimumValue = 0.0

            let isMuted: Bool = UserDefaults.standard.bool(forKey: .MuteKey)
            player?.isMuted = isMuted

            updateButtons()

            player?.addPeriodicTimeObserver(forInterval: .init(seconds: 1, preferredTimescale: 600), queue: .main) { [weak self] time in
                self?.slider.maximumValue = max(Float(self?.player?.currentItem?.duration.seconds ?? 1.0), 1.0)
                self?.slider.value = Float(time.seconds)

                let formatter = DateComponentsFormatter()
                if self?.player?.currentItem?.duration.seconds ?? 0 <= 3600 {
                    formatter.allowedUnits = [.minute, .second]
                } else {
                    formatter.allowedUnits = [.hour, .minute, .second]
                }
                formatter.unitsStyle = .positional
                formatter.zeroFormattingBehavior = .pad

                self?.currentTimeLabel.text = formatter.string(from: TimeInterval(Int(self?.player?.currentItem?.currentTime().seconds ?? 0)))
                self?.durationTimeLabel.text = formatter.string(from: TimeInterval(Int(self?.player?.currentItem?.duration.seconds ?? 0)))

                self?.updateButtons()
            }
        }
    }

    var isPlaying: Bool {
        player?.rate != 0 && player?.error == nil && player?.timeControlStatus == .playing
    }

    var isShowingOverlay: Bool {
        !overlay.isHidden
    }

    private var storedPip: Bool = false

    var isPip: Bool {
        get { storedPip }
        set {
            storedPip = newValue
            UIView.animate(withDuration: 0.2) {
                self.configureViews(forPip: self.isPip)
            }
            // TODO:
//            PipManager.shared.setPip(playerVc: self)
        }
    }

    init(isPip: Bool = false) {
        storedPip = isPip
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.showsPlaybackControls = false
        self.delegate = self

        configureViews(forPip: self.isPip)
        configureActions()
    }

    private func configureViews(forPip: Bool) {
        fullscreenButton.isHidden = forPip
        muteButton.isHidden = forPip
        currentTimeLabel.isHidden = forPip
        durationTimeLabel.isHidden = forPip
        slider.isEnabled = !forPip
        closePipButton.isHidden = !forPip

        if forPip {
            pipButton.snp.remakeConstraints { make in
                make.right.equalToSuperview().offset(-5)
                make.top.equalToSuperview().offset(5)
                make.width.height.equalTo(30)
            }

            slider.snp.remakeConstraints { make in
                make.centerY.equalToSuperview()
                make.left.equalToSuperview().offset(5)
                make.right.equalToSuperview().offset(-5)
            }
        } else {
            pipButton.snp.remakeConstraints { make in
                make.width.height.equalTo(30)
                make.top.equalToSuperview().offset(10)
                make.right.equalTo(fullscreenButton.snp.left).offset(-10)
            }

            slider.snp.remakeConstraints { make in
                make.centerY.equalToSuperview()
                make.left.equalTo(currentTimeLabel.snp.right)
                make.right.equalTo(durationTimeLabel.snp.left)
            }
        }
    }

    private func configureActions() {
        let viewTapped = UITapGestureRecognizer(target: self, action: #selector(onBackgroundTapped(_:)))
        self.view.addGestureRecognizer(viewTapped)

        let overlayTapped = UITapGestureRecognizer(target: self, action: #selector(onBackgroundTapped(_:)))
        overlay.addGestureRecognizer(overlayTapped)

        playPauseButton.addTarget(self, action: #selector(playPauseButtonTapped(_:)), for: .touchUpInside)
        playPauseButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        playPauseButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        fullscreenButton.addTarget(self, action: #selector(fullscreenButtonTapped(_:)), for: .touchUpInside)
        fullscreenButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        fullscreenButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        pipButton.addTarget(self, action: #selector(pipButtonTapped(_:)), for: .touchUpInside)
        pipButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        pipButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        closePipButton.addTarget(self, action: #selector(closePipButtonTapped(_:)), for: .touchUpInside)
        closePipButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        closePipButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        muteButton.addTarget(self, action: #selector(muteButtonTapped(_:)), for: .touchDown)
        muteButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        muteButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        goforwardButton.addTarget(self, action: #selector(goforwardButtonTapped(_:)), for: .touchDown)
        goforwardButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        goforwardButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        gobackwardButton.addTarget(self, action: #selector(gobackwardButtonTapped(_:)), for: .touchDown)
        gobackwardButton.addTarget(self, action: #selector(opacityEffect(_:)), for: .touchDown)
        gobackwardButton.addTarget(self, action: #selector(revertOpacity(_:)), for: [.touchCancel, .touchUpInside, .touchUpOutside])

        slider.addTarget(self, action: #selector(sliderChanged(_:)), for: .valueChanged)

        NotificationCenter.default.addObserver(
            self,
            selector:#selector(self.playerDidPlayToEndTime(note:)),
            name: NSNotification.Name.AVPlayerItemDidPlayToEndTime,
            object: player?.currentItem
        )
    }

    @objc private func onBackgroundTapped(_ sender: UITapGestureRecognizer) {
        if isShowingOverlay {
            overlay.isHidden = true
        } else {
            overlay.isHidden = false
            view.bringSubviewToFront(overlay)
        }
    }

    var didPlayToEndTime: Bool = false
    @objc private func playerDidPlayToEndTime(note: NSNotification) {
        didPlayToEndTime = true
        updateButtons()
    }

    @objc private func playPauseButtonTapped(_ sender: UIButton) {
        if sender.isSelected {
            player?.pause()
        } else {
            if didPlayToEndTime {
                seek(toSeconds: 0)
                didPlayToEndTime = false
            }
            player?.play()
        }
        updateButtons()
    }

    @objc private func fullscreenButtonTapped(_ sender: UIButton) {
        perform(NSSelectorFromString("enterFullScreenAnimated:completionHandler:"), with: true, with: nil)
    }

    @objc private func pipButtonTapped(_ sender: UIButton) {
        isPip.toggle()
    }

    @objc private func closePipButtonTapped(_ sender: UIButton) {
        self.view.removeFromSuperview()
        self.removeFromParent()
        self.didMove(toParent: nil)
//        PipManager.shared.cancelPip()
    }

    @objc private func muteButtonTapped(_ sender: UIButton) {
        player?.isMuted.toggle()
        UserDefaults.standard.set(player?.isMuted, forKey: .MuteKey)
        updateButtons()
    }

    @objc private func goforwardButtonTapped(_ sender: UIButton) {
        seek(byAddingSeconds: 15)
    }

    @objc private func gobackwardButtonTapped(_ sender: UIButton) {
        seek(byAddingSeconds: -15)
    }

    @objc private func opacityEffect(_ sender: UIButton) {
        sender.layer.opacity = 0.5
    }

    @objc private func revertOpacity(_ sender: UIButton) {
        sender.layer.opacity = 1
    }

    @objc private func sliderChanged(_ sender: UISlider) {
        seek(toSeconds: Double(sender.value))
    }

    private func seek(byAddingSeconds: Double) {
        guard let currentSeconds = self.player?.currentItem?.currentTime().seconds else {
            debugPrint("Failed to get player current time.")
            return
        }
        let seekTo: CMTime = .init(seconds: currentSeconds + byAddingSeconds, preferredTimescale: 600)
        self.player?.seek(to: seekTo, toleranceBefore: .zero, toleranceAfter: .zero)
    }

    private func seek(toSeconds: Double) {
        let seekTo: CMTime = .init(seconds: toSeconds, preferredTimescale: 600)
        self.player?.seek(to: seekTo, toleranceBefore: .zero, toleranceAfter: .zero)
    }

    private func updateButtons() {
        self.playPauseButton.isSelected = isPlaying
        self.muteButton.isSelected = self.player?.isMuted ?? false
    }
    
}

extension CustomPlayerVC: AVPlayerViewControllerDelegate {

    func playerViewController(_ playerViewController: AVPlayerViewController, willEndFullScreenPresentationWithAnimationCoordinator coordinator: UIViewControllerTransitionCoordinator) {
        self.showsPlaybackControls = false
    }

    func playerViewController(_ playerViewController: AVPlayerViewController, willBeginFullScreenPresentationWithAnimationCoordinator coordinator: UIViewControllerTransitionCoordinator) {
        self.showsPlaybackControls = true
    }

}
