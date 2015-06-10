//
//  CapitalCloudVideoPlayInfor.h
//  CapitalCloudClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudRendition.h"
#import "CapitalCloudAPIClient.h"
#import "CapitalCloudImage.h"
@class CapitalCloudAPIClient;

@interface CapitalCloudVideoPlayInfor : NSObject

@property(nonatomic, strong) NSString *videoId;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *playInfoDescription;
@property(nonatomic, assign) NSInteger duration;
@property(nonatomic, strong) NSArray *renditions;
@property(nonatomic, strong) NSArray *thumbnails;
@property(nonatomic, strong) NSString *pubId;
@property(nonatomic, strong) CapitalCloudAPIClient *apiClient;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end
