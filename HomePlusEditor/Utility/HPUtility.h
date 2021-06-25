//
// HPUtility.h
// HomePlus
//
// Utilities used across the tweak
// TODO: refactor a "HPUtilities"
//
// Authors: Kritanta
// Created  Dec 2019
//

#include <UIKit/UIKit.h>

#ifndef HPUTILITY_H
#define HPUTILITY_H

@interface HPUtility : NSObject

+ (BOOL)isCurrentDeviceNotched;
+ (NSString *)deviceName;
+ (BOOL)deviceRotatable;
+ (NSInteger)defaultRows;
+ (BOOL)writeToBundle:(NSString *)identifier atKey:(NSString *)key withValue:(id)value;
+ (UIImage*)imageByCombiningImage:(UIImage*)firstImage withImage:(UIImage*)secondImage;
+ (UIImage*)imageWithImage:(UIImage*)sourceImage scaledToWidth:(float)i_width;
+ (NSString *)localizedItem:(NSString *)key;
+ (NSString *)udid;
@end

#endif