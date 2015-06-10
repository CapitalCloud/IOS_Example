//
//  VideoDownloaderListViewController.h
//  Example
//
//  Created by yangfei on 1/28/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideoDownloader.h"

@interface VideoDownloaderListViewController : UITableViewController<CapitalCloudVideoDownloaderDelegate>
@property(nonatomic,strong)NSMutableArray *downloaderList;
@end
