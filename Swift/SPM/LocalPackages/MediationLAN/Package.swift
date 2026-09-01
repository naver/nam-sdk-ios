// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationLAN",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationLAN",
            targets: ["MediationLAN"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/ly-ads-network/swift-package-manager-fivead.git", exact: "3.0.1"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationLAN_Binary",
            path: "../../../../AdMediationSDK/LAN/GFPSDKMediationLAN.xcframework"
        ),
        .target(
            name: "MediationLAN",
            dependencies: [
                "GFPSDKMediationLAN_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "FiveAd", package: "swift-package-manager-fivead"),
            ],
            path: "Sources/Core"
        ),
    ]
)
