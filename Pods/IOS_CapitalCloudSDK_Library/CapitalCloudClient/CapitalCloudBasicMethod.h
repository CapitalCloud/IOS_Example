//
//  CapitalCloudBasicMethod.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudHttpResponse.h"
#import "CapitalCloudHttpConnection.h"

@interface CapitalCloudBasicMethod : NSObject

@property(readwrite, strong) NSMutableDictionary *params;
@property(readwrite, strong) NSMutableDictionary *headers;
@property int timeout;

-(void)addParameter:(NSString*)paramData withName:(NSString*)paramName;
-(void)addParametersFromDictionary:(NSDictionary*)dict;
-(void)addHeader:(NSString*)paramData withName:(NSString*)paramName;
-(CapitalCloudHttpResponse *)executeMethodSynchronously:(NSURL*)methodURL methodType:(NSString*)methodType dataInBody:(bool)dataInBody contentType:(NSString*)contentType error:(NSError **)error;

-(CapitalCloudHttpConnection *)prepareAsynchronously:(NSURL *)methodURL methodType:(NSString*)methodType dataInBody:(bool)dataInBody contentType:(NSString*)contentType delegate:(id<CapitalCloudHttpConnectionDelegate>)delegate;
@end
