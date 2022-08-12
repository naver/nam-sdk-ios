//
//  AmazonMediationConstants.h
//  Serverless
//
//  Created by Krivopaltsev, Eugene on 12/12/18.
//  Copyright © 2018 Krivopaltsev, Eugene. All rights reserved.
//

#ifndef AmazonMediationConstants_h
#define AmazonMediationConstants_h

#define BID_INFO                @"bidInfo"
#define PLACEMENT_HINT          @"pHint"
#define AMAZON_SLOTS            @"amznslots"
#define AMAZON_AD_INFO          @"amazon_ad_info"
#define EVENT_SERVER_PARAMETER  @"event_server_parameter"
#define LOAD_START_TIME         @"load_start"
#define EXPECTED_WIDTH          @"expected_width"
#define EXPECTED_HEIGHT         @"expected_height"
#define SKADNETWORK_PARAMS      @"skadn_params"
#define CLICKTRACKERS_ARRAY     @"clicktrackers"

/// Sample error codes.
typedef NS_ENUM(NSInteger, DTBAdErrorCode) {
    SampleErrorCodeBadRequest,    ///< Bad request.
    SampleErrorCodeUnknown,       ///< Unknown error.
    SampleErrorCodeNetworkError,  ///< Network error.
    SampleErrorCodeNoInventory,   ///< No inventory.
};


#endif /* AmazonMediationConstants_h */
