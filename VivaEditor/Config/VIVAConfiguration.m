//
// Created by vrisk/a on 7/8/21.
//

#import "VIVAConfiguration.h"


@implementation VIVAConfiguration
{

@private
    NSMutableDictionary<NSString *, VIVAPageConfiguration *> *_pageConfigurations;
    BOOL isPageSpecificConfigurationEnabled;
}
@synthesize pageConfigurations = _pageConfigurations;
@synthesize isPageIndexSpecificConfigurationEnabled = _isPageIndexSpecificConfigurationEnabled;

- (instancetype)initWithPageConfigurations:(NSMutableDictionary<NSString *, VIVAPageConfiguration *> *)pageConfigurations isPageIndexSpecificConfigurationEnabled:(BOOL)pageIndexSpecificConfigurationEnabled
{
    self = [super init];
    if (self)
    {
        self.pageConfigurations = pageConfigurations;
        self.isPageIndexSpecificConfigurationEnabled = isPageSpecificConfigurationEnabled;
    }

    return self;
}

+ (instancetype)configurationWithPageConfigurations:(NSMutableDictionary<NSString *, VIVAPageConfiguration *> *)pageConfigurations isPageSpecificConfigurationEnabled:(BOOL)isPageSpecificConfigurationEnabled
{
    return [[self alloc] initWithPageConfigurations:pageConfigurations isPageIndexSpecificConfigurationEnabled:isPageSpecificConfigurationEnabled];
}

- (VIVAConfiguration *)initWithCoder:(NSCoder *)coder
{

    self = [super init];
    if (self)
    {
        BOOL pageSpecific = [coder decodeBoolForKey:@"PageIndexSpecificConfigs"];
        NSMutableDictionary *configs = [NSKeyedUnarchiver unarchiveObjectWithData:[coder decodeObjectForKey:@"PageConfigurations"]];
        NSData *data = [coder decodeObjectForKey:@"self.name"];
        self = [self initWithPageConfigurations:configs isPageIndexSpecificConfigurationEnabled:pageSpecific];
        self.name = [[NSString alloc] initWithData:data encoding:NSDataBase64EncodingEndLineWithLineFeed];
    }

    return self;
}

- (void) encodeWithCoder:(NSCoder *)aCoder
{
    NSData *encodedConfigurations = [NSKeyedArchiver archivedDataWithRootObject:_pageConfigurations requiringSecureCoding:FALSE error:nil];
    [aCoder encodeBool:_isPageIndexSpecificConfigurationEnabled forKey:@"PageIndexSpecificConfigs"];
    [aCoder encodeObject:encodedConfigurations forKey:@"PageConfigurations"];
    NSData *dataFromString = [self.name dataUsingEncoding:NSDataBase64EncodingEndLineWithLineFeed];
    [aCoder encodeObject:dataFromString forKey:@"self.name"];
}


@end