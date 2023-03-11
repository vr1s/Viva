//
// Created by vrisk/a on 7/8/21.
//

#import <VIVAConfiguration.h>
#import "VIVAConfigurationManager.h"
#import "VIVAConfigurationDirectory.h"
#import "VIVAPageConfiguration.h"
#include "VIVALayoutManager.h"
#include "VivaUtility.h"


@interface VIVAConfigurationManager ()
+ (VIVAConfiguration *)defaultConfiguration;
@end

@implementation VIVAConfigurationManager
{

@private
    NSUserDefaults *_store;
    VIVAConfigurationDirectory *_directory;
}

@synthesize store = _store;

@synthesize directory = _directory;

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        _store = [[NSUserDefaults alloc] initWithSuiteName:@"sk.vri.viva"];
        NSData *directoryData = [_store dataForKey:@"Directory"];
        NSString *currentlySelectedConfigurationName = [_store objectForKey:@"CurrentConfigurationName"];


        if (!directoryData)
            _directory = [VIVAConfigurationManager defaultDirectory];
        else
            _directory = [NSKeyedUnarchiver unarchiveObjectWithData:directoryData];

        // So, there's this odd failure state where, if the Directory key got saved to with bogus data
        //      directoryData wont be null, none of the code anywhere in the tweak will throw an exception,
        //      however _directory will be null. So if we hit that failure state, the user configs are fucked,
        //      and we want to just reload them from defaults.
        if (!_directory)
            _directory = [VIVAConfigurationManager defaultDirectory];

        [self save];
        _directory.selectedConfigurationName = currentlySelectedConfigurationName;
        _currentConfiguration = [self configurationWithName:_directory.selectedConfigurationName createIfNecessary:YES];
    }

    return self;
}

- (void)save
{
    [_store setObject:[NSKeyedArchiver archivedDataWithRootObject:_directory requiringSecureCoding:NO error:nil]
               forKey:@"Directory"];
    
    [_store setObject:_directory.selectedConfigurationName forKey:@"CurrentConfigurationName"];
}

+ (instancetype)sharedInstance
{
    static id _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        _sharedInstance = [[self alloc] init];
    });

    return _sharedInstance;
}

- (void)reset 
{
    [_store removeObjectForKey:@"Directory"];
    _directory = [VIVAConfigurationManager defaultDirectory];
    [self save];
}

- (void)setCurrentConfiguration:(VIVAConfiguration *)configuration 
{
    _currentConfiguration = configuration;
    _directory.selectedConfigurationName = configuration.name;

}

- (void)deleteConfigurationWithName:(NSString *)name
{
    [_directory.configurations removeObjectForKey:name];
    [self save];
}

- (VIVAConfiguration *)configurationWithName:(NSString *)name createIfNecessary:(BOOL)create
{
    
    if (_directory.configurations[name])
        return _directory.configurations[name];

    if (create)
    {
        _directory.configurations[name] = [VIVAConfigurationManager defaultConfiguration];
        ((VIVAConfiguration *)_directory.configurations[name]).name = name;
    }

    return _directory.configurations[name];
}

+ (VIVAConfigurationDirectory *)defaultDirectory
{
    VIVAConfigurationDirectory *directory = [[VIVAConfigurationDirectory alloc] init];
    directory.selectedConfigurationName = @"Default";
    directory.configurations = [@{@"Default": [VIVAConfigurationManager defaultConfiguration]} mutableCopy];
    return directory;
}

+ (VIVAConfiguration *)defaultConfiguration
{

    NSMutableDictionary *pageConfigs = [[NSMutableDictionary alloc] init];


    SBIconListGridLayoutConfiguration *defaultRootConfiguration = [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationRoot"];
    
    VIVALayoutConfiguration layoutConfig = { .pageInsets=UIOffsetZero, .pageSpacing=UIOffsetZero, .iconImageInfo={
        .size = CGSizeMake(60, 60),
        .scale = {3},
        .continuousCornerRadius = {13.5}}, .iconGridSize={.rows=[VIVAUtility defaultRows], .columns=4}};
    VIVALayoutOptions layoutOptions = {.hidePageControl=0, .hideLabels=0, .hideBadges=0};

    VIVAPageConfiguration *pageConfiguration = [[VIVAPageConfiguration alloc] initWithLayoutConfiguration:layoutConfig layoutOptions:layoutOptions];

    pageConfigs[@"SBIconLocationRoot"]=pageConfiguration;



    SBIconListGridLayoutConfiguration *defaultDockConfiguration = [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationDock"];

    VIVALayoutConfiguration dockLayoutConfig = { .pageInsets=UIOffsetZero, .pageSpacing=UIOffsetZero, .iconImageInfo={
        .size = CGSizeMake(60, 60),
        .scale = {3},
        .continuousCornerRadius = {13.5}}, .iconGridSize={.rows=1, .columns=4}};
    VIVALayoutOptions dockLayoutOptions = {.hidePageControl=0, .hideLabels=0, .hideBadges=0};

    VIVAPageConfiguration *dockPageConfiguration = [[VIVAPageConfiguration alloc] initWithLayoutConfiguration:dockLayoutConfig layoutOptions:dockLayoutOptions];

    pageConfigs[@"SBIconLocationDock"]=dockPageConfiguration;

    NSMutableDictionary *indexSpecificConfigurations = [[NSMutableDictionary alloc] init];
    pageConfigs[@"IndexSpecificConfigurations"] = indexSpecificConfigurations;

    VIVAConfiguration *configuration = [VIVAConfiguration configurationWithPageConfigurations:pageConfigs isPageSpecificConfigurationEnabled:NO];
    configuration.name = @"Default";

    return configuration;
}

@end