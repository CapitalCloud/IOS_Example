//
//  CapitalCloudVideoPlayer.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-30.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

/*!
 @header CapitalCloudVideoPlayer
 @abstract 视频播放接口类.
 @author capitalCloud
 @version 1.3.2
 */
#import <Foundation/Foundation.h>
@class CapitalCloudVideoPlayerConfigurations;
/*!
 @property
 @abstract 视频准备播放；
 需#import "CapitalCloudVideoPlayer.h"
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxxx:)      name:videoStart object:nil];
 */
extern NSString * const videoStart;

/*!
 @property
 @abstract 视频暂停；
 需#import "CapitalCloudVideoPlayer.h"
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxxx:)      name:videoPause object:nil];
 */
extern NSString * const videoPause;

/*!
 @property
 @abstract 视频开始播放；
 需#import "CapitalCloudVideoPlayer.h"
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxxx:)      name:videoPlay object:nil];
 */
extern NSString * const videoPlay;

/*!
 @property
 @abstract 视频播放进度；
 需#import "CapitalCloudVideoPlayer.h"
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxxx:)      name:videoProgress object:nil];
 */
extern NSString * const videoProgress;

/*!
 @property
 @abstract 视频播放完成；
 需#import "CapitalCloudVideoPlayer.h"
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxxx:)      name:videoComplete object:nil];
 */
extern NSString * const videoComplete;

extern NSString * const showSnapshot;

@protocol CapitalCloudVideoPlayerDelegate <NSObject>

@optional
@property (nonatomic) BOOL fullScreenToggled;
- (void)trackEvent:(NSString *)event videoID:(NSString *)videoID title:(NSString *)title;

@end

@protocol CapitalCloudVideoPlayer <NSObject>

@property (readonly, strong) NSDictionary *currentVideoInfo;
@property (nonatomic, weak) id <CapitalCloudVideoPlayerDelegate> delegate;
@property (readonly) BOOL fullScreenModeToggled;
@property (nonatomic) BOOL showStaticEndTime;
@property (nonatomic) BOOL allowPortraitFullscreen;
@property (nonatomic, readonly) BOOL isPlaying;

- (void)playVideoWithTitle:(NSString *)title playerConfigurations:(CapitalCloudVideoPlayerConfigurations *)configurations isStreaming:(BOOL)streaming playInFullScreen:(BOOL)playInFullScreen;
- (void)showCannotFetchStreamError;
- (void)launchFullScreen;
- (void)minimizeVideo;
- (void)playPauseHandler;

@end
