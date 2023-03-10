//
// HPManager.h
// HomePlus
//
// Global manager for Data
//
// Currently gutted. This needs to be rewritten and reimplemented
//      as using Springboard's UserDefaults is not the best practice. 
//
// Authors: Kritanta
// Created  Oct 2019
//

#include <UIKit/UIKit.h>
#include "HomePlus.h"

#ifndef HPMANAGER_H
#define HPMANAGER_H
@interface HPManager : NSObject


// Preference globals
@property (nonatomic, assign)  BOOL _pfTweakEnabled;
// @property (nonatomic, assign)  BOOL _pfBatterySaver = NO; // Planned LPM Reduced Animation State
@property (nonatomic, assign)  BOOL _pfGestureDisabled;
@property (nonatomic, assign)  NSInteger _pfActivationGesture;
//@property (nonatomic, assign)  CGFloat _pfEditingScale = 0.7;

// Values we use everywhere during runtime. 
// These should be *avoided* wherever possible
// We can likely interface managers to handle these without too much overhead
@property (nonatomic, assign)  BOOL _rtEditingEnabled;
@property (nonatomic, assign)  BOOL _rtConfigured;
@property (nonatomic, assign)  BOOL _rtKickedUp;
@property (nonatomic, assign)  BOOL _rtIconSupportInjected;
// On <iOS 13 we need to reload the icon view initially several times to update our changes :)
@property (nonatomic, assign)  int _rtIconViewInitialReloadCount;

// Tweak compatability stuff. 
// See the %ctor at the bottom of the file for more info
@property (nonatomic, assign)  BOOL _tcDockyInstalled;

// Views to shrink with pan gesture
@property (nonatomic, retain)  UIView *wallpaperView;
@property (nonatomic, retain)  UIView *homeWindow;
@property (nonatomic, retain)  UIView *floatingDockWindow;
@property (nonatomic, retain)  UIView *mockBackgroundView;

// Gesture recognizer to enable whenever kDisableEditingMode is hit.
@property (nonatomic, retain)  UIGestureRecognizer *_rtGestureRecognizer;
@property (nonatomic, retain)  UIGestureRecognizer *_rt2GestureRecognizer;
@property (nonatomic, retain)  UIView *_rtHitboxWindow;

+ (instancetype)sharedInstance;
- (instancetype)init;

- (void)performInitialConfigurationWithView:(UIView*)view;


@end

#endif