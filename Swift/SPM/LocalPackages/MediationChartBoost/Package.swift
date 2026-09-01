// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationChartBoost",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationChartBoost",
            targets: ["MediationChartBoost"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/ChartBoost/chartboost-monetization-ios-sdk.git", exact: "9.13.0"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationChartBoost_Binary",
            path: "../../../../AdMediationSDK/ChartBoost/GFPSDKMediationChartBoost.xcframework"
        ),
        .target(
            name: "MediationChartBoost",
            dependencies: [
                "GFPSDKMediationChartBoost_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "ChartboostSDK", package: "chartboost-monetization-ios-sdk"),
            ],
            path: "Sources/Core"
        ),
    ]
)
