//
//  CapitalCloudHelper.m
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import "CapitalCloudHelper.h"
#import "CapitalCloudVideoDownloaderManager.h"
#import "CapitalCloudVideoUploaderManager.h"

@implementation CapitalCloudHelper

static CapitalCloudAPIClient *_apiClient;
static CapitalCloudVideoDownloaderManager *_downloaderManager;
static CapitalCloudVideoUploaderManager *_uploaderManager;

+ (CapitalCloudAPIClient *) apiClient
{
    if (!_apiClient)
    {
        
        _apiClient = [[CapitalCloudAPIClient alloc] initWithToken:@"SJQ-7zgT_lOwaq816PPkkeJiCY5zjPAVGx-ZDyLL854="];
//      capitalcloud
//        _apiClient = [[CapitalCloudAPIClient alloc] initWithToken:@"U2QDmmEY5tOSEb6qw3g_p5hsmCOXc92iJd304oUq7ISgzT3KWRf61xKFm0fa_rEX"];
        
//      dev
//        _apiClient = [[CapitalCloudAPIClient alloc] initWithToken:@"SJQ-7zgT_lOwaq816PPkkQRsTEepLlhulfJpjSCE30g="];
//      staging
//     _apiClient = [[CapitalCloudAPIClient alloc] initWithToken:@"U2QDmmEY5tOSEb6qw3g_p5hsmCOXc92iJd304oUq7ITUh9GFH1c7E5ayBUXNNVE4"];
    }
    return _apiClient;
}

+ (CapitalCloudVideoDownloaderManager *) downloaderManager {
    if (!_downloaderManager)
    {
        
        _downloaderManager = [[CapitalCloudVideoDownloaderManager alloc] initWithClient:[CapitalCloudHelper apiClient]];
    }
    return _downloaderManager;
}

+ (CapitalCloudVideoUploaderManager *)uploaderManager
{
    if (!_uploaderManager)
    {
        _uploaderManager = [[CapitalCloudVideoUploaderManager alloc] initWithClient:[CapitalCloudHelper apiClient]];
    }
    return _uploaderManager;
}

@end
