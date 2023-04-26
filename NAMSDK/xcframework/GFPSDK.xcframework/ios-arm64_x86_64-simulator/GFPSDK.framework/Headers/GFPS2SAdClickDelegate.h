//
//  GFPS2SAdClickDelegate.h
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//


typedef void(^GFPS2SAdLandingHandler)(BOOL isSuccess);


@protocol GFPS2SAdClickDelegate <NSObject>

- (void)openURLWith:(NSString *)urlString landingHandler:(GFPS2SAdLandingHandler)landingHandler;

@end
