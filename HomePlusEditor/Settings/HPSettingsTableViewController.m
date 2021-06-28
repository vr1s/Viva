//
// HPSettingsTableViewController.m
// HomePlus
//
// Settings (UITable)View Controller. Load stuff and call changes here. 
//
// Created Oct 2019
// Author: Kritanta
//
// TODO: this just needs rewritten honestly

#include "HPSettingsTableViewController.h"
#include "../Utility/HPResources.h"
#include "../Utility/HPUtility.h"
#include "../Data/HPConfiguration.h"
#include "../../Data/HPDataManager.h"
#include "../HPUIManager.h"
#include "../Utility/HPTableCell.h"
#include "HomePlus.h"
#include "spawn.h"
#import "HPLayoutManager.h"

static NSArray *_rtCells;

#pragma mark UIViewController

NSArray *getCells();

@implementation HPSettingsTableViewController


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    if (self)
    {
        _rtCells = getCells();
    }

    return self;
}

- (void)opened
{
    [self.tableView reloadData];
}

- (UITableView *)tableView
{
    if (!_tableView)
    {
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0,100,375,1000)];
        _tableView.dataSource = self;
        _tableView.delegate = self;
    }
    return _tableView;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(donePressed:)];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    [self.tableView sizeToFit];
    self.tableView.frame = CGRectMake(self.tableView.frame.origin.x, self.tableView.frame.origin.y, self.tableView.frame.size.width, self.tableView.frame.size.height);

    UIView *bg = [[UIView alloc] init];
    if (!UIAccessibilityIsReduceTransparencyEnabled()) 
    {
        bg.backgroundColor = [UIColor clearColor];

        UIBlurEffect *blurEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleDark];
        UIVisualEffectView *blurEffectView = [[UIVisualEffectView alloc] initWithEffect:blurEffect];
        blurEffectView.frame = self.view.bounds;
        blurEffectView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

        [bg addSubview:blurEffectView];
    } 
    else 
    {
        bg.backgroundColor = [UIColor blackColor];
    }

    self.tableView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:bg];
    [self.view sendSubviewToBack:bg];


    [[[self navigationController] navigationBar] setBarTintColor:[UIColor blackColor]];
    [[[self navigationController] navigationBar] setTranslucent:NO];

    NSDictionary *attributes = @{
                                 NSUnderlineStyleAttributeName: @0,
                                 NSForegroundColorAttributeName : [UIColor whiteColor],
                                 NSFontAttributeName: [UIFont fontWithName:@"HelveticaNeue-Bold" size:17]
                                 };

    [[[self navigationController] navigationBar] setTitleTextAttributes:attributes];


    [self.tableView registerClass:[HPTableCell class] forCellReuseIdentifier:@"Cell"];

    UIButton *doneButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [doneButton setTitle:@"Done" forState:UIControlStateNormal];
        [doneButton setFrame:CGRectMake([[self view] bounds].size.width - 90, 30, 80, 35)];
        [[doneButton titleLabel] setFont:[UIFont systemFontOfSize:15]];
        [doneButton addTarget:self action:@selector(doneButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
        [doneButton layer].cornerRadius = 5.0f;
        [doneButton layer].cornerCurve = kCACornerCurveContinuous;
        [doneButton setBackgroundColor:[UIColor colorWithWhite:1 alpha:0.04]];

    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(15, 30, self.view.bounds.size.width-90, 40)];
        [titleLabel setText:@"Settings"];
        [titleLabel setFont:[UIFont boldSystemFontOfSize:35]];

    [self.view addSubview:titleLabel];
    [self.view addSubview:doneButton];

    [self.view addSubview:self.tableView];
}

- (void)donePressed:(id)button
{

}

-(void)doneButtonPressed:(UIButton*)butt 
{
    [self dismissViewControllerAnimated:YES completion:^{
            [[[HPUIManager sharedInstance] editorViewController] handleDoneSettingsButtonPress:nil];
        }];
}

