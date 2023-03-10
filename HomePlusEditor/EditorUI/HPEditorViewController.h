//
// HPEditorViewController
//
// View controller for the editor/homebase for handling UI
//
// Authors: Kritanta
// Created  Dec 2019
//


#include <UIKit/UIKit.h>

#import "../Utility/OBSlider.h"
#import "HPControllerView.h"
#include "../Extensions/HPExtensionControllerView.h"
#include "../Extensions/HPExtension.h"
#import "../Settings/HPSettingsTableViewController.h"
#import "HPEditorViewNavigationTabBar.h"


#ifndef HPEDITORVIEWCONTROLLER_H
#define HPEDITORVIEWCONTROLLER_H

@protocol HPEditorViewControllerDelegate;

@interface HPEditorViewController : UIViewController 

@property (nonatomic, strong) id <HPEditorViewControllerDelegate> delegate;

@property (nonatomic, readonly, strong) HPControllerView *offsetControlView;
@property (nonatomic, readonly, strong) HPControllerView *spacingControlView;
@property (nonatomic, readonly, strong) HPControllerView *iconCountControlView;
@property (nonatomic, readonly, strong) HPControllerView *scaleControlView;
@property (nonatomic, readonly, strong) HPControllerView *settingsView;

@property (nonatomic, readonly, strong) HPEditorViewNavigationTabBar *tabBar;
@property (nonatomic, readonly, strong) HPEditorViewNavigationTabBar *loadoutTabBar;
@property (nonatomic, readonly, strong) HPSettingsTableViewController *tableViewController;

@property (nonatomic, retain) HPEditorViewNavigationTabBar *extensionBar;

@property (nonatomic, retain) HPExtension *activeExtension;

@property (nonatomic, retain) NSMutableArray *rootIconListViewsToUpdate;

@property (nonatomic, retain) NSMutableArray *homeTabControllerViews;



- (HPEditorViewNavigationTabBar *)anExtensionBar;
- (HPEditorViewNavigationTabBar *)customExtensionTabBar;
- (HPEditorViewNavigationTabBar *)defaultTabBar;
- (void)handleExtensionBarButtonPress:(UIButton *)button;
- (void)loadExtension:(HPExtension *)extension;
- (void)handleExtensionTabBarButtonPress:(UIButton *)button;
- (void)handleDefaultBarTabButtonPress:(UIButton *)button;
- (void)unloadExtensionPanes;
- (void)doHighlight:(UIButton*)b;
- (void)reload;
- (void)resetAllValuesToDefaults;
- (void)handleSettingsButtonPress:(UIButton*)sender;
- (void)handleDoneSettingsButtonPress:(UIButton*)sender;
- (void)handleRootButtonPress:(UIButton*)sender;
- (void)handleDockButtonPress:(UIButton*)sender;
- (void)layoutAllSpringboardIcons;
- (void)transitionViewsToActivationPercentage:(CGFloat)amount;
- (void)transitionViewsToActivationPercentage:(CGFloat)amount withDuration:(CGFloat)duration ;
@end

@protocol HPEditorViewControllerDelegate <NSObject>

- (void)editorViewControllerDidFinish:(HPEditorViewController *)editorViewController;

@end

#endif