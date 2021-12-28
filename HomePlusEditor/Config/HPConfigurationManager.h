//
// Created by Kritanta on 7/8/21.
//

#import <Foundation/Foundation.h>
#import "HPConfiguration.h"

@class HPConfigurationDirectory;

#ifndef HOMEPLUS_HPCONFIGURATIONMANAGER_H
#define HOMEPLUS_HPCONFIGURATIONMANAGER_H

@interface HPConfigurationManager : NSObject
- (void)save;

+ (instancetype)sharedInstance;

- (void)deleteConfigurationWithName:(NSString *)name;
- (HPConfiguration *)configurationWithName:(NSString *)name createIfNecessary:(BOOL)create;
- (void)reset;
@property NSUserDefaults *store;
@property HPConfigurationDirectory *directory;
@property HPConfiguration *currentConfiguration;
@end

#endif //HOMEPLUS_HPCONFIGURATIONMANAGER_H