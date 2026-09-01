// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationFAN",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationFAN",
            targets: ["MediationFAN"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/facebook/FBAudienceNetwork.git", exact: "6.21.1"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationFAN_Binary",
            path: "../../../../AdMediationSDK/FAN/GFPSDKMediationFAN.xcframework"
        ),
        .target(
            name: "MediationFAN",
            dependencies: [
                "GFPSDKMediationFAN_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "FBAudienceNetwork", package: "FBAudienceNetwork"),
            ],
            path: "Sources/Core"
        ),
    ]
)
