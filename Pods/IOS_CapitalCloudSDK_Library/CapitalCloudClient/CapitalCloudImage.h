//
//  CapitalCloudImage.h
//  CapitalCloudClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CapitalCloudImage : NSObject

@property(nonatomic, strong) NSString *imageId;
@property(nonatomic, strong) NSString *entryId;
@property(nonatomic, strong) NSString *type;
@property(nonatomic, strong) NSString *url;
@property(nonatomic, strong) NSString *fileKey;
@property(nonatomic, assign) NSInteger fileSize;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, assign) NSInteger group;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject;

@end
