//
// Created by vrisk/a on 7/8/21.
//

#import <Foundation/Foundation.h>
#import "Viva.h"

#include <SpringBoardHome/SBIconListGridLayoutConfiguration.h>

#ifndef VIVA_VIVAPAGECONFIGURATION_H
#define VIVA_VIVAPAGECONFIGURATION_H


typedef struct VIVALayoutConfiguration {
    UIOffset pageInsets;
    UIOffset pageSpacing;
    SBHIconGridSize iconGridSize;
    SBIconImageInfo iconImageInfo;
} VIVALayoutConfiguration;

typedef struct VIVALayoutOptions {
    BOOL hideLabels;
    BOOL hideBadges;
    BOOL hidePageControl;
} VIVALayoutOptions;



@interface VIVAPageConfiguration : NSObject <NSCoding>
@property NSString *name;
@property VIVALayoutConfiguration layoutConfiguration;
@property VIVALayoutOptions layoutOptions;

- (void)setConfigItem:(NSString *)item toValue:(NSInteger)value;

- (NSInteger)valueForItem:(NSString *)item;

- (BOOL)boolForOption:(NSString *)option;

- (void)setBool:(BOOL)value forOption:(NSString *)option;



- (instancetype)initWithLayoutConfiguration:(VIVALayoutConfiguration)layoutConfiguration layoutOptions:(VIVALayoutOptions)layoutOptions;

+ (instancetype)configurationWithLayoutConfiguration:(VIVALayoutConfiguration)layoutConfiguration layoutOptions:(VIVALayoutOptions)layoutOptions;

@end

#endif //VIVA_VIVAPAGECONFIGURATION_H