//
//  UploadTableViewCell.h
//  Example
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideoUploader.h"
#import "CapitalCloudUploadView.h"

@interface UploadTableViewCell : UITableViewCell<CapitalCloudVideoUploaderDelegate>
@property (strong, nonatomic)CapitalCloudVideoUploader * uploader;
@property (strong, nonatomic)CapitalCloudUploadView * uploaderView;
@end
