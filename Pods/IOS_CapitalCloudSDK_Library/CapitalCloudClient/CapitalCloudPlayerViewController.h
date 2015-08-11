//
//  CapitalCloudPlayerViewController.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-31.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//


/*!
 @header CapitalCloudPlayerViewController
 @abstract 视频播放控制类；
 @author capitalCloud
 @version 1.0.1
 */
#import <UIKit/UIKit.h>
#import "CapitalCloudVideo.h"
#import "CapitalCloudAPIClient.h"

/*!
 @class
 @abstract 视频播放控制类；
 */
@interface CapitalCloudPlayerViewController : UIViewController

/*!
 @property
 @abstract 视频信息；
 */
@property(nonatomic, strong) CapitalCloudVideo *video;

/*!
 @method
 @abstract	播放；
 @discussion	视频暂停，或者未开始播放时有效；
 */
- (void) play;

/*!
 @method
 @abstract	暂停；
 @discussion	视频正在播放时有效；
 */
- (void) pause;

/*!
 @method
 @abstract	显示或者隐藏进度条；
 @discussion	决定进度条的显示状态，是否隐藏；
 @param hodeOrNot [IN|OUT] 是否隐藏进度条；
 */
- (void) hideControlBar:(BOOL) hideOrNot;

/*!
 @method
 @abstract	seek；
 @discussion	seek到某一时间点开始播放；
 
 @param time [IN|OUT] 秒未单位的时间点；
 */
- (void) seek:(float) time;

/*!
 @method
 @abstract	初始化视频信息；
 @discussion	初始化视频播放所必要的信息；
 
 @param video [IN|OUT] 视频信息的封装；
 @param apiClient [IN|OUT] apiClient;
 @param playerId [IN|OUT] 播放器ID；
 @param region [IN|OUT] 播放器区域；
 */
- (void) prepareVideo:(CapitalCloudVideo *)video withApiClient:(CapitalCloudAPIClient *) apiClient andPlayerId:(NSString *) playerId inRegion:(CGRect)region;

@end
