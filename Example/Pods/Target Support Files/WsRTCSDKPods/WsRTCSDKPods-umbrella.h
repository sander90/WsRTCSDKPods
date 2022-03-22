#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SDWsRTCHeader.h"
#import "RTCVideoRenderer.h"
#import "WsRTC.h"
#import "WsRTCLive.h"
#import "WsRTCLiveManager.h"
#import "WsRTCLiveView.h"

FOUNDATION_EXPORT double WsRTCSDKPodsVersionNumber;
FOUNDATION_EXPORT const unsigned char WsRTCSDKPodsVersionString[];

