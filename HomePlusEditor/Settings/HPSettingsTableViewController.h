//
// HPSettingsTableViewController.h
// HomePlus
//
// Small little view controller for the settings table
//
// Authors: Kritanta
// Created  Oct 2019
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class HPEditorViewController;

@interface HPSettingsTableViewController<UIAlertViewDelegate> : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, retain) HPEditorViewController *delegate;

@property (nonatomic, retain) UITableView *tableView;

-(void)opened;

@end