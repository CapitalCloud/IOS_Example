//
//  VideoDetailsViewController.m
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import "VideoDetailsViewController.h"
#import "CapitalCloudPlayerViewController.h"
#import "CapitalCloudHelper.h"
#import "CapitalCloudVideoDownloaderManager.h"
#import "VideoDownloaderListViewController.h"
#import "CapitalCloudVideoPlayerConfigurations.h"
#import "CapitalCloudVideoPlayer.h"

@interface VideoDetailsViewController ()

@end

@implementation VideoDetailsViewController
{
    CapitalCloudPlayerViewController *ivc;
}

- (void) setVideo:(CapitalCloudVideo *)video
{
    _video = video;
}

- (void)viewDidLoad
{
    _videoDescription.text = [NSString stringWithFormat:@"描述：%@",_video.videoDescription];
    _resolution.text = [NSString stringWithFormat:@"分辨率：%ldx%ld",(long)_video.width,(long)_video.height];
    _bitrate.text = [NSString stringWithFormat:@"码率：%ldkbs",(long)_video.videoKbps];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoStart:)      name:videoStart object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoPlay:)       name:videoPlay object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoPause:)      name:videoPause object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoProgress:)   name:videoProgress object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoComplete:)   name:videoComplete object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(fullScreen:)   name:fullScreen object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(exitFullScreen:)   name:exitFullScreen object:nil];
    [super viewDidLoad];
    
}

- (IBAction)saveVideo:(id)sender
{
    NSError *error = nil;
    CapitalCloudRendition *rendition = [[[CapitalCloudHelper apiClient].entriesHandler getPlayInfor:self.video.entryId error:&error].renditions objectAtIndex:0];
    if(![[CapitalCloudHelper downloaderManager] download:rendition error:&error])
    {
        NSString *errorMessage = [[error userInfo] objectForKey:@"msg"];
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Failed to load videos."
                                                            message:errorMessage
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
    }
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.destinationViewController isKindOfClass:[CapitalCloudPlayerViewController class]])
    {
        ivc = (CapitalCloudPlayerViewController *)segue.destinationViewController;
        CGRect region = CGRectMake(0, 0, 320, 240);
//        [ivc prepareVideo:self.video withApiClient:[CapitalCloudHelper apiClient] andPlayerId:@"428082998184697028" inRegion:region];
        //      capitalcloud
        [ivc prepareVideo:self.video withApiClient:[CapitalCloudHelper apiClient] andPlayerId:@"622181572574391587" inRegion:region];
        //        dev
        NSError *error = nil;
//        [ivc prepareVideo:self.video withApiClient:[CapitalCloudHelper apiClient] andPlayerId:@"906046303676895492" inRegion:region];
        [[[CapitalCloudHelper apiClient] entriesHandler] get:@"906785641614461714" error:&error];
        //        staging
//        [ivc prepareVideo:self.video withApiClient:[CapitalCloudHelper apiClient] andPlayerId:@"622181572574391587" inRegion:region];
    }
    else if ([segue.destinationViewController isKindOfClass:[VideoDownloaderListViewController class]])
    {
        VideoDownloaderListViewController *idvc = (VideoDownloaderListViewController *)segue.destinationViewController;
        idvc.downloaderList = [[CapitalCloudHelper downloaderManager] getDownloaderList];
    }
}

- (IBAction)play:(id)sender
{
    [ivc play];
}

- (IBAction)pause:(id)sender
{
    [ivc pause];
}

- (IBAction)seek10:(id)sender
{
    [ivc seek:10];
}

- (IBAction)seek1:(id)sender
{
    [ivc seek:1];
}

- (IBAction)hideControlBar:(id)sender
{
    switch (((UISegmentedControl *)sender).selectedSegmentIndex) {
        case 0:
            [ivc hideControlBar:NO];
            break;
        case 1:
            [ivc hideControlBar:YES];
            break;
    }
}

- (void) videoStart:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoStart obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"videoStart:%@",obj];
    [ivc seek:10.0];
}

- (void) videoPlay:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoPlay obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"videoPlay:%@",obj];
    [ivc seek:10.0];
}

- (void) videoPause:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoPause obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"videoPause:%@",obj];
}

- (void) videoComplete:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoComplete obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"videoComplete:%@",obj];
}

- (void) exitFullScreen:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"exitFullScreen obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"exitFullScreen:%@",obj];
}

- (void) fullScreen:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"fullScreen obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"fullScreen:%@",obj];
}

- (void) videoProgress:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoProgress obj:\n%@",obj);
    _status.text = [NSString stringWithFormat:@"videoProgress:%@",obj];
}

-(void)dealloc
{
    
}


@end
