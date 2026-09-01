// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "GFPSDKMediationDFP",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDKMediationDFP",
            targets: ["MediationDFP"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/naver/nam-sdk-ios.git", .upToNextMajor(from: "8.20.0")),
        .package(url: "https://github.com/googleads/swift-package-manager-google-mobile-ads.git", exact: "12.14.0"),
    ],
    targets: [
        .binaryTarget(
            name: "GFPSDKMediationDFP_Binary",
            path: "../../../../AdMediationSDK/DFP/GFPSDKMediationDFP.xcframework"
        ),
        .target(
            name: "MediationDFP",
            dependencies: [
                "GFPSDKMediationDFP_Binary",
                .product(name: "GFPSDK", package: "nam-sdk-ios"),
                .product(name: "GoogleMobileAds", package: "swift-package-manager-google-mobile-ads"),
            ],
            path: "Sources/Core"
        ),
    ]
)
