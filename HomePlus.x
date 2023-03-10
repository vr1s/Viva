//
// HomePlus.xm
// HomePlus
//
// Collection of the hooks needed to get this tweak working
//
// Pragma marks are formatted to look best in VSCode w/ mark jump
//
// Created Oct 2019
// Author: Kritanta
//

#include "HPUIManager.h"
#include "HPExtensionManager.h"
#include "HPManager.h"
#include "HPUtility.h"
#include "HomePlus.h"
#import <AudioToolbox/AudioToolbox.h>
#include <objc/runtime.h>
#include <dlfcn.h> 
#include <spawn.h>
#pragma mark Global Values


// Global for the preference dict. Not used outside of reloadPrefs() but its cool to have
NSDictionary *prefs = nil;

static BOOL performedInitialConfiguration;

%hook SBHomeScreenView
- (void)movedToSuperview:(UIView*)view
{
    %orig;

    [[HPManager sharedInstance] performInitialConfigurationWithView:view];
}
%end


static void *observer = NULL;

static void reloadPrefs() 
{
    
    if ([NSHomeDirectory() isEqualToString:@"/var/mobile"]) 
    {
        CFArrayRef keyList = CFPreferencesCopyKeyList((CFStringRef)kIdentifier, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);

        if (keyList) 
        {
            prefs = (NSDictionary *)CFBridgingRelease(CFPreferencesCopyMultiple(keyList, (CFStringRef)kIdentifier, kCFPreferencesCurrentUser, kCFPreferencesAnyHost));

            if (!prefs) 
            {
                prefs = [NSDictionary new];
            }
            CFRelease(keyList);
        }
    } 
    else 
    {
        prefs = [NSDictionary dictionaryWithContentsOfFile:kSettingsPath];
    }
}


static BOOL boolValueForKey(NSString *key, BOOL defaultValue) 
{
    return (prefs && [prefs objectForKey:key]) ? [[prefs objectForKey:key] boolValue] : defaultValue;
}

static BOOL pagebar = YES;

static void preferencesChanged() 
{
    CFPreferencesAppSynchronize((CFStringRef)kIdentifier);
    reloadPrefs();
    [HPManager sharedInstance]._pfTweakEnabled = boolValueForKey(@"HPEnabled", YES);
    [HPManager sharedInstance]._pfGestureDisabled = boolValueForKey(@"gesturedisabled", NO);
    pagebar = boolValueForKey(@"pagebar", YES);

    [HPManager sharedInstance]._pfActivationGesture = [[prefs valueForKey:@"gesture"] intValue];
    if (![HPManager sharedInstance]._rtIconSupportInjected && boolValueForKey(@"iconsupport", NO))
    {
        @try 
        {
            [HPManager sharedInstance]._rtIconSupportInjected = YES;
            dlopen("/Library/MobileSubstrate/DynamicLibraries/IconSupport.dylib", RTLD_NOW);
        }
        @catch (NSException *exception)
        {

        }
    }
}
#pragma mark ctor

%ctor
{
    preferencesChanged();

    CFNotificationCenterAddObserver(
        CFNotificationCenterGetDarwinNotifyCenter(),
        &observer,
        (CFNotificationCallback)preferencesChanged,
        (CFStringRef)@"me.kritanta.homeplus/settingschanged",
        NULL,
        CFNotificationSuspensionBehaviorDeliverImmediately
    );
}
