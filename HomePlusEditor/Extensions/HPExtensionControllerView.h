//
// HPExtensionControllerView.h
// HomePlus
//
// HPControllerView subclass for extensions
// Supports various interfaces (sliders, buttons, etc)
//
// Also handles interacting with tweak prefs
//
// Authors: Kritanta
// Created  Dec 2019
//

#include "HPExtension.h"
#include "../EditorUI/HPControllerView.h"

#ifndef HPEXTENSIONCONTROLLERVIEW_H
#define HPEXTENSIONCONTROLLERVIEW_H

typedef enum ControlType : NSUInteger {
   kSlider,
   kCounter,
   kSwitch,
   kNone
} ControlType;

@interface HPExtensionControllerView : HPControllerView

@property (nonatomic, assign) ControlType topControlType;
@property (nonatomic, assign) ControlType bottomControlType;

@property (nonatomic, retain) UIImage *paneIcon; 

@property (nonatomic, retain) HPExtension *extension;

@property (nonatomic, retain) NSString *bundleID;
@property (nonatomic, retain) NSString *bundleValueLocation;

@property (nonatomic, retain) NSString *topPreferenceLink;
@property (nonatomic, retain) NSString *bottomPreferenceLink;

@property (nonatomic, retain) NSString *topNotification;
@property (nonatomic, retain) NSString *bottomNotification;

- (void)configureValuesFromBundle;

@end

#endif