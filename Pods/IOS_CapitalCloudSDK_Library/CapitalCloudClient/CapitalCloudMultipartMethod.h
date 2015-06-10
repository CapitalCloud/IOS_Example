//
//  CapitalCloudMultipartMethod.h
//  CapitalCloudClient
//
//  Created by julien on 13-11-22.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudPart.h"
#import "CapitalCloudStringPart.h"
#import "CapitalCloudFilePart.h"
#import "CapitalCloudHttpMethod.h"
#import "CapitalCloudBasicMethod.h"

@interface CapitalCloudMultipartMethod : CapitalCloudBasicMethod <CapitalCloudHttpMethod>

@property(readwrite, strong) NSMutableArray *methodParts;

-(void)addPart:(id<CapitalCloudPart>)newPart;
-(void)addStringPartsFromDictionary:(NSDictionary*)dict;

-(CapitalCloudHttpConnection *)prepareAsynchronouslyAtURL:(NSURL *)methodURL;

@end
