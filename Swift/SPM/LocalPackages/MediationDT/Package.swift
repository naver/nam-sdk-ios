// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationDT",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationDT",
            targets: ["MediationDT"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/inner-active/DTExchangeSDK-iOS-SPM.git", exact: "8.4.2"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationDT_Binary",
            path: "../../../../AdMediationSDK/DT/GFPSDKMediationDT.xcframework"
        ),
        .target(
            name: "MediationDT",
            dependencies: [
                "GFPSDKMediationDT_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "DTExchangeSDK", package: "DTExchangeSDK-iOS-SPM"),
            ],
            path: "Sources/Core"
        ),
    ]
)
