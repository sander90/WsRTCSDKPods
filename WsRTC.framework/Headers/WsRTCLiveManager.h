//
//  WsRTCLiveManager.h
//  WSRTLive
//
//  Created by p2pdev on 2021/6/11.
//  Copyright © 2021 Wangsu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface WsAudioSessionConfiguration : NSObject

@property(nonatomic, strong) NSString *category;
@property(nonatomic, assign) AVAudioSessionCategoryOptions categoryOptions;
@property(nonatomic, strong) NSString *mode;

@end

typedef NS_ENUM(NSInteger, WsRTCAudioFormat) {
    WsRTCAudio_OPUS  = 0,
    WsRTCAudio_AAC_ADTS,
    WsRTCAudio_AAC_LATM
};

typedef NS_ENUM(NSInteger, WsRTCLiveVideoRenderMode) {
    WsRTCVideoRenderMode_ScaleAspect_FILL  = 0,
    WsRTCVideoRenderMode_ScaleAspect_FIT
};

typedef NS_ENUM(NSInteger, WsRTCLiveError) {
    WsErrorUnknown = -2001,
    WsErrorCreateSDP = -2002,
    WsErrorSetSDP = -2003,
    WsErrorGetSignal = -2004,
    WsErrorPeerDisConn = -2005,
    WsErrorPeerConnFailed = -2006
};

typedef enum {
    WsRTCLiveLogLevelDebug,
    WsRTCLiveLogLevelInfo,
    WsRTCLiveLogLevelWarning,
    WsRTCLiveLogLevelError,
    WsRTCLiveLogLevelNone,
} WsRTCLiveLogLevel;

@protocol WsRTCLogDelegate <NSObject>

@required

/**
 日志打印接口
 
 @param logLevel 日志打印级别
 @param log log
 */
- (void)logWithLevel:(WsRTCLiveLogLevel)logLevel log:(NSString *)log;


@end

@interface WsRTCLiveManager : NSObject

///【字段含义】播放器遭遇网络连接断开时 SDK 默认重试的次数，取值范围0 - 10，默认值：0。
@property(nonatomic, assign) int connectRetryCount;

///【字段含义】网络重连的时间间隔，单位秒，取值范围3 - 30，默认值：1。
@property(nonatomic, assign) int connectRetryInterval;

///audio jitter buffer max size. default 20
@property(nonatomic, assign) int audioJitterBufferMaxPackets;

///audio acceerate default true
@property(nonatomic, assign) BOOL audioJitterBufferFastAccelerate;


+ (instancetype)sharedManager;

@property (nonatomic, copy) NSString *clientInfo;

/**
 * dirPath  日志保存目录
 * minDebugLogLevel  日志等级
 */
-(void)initSDK;

-(void)finitSDK;



@end

NS_ASSUME_NONNULL_END
