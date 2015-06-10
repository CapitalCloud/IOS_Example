//
//  CapitalCloudVideoPlayerViewController.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-30.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CapitalCloudVideoPlayer.h"
#import "CapitalCloudVideoPlayerView.h"
#import "CapitalCloudVideoPlayerConfigurations.h"
#import "CapitalCloudVideoPlayInfor.h"

@interface CapitalCloudVideoPlayerViewController : UIViewController <CapitalCloudVideoPlayer>

@property (nonatomic, weak) id <CapitalCloudVideoPlayerDelegate> delegate;
@property (readonly, strong) NSMutableDictionary *currentVideoInfo;
@property (readonly, strong) CapitalCloudVideoPlayerView *videoPlayerView;
@property (readonly) BOOL fullScreenModeToggled;
@property (nonatomic) BOOL showStaticEndTime;
@property (nonatomic, readonly) BOOL isPlaying;
@property (nonatomic) BOOL allowPortraitFullscreen;
@property (nonatomic) UIEdgeInsets controlsEdgeInsets;
@property (readwrite, strong) CapitalCloudVideoPlayInfor *pl;
@property (readwrite, strong) AVPlayer *videoPlayer;

- (void)playVideoWithTitle:(NSString *)title playerConfigurations:(CapitalCloudVideoPlayerConfigurations *)configurations isStreaming:(BOOL)streaming playInFullScreen:(BOOL)playInFullScreen;
- (void)syncFullScreenButton;
- (void)showCannotFetchStreamError;
- (void)launchFullScreen;
- (void)minimizeVideo;
- (void)playPauseHandler;
- (void)seekToTime:(CMTime)time;
+ (CapitalCloudVideoPlayerViewController *)videoPlayerWithContainingViewController:(UIViewController *)containingViewController topView:(UIView *)topView videoPlayInfor:(CapitalCloudVideoPlayInfor *)plinfo;


@end
