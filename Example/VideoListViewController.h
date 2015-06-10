//
//  VideoListViewController.h
//  Example
//
//  Created by julien on 13-12-26.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/UTCoreTypes.h>
#import "CapitalCloudVideoUploader.h"
#import "CapitalCloudHttpConnection.h"
#import "CapitalCloudVideoDownloader.h"

@interface VideoListViewController : UITableViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate, CapitalCloudVideoUploaderDelegate, CapitalCloudVideoDownloaderDelegate>

@property(nonatomic, strong) NSArray *videos;
@property(nonatomic, strong) CapitalCloudHttpConnection *uploadConnection;

- (IBAction)fetchVideos;
- (void)handleError:(NSError *)error;

@end
