//
//  CapitalCloudHttpMethod.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import "CapitalCloudHttpResponse.h"
#import "CapitalCloudHttpConnection.h"

@protocol CapitalCloudHttpMethod <NSObject>

-(CapitalCloudHttpResponse *)executeSynchronouslyAtURL:(NSURL *)methodURL error:(NSError **) error;

//-(CapitalCloudHttpConnection *)prepareAsynchronouslyAtURL:(NSURL *)methodURL delegate:(id<CapitalCloudHttpConnectionDelegate>)delegate;

@end
