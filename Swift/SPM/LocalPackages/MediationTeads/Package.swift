// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationTeads",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationTeads",
            targets: ["MediationTeads"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.22.0")),
        .package(url: "https://github.com/teads/TeadsSDK-iOS.git", exact: "6.0.10"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationTeads_Binary",
            path: "../../../../AdMediationSDK/Teads/GFPSDKMediationTeads.xcframework"
        ),
        .target(
            name: "MediationTeads",
            dependencies: [
                "GFPSDKMediationTeads_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "TeadsSDK", package: "TeadsSDK-iOS"),
            ],
            path: "Sources/Core"
        ),
    ]
)
