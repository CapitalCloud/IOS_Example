//
//  CapitalCloudImageDownloader.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

/*!
 @header CapitalCloudImageDownloader
 @abstract 图片加载类；
 @author capitalCloud
 @version 1.3.2
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 @class
 @abstract 主要用于图片加载；
 */
@interface CapitalCloudImageDownloader : NSObject

/*!
 @property
 @abstract 所加载图片地址；
 */
@property (nonatomic, strong) NSString *imageUrl;

/*!
 @property
 @abstract block代码块，用于处理所加载的图片；
 */
@property (nonatomic, copy) void (^completionHandler)(UIImage *);

/*!
 @method
 @abstract	开始下载；
 @discussion	开始下载图片，之前请设置imageUrl；
 */
- (void)startDownload;

/*!
 @method
 @abstract	取消下载；
 @discussion	取消下载；
 */
- (void)cancelDownload;

@end
