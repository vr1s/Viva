//
// HPUtility.m
// HomePlus
//
// Utilities used across the tweak
// TODO: refactor a "HPUtilities"
//
// Authors: Kritanta
// Created  Dec 2019
//
// TODO: can we use C functions for this, maybe?
// TODO: could even make a library /shrug

#import "HPUtility.h"
#include "HPDataManager.h"
#import <sys/utsname.h>
#include <sandbox.h>
#include <dlfcn.h> 
#include <objc/runtime.h>
#include <spawn.h>
#import <mach/port.h>
#import <mach/kern_return.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/sysctl.h>
#include <sys/mman.h>
#include <CommonCrypto/CommonDigest.h>
#include "util.h"

@implementation HPUtility

+ (BOOL)isCurrentDeviceNotched
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
    {
        switch ((int)[[UIScreen mainScreen] nativeBounds].size.height)
        {
            case 2436: 
            {
                return YES;
                break;
            }
            case 2688:
            {
                return YES;
                break;
            }
            case 1792:
            {
                return YES;
                break;
            }
            default:
            {
                return NO;
                break;
            }
        }
    }  
    return NO; 
}

+(NSString *)deviceName
{
    struct utsname systemInfo;

    uname(&systemInfo);

    NSString* code = [NSString stringWithCString:systemInfo.machine
                                        encoding:NSUTF8StringEncoding];

    static NSDictionary* deviceNamesByCode = nil;

    if (!deviceNamesByCode) {

        deviceNamesByCode = @{@"i386"      : @"Simulator",
                              @"x86_64"    : @"Simulator",
                              @"iPod1,1"   : @"iPod Touch",        // (Original)
                              @"iPod2,1"   : @"iPod Touch",        // (Second Generation)
                              @"iPod3,1"   : @"iPod Touch",        // (Third Generation)
                              @"iPod4,1"   : @"iPod Touch",        // (Fourth Generation)
                              @"iPod7,1"   : @"iPod Touch",        // (6th Generation)       
                              @"iPhone1,1" : @"iPhone",            // (Original)
                              @"iPhone1,2" : @"iPhone",            // (3G)
                              @"iPhone2,1" : @"iPhone",            // (3GS)
                              @"iPad1,1"   : @"iPad",              // (Original)
                              @"iPad2,1"   : @"iPad 2",            //
                              @"iPad3,1"   : @"iPad",              // (3rd Generation)
                              @"iPhone3,1" : @"iPhone 4",          // (GSM)
                              @"iPhone3,3" : @"iPhone 4",          // (CDMA/Verizon/Sprint)
                              @"iPhone4,1" : @"iPhone 4S",         //
                              @"iPhone5,1" : @"iPhone 5",          // (model A1428, AT&T/Canada)
                              @"iPhone5,2" : @"iPhone 5",          // (model A1429, everything else)
                              @"iPad3,4"   : @"iPad",              // (4th Generation)
                              @"iPad2,5"   : @"iPad Mini",         // (Original)
                              @"iPhone5,3" : @"iPhone 5c",         // (model A1456, A1532 | GSM)
                              @"iPhone5,4" : @"iPhone 5c",         // (model A1507, A1516, A1526 (China), A1529 | Global)
                              @"iPhone6,1" : @"iPhone 5s",         // (model A1433, A1533 | GSM)
                              @"iPhone6,2" : @"iPhone 5s",         // (model A1457, A1518, A1528 (China), A1530 | Global)
                              @"iPhone7,1" : @"iPhone 6 Plus",     //
                              @"iPhone7,2" : @"iPhone 6",          //
                              @"iPhone8,1" : @"iPhone 6S",         //
                              @"iPhone8,2" : @"iPhone 6S Plus",    //
                              @"iPhone8,4" : @"iPhone SE",         //
                              @"iPhone9,1" : @"iPhone 7",          //
                              @"iPhone9,3" : @"iPhone 7",          //
                              @"iPhone9,2" : @"iPhone 7 Plus",     //
                              @"iPhone9,4" : @"iPhone 7 Plus",     //
                              @"iPhone10,1": @"iPhone 8",          // CDMA
                              @"iPhone10,4": @"iPhone 8",          // GSM
                              @"iPhone10,2": @"iPhone 8 Plus",     // CDMA
                              @"iPhone10,5": @"iPhone 8 Plus",     // GSM
                              @"iPhone10,3": @"iPhone X",          // CDMA
                              @"iPhone10,6": @"iPhone X",          // GSM
                              @"iPhone11,2": @"iPhone XS",         //
                              @"iPhone11,4": @"iPhone XS Max",     //
                              @"iPhone11,6": @"iPhone XS Max",     // China
                              @"iPhone11,8": @"iPhone XR",         //
                              @"iPhone12,1": @"iPhone 11",         //
                              @"iPhone12,3": @"iPhone 11 Pro",     //
                              @"iPhone12,5": @"iPhone 11 Pro Max", //

                              @"iPad4,1"   : @"iPad Air",          // 5th Generation iPad (iPad Air) - Wifi
                              @"iPad4,2"   : @"iPad Air",          // 5th Generation iPad (iPad Air) - Cellular
                              @"iPad4,4"   : @"iPad Mini 2",         // (2nd Generation iPad Mini - Wifi)
                              @"iPad4,5"   : @"iPad Mini 2",         // (2nd Generation iPad Mini - Cellular)
                              @"iPad4,7"   : @"iPad Mini 3",         // (3rd Generation iPad Mini - Wifi (model A1599))
                              @"iPad5,2"   : @"iPad Mini 4",
                              @"iPad6,7"   : @"iPad Pro (12.9\")", // iPad Pro 12.9 inches - (model A1584) 
                              @"iPad6,8"   : @"iPad Pro (12.9\")", // iPad Pro 12.9 inches - (model A1652) 
                              @"iPad6,3"   : @"iPad Pro (9.7\")",  // iPad Pro 9.7 inches - (model A1673)
                              @"iPad6,4"   : @"iPad Pro (9.7\")"   // iPad Pro 9.7 inches - (models A1674 and A1675)
                              };
    }

    NSString* deviceName = [deviceNamesByCode objectForKey:code];

    if (!deviceName) {
        // Not found on database. At least guess main device type from string contents:

        if ([code rangeOfString:@"iPod"].location != NSNotFound) {
            deviceName = @"iPod Touch";
        }
        else if([code rangeOfString:@"iPad"].location != NSNotFound) {
            deviceName = @"iPad";
        }
        else if([code rangeOfString:@"iPhone"].location != NSNotFound){
            deviceName = @"iPhone";
        }
        else {
            deviceName = @"Unknown";
        }
    }

    return deviceName;
}

