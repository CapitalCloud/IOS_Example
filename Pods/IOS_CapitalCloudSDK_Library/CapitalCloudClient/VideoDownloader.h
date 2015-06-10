//
//  VideoDownloader.h
//  CapitalCloudClient
//
//  Created by yangfei on 14-12-2.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SegmentDownloader.h"

@class CapitalCloudRendition;
@class CapitalCloudAPIClient;
@class M3u8SegmentList;
@class SegmentDownloader;

@protocol VideoDownloadDelegate;
@interface VideoDownloader : NSObject<SegmentDownloadDelegate>

@property(nonatomic,strong)id<VideoDownloadDelegate> delegate;

-(id)initWithSegmentList:(M3u8SegmentList*)list andClient:(CapitalCloudAPIClient*)client andRendition:(CapitalCloudRendition*)rendition;

-(void)startDownloadVideo;

-(void)stopDownloadVideo;

-(void)cancelDownloadVideo;

@end

@protocol VideoDownloadDelegate <NSObject>
@optional
-(void)videoDownloaderFinished:(VideoDownloader*)request;
-(void)videoDownloaderProgress:(double)progress;
-(void)videoDownloaderFailed:(VideoDownloader*)request;
@end
