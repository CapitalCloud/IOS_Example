//
//  CapitalCloudPart.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CapitalCloudPart <NSObject>

-(void)appendData:(NSMutableData *)outputData;

@end
