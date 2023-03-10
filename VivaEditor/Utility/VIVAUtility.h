//
// VIVAUtility.h
// Viva
//
// Utilities used across the tweak
// TODO: refactor a "VIVAUtilities"
//
// Authors: vriska
// Created  Dec 2019
//

#include <UIKit/UIKit.h>

#ifndef VIVAUTILITY_H
#define VIVAUTILITY_H

@interface VIVAUtility : NSObject

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