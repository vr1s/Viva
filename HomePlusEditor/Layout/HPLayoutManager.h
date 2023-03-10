//
// Created by Kritanta on 6/27/21.
//

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>
#include "HomePlus.h"

#include <SpringBoardHome/SBIconListGridLayoutConfiguration.h>
#include <SpringBoardHome/SBHDefaultIconListLayoutProvider.h>

#ifndef HOMEPLUS_HPLAYOUTMANAGER_H
#define HOMEPLUS_HPLAYOUTMANAGER_H

@interface HPLayoutManager : NSObject

@property (nonatomic, retain) SBHDefaultIconListLayoutProvider* defaultProvider;

@property (nonatomic, assign) bool readyForIconModelSwap;

@property (nonatomic, retain) NSMutableDictionary *originalConfigs;
@property (nonatomic, retain) NSMutableDictionary *overlayConfigs;

+(SBIconListGridLayoutConfiguration *)defaultConfigurationForIconLocation:(NSString *)iconLocation ;
+(void)updateCacheForLocation:(NSString *)iconLocation;

+ (instancetype)sharedInstance;

- (void)doSharedEditorClosedTasks;

+ (void)updateConfigItem:(NSString *)key forLocation:(NSString *)location withValue:(NSInteger)value;

- (void)initializeCacheOverride;

-(SBIconListFlowLayout *)layoutForIconLocation:(NSString* )arg0;

-(void)layoutIconViews;

-(void)layoutIconViewsAnimated;

- (void)layoutIndividualIcons;
@end

#endif //HOMEPLUS_HPLAYOUTMANAGER_H