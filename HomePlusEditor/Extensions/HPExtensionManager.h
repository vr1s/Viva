//
// HPExtensionManager.h
// HomePlus
//
// Global manager for the Extension Framework
//
// Maybe at some point this should be refactored to HPExtensionManager
//
// Authors: Kritanta
// Created  Dec 2019
//
#include <Foundation/Foundation.h>

#ifndef HPEXTENSIONMANAGER_H
#define HPEXTENSIONMANAGER_H

@interface HPExtensionManager : NSObject

@property (nonatomic, retain) NSMutableArray *extensions;

+ (instancetype)sharedInstance;
- (instancetype)init;

- (void)findAndLoadInExtensions;

@end

#endif