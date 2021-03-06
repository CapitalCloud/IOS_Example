//
//  VideoDownloaderListViewController.m
//  Example
//
//  Created by yangfei on 1/28/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

#import "VideoDownloaderListViewController.h"
#import "DownloaderTableViewCell.h"
#import "CapitalCloudHelper.h"
@interface VideoDownloaderListViewController ()

@end

@implementation VideoDownloaderListViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.downloaderList count];
}

-(UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return UITableViewCellEditingStyleDelete;
}

-(void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle==UITableViewCellEditingStyleDelete)
    {
        NSInteger row = [indexPath row];
        CapitalCloudVideoDownloader *downloader = (CapitalCloudVideoDownloader *)[self.downloaderList objectAtIndex:row];
        [[CapitalCloudHelper downloaderManager] cancel:downloader];
        [self.downloaderList removeObject:downloader];
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
    }
}

- (DownloaderTableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *TableSampleIdentifier = @"DownloaderCell";
    
    DownloaderTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:
                             TableSampleIdentifier];
    if (cell == nil)
    {
        cell = [[DownloaderTableViewCell alloc]
                initWithStyle:UITableViewCellStyleDefault
                reuseIdentifier:TableSampleIdentifier];
    }
    NSUInteger row = [indexPath row];
    CapitalCloudVideoDownloader *downloader = (CapitalCloudVideoDownloader *)[self.downloaderList objectAtIndex:row];
    downloader.delegate = cell;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.loader = downloader;
    cell.title.text = downloader.capitalCloudRendition.entryId;
    cell.status.text = [self status:downloader.status];
    cell.pauseOrResume.on =![downloader.status isEqualToString:@"paused"];
    cell.pauseOrResume.enabled = ![downloader.status isEqualToString:@"finished"];
    cell.progress.progress = downloader.progress;
    return cell;
}


-(IBAction)pauseAll:(id)sender
{
    [[CapitalCloudHelper downloaderManager] pause];
    NSLog(@"pause_all");
}

-(IBAction)resumeAll:(id)sender
{
    [[CapitalCloudHelper downloaderManager] resume];
    NSLog(@"resume_all");
}

-(NSString *)status:(NSString *)status
{
    if([status isEqualToString:@"preparing"])
    {
        return @"准备下载";
    }else if ([status isEqualToString:@"loading"])
    {
        return @"正在下载";
    }else if([status isEqualToString:@"failed"])
    {
        return @"下载失败";
    }else if ([status isEqualToString:@"finished"])
    {
        return @"下载完成";
    }else if([status isEqualToString:@"paused"])
    {
        return @"暂停";
    }
    return status;
}

- (void)layoutSubviews
{
    [self.tableView layoutSubviews];
}

@end
