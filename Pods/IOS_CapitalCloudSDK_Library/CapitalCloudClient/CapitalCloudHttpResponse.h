//
//  CapitalCloudHttpResponse.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CapitalCloudHttpResponse : NSObject

@property(readwrite) NSInteger statusCode;
@property(readwrite, strong) NSDictionary *headerFields;
@property(readwrite, strong) NSData *responseData;

-(instancetype)initWithHttpURLResponse:(NSHTTPURLResponse*)response withData:(NSData*)data;

@end
