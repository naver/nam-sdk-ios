// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "GFPSDK",
    defaultLocalization: "en",

    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "GFPSDK",
            targets: ["Core", "AdRenderer", "MediationNDA", "MediationNDAVideo", "MediationNDARich"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/robbiehanson/KissXML.git", exact: "5.3.3"),
        .package(url: "https://github.com/naver/nas-sdk-ios.git", exact: "1.1.2-test")
    ],
    targets: [
        // core
        .binaryTarget(
            name: "Core_Binary",
            path: "NAMSDK/xcframework/GFPSDK.xcframework"
        ),
        .binaryTarget (
            name: "OMSDK_Binary",
            path: "NAMSDK/xcframework/libraries/OMSDK_Navercorp.xcframework"
        ),
        .target(
            name: "Core",
            dependencies: ["Core_Binary", "OMSDK_Binary", "KissXML", "NaverAdsServices"],
            path: "NAMSDK/SPM_Dummy/Core",
            resources: [
                .copy("../../resourcebundle/GFPSDKResource.bundle")
            ]
        ),

        // adRenderer
        .binaryTarget(
            name: "AdRenderer_Binary",
            path: "NAMSDK/xcframework/GFPSDKAdRenderer.xcframework"
        ),
        .target(
            name: "AdRenderer",
            dependencies: ["AdRenderer_Binary", "Core"],
            path: "NAMSDK/SPM_Dummy/AdRenderer",
            resources: [
                .copy("../../resourcebundle/GFPSDKRendererResource.bundle")
            ]
        ),

        // NDA
        .binaryTarget(
            name: "MediationNDA_Binary",
            path: "NAMSDK/xcframework/GFPSDKMediationNDA.xcframework"
        ),
        .target(
            name: "MediationNDA",
            dependencies: ["MediationNDA_Binary", "Core"],
            path: "NAMSDK/SPM_Dummy/MediationNDA",
            resources: [
                .copy("../../resourcebundle/GFPNDAMraidResource.bundle"),
                .copy("../../resourcebundle/GFPNDANativeResource.bundle")
            ]
        ),

        // NDAVideo
        .binaryTarget(
            name: "MediationNDAVideo_Binary",
            path: "NAMSDK/xcframework/GFPSDKMediationNDAVideo.xcframework"
        ),
        .target(
            name: "MediationNDAVideo",
            dependencies: ["MediationNDAVideo_Binary", "Core", "MediationNDA"],
            path: "NAMSDK/SPM_Dummy/MediationNDAVideo",
            resources: [
                .copy("../../resourcebundle/GFPNDAVideoResource.bundle"),
                .copy("../../resourcebundle/GFPNDANativeResource.bundle")
            ]
        ),

        // NDARich
        .binaryTarget(
            name: "MediationNDARich_Binary",
            path: "NAMSDK/xcframework/GFPSDKMediationNDARich.xcframework"
        ),
        .target(
            name: "MediationNDARich",
            dependencies: ["MediationNDARich_Binary", "Core", "MediationNDA", "MediationNDAVideo", "AdRenderer"],
            path: "NAMSDK/SPM_Dummy/MediationNDARich"
        ),

        // Test
        .testTarget(
            name: "GFPSDKTests",
            dependencies: ["Core", "AdRenderer", "MediationNDA", "MediationNDAVideo", "MediationNDARich"],
            path: "NAMSDK/SPM_Tests"
        )
    ]
)
