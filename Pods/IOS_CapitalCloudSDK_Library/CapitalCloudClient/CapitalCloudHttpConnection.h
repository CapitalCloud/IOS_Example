//
//  CapitalCloudHttpConnection.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-11.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol CapitalCloudHttpConnectionDelegate;

@interface CapitalCloudHttpConnection : NSObject<NSURLConnectionDataDelegate>

@property(nonatomic, strong) NSURLRequest *request;
@property(nonatomic, strong) id<CapitalCloudHttpConnectionDelegate> httpDelegate;

- (instancetype)initWithRequest:(NSURLRequest *)request;
- (void)start;
- (void)cancel;

@end

@protocol CapitalCloudHttpConnectionDelegate <NSObject>
@optional
- (void)cancel:(CapitalCloudHttpConnection *)connection;
- (void)receiveData:(NSData *) data InResponse:(NSHTTPURLResponse *)response;
- (void)receiveResonse:(NSHTTPURLResponse *)response;
- (void)finishWithData:(NSMutableData *) data InResponse:(NSHTTPURLResponse *)response;
- (void)failedWithError:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;

@end
