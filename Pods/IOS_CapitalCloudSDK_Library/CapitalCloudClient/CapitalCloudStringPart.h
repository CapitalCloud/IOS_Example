//
//  CapitalCloudStringPart.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudPart.h"

@interface CapitalCloudStringPart : NSObject <CapitalCloudPart>

@property(readwrite, strong) NSString *name;
@property(readwrite, strong) NSString *value;

-(instancetype) initWithParameter:(NSString*)value withName:(NSString*)name;

@end
