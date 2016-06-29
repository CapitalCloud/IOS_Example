//
//  DownloaderTableViewCell.m
//  Example
//
//  Created by yangfei on 1/29/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

#import "DownloaderTableViewCell.h"
#import "CapitalCloudHelper.h"

@interface DownloaderTableViewCell()
@property (readwrite) NSTimer *timer;
@end

@implementation DownloaderTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
        // Initialization code
    }
    return self;
}

-(void)downloadFinished:(CapitalCloudVideoDownloader *)loader
{
    _progress.progress = 1.0;
    _pauseOrResume.enabled = false;
    _status.text = @"下载完成";
}

- (void)downloadCanceled:(CapitalCloudVideoDownloader *)loader
{
    
}

- (void)downloadDidUpdate:(double)progress
{
    _progress.progress = progress;
    _status.text = @"正在下载";
}

-(void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response
{
    _status.text = @"下载错误";
}

- (void)awakeFromNib
{
    // Initialization code
}

- (IBAction)pause:(id)sender
{
    [[CapitalCloudHelper downloaderManager] pause:_loader];
    _status.text = @"暂停";
}

- (IBAction)resume:(id)sender
{
    [[CapitalCloudHelper downloaderManager] resume:_loader];
    _status.text = @"恢复";
}

- (IBAction)pauseOrResume:(id)sender
{
    if ([self timer].isValid) {
        [[self timer] invalidate];
    }
    [self setTimer:nil];
    [self setTimer:[NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(swichVideoStatus:) userInfo:[NSNumber numberWithBool:[(UISwitch *)sender isOn]] repeats:NO]];
    
}

-(void)swichVideoStatus:(NSTimer *)timer{
    NSLog(@"userinfo:%d",[timer userInfo]==[NSNumber numberWithInt:1]);
    if([[NSNumber numberWithInt:1] compare:[timer userInfo]] == NSOrderedSame)
    {
        [[CapitalCloudHelper downloaderManager] resume:_loader];
        _status.text = @"正在下载";
    }else
    {
        [[CapitalCloudHelper downloaderManager] pause:_loader];
        _status.text = @"暂停";
    }
}

@end
