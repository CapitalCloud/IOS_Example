//
//  AppDelegate.h
//  Example
//
//  Created by julien on 13-12-26.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideoDownloader.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate,CapitalCloudVideoDownloaderDelegate>
@property (strong, nonatomic) UIWindow *window;

@end
