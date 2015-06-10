//
//  DownloaderTableViewCell.h
//  Example
//
//  Created by yangfei on 1/29/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideoDownloader.h"

@interface DownloaderTableViewCell : UITableViewCell<CapitalCloudVideoDownloaderDelegate>
@property (strong, nonatomic) IBOutlet UILabel *title;
@property (strong, nonatomic) IBOutlet UILabel *status;
@property (strong, nonatomic) IBOutlet UIProgressView *progress;
@property (strong, nonatomic) IBOutlet UISwitch *pauseOrResume;
@property (strong, nonatomic)CapitalCloudVideoDownloader* loader;
@end
