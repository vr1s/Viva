//
// VIVAResources.h
// Viva
//
// Holds some images used everywhere in the tweak in base64 string format
//
// Authors: vriska
// Created  Oct 2019
//

#include <UIKit/UIKit.h>

#ifndef VIVARESOURCES_H
#define VIVARESOURCES_H

@interface VIVAResources : NSObject
+ (UIImage *)logo;
+ (UIImage *)spacerImageToggled:(BOOL)toggled;
+ (UIImage *)offsetImageToggled:(BOOL)toggled;
+ (UIImage *)rootImageToggled:(BOOL)toggled;
+ (UIImage *)dockImageToggled:(BOOL)toggled;
+ (UIImage *)iconCountImageToggled:(BOOL)toggled;
+ (UIImage *)scaleImageToggled:(BOOL)toggled;
+ (UIImage *)settingsImageToggled:(BOOL)toggled;
+ (UIImage *)resetImageToggled:(BOOL)toggled;
+ (UIImage *)inAppBannerToggled:(BOOL)toggled;
+ (UIImage *)inAppBannerNotchedToggled:(BOOL)toggled;
+ (UIImage *)inAppFooterToggled:(BOOL)toggled;
+ (UIImage *)extensionHomeToggled:(BOOL)toggled;
+ (UIImage *)saveToggled:(BOOL)toggled;
+ (UIImage *)cancelToggled:(BOOL)toggled;
+ (UIImage *)loadoutsToggled:(BOOL)toggled;
@end 

#endif