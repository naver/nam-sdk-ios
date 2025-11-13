// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "GFPSDK",

    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDK",
            type: .static,
            targets: ["Core", "AdRenderer_Resource", "MediationNDA_Resource", "MediationNDAVideo_Resource"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/robbiehanson/KissXML.git", exact: "5.3.3"),
        .package(url: "https://github.com/naver/nas-sdk-ios.git", .upToNextMinor(from: "1.3.1"))
    ],
    targets: [
        // core
        .binaryTarget(
            name: "Core_Binary",
            path: "NAMSDK/SPM/xcframework/GFPSDK.xcframework"
        ),
        .binaryTarget (
            name: "OMSDK_Binary",
            path: "NAMSDK/xcframework/libraries/OMSDK_Navercorp.xcframework"
        ),
        .target(
            name: "Core",
            dependencies: [
                "Core_Binary",
                "OMSDK_Binary",
                "KissXML",

                .product(name: "NaverAdsServices", package: "nas-sdk-ios")
            ],
            path: "NAMSDK/SPM/Sources/Core",
            resources: [
                .process("../../../resourcebundle/GFPSDKResource.bundle"),
                .process("../../../xcframework/GFPSDK.xcframework/ios-arm64/GFPSDK.framework/PrivacyInfo.xcprivacy")
            ]
        ),
        .target(
            name: "AdRenderer_Resource",
            path: "NAMSDK/SPM/Sources/AdRenderer",
            resources: [
                .process("../../../resourcebundle/GFPSDKRendererResource.bundle")
            ]
        ),
        .target(
            name: "MediationNDA_Resource",
            path: "NAMSDK/SPM/Sources/MediationNDA",
            resources: [
                .process("../../../resourcebundle/GFPNDAMraidResource.bundle"),
                .process("../../../resourcebundle/GFPNDANativeResource.bundle")
            ]
        ),
        .target(
            name: "MediationNDAVideo_Resource",
            path: "NAMSDK/SPM/Sources/MediationNDAVideo",
            resources: [
                .process("../../../resourcebundle/GFPNDAVideoResource.bundle"),
                .process("../../../resourcebundle/GFPNDANativeResource.bundle")
            ]
        ),
        
        // Test
        .testTarget(
            name: "GFPSDKTests",
            dependencies: ["Core", "AdRenderer_Resource", "MediationNDA_Resource", "MediationNDAVideo_Resource"],
            path: "NAMSDK/SPM/Tests"
        )
    ]
)
