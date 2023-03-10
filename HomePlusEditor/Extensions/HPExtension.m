//
// HPExtension.h
// HomePlus
//
// Extension Object. 
// Holds everything important about an extension that was found, including ControllerViews
//
// Created by passing a dictionary and the location of the plist that dict represents
// * This could possibly reduced to only the location of the plist. 
//
// Authors: Kritanta
// Created  Dec 2019
//
// TODO: fix jank
// TODO: make api less dumb
//

#include "HPExtension.h"
#include "HPExtensionControllerView.h"
@implementation HPExtension

NSString *getStringForKey(NSDictionary *dict, NSString *key, NSString *fallback) 
{
    id result = [dict objectForKey:key];

    if (!result)
        result = fallback;
    else if (![result isKindOfClass: [NSString class]])
        result = [result description];

    return result;
}

CGFloat getFloatForKey(NSDictionary *dict, id key, CGFloat fallback)
{
    CGFloat result = [[dict valueForKey:key] floatValue];

    if (!result)
        result = fallback;

    return result;
}

- (instancetype)init
{
    self = [super init];

    if (self) {
        //
    }

    return self;
}
- (instancetype)initWithDictionary:(NSMutableDictionary *)extensionDict atBundlePath:(NSString *)bundlePath
{
    self = [super init];

    self.bundleFilePath = bundlePath;

    NSString *imagePath = [NSString stringWithFormat:@"%@/%@", bundlePath, @"icon.png"];

    self.extensionIcon = [[UIImage alloc] initWithContentsOfFile:imagePath];

    self.extensionDictionary = extensionDict;

    [self parseDictionary];

    return self;
}

- (void)parseDictionary
{
    NSArray<NSDictionary*> *panes = (NSArray<NSDictionary*> *)[self.extensionDictionary objectForKey:@"pages"];
    self.extensionControllerViews = [[NSMutableArray alloc] init];

    NSMutableDictionary *infoDictionary = [NSMutableDictionary dictionaryWithContentsOfFile:[NSString stringWithFormat:@"%@/Info.plist", self.bundleFilePath]];

    NSString *prefBundleValuePath = [NSString stringWithFormat:@"/var/mobile/Library/Preferences/%@.plist", getStringForKey(infoDictionary, @"CFBundleIdentifier", @"")];

    for (NSDictionary* dict in panes)
    {
        HPExtensionControllerView *pane = [[HPExtensionControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        pane.bundleValueLocation = prefBundleValuePath;
        pane.bundleID = getStringForKey(infoDictionary, @"CFBundleIdentifier", @"");
        BOOL paneInvalid = NO;

        NSString *controlTypeString = getStringForKey(dict, @"topControlType", @"Slider");
        if ([controlTypeString isEqualToString:@"None"])
        {
            pane.topControlType = kNone;
        }
        else if ([controlTypeString isEqualToString:@"Slider"])
        {
            pane.topControlType = kSlider;
        }
        else if ([controlTypeString isEqualToString:@"Counter"])
        {
            pane.topControlType = kCounter;
        }
        else if ([controlTypeString isEqualToString:@"Switch"])
        {
            pane.topControlType = kSwitch;
        }
        else 
        {
            paneInvalid = YES;
        }

        controlTypeString = getStringForKey(dict, @"bottomControlType", @"Slider");
        if ([controlTypeString isEqualToString:@"None"])
        {
            pane.bottomControlType = kNone;
        }
        else if ([controlTypeString isEqualToString:@"Slider"])
        {
            pane.bottomControlType = kSlider;
        }
        else if ([controlTypeString isEqualToString:@"Counter"])
        {
            pane.bottomControlType = kCounter;
        }
        else if ([controlTypeString isEqualToString:@"Switch"])
        {
            pane.bottomControlType = kSwitch;
        }
        else 
        {
            paneInvalid = YES;
        }

        [pane layoutControllerView];

        pane.topControl.minimumValue = getFloatForKey(dict, @"topMin", 0);
        pane.topControl.maximumValue = getFloatForKey(dict, @"topMax", 100);

        pane.bottomControl.minimumValue = getFloatForKey(dict, @"bottomMin", 0);
        pane.bottomControl.maximumValue = getFloatForKey(dict, @"bottomMax", 0);

        NSString *imagePath = [NSString stringWithFormat:@"%@/%@", self.bundleFilePath, getStringForKey(dict, @"icon", @"icon.png")];
        pane.paneIcon = [UIImage imageWithContentsOfFile:imagePath];

        pane.topLabel.text = getStringForKey(dict, @"topLabel", @"Top Control");

        pane.topPreferenceLink = getStringForKey(dict, @"topPreferenceKeyLink", @"invalid");
        pane.topNotification = getStringForKey(dict, @"topPostNotification", @"");

        pane.bottomLabel.text = getStringForKey(dict, @"bottomLabel", @"Bottom Control");

        pane.bottomPreferenceLink = getStringForKey(dict, @"bottomPreferenceKeyLink", @"invalid");
        pane.bottomNotification = getStringForKey(dict, @"bottomPostNotification", @"");

        if ([pane.topPreferenceLink isEqualToString:@"invalid"] || [pane.bottomPreferenceLink isEqualToString:@"invalid"])
            paneInvalid = YES;

        pane.alpha = 1;
        [pane configureValuesFromBundle];
        [self.extensionControllerViews addObject:pane];
    }
}

@end