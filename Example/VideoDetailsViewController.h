//
//  VideoDetailsViewController.h
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideo+Image.h"
#import "CapitalCloudVideoDownloader.h"

@interface VideoDetailsViewController : UIViewController <CapitalCloudVideoDownloaderDelegate>
@property (strong, nonatomic) IBOutlet UILabel *videoDescription;
@property (strong, nonatomic) IBOutlet UIButton *save;
@property (strong, nonatomic) IBOutlet UILabel *resolution;
@property (strong, nonatomic) IBOutlet UILabel *bitrate;
@property (strong, nonatomic) IBOutlet UILabel *status;

@property(nonatomic, strong) CapitalCloudVideo *video;

@end
