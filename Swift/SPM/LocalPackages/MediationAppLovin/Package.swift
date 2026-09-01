// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationAppLovin",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationAppLovin",
            targets: ["MediationAppLovin"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package.git", exact: "13.5.1"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationAppLovin_Binary",
            path: "../../../../AdMediationSDK/AppLovin/GFPSDKMediationAppLovin.xcframework"
        ),
        .target(
            name: "MediationAppLovin",
            dependencies: [
                "GFPSDKMediationAppLovin_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "AppLovinSDK", package: "AppLovin-MAX-Swift-Package"),
            ],
            path: "Sources/Core"
        ),
    ]
)
