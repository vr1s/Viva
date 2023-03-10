//
// VIVAExtensionManager.m
// Viva
//
// Global manager for the Extension Framework
//
// Maybe at some point this should be refactored to VIVAExtensionManager
//
// Authors: vriska
// Created  Dec 2019
//

#include "VIVAExtensionManager.h"
#include "../Extensions/VIVAExtensionControllerView.h"
#include "../Extensions/VIVAExtension.h"

@implementation VIVAExtensionManager

+ (instancetype)sharedInstance
{
    static VIVAExtensionManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (VIVAExtensionManager *)[[[self class] alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init
{
    self = [super init];

    if (self) 
    {
        self.extensions = [[NSMutableArray alloc] init];
        [self findAndLoadInExtensions];
    }

    return self;
}

- (void)findAndLoadInExtensions
{
    NSArray<NSString *> *listOfPrefBundles = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Library/PreferenceBundles" error:nil];
    for (NSString *bundle in listOfPrefBundles)
    {
        NSString *ting = [NSString stringWithFormat:@"%@%@",@"/Library/PreferenceBundles/", bundle];
        NSArray<NSString *> *listOfBundleContents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:ting error:nil];
        for (NSString *item in listOfBundleContents)
        {
            if ([item isEqualToString:@"Viva.plist"])
            {
                [self loadExtensionFromBundle:ting];
            }
        }
    }
}

- (void)loadExtensionFromBundle:(NSString *)bundlePath
{
    NSString *extensionPath = [NSString stringWithFormat:@"%@%@", bundlePath, @"/Viva.plist"];
    NSMutableDictionary *extensionDictionary = [NSMutableDictionary dictionaryWithContentsOfFile:extensionPath];
    VIVAExtension *extension = [[VIVAExtension alloc] initWithDictionary:extensionDictionary atBundlePath:bundlePath];
    [self.extensions addObject:extension];
}

@end