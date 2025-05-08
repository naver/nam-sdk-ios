//
//  GFPOMIDInfoProtocol.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
	

@protocol GFPOMIDInfoPresentable <NSObject>

@property (readonly, nonatomic, strong, nullable) NSString *vendor;
@property (readonly, nonatomic, strong, nullable) NSString *verificationUrl;
@property (readonly, nonatomic, strong, nullable) NSString *verificationParams;

@property (readonly, nonatomic, strong, nullable) NSArray <NSString *> *verificationNotExecutedUrls;

@required
- (BOOL)isValid;

@end
