//
// HPExtension.h
// HomePlus
//
// Extension Object. 
// Holds everything important about an extension that was found
//
// Authors: vriska
// Created  Dec 2019
//

#include <UIKit/UIKit.h>

#ifndef HPEXTENSION_H
#define HPEXTENSION_H
@interface HPExtension : NSObject

- (instancetype)initWithDictionary:(NSMutableDictionary *)extensionDict atBundlePath:(NSString*)bundlePath;

@property (nonatomic, retain) NSString *bundleFilePath;

@property (nonatomic, retain) NSString *extensionName;

@property (nonatomic, retain) UIImage *extensionIcon;

@property (nonatomic, retain) NSMutableDictionary *extensionDictionary;

@property (nonatomic, retain) NSMutableArray *extensionControllerViews;

@end

#endif