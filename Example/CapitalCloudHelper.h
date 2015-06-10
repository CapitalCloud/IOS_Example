//
//  CapitalCloudHelper.h
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudAPIClient.h"
#import "CapitalCloudVideoDownloaderManager.h"
#import "CapitalCloudVideoUploaderManager.h"

@interface CapitalCloudHelper : NSObject

+ (CapitalCloudAPIClient *) apiClient;
+ (CapitalCloudVideoDownloaderManager *) downloaderManager;
+ (CapitalCloudVideoUploaderManager *) uploaderManager;

@end
