/*
* Copyright 2018-2019 Amazon.com,
* Inc. or its affiliates. All Rights Reserved.
* Licensed under the Amazon Software License (the "License").
* You may not use this file except in compliance with the
* License. A copy of the License is located at
* http://aws.amazon.com/asl/
* or in the "license" file accompanying this file. This file is
* distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
* CONDITIONS OF ANY KIND, express or implied. See the License
* for the specific language governing permissions and
* limitations under the License.
*/

#import <Foundation/Foundation.h>
#import "DTBSlotGroup.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBFetchManager;
@class DTBAdLoader;

@interface DTBFetchFactory : NSObject

+(DTBFetchFactory * _Nonnull) sharedInstance;

/* CREATING FETCH MANAGERS */
-(NSError * _Nullable) createFetchManagerForLoader:(DTBAdLoader * _Nonnull)loader;
-(NSError * _Nullable) createFetchManagerForLoader:(DTBAdLoader * _Nonnull)loader isSmartBanner:(BOOL)isSmartBanner;

/* RETRIEVING FETCH MANAGERS */
-(DTBFetchManager * _Nullable) fetchManagerBySlotType:(DTBSlotType)slotType;

/* REMOVING FETCH MANAGERS */
-(void)removeFetchManagerForSlotType:(DTBSlotType)slotType;

@end

NS_ASSUME_NONNULL_END
