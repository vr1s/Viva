//
// Created by vrisk/a on 7/8/21.
//

#import <Foundation/Foundation.h>
#import "VIVAConfiguration.h"

@class VIVAConfigurationDirectory;

#ifndef VIVA_VIVACONFIGURATIONMANAGER_H
#define VIVA_VIVACONFIGURATIONMANAGER_H

@interface VIVAConfigurationManager : NSObject
- (void)save;

+ (instancetype)sharedInstance;

- (void)deleteConfigurationWithName:(NSString *)name;
- (VIVAConfiguration *)configurationWithName:(NSString *)name createIfNecessary:(BOOL)create;
- (void)reset;
@property NSUserDefaults *store;
@property VIVAConfigurationDirectory *directory;
@property VIVAConfiguration *currentConfiguration;
@end

#endif //VIVA_VIVACONFIGURATIONMANAGER_H