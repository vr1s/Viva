//
// VIVAExtensionControllerView.h
// Viva
//
// VIVAControllerView subclass for extensions
// Supports various interfaces (sliders, buttons, etc)
//
// Also handles interacting with tweak prefs
//
// Authors: vriska
// Created  Dec 2019
//

#include "VIVAExtension.h"
#include "../EditorUI/VIVAControllerView.h"

#ifndef VIVAEXTENSIONCONTROLLERVIEW_H
#define VIVAEXTENSIONCONTROLLERVIEW_H

typedef enum ControlType : NSUInteger {
   kSlider,
   kCounter,
   kSwitch,
   kNone
} ControlType;

@interface VIVAExtensionControllerView : VIVAControllerView

@property (nonatomic, assign) ControlType topControlType;
@property (nonatomic, assign) ControlType bottomControlType;

@property (nonatomic, retain) UIImage *paneIcon; 

@property (nonatomic, retain) VIVAExtension *extension;

@property (nonatomic, retain) NSString *bundleID;
@property (nonatomic, retain) NSString *bundleValueLocation;

@property (nonatomic, retain) NSString *topPreferenceLink;
@property (nonatomic, retain) NSString *bottomPreferenceLink;

@property (nonatomic, retain) NSString *topNotification;
@property (nonatomic, retain) NSString *bottomNotification;

- (void)configureValuesFromBundle;

@end

#endif