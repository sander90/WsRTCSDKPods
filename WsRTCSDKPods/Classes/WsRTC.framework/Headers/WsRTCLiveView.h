//
//  WsRTCLiveView.h
//  WSRTLive
//
//  Created by p2pdev on 2021/5/26.
//  Copyright © 2021 Wangsu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "WsRTCLiveManager.h"
#include "RTCVideoRenderer.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, WsRTCVideoRotation) {
  WsRTCVideoRotation_0 = 0,
  WsRTCVideoRotation_90 = 90,
  WsRTCVideoRotation_180 = 180,
  WsRTCVideoRotation_270 = 270,
};

typedef NS_ENUM(NSInteger, WsRTCVideoRenderMode) {
    WsVideoRenderMode_ScaleAspect_FILL  = 0,
    WsVideoRenderMode_ScaleAspect_FIT
};


@class WsRTCLiveView;

@protocol WsRTCLiveViewControllerDelegate <NSObject>
@required
    -(void)startplay;

    -(void)pause;

    -(void)stop;

    -(void)resume;

    -(void)setVolume:(double)volume;

    -(void)setAudioMute:(BOOL)mute;

    -(void)setVideoPaused:(BOOL)paused;

    - (void)restart;

    /*开启统计回*/
    -(void)setStatState:(BOOL)stat;
    
    /*获取截图*/
    -(UIImage*)captureVideoFrame;
    
    /*旋转*/
    - (void)setRenderRotation:(WsRTCVideoRotation)rotation;

    - (void)setRenderMode:(WsRTCVideoRenderMode)renderMode;

@end

@protocol WsRTCLiveViewDelegate <NSObject>

@required

- (void)videoView:(WsRTCLiveView *)videoView didError:(NSError *)error;

- (void)videoView:(WsRTCLiveView *)videoView didChangeVideoSize:(CGSize)size;


@optional

- (void)onFirstFrameRender:(WsRTCLiveView*)videoView;

- (void)notifyCaton:(WsRTCLiveView *)videoView status:(int)status;

- (void)onConnected:(WsRTCLiveView*)videoView;

- (void)showStats:(WsRTCLiveView *)videoView strStat:(NSString*)strStat;

@end

@interface WsRTCLiveView : UIView <WsRTCLiveViewControllerDelegate>

@property (nonatomic, copy) NSString *streamUrl;
@property(nonatomic, weak) id<WsRTCLiveViewDelegate> delegate;
@property(nonatomic, readonly) __kindof UIView<RTCVideoRenderer> *remoteVideoView;

- (instancetype)initWithFrame:(CGRect)frame audioforamt:(WsRTCAudioFormat)format encrypt:(BOOL)encrypt;

@end

NS_ASSUME_NONNULL_END

