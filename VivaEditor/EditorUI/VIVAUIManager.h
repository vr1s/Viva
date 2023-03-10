//
// VIVAUIManager.h
// Viva
//
// Global manager for the Editor (and tutorial) views. 
//
// Maybe at some point this should be refactored to VIVAUIManager :)
//
// Authors: vriska
// Created  Oct 2019
//
#include <UIKit/UIKit.h>

#import "VivaEditor/EditorUI/MainEditorView/VIVAEditorViewController.h"


#ifndef VIVAUIManager_H
#define VIVAUIManager_H

@interface VIVAUIManager : NSObject

+ (instancetype)sharedInstance;
@property (nonatomic, retain) NSString *editingLocation;
@property (nonatomic, readonly, strong) VIVAEditorViewController *editorViewController;

@property (nonatomic, retain) UIImage *wallpaper;
@property (nonatomic, retain) UIImage *dynamicallyGeneratedSettingsHeaderImage;
@property (nonatomic, retain) UIImage *blurredAndDarkenedWallpaper;
@property (nonatomic, retain) UIImage *blurredMoreBackgroundImage;
-(UIImage *)bdBackgroundImage;
-(UIImage *)blurredMoreBGImage;
-(void)loadUpImagesFromWallpaper:(UIImage *)image;

-(VIVAEditorViewController *)editorViewController;
-(void)resetAllValuesToDefaults;
-(void)showEditorView;
-(void)hideEditorView;

@end

#endif