#pragma mark - Table View Data Source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [_rtCells count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [_rtCells[(NSUInteger) section][@"Items"] count];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section 
{
    return _rtCells[(NSUInteger) section][@"Title"];
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([cell respondsToSelector:@selector(tintColor)]) {
        if (tableView == self.tableView) {
            CGFloat cornerRadius = 15.f;
            cell.backgroundColor = [UIColor clearColor];
            CAShapeLayer *layer = [[CAShapeLayer alloc] init];
            CGMutablePathRef pathRef = CGPathCreateMutable();
            CGRect bounds = CGRectInset(cell.bounds, 0, 0);
            BOOL addLine = NO;
            if (indexPath.row == 0 && indexPath.row == [tableView numberOfRowsInSection:indexPath.section]-1) {
                CGPathAddRoundedRect(pathRef, nil, bounds, cornerRadius, cornerRadius);
            } else if (indexPath.row == 0) {
                CGPathMoveToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMaxY(bounds));
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMinY(bounds), CGRectGetMidX(bounds), CGRectGetMinY(bounds), cornerRadius);
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMinY(bounds), CGRectGetMaxX(bounds), CGRectGetMidY(bounds), cornerRadius);
                CGPathAddLineToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMaxY(bounds));
                addLine = YES;
            } else if (indexPath.row == [tableView numberOfRowsInSection:indexPath.section]-1) {
                CGPathMoveToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMinY(bounds));
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMaxY(bounds), CGRectGetMidX(bounds), CGRectGetMaxY(bounds), cornerRadius);
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMaxY(bounds), CGRectGetMaxX(bounds), CGRectGetMidY(bounds), cornerRadius);
                CGPathAddLineToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMinY(bounds));
            } else {
                CGPathAddRect(pathRef, nil, bounds);
                addLine = YES;
            }
            layer.path = pathRef;
            CFRelease(pathRef);
            layer.fillColor = [UIColor colorWithRed:10.0/255.0 green:10.0/255.0 blue:10.0/255.0 alpha:0.4].CGColor;

            if (addLine == YES) {
                CALayer *lineLayer = [[CALayer alloc] init];
                CGFloat lineHeight = (1.f / [UIScreen mainScreen].scale);
                lineLayer.frame = CGRectMake(CGRectGetMinX(bounds)+10, bounds.size.height-lineHeight, bounds.size.width-10, lineHeight);
                lineLayer.backgroundColor = tableView.separatorColor.CGColor;
                [layer addSublayer:lineLayer];
            }
            UIView *testView = [[UIView alloc] initWithFrame:bounds];
            [testView.layer insertSublayer:layer atIndex:0];
            testView.backgroundColor = UIColor.clearColor;
            cell.backgroundView = testView;
        }
    }
}


- (BOOL)storedStateForSwitchAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *key = @"";

    key = _rtCells[(NSUInteger) indexPath.section][@"Items"][(NSUInteger) indexPath.row][@"Key"];

    return [[[HPDataManager sharedInstance] currentConfiguration] objectForKey:key]
                ? [[[HPDataManager sharedInstance] currentConfiguration] boolForKey:key]
                : NO;
}

