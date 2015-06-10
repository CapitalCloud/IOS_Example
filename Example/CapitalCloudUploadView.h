//
//  CapitalCloudUploadView.h
//  Example
//
//  Created by julien on 14-1-8.
//  Copyright (c) 2014年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CapitalCloudUploadProgressDelegate;

@interface CapitalCloudUploadView : UIControl

@property (weak, nonatomic) id<CapitalCloudUploadProgressDelegate> delegate;
@property (nonatomic) CGFloat progress;
@property (strong, nonatomic) UILabel *progressLabel;
- (instancetype)initWithTableView:(UITableViewCell *)tableViewCell message:(NSString *)uploadMsg;
@end