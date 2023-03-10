//
// VIVAManager.m
// Viva
//
// Generic Manager
//
// Created Oct 2019
// Author: vrisk/a
//

#include "VIVAManager.h"
#import "VIVAUIManager.h"
#import "VIVALayoutManager.h"

#include <SpringBoard/SBIconController.h>
#include <SpringBoard/SBIconModel.h>

#define kIconModelDidLayoutNotification @"SBIconModelWillLayoutIconStateNotification"

@implementation VIVAManager

+ (instancetype)sharedInstance
{
    static VIVAManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (VIVAManager *)[[[self class] alloc] init];
    });
    return sharedInstance;
}
- (instancetype)init
{
    self = [super init];

    if (self) {

        [[NSNotificationCenter defaultCenter] addObserver:[VIVALayoutManager sharedInstance] selector:@selector(initializeCacheOverride) name:kIconModelDidLayoutNotification object:nil];
        //[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(performInitialConfiguration) name:@"SBHomescreenDisplayChangedNotification" object:nil];

        // Preference globals
        self._pfTweakEnabled = YES;
        // self._pfBatterySaver = NO; // Planned LPM Reduced Animation State
        self._pfGestureDisabled = YES;
        self._pfActivationGesture = 1;
        //static CGFloat _pfEditingScale = 0.7;

        // Values we use everywhere during runtime. 
        // These should be *avoided* wherever possible
        // We can likely interface managers to handle these without too much overhead
        self._rtEditingEnabled = NO;
        self._rtConfigured = NO;
        self._rtKickedUp = NO;
        self._rtIconSupportInjected = NO;
        // On <iOS 13 we need to reload the icon view initially several times to update our changes :)
        self._rtIconViewInitialReloadCount = 0;

        // Tweak compatability stuff. 
        // See the %ctor at the bottom of the file for more info
        self._tcDockyInstalled = NO;

        // Views to shrink with pan gesture
        self.wallpaperView = nil;
        self.homeWindow = nil;
        self.homeView = nil;
        self.floatingDockWindow = nil;
        self.mockBackgroundView = nil;

        // Gesture recognizer to enable whenever kDisableEditingMode is hit.
        self._rtGestureRecognizer = nil;
        self._rtHitboxWindow = nil;
        //[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateCacheFor) name:@"VIVAUpdateLayoutCache" object:nil];
    }

    return self;
}

-(void)performInitialConfigurationWithView:(UIView*)view
{
    self.homeView = view;
    [kIconController addChildViewController:[[VIVAUIManager sharedInstance] editorViewController]];
    [[[VIVAUIManager sharedInstance] editorViewController] loadView];
    [view addSubview:[[[VIVAUIManager sharedInstance] editorViewController] view]];
    [view sendSubviewToBack:[[[VIVAUIManager sharedInstance] editorViewController] view]];
    [VIVALayoutManager.sharedInstance initializeCacheOverride];
    
    NSLog(@"Added viewController");
}

@end


static __attribute__((constructor)) void VivaConstructor (int __unused argc, char __unused **argv, char __unused **envp)
{
    [VIVAManager sharedInstance];
}