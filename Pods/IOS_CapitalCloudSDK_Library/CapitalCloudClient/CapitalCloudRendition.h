//
//  CapitalCloudRendition.h
//  CapitalCloudClient
//
//  Created by julien on 14-5-7.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudRenditionUrl.h"

@interface CapitalCloudRendition : NSObject

@property(nonatomic, strong) NSString *renditionId;
@property(nonatomic, strong) NSString *entryId;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *status;
@property(nonatomic, strong) NSString *errorCode;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, assign) NSInteger frameRate;
@property(nonatomic, assign) NSInteger kbps;
@property(nonatomic, assign) NSInteger fileSize;
@property(nonatomic, strong) NSDictionary *urls;

- (instancetype) initWithJsonObject:(NSDictionary *)jsonObject entryId:(NSString *) entryId;
- (BOOL) isEqualToRendition:(CapitalCloudRendition *)rendition;
@end
