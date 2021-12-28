//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <UIKit/UIView.h>

#import <SpringBoard/SBReachabilityObserver-Protocol.h>
#import <SpringBoard/_SBFakeBlur-Protocol.h>

@class NSString, SBFWallpaperView, SBWallpaperController, UIImageView;
@protocol _SBFakeBlurObserver;

@interface _SBFakeBlurView : UIView <_SBFakeBlur, SBReachabilityObserver>
{
    NSUInteger _transformOptions;
    long long _requestedStyle;
    long long _effectiveStyle;
    SBFWallpaperView *_wallpaperView;
    BOOL _fullscreen;
    UIImageView *_imageView;
    CGPoint _wallpaperOffset;
    id <_SBFakeBlurObserver> _observer;
    SBWallpaperController *_wallpaperController;
}

+ (id)_imageForStyle:(inout long long )arg1 withSource:(id)arg2 rootSettings:(id)arg3 overrideTraitCollection:(id)arg4;
+ (id)_imageForStyle:(inout long long )arg1 withSource:(id)arg2 rootSettings:(id)arg3;
@property(readonly, nonatomic) __weak SBWallpaperController *wallpaperController; // @synthesize wallpaperController=_wallpaperController;
@property(nonatomic) NSUInteger transformOptions; // @synthesize transformOptions=_transformOptions;
@property(nonatomic, getter=isFullscreen) BOOL fullscreen; // @synthesize fullscreen=_fullscreen;
@property(nonatomic) __weak id <_SBFakeBlurObserver> observer; // @synthesize observer=_observer;
// - (void).cxx_destruct;
- (void)traitCollectionDidChange:(id)arg1;
- (void)_createOrRemoveMatchMoveAnimationIfNeeded;
- (void)didMoveToWindow;
- (void)willMoveToWindow:(id)arg1;
- (void)layoutSubviews;
- (void)offsetWallpaperBy:(CGPoint)arg1;
- (void)rotateToInterfaceOrientation:(long long)arg1;
- (void)_setImage:(id)arg1 style:(long long)arg2 notify:(BOOL)arg3;
- (void)_updateImageWithSource:(id)arg1 overrideTraitCollection:(id)arg2 notifyObserver:(BOOL)arg3;
- (void)updateImageWithSource:(id)arg1 overrideTraitCollection:(id)arg2;
- (void)updateImageWithSource:(id)arg1;
- (void)reconfigureWithSource:(id)arg1;
@property(readonly, nonatomic) long long variant;
- (void)dealloc;
- (id)initWithVariant:(long long)arg1 wallpaperController:(id)arg2 transformOptions:(NSUInteger)arg3;
- (void)handleReachabilityYOffsetDidChange;
@property(nonatomic) double zoomScale;
- (long long)effectiveStyle;
- (void)requestStyle:(long long)arg1;
@property(readonly, copy) NSString *description;

@end

