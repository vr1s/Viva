//
// VIVAEditorViewController
//
// View controller for the editor/homebase for handling UI
//
// Authors: vriska
// Created  Dec 2019
//


#include <UIKit/UIKit.h>

#import "OBSlider.h"
#import "../VIVAControllerView.h"
#include "VIVAExtensionControllerView.h"
#include "VIVAExtension.h"
#import "VIVASettingsTableViewController.h"
#import "VIVAEditorViewNavigationTabBar.h"


#ifndef VIVAEDITORVIEWCONTROLLER_H
#define VIVAEDITORVIEWCONTROLLER_H

@protocol VIVAEditorViewControllerDelegate;

@interface VIVAEditorViewController : UIViewController 

@property (nonatomic, strong) id <VIVAEditorViewControllerDelegate> delegate;

@property (nonatomic, readonly, strong) VIVAControllerView *offsetControlView;
@property (nonatomic, readonly, strong) VIVAControllerView *spacingControlView;
@property (nonatomic, readonly, strong) VIVAControllerView *iconCountControlView;
@property (nonatomic, readonly, strong) VIVAControllerView *scaleControlView;
@property (nonatomic, readonly, strong) VIVAControllerView *settingsView;

@property (nonatomic, readonly, strong) VIVAEditorViewNavigationTabBar *tabBar;
@property (nonatomic, readonly, strong) VIVAEditorViewNavigationTabBar *loadoutTabBar;
@property (nonatomic, readonly, strong) VIVASettingsTableViewController *tableViewController;

@property (nonatomic, retain) VIVAEditorViewNavigationTabBar *extensionBar;

@property (nonatomic, retain) VIVAExtension *activeExtension;

@property (nonatomic, retain) NSMutableArray *rootIconListViewsToUpdate;

@property (nonatomic, retain) NSMutableArray *homeTabControllerViews;



- (VIVAEditorViewNavigationTabBar *)anExtensionBar;
- (VIVAEditorViewNavigationTabBar *)customExtensionTabBar;
- (VIVAEditorViewNavigationTabBar *)defaultTabBar;
- (void)handleExtensionBarButtonPress:(UIButton *)button;
- (void)loadExtension:(VIVAExtension *)extension;
- (void)handleExtensionTabBarButtonPress:(UIButton *)button;
- (void)handleDefaultBarTabButtonPress:(UIButton *)button;
- (void)unloadExtensionPanes;
- (void)doHighlight:(UIButton*)b;
- (void)reload;
- (void)resetAllValuesToDefaults;
- (void)handleSettingsButtonPress:(UIButton*)sender;
- (void)handleDoneSettingsButtonPress:(UIButton*)sender;
- (void)settingsViewControllerDidDismiss;
- (void)handleRootButtonPress:(UIButton*)sender;
- (void)handleDockButtonPress:(UIButton*)sender;
- (void)layoutAllSpringboardIcons;
- (void)transitionViewsToActivationPercentage:(CGFloat)amount;
- (void)transitionViewsToActivationPercentage:(CGFloat)amount withDuration:(CGFloat)duration ;
@end

@protocol VIVAEditorViewControllerDelegate <NSObject>

- (void)editorViewControllerDidFinish:(VIVAEditorViewController *)editorViewController;

@end

#endif