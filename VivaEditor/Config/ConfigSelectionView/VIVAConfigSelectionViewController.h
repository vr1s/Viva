//
// Created by vrisk/a on 7/11/21.
//

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

#ifndef VIVA_VIVACONFIGSELECTIONVIEWCONTROLLER_H
#define VIVA_VIVACONFIGSELECTIONVIEWCONTROLLER_H

@interface VIVAConfigSelectionViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;
@property (nonatomic, retain) UITableView *table;

@end

#endif //VIVA_VIVACONFIGSELECTIONVIEWCONTROLLER_H