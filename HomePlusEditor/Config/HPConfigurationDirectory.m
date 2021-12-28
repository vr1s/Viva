//
// Created by Kritanta on 7/8/21.
//

#import <Foundation/Foundation.h>
#import "HPConfigurationDirectory.h"
#include "HPConfiguration.h"

@implementation HPConfigurationDirectory
{

@private
    NSMutableDictionary *_configurations;
    NSString *_selectedConfigurationName;
}
@synthesize configurations = _configurations;

@synthesize selectedConfigurationName = _selectedConfigurationName;

- (NSString *)selectedConfigurationName 
{
    // not sure why this is happening but it is /shrug
    if (!_selectedConfigurationName)
        _selectedConfigurationName = @"Default";
    if ([_selectedConfigurationName isEqualToString:@""])
        _selectedConfigurationName = @"Default";


    return _selectedConfigurationName;
}

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super init];
    if (self)
    {
        self.configurations = [coder decodeObjectForKey:@"self.configurations"];
        NSData *data = [coder decodeObjectForKey:@"self.selectedConfigurationName"];
        for (NSString *key in self.configurations)
        {
            ((HPConfiguration *)self.configurations[key]).name = key;
        }
        self.selectedConfigurationName = [[NSString alloc] initWithData:data encoding:NSDataBase64EncodingEndLineWithLineFeed];
    }

    return self;
}


- (void)encodeWithCoder:(NSCoder *)coder
{
    [coder encodeObject:self.configurations forKey:@"self.configurations"];
    NSData *dataFromString = [self.selectedConfigurationName dataUsingEncoding:NSDataBase64EncodingEndLineWithLineFeed];
    [coder encodeObject:dataFromString forKey:@"self.selectedConfigurationName"];
}



@end