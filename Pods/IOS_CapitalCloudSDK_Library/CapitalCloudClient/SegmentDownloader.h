//
//  SegmentDownloader.h
//  CapitalCloudClient
//
//  Created by yangfei on 14-12-1.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CapitalCloudHttpConnection.h"

@protocol SegmentDownloadDelegate;

@interface SegmentDownloader:NSObject<CapitalCloudHttpConnectionDelegate>

@property(nonatomic,retain)id<SegmentDownloadDelegate>delegate;

-(void)start;
-(void)stop;
-(void)clean;
-(id)initWithUrl:(NSString*)url andFilePath:(NSString*)path  andFileName:(NSString*)fileName;

@end

@protocol SegmentDownloadDelegate <NSObject>
@optional
    -(void)segmentDownloadFinished:(SegmentDownloader *)request;
    -(void)segmentDownloadFailed:(SegmentDownloader *)request;
@end
