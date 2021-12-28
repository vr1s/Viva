//
// Created by Kritanta on 7/8/21.
//

#import <Foundation/Foundation.h>
#import "HomePlus.h"

#ifndef HOMEPLUS_HPPAGECONFIGURATION_H
#define HOMEPLUS_HPPAGECONFIGURATION_H


typedef struct HPLayoutConfiguration {
    UIOffset pageInsets;
    UIOffset pageSpacing;
    SBHIconGridSize iconGridSize;
    SBIconImageInfo iconImageInfo;
} HPLayoutConfiguration;

typedef struct HPLayoutOptions {
    BOOL hideLabels;
    BOOL hideBadges;
    BOOL hidePageControl;
} HPLayoutOptions;



@interface HPPageConfiguration : NSObject <NSCoding>
@property NSString *name;
@property HPLayoutConfiguration layoutConfiguration;
@property HPLayoutOptions layoutOptions;

- (void)setConfigItem:(NSString *)item toValue:(NSInteger)value;

- (NSInteger)valueForItem:(NSString *)item;

- (BOOL)boolForOption:(NSString *)option;

- (void)setBool:(BOOL)value forOption:(NSString *)option;



- (instancetype)initWithLayoutConfiguration:(HPLayoutConfiguration)layoutConfiguration layoutOptions:(HPLayoutOptions)layoutOptions;

+ (instancetype)configurationWithLayoutConfiguration:(HPLayoutConfiguration)layoutConfiguration layoutOptions:(HPLayoutOptions)layoutOptions;

@end

#endif //HOMEPLUS_HPPAGECONFIGURATION_H