+ (BOOL)deviceRotatable
{
    return NO;
    if ([[[HPDataManager sharedInstance] currentConfiguration] boolForKey:@"HPDataForceRotation"])
        return YES;

    if ([[HPUtility deviceName] containsString:@"iPad"])
        return YES;
    
    if ([[HPUtility deviceName] containsString:@"Plus"])
        return YES;

    return NO;
}

+ (NSInteger)defaultRows
{
    // lol
    struct utsname systemInfo;

    uname(&systemInfo);

    NSString* code = [NSString stringWithCString:systemInfo.machine
                                        encoding:NSUTF8StringEncoding];

    static NSDictionary* deviceNamesByCode = nil;

    // its big brain time
    // literally nothing else was reliable enough across versions and devices.
    if (!deviceNamesByCode) {

        deviceNamesByCode = @{@"i386"      : @5,        // Simulator (32 bit)
                              @"x86_64"    : @5,        // Simulator (64 bit)
                              @"iPod1,1"   : @4,        // iPod Touch
                              @"iPod2,1"   : @4,        // iPod Touch 2
                              @"iPod3,1"   : @4,        // iPod Touch 3
                              @"iPod4,1"   : @4,        // iPod Touch 4
                              @"iPod7,1"   : @4,        // iPod Touch 6   
                              @"iPhone1,1" : @4,        // iPhone
                              @"iPhone1,2" : @4,            // (3G)
                              @"iPhone2,1" : @4,            // (3GS)
                              @"iPad1,1"   : @4,              // (Original)
                              @"iPad2,1"   : @4,            //
                              @"iPad3,1"   : @4,              // (3rd Generation)
                              @"iPhone3,1" : @4,          // (GSM)
                              @"iPhone3,3" : @4,          // (CDMA/Verizon/Sprint)
                              @"iPhone4,1" : @4,         //
                              @"iPhone5,1" : @5,          // (model A1428, AT&T/Canada)
                              @"iPhone5,2" : @5,          // (model A1429, everything else)
                              @"iPad3,4"   : @4,              // (4th Generation)
                              @"iPad2,5"   : @4,         // (Original)
                              @"iPhone5,3" : @5,         // (model A1456, A1532 | GSM)
                              @"iPhone5,4" : @5,         // (model A1507, A1516, A1526 (China), A1529 | Global)
                              @"iPhone6,1" : @5,         // (model A1433, A1533 | GSM)
                              @"iPhone6,2" : @5,         // (model A1457, A1518, A1528 (China), A1530 | Global)
                              @"iPhone7,1" : @6,     //
                              @"iPhone7,2" : @6,          //
                              @"iPhone8,1" : @6,         //
                              @"iPhone8,2" : @6,    //
                              @"iPhone8,4" : @5,         //
                              @"iPhone9,1" : @6,          //
                              @"iPhone9,3" : @6,          //
                              @"iPhone9,2" : @6,     //
                              @"iPhone9,4" : @6,     //
                              @"iPhone10,1": @6,          // CDMA
                              @"iPhone10,4": @6,          // GSM
                              @"iPhone10,2": @6,     // CDMA
                              @"iPhone10,5": @6,     // GSM
                              @"iPhone10,3": @6,          // CDMA
                              @"iPhone10,6": @6,          // GSM
                              @"iPhone11,2": @6,         //
                              @"iPhone11,4": @6,     //
                              @"iPhone11,6": @6,     // China
                              @"iPhone11,8": @6,         //
                              @"iPhone12,1": @6,         //
                              @"iPhone12,3": @6,     //
                              @"iPhone12,5": @6, //

                              @"iPad4,1"   : @5,          // 5th Generation iPad (iPad Air) - Wifi
                              @"iPad4,2"   : @5,          // 5th Generation iPad (iPad Air) - Cellular
                              @"iPad4,4"   : @4,         // (2nd Generation iPad Mini - Wifi)
                              @"iPad4,5"   : @4,         // (2nd Generation iPad Mini - Cellular)
                              @"iPad4,7"   : @4,         // (3rd Generation iPad Mini - Wifi (model A1599))
                              @"iPad5,2"   : @5,
                              @"iPad6,7"   : @5, // iPad Pro 12.9 inches - (model A1584) 
                              @"iPad6,8"   : @5, // iPad Pro 12.9 inches - (model A1652) 
                              @"iPad6,3"   : @5,  // iPad Pro 9.7 inches - (model A1673)
                              @"iPad6,4"   : @5  // iPad Pro 9.7 inches - (models A1674 and A1675)
                              };
    }

    NSInteger rows = [[deviceNamesByCode valueForKey:code] intValue];

    if (!rows) {
        rows = 5;
    }

    return rows;
}

+ (BOOL)writeToBundle:(NSString *)identifier atKey:(NSString *)key withValue:(id)value
{
    CFPreferencesAppSynchronize((CFStringRef)identifier);
    CFPreferencesSetValue((CFStringRef)key, (CFPropertyListRef)value, (CFStringRef)identifier, CFSTR("mobile"), kCFPreferencesAnyHost);
    return YES;
}

+(UIImage*)imageWithImage: (UIImage*) sourceImage scaledToWidth: (float) i_width
{
    float oldWidth = sourceImage.size.width;
    float scaleFactor = i_width / oldWidth; 

    float newHeight = sourceImage.size.height * scaleFactor;
    float newWidth = oldWidth * scaleFactor;

    UIGraphicsBeginImageContext(CGSizeMake(newWidth, newHeight));
    [sourceImage drawInRect:CGRectMake(0, 0, newWidth, newHeight)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();    
    UIGraphicsEndImageContext();
    return newImage;
}

+ (UIImage*)imageByCombiningImage:(UIImage*)firstImage withImage:(UIImage*)secondImage {
    UIImage *image = nil;

    CGSize newImageSize = secondImage.size;
    UIGraphicsBeginImageContext(newImageSize); 

    [firstImage drawAtPoint:CGPointMake(roundf((newImageSize.width-firstImage.size.width)/2), 
                                        roundf((newImageSize.height-firstImage.size.height)/2))]; 
    [secondImage drawAtPoint:CGPointMake(roundf((newImageSize.width-secondImage.size.width)/2), 
                                         roundf((newImageSize.height-secondImage.size.height)/2))]; 
    image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    return image;
}

+ (NSString *)localizedItem:(NSString *)key 
{
    NSBundle *tweakBundle = [NSBundle bundleWithPath:@"/Library/Application Support/HomePlus.bundle"];

    return [tweakBundle localizedStringForKey:key value:@"" table:nil] ?: @"";
}

@end