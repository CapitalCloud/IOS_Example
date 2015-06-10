//
//  CapitalCloudFilePart.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudPart.h"

@interface CapitalCloudFilePart : NSObject <CapitalCloudPart>

@property(readwrite, strong) NSURL *fileURL;
@property(readwrite, strong) NSString *paramName;

-(instancetype) initWithFile:(NSURL*)fileURL withName: (NSString*)paramName;

@end
