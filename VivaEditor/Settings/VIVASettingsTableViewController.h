//
// VIVASettingsTableViewController.h
// Viva
//
// Small little view controller for the settings table
//
// Authors: vriska
// Created  Oct 2019
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VIVAEditorViewController;

@interface VIVASettingsTableViewController<UIAlertViewDelegate> : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, retain) VIVAEditorViewController *delegate;

@property (nonatomic, retain) UITableView *tableView;

-(void)opened;

@end