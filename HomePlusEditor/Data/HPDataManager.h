#include <Foundation/Foundation.h>

#include "../Data/HPConfiguration.h"

#ifndef HPDATAMANAGER_H
#define HPDATAMANAGER_H

@interface HPDataManager : NSObject 

+ (instancetype)sharedInstance;

@property (nonatomic, retain) HPConfiguration *currentConfiguration;
@property (nonatomic, retain) NSMutableArray *savedConfigurations;

- (void)loadListOfSavedConfigurations;
- (void)loadConfigurationWithName:(NSString *)name;

@end

#endif