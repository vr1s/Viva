//
// HPResources.m
// HomePlus
//
// Stores static images for usage across app
// Pretty big file, be careful opening. 
// 
// Created Oct 2019 
// Authors: vriska
//
// TODO: certain parts of this could be better honestly

#include "HPResources.h"

@implementation HPResources

+ (UIImage *)logo
{
    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@", @"homeplus"] ofType:@"png"];
    return [UIImage imageWithContentsOfFile:imagePath];
}

+ (UIImage *)spacerImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@spacing_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    
    return image;
}

+ (UIImage *)iconCountImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@add-row-column_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)offsetImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@layouts_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)tutorialTwoToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)rootImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@homescreen_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)dockImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@dock_icons%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)scaleImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@icon-settings_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+(UIImage *)resetImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@Reset_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)settingsImageToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@settings_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)inAppBannerToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)inAppBannerNotchedToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)inAppFooterToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)extensionHomeToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@home_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

+ (UIImage *)saveToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)cancelToggled:(BOOL)toggled 
{
    return [UIImage imageNamed:@""];
}

+ (UIImage *)loadoutsToggled:(BOOL)toggled 
{
    NSString *toggleInsertPartOne = toggled ? @"toggled_icons/" : @"";
    NSString *toggleInsertPartTwo = toggled ? @"_toggled" : @"";

    NSBundle *bundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];
    NSString *imagePath = [bundle pathForResource:[NSString stringWithFormat:@"assets/icons/%@loadouts_icon%@", toggleInsertPartOne, toggleInsertPartTwo] ofType:@"png"];
    UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    
    return image;
}

@end