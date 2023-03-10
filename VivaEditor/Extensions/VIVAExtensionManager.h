//
// VIVAExtensionManager.h
// Viva
//
// Global manager for the Extension Framework
//
// Maybe at some point this should be refactored to VIVAExtensionManager
//
// Authors: vriska
// Created  Dec 2019
//
#include <Foundation/Foundation.h>

#ifndef VIVAEXTENSIONMANAGER_H
#define VIVAEXTENSIONMANAGER_H

@interface VIVAExtensionManager : NSObject

@property (nonatomic, retain) NSMutableArray *extensions;

+ (instancetype)sharedInstance;
- (instancetype)init;

- (void)findAndLoadInExtensions;

@end

#endif