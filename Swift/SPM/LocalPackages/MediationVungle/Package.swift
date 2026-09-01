// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationVungle",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationVungle",
            targets: ["MediationVungle"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/Vungle/VungleAdsSDK-SwiftPackageManager.git", exact: "7.6.2"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationVungle_Binary",
            path: "../../../../AdMediationSDK/Vungle/GFPSDKMediationVungle.xcframework"
        ),
        .target(
            name: "MediationVungle",
            dependencies: [
                "GFPSDKMediationVungle_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "VungleAdsSDK", package: "VungleAdsSDK-SwiftPackageManager"),
            ],
            path: "Sources/Core"
        ),
    ]
)
