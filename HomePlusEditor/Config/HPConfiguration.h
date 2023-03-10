//
// Created by Kritanta on 7/8/21.
//

#import <Foundation/Foundation.h>

#import "HPPageConfiguration.h"

#ifndef HOMEPLUS_HPCONFIGURATION_H
#define HOMEPLUS_HPCONFIGURATION_H

@interface HPConfiguration : NSObject <NSCoding>
@property NSString *name;
@property NSMutableDictionary<NSString *, HPPageConfiguration *> *pageConfigurations;
@property BOOL isPageIndexSpecificConfigurationEnabled;

- (instancetype)initWithPageConfigurations:(NSMutableDictionary<NSString *, HPPageConfiguration *> *)pageConfigurations isPageIndexSpecificConfigurationEnabled:(BOOL)isPageSpecificConfigurationEnabled;

+ (instancetype)configurationWithPageConfigurations:(NSMutableDictionary<NSString *, HPPageConfiguration *> *)pageConfigurations isPageSpecificConfigurationEnabled:(BOOL)isPageSpecificConfigurationEnabled;

@end

#endif //HOMEPLUS_HPCONFIGURATION_H