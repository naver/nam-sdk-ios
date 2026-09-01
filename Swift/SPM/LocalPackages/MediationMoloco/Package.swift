// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationMoloco",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationMoloco",
            targets: ["MediationMoloco"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.22.0")),
        .package(url: "https://github.com/moloco/moloco-sdk-ios-spm.git", exact: "4.6.1"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationMoloco_Binary",
            path: "../../../../AdMediationSDK/Moloco/GFPSDKMediationMoloco.xcframework"
        ),
        .target(
            name: "MediationMoloco",
            dependencies: [
                "GFPSDKMediationMoloco_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "MolocoSDK", package: "moloco-sdk-ios-spm"),
            ],
            path: "Sources/Core"
        ),
    ]
)
