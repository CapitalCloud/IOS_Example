//
//  CapitalCloudVideoPlayerView.h
//  CapitalCloudClient
//
//  Created by julien on 13-12-30.
//  Copyright (c) 2013年 capitalCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import <MediaPlayer/MediaPlayer.h>

@interface CapitalCloudVideoPlayerView : UIView

@property (readwrite) CGFloat padding;
@property (readonly, strong) UILabel *titleLabel;
@property (readonly, strong) UIView *playerControlBar;
@property (readonly, strong) UIView *renditionSelectPanel;
@property (readonly, strong) UIButton *playPauseButton;
@property (readonly, strong) UIButton *fullScreenButton;
@property (readonly, strong) UIButton *settingButton;
@property (readonly, strong) UISlider *videoScrubber;
@property (readonly, strong) UILabel *currentPositionLabel;
@property (readonly, strong) UILabel *timeLeftLabel;
@property (readonly, strong) UIProgressView *progressView;
@property (readwrite) UIEdgeInsets controlsEdgeInsets;
@property (nonatomic, readwrite, getter=isFullscreen) BOOL fullscreen;
@property (readonly, strong) UIActivityIndicatorView *activityIndicator;

- (void)setTitle:(NSString *)title;
- (CGFloat)heightForWidth:(CGFloat)width;
- (void)setPlayer:(AVPlayer *)player;

@end
