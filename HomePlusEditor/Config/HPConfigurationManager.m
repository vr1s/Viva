//
// Created by Kritanta on 7/8/21.
//

#import <HPConfiguration.h>
#import "HPConfigurationManager.h"
#import "HPConfigurationDirectory.h"
#import "HPPageConfiguration.h"
#include "HPLayoutManager.h"


@interface HPConfigurationManager ()
+ (HPConfiguration *)defaultConfiguration;
@end

@implementation HPConfigurationManager
{

@private
    NSUserDefaults *_store;
    HPConfigurationDirectory *_directory;
}

@synthesize store = _store;

@synthesize directory = _directory;

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        _store = [[NSUserDefaults alloc] initWithSuiteName:@"me.krit.homepluspro"];
        NSData *directoryData = [_store dataForKey:@"Directory"];
        NSString *currentlySelectedConfigurationName = [_store objectForKey:@"CurrentConfigurationName"];


        if (!directoryData)
            _directory = [HPConfigurationManager defaultDirectory];
        else
            _directory = [NSKeyedUnarchiver unarchiveObjectWithData:directoryData];

        // So, there's this odd failure state where, if the Directory key got saved to with bogus data
        //      directoryData wont be null, none of the code anywhere in the tweak will throw an exception,
        //      however _directory will be null. So if we hit that failure state, the user configs are fucked,
        //      and we want to just reload them from defaults.
        if (!_directory)
            _directory = [HPConfigurationManager defaultDirectory];

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
    _directory = [HPConfigurationManager defaultDirectory];
    [self save];
}

- (void)setCurrentConfiguration:(HPConfiguration *)configuration 
{
    _currentConfiguration = configuration;
    _directory.selectedConfigurationName = configuration.name;

}

- (void)deleteConfigurationWithName:(NSString *)name
{
    [_directory.configurations removeObjectForKey:name];
    [self save];
}

- (HPConfiguration *)configurationWithName:(NSString *)name createIfNecessary:(BOOL)create
{
    
    if (_directory.configurations[name])
        return _directory.configurations[name];

    if (create)
    {
        _directory.configurations[name] = [HPConfigurationManager defaultConfiguration];
        ((HPConfiguration *)_directory.configurations[name]).name = name;
    }

    return _directory.configurations[name];
}

+ (HPConfigurationDirectory *)defaultDirectory
{
    HPConfigurationDirectory *directory = [[HPConfigurationDirectory alloc] init];
    directory.selectedConfigurationName = @"Default";
    directory.configurations = [@{@"Default": [HPConfigurationManager defaultConfiguration]} mutableCopy];
    return directory;
}

+ (HPConfiguration *)defaultConfiguration
{

    NSMutableDictionary *pageConfigs = [[NSMutableDictionary alloc] init];


    SBIconListGridLayoutConfiguration *defaultRootConfiguration = [HPLayoutManager defaultConfigurationForIconLocation:@"SBIconLocationRoot"];
    
    HPLayoutConfiguration layoutConfig = { .pageInsets=UIOffsetZero, .pageSpacing=UIOffsetZero, .iconImageInfo={
        .size = CGSizeMake(60, 60),
        .scale = {3},
        .continuousCornerRadius = {13.5}}, .iconGridSize={.rows=6, .columns=4}};
    HPLayoutOptions layoutOptions = {.hidePageControl=0, .hideLabels=0, .hideBadges=0};

    HPPageConfiguration *pageConfiguration = [[HPPageConfiguration alloc] initWithLayoutConfiguration:layoutConfig layoutOptions:layoutOptions];

    pageConfigs[@"SBIconLocationRoot"]=pageConfiguration;



    SBIconListGridLayoutConfiguration *defaultDockConfiguration = [HPLayoutManager defaultConfigurationForIconLocation:@"SBIconLocationDock"];

    HPLayoutConfiguration dockLayoutConfig = { .pageInsets=UIOffsetZero, .pageSpacing=UIOffsetZero, .iconImageInfo={
        .size = CGSizeMake(60, 60),
        .scale = {3},
        .continuousCornerRadius = {13.5}}, .iconGridSize={.rows=1, .columns=4}};
    HPLayoutOptions dockLayoutOptions = {.hidePageControl=0, .hideLabels=0, .hideBadges=0};

    HPPageConfiguration *dockPageConfiguration = [[HPPageConfiguration alloc] initWithLayoutConfiguration:dockLayoutConfig layoutOptions:dockLayoutOptions];

    pageConfigs[@"SBIconLocationDock"]=dockPageConfiguration;



    NSMutableDictionary *indexSpecificConfigurations = [[NSMutableDictionary alloc] init];
    pageConfigs[@"IndexSpecificConfigurations"] = indexSpecificConfigurations;

    HPConfiguration *configuration = [HPConfiguration configurationWithPageConfigurations:pageConfigs isPageSpecificConfigurationEnabled:NO];
    configuration.name = @"Default";

    return configuration;
}

@end