- (HPTableCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([_rtCells[(NSUInteger) indexPath.section][@"Items"][(NSUInteger) indexPath.row][@"Cell"] isEqualToString:@"Default"])
    {
        HPTableCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SettingsPaneCell"];

        if (!cell) 
        {
            cell = [[HPTableCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"SettingsPaneCell"];
            cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
            cell.textLabel.font = [UIFont systemFontOfSize:16.0];
        }
        
        cell.textLabel.text = _rtCells[(NSUInteger) indexPath.section][@"Items"][(NSUInteger) indexPath.row][@"Title"];

        [cell setBackgroundColor: [UIColor colorWithRed:10.0/255.0 green:10.0/255.0 blue:10.0/255.0 alpha:0.4]];

        [cell.layer setBorderColor:[UIColor blackColor].CGColor];
        [cell.layer setBorderWidth:0];

        cell.textLabel.textColor = [UIColor whiteColor];
        cell.detailTextLabel.textColor = [UIColor whiteColor];

        cell.clipsToBounds = YES;
        cell.hidden = NO;
        return cell;
    }

    HPTableCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SettingsPaneSwitchCell"];

    if( cell == nil )
    {
        cell = [[HPTableCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"SettingsPaneSwitchCell"];
        cell.textLabel.text = _rtCells[(NSUInteger)indexPath.section][@"Items"][(NSUInteger) indexPath.row][@"Title"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        UISwitch *switchView = [[UISwitch alloc] initWithFrame:CGRectZero];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        cell.accessoryView = switchView;
        [switchView setOn:[self storedStateForSwitchAtIndexPath:indexPath] animated:NO];
        [switchView addTarget:self action:@selector(settingSwitchChanged:) forControlEvents:UIControlEventValueChanged];

        [cell setBackgroundColor: [UIColor colorWithRed:10.0/255.0 green:10.0/255.0 blue:10.0/255.0 alpha:0.4]];

        [cell.layer setBorderColor:[UIColor blackColor].CGColor];
        [cell.layer setBorderWidth:0];

        cell.textLabel.textColor = [UIColor whiteColor];
        cell.detailTextLabel.textColor = [UIColor whiteColor];

        cell.clipsToBounds = YES;
    }
    return cell;
}


#pragma mark - Table View Data Source

- (void)settingSwitchChanged:(UISwitch *)sender
{
    NSString *key =  _rtCells[(NSUInteger) [self.tableView
            indexPathForCell:(UITableViewCell *) sender.superview]
            .section][@"Items"][(NSUInteger) [self.tableView
            indexPathForCell:(UITableViewCell *) sender.superview]
            .row][@"Key"];
    [[[HPDataManager sharedInstance] currentConfiguration] setBool:sender.on
                                                            forKey:key];

    [kIconModel layout];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"HPUpdateLayoutCache" object:nil];
    [[HPLayoutManager sharedInstance] layoutIconViews];
}


#pragma mark - Table View Delegate


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    switch (indexPath.section) 
    {
        case 0: 
        {
            switch (indexPath.row) 
            {
                case 0: 
                {
                    UIAlertController * alert = [UIAlertController
                                    alertControllerWithTitle:[HPUtility localizedItem:@"THIS_WILL_RESET"]
                                                    message:[HPUtility localizedItem:@"ARE_YOU_SURE_RESET"]
                                            preferredStyle:UIAlertControllerStyleAlert];
                    UIAlertAction* yesButton = [UIAlertAction
                                        actionWithTitle:@"Yes"
                                                style:UIAlertActionStyleDefault
                                                handler:^(UIAlertAction * action) {
                                                    [[[HPDataManager sharedInstance] currentConfiguration] setInteger:1 forKey:@"HPTutorialGiven"];
                                                    [[[HPDataManager sharedInstance] currentConfiguration] writeDefaults];
                                                    [kIconModel layout];
                                                    [[NSNotificationCenter defaultCenter] postNotificationName:@"HPUpdateLayoutCache" object:nil];
                                                    [[HPLayoutManager sharedInstance] layoutIconViews];
                                                    [[[HPUIManager sharedInstance] editorViewController] reload];
                                                }];

                    UIAlertAction* noButton = [UIAlertAction
                                            actionWithTitle:@"No"
                                                    style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action) {
                                                    //Handle no, thanks button                
                                                    }];

                    [alert addAction:yesButton];
                    [alert addAction:noButton];

                    [self presentViewController:alert animated:YES completion:nil];
                    break;
                }
                default:break;
            }
            break;
        }
        case 3:
        {
            switch (indexPath.row)
            {
                case 0:
                {
                    [[[HPDataManager sharedInstance] currentConfiguration] saveConfigurationToFile];
                    pid_t pid;
                    int status;
                    const char *args[] = {"sbreload", NULL, NULL, NULL};
                    posix_spawn(&pid, "usr/bin/sbreload", NULL, NULL, (char *const *) args, NULL);
                    waitpid(pid, &status, WEXITED);
                    break;
                }
                default:break;
            }
        }
        default:break;
    }
}

- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section
{
    // Background color
    view.tintColor = [UIColor clearColor];

    // Text Color
    UITableViewHeaderFooterView *header = (UITableViewHeaderFooterView *)view;
    header.layoutMargins = UIEdgeInsetsMake(0,0,0,15);
    [header.textLabel setTextColor:[UIColor whiteColor]];
    header.textLabel.font = [UIFont boldSystemFontOfSize:15];

}

@end

NSArray *getCells()
{
    return @[
            @{
                    @"Cell":@"Section",
                    @"Title":[HPUtility localizedItem:@"LOADOUT"],
                    @"Items":@[
                    @{
                            @"Cell":@"Default",
                            @"Title":[HPUtility localizedItem:@"RESET_VALUES"],
                            @"Key":@"RESETVALUES"
                    }]
            },
            @{
                    @"Cell":@"Section",
                    @"Title":@"HomeScreen",
                    @"Items":@[
                    @{
                            @"Cell":@"Switch",
                            @"Title":[HPUtility localizedItem:@"HIDE_ICON_LABELS"],
                            @"Key":@"HPDataIconLabels"
                    },
                    @{
                            @"Cell":@"Switch",
                            @"Title":[HPUtility localizedItem:@"HIDE_BADGES"],
                            @"Key":@"HPDataIconBadges"
                    },
                    @{
                            @"Cell":@"Switch",
                            @"Title":@"Hide Page Control",
                            @"Key":@"HPDataRootHidePageControl"
                    }]
            },
            @{
                    @"Cell":@"Section",
                    @"Title":@"Dock",
                    @"Items":@[
                    @{
                            @"Cell":@"Switch",
                            @"Title":[HPUtility localizedItem:@"HIDE_DOCK_BG"],
                            @"Key":@"HPDataDockBG"
                    }]
            },
            @{
                    @"Cell":@"Section",
                    @"Title":@"HomePlus",
                    @"Items":@[
                    @{
                            @"Cell":@"Default",
                            @"Title":[HPUtility localizedItem:@"Respring"],
                            @"Key":@"RESPRING"
                    }]
            }];
}