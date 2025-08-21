//
//  GFPLanguageType.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, GFPLanguageType) {
    GFPLanguageType_none,
    GFPLanguageType_ko,
    GFPLanguageType_en,
    GFPLanguageType_es,
    GFPLanguageType_fr,
    GFPLanguageType_id,
    GFPLanguageType_th,
    GFPLanguageType_zh_Hant,
    GFPLanguageType_zh_Hans,
    GFPLanguageType_ja,
    GFPLanguageType_de,
};


@protocol GFPLanguagePresentable <NSObject>

@property (nonatomic, readonly, assign) GFPLanguageType preferredLanguage;

@end
