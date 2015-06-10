//
//  CapitalCloudRenditionUrl.h
//  CapitalCloudClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CapitalCloudRenditionUrl : NSObject

@property(nonatomic, strong) NSString *url;
@property(nonatomic, assign) NSInteger expireTime;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end
