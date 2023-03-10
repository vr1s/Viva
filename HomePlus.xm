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
#include "HPConfigurationManager.h"
#include "HPLayoutManager.h"
#include "HPManager.h"
#include "HPUtility.h"
#include "HomePlus.h"
#include <SpringBoardHome/SBFolderControllerConfiguration.h>
@interface SBRootFolderControllerConfiguration : SBFolderControllerConfiguration
@end
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

%hook SBRootFolderControllerConfiguration

-(id)listLayoutProvider
{
    return [HPLayoutManager sharedInstance];
}

%end

%hook SBRootFolderController

-(id)listLayoutProvider
{
    return [HPLayoutManager sharedInstance];
}


%end

@interface SBFolder : NSObject
@end

@interface SBRootFolder : SBFolder 
@end


NSInteger widgetWidthSlidein(NSInteger size, NSInteger cols)
{
    CGFloat colf = (CGFloat) cols;
    if (size <= 2)
        return (NSInteger) (ceil(0.5f * colf)); // floor when widget resizing logic is implemented.
    if (size == 3)
        return (NSInteger) (floor(0.75f * colf));
    if (size >= 4)
        return cols;
    return size;
}

%hook SBRootFolder 

-(struct SBHIconGridSize)listGridSize
{
    struct SBHIconGridSize size;
    NSUInteger loadoutValueRows = [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.rows;
    NSUInteger loadoutValueColumns = [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.columns;

    size.rows = loadoutValueRows;
    size.columns = loadoutValueColumns;

    [self setValue:[NSValue value:&size withObjCType:@encode(struct SBHIconGridSize)] forKey:@"_listGridSize"];

    SBHIconGridSizeClassSizes sizes = { .small = { .columns = (short)widgetWidthSlidein(2, loadoutValueColumns), .rows = 2 },
                                        .medium = { .columns = (short)widgetWidthSlidein(4, loadoutValueColumns), .rows = 2 },
                                        .large = { .columns = (short)widgetWidthSlidein(4, loadoutValueColumns), .rows = 6 },
                                        .extraLarge = { .columns = (short)widgetWidthSlidein(4, loadoutValueColumns), .rows = 6
            } };

    [self setValue:[NSValue value:&sizes withObjCType:@encode(struct SBHIconGridSizeClassSizes)] forKey:@"_iconGridSizeClassSizes"];

    return size;
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
