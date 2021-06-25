//
// HPDataManager.m
// HomePlus
//
// Global manager for Data used in HomePlus
//
// Authors: Kritanta
// Created  Dec 2019
//

#include <objc/runtime.h>

#include "HomePlus.h"
#include "HPDataManager.h"
#include "../Data/HPConfiguration.h"

@implementation HPDataManager

+ (instancetype)sharedInstance
{
    static HPDataManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (HPDataManager *) [[[self class] alloc] init];
    });
    return sharedInstance;
}


- (instancetype)init
{
    self = [super init];

    if (self) 
    {
        self.savedConfigurations = [[NSMutableArray alloc] init];
        [self loadListOfSavedConfigurations];
        NSString *configName = [[NSUserDefaults standardUserDefaults] stringForKey:@"HPCurrentLoadout"] ?: @"Default";
        [self loadConfigurationWithName:configName];
    }

    return self;
}

- (void)loadListOfSavedConfigurations
{
    NSArray<NSString *> *listOfConfigurations = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/var/mobile/Documents/HomePlus/Loadouts" error:nil];
    self.savedConfigurations = [NSMutableArray new];
    for (NSString *bundle in listOfConfigurations)
    {
        if ([bundle containsString:@".plist"])
        {
            [self.savedConfigurations addObject:[[HPConfiguration alloc] initWithConfigurationName:bundle]];
        }
    }
}

- (void)loadConfigurationWithName:(NSString *)name
{
    NSError *error;
    [[NSNotificationCenter defaultCenter] postNotificationName:@"HPSaveIconState" object:nil];
    if (![name containsString:@".plist"])
    {
        name = [NSString stringWithFormat:@"%@%@", name, @".plist"];
    }
    self.currentConfiguration = [[HPConfiguration alloc] initWithConfigurationName:name];
    [[NSUserDefaults standardUserDefaults] setObject:name forKey:@"HPCurrentLoadout"];
}

@end
