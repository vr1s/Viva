//
// HPExtensionManager.m
// HomePlus
//
// Global manager for the Extension Framework
//
// Maybe at some point this should be refactored to HPExtensionManager
//
// Authors: Kritanta
// Created  Dec 2019
//

#include "HPExtensionManager.h"
#include "../Extensions/HPExtensionControllerView.h"
#include "../Extensions/HPExtension.h"

@implementation HPExtensionManager

+ (instancetype)sharedInstance
{
    static HPExtensionManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (HPExtensionManager *)[[[self class] alloc] init];
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
            if ([item isEqualToString:@"HomePlus.plist"])
            {
                [self loadExtensionFromBundle:ting];
            }
        }
    }
}

- (void)loadExtensionFromBundle:(NSString *)bundlePath
{
    NSString *extensionPath = [NSString stringWithFormat:@"%@%@", bundlePath, @"/HomePlus.plist"];
    NSMutableDictionary *extensionDictionary = [NSMutableDictionary dictionaryWithContentsOfFile:extensionPath];
    HPExtension *extension = [[HPExtension alloc] initWithDictionary:extensionDictionary atBundlePath:bundlePath];
    [self.extensions addObject:extension];
}

@end