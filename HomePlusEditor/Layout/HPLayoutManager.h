//
// Created by Kritanta on 6/27/21.
//

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>
#include "HomePlus.h"
#include "HPDataManager.h"

#ifndef HOMEPLUS_HPLAYOUTMANAGER_H
#define HOMEPLUS_HPLAYOUTMANAGER_H

@interface HPLayoutManager : NSObject
+(void)updateCacheForLocation:(NSString *)iconLocation;

+ (instancetype)sharedInstance;


+ (void)updateConfigItem:(NSString *)key forLocation:(NSString *)location withValue:(NSInteger)value;

- (void)initializeCacheOverride;

-(void)layoutIconViews;

-(void)layoutIconViewsAnimated;

- (void)layoutIndividualIcons;
@end

#endif //HOMEPLUS_HPLAYOUTMANAGER_H