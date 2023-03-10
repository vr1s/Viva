//
// Created by vrisk/a on 7/8/21.
//

#import <Foundation/Foundation.h>

#import "VIVAPageConfiguration.h"

#ifndef VIVA_VIVACONFIGURATION_H
#define VIVA_VIVACONFIGURATION_H

@interface VIVAConfiguration : NSObject <NSCoding>
@property NSString *name;
@property NSMutableDictionary<NSString *, VIVAPageConfiguration *> *pageConfigurations;
@property BOOL isPageIndexSpecificConfigurationEnabled;

- (instancetype)initWithPageConfigurations:(NSMutableDictionary<NSString *, VIVAPageConfiguration *> *)pageConfigurations isPageIndexSpecificConfigurationEnabled:(BOOL)isPageSpecificConfigurationEnabled;

+ (instancetype)configurationWithPageConfigurations:(NSMutableDictionary<NSString *, VIVAPageConfiguration *> *)pageConfigurations isPageSpecificConfigurationEnabled:(BOOL)isPageSpecificConfigurationEnabled;

@end

#endif //VIVA_VIVACONFIGURATION_H