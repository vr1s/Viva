//
// Created by Kritanta on 7/11/21.
//

#import <Foundation/Foundation.h>
@import UIKit;

#ifndef HOMEPLUS_HPCONFIGSELECTIONVIEWCONTROLLER_H
#define HOMEPLUS_HPCONFIGSELECTIONVIEWCONTROLLER_H

@interface HPConfigSelectionViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;
@property (nonatomic, retain) UITableView *table;

@end

#endif //HOMEPLUS_HPCONFIGSELECTIONVIEWCONTROLLER_H