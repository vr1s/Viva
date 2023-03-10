//
// HPSettingsTableViewController.h
// HomePlus
//
// Small little view controller for the settings table
//
// Authors: Kritanta
// Created  Oct 2019
//

#include <UIKit/UIKit.h>

@interface HPSettingsTableViewController<UIAlertViewDelegate> : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, retain) UITableView *tableView;

-(void)opened;

@end