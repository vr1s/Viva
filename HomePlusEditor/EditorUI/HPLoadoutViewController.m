#import "HPLoadoutViewController.h"

#include "../Data/HPDataManager.h"
#include "HPUIManager.h"
#include "../Utility/HPUtility.h"

@interface HPLoadoutViewController () <UITableViewDelegate, UITableViewDataSource>

@property(nonatomic, strong) UITableView *table;

@end

@implementation HPLoadoutViewController

// TODO: huh?
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    if (self)
    {
        self.view = [[UIView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    }

    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    UIView *bg = [[UIView alloc] init];

    if (!UIAccessibilityIsReduceTransparencyEnabled())
    {
        bg.backgroundColor = [UIColor clearColor];

        UIBlurEffect *blurEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleSystemThickMaterialDark];
        UIVisualEffectView *blurEffectView = [[UIVisualEffectView alloc] initWithEffect:blurEffect];
        //always fill the view
        blurEffectView.frame = self.view.bounds;
        blurEffectView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

        [bg addSubview:blurEffectView]; //if you have more UIViews, use an insertSubview API to place it where needed
    }
    else
    {
        bg.backgroundColor = [UIColor blackColor];
    }

    [self.view addSubview:bg];

    self.view.backgroundColor = [UIColor clearColor];

    self.table = [[UITableView alloc] initWithFrame:CGRectInset(CGRectOffset(CGRectInset(self.view.bounds, 0, 60), 0, 30), 10, 0) style:UITableViewStylePlain];
    self.table.delegate = self;
    self.table.dataSource = self;
    self.table.backgroundColor = [UIColor clearColor];
    self.table.separatorStyle = UITableViewCellSeparatorStyleNone;

    [self.view addSubview:self.table];

    UIButton *new = [UIButton buttonWithType:UIButtonTypeCustom];
    [new setTitle:@"Create" forState:UIControlStateNormal];
    new.frame = CGRectMake(self.view.bounds.size.width - 90, 30, 80, 35);
    new.font = [UIFont systemFontOfSize:15];
    [new addTarget:self action:@selector(createNewButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    new.layer.cornerRadius = 5.0f;
    new.layer.cornerCurve = kCACornerCurveContinuous;
    new.backgroundColor = [UIColor colorWithWhite:1 alpha:0.04];

    UILabel *loadouts = [[UILabel alloc] initWithFrame:CGRectMake(15, 30, self.view.bounds.size.width-90, 40)];
    [loadouts setText:@"Loadouts"];
    loadouts.font = [UIFont boldSystemFontOfSize:35];
    [self.view addSubview:loadouts];
    [self.view addSubview:new];

} 


- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section
{
    // Make header views transparent
    view.tintColor = [UIColor clearColor];

    UITableViewHeaderFooterView *header = (UITableViewHeaderFooterView *) view;
    [header.textLabel setTextColor:[UIColor whiteColor]];
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Part of the code required to make a table view appear curved (by emulating table view colors using the cells)
    if ([cell respondsToSelector:@selector(tintColor)])
    {
        if (tableView == self.table)
        {
            CGFloat cornerRadius = 15.f;
            cell.backgroundColor = [UIColor clearColor];
            CAShapeLayer *layer = [[CAShapeLayer alloc] init];
            CGMutablePathRef pathRef = CGPathCreateMutable();
            CGRect bounds = CGRectInset(cell.bounds, 0, 0);
            BOOL addLine = NO;
            if (indexPath.row == 0 && indexPath.row == [tableView numberOfRowsInSection:indexPath.section] - 1)
            {
                CGPathAddRoundedRect(pathRef, nil, bounds, cornerRadius, cornerRadius);
            }
            else if (indexPath.row == 0)
            {
                CGPathMoveToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMaxY(bounds));
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMinY(bounds), CGRectGetMidX(bounds), CGRectGetMinY(bounds), cornerRadius);
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMinY(bounds), CGRectGetMaxX(bounds), CGRectGetMidY(bounds), cornerRadius);
                CGPathAddLineToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMaxY(bounds));
                addLine = YES;
            }
            else if (indexPath.row == [tableView numberOfRowsInSection:indexPath.section] - 1)
            {
                CGPathMoveToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMinY(bounds));
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMinX(bounds), CGRectGetMaxY(bounds), CGRectGetMidX(bounds), CGRectGetMaxY(bounds), cornerRadius);
                CGPathAddArcToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMaxY(bounds), CGRectGetMaxX(bounds), CGRectGetMidY(bounds), cornerRadius);
                CGPathAddLineToPoint(pathRef, nil, CGRectGetMaxX(bounds), CGRectGetMinY(bounds));
            }
            else
            {
                CGPathAddRect(pathRef, nil, bounds);
                addLine = YES;
            }

            layer.path = pathRef;
            CFRelease(pathRef);
            layer.fillColor = [UIColor colorWithRed:10.0 / 255.0 green:10.0 / 255.0 blue:10.0 / 255.0 alpha:0.4].CGColor;

            if (addLine == YES)
            {
                CALayer *lineLayer = [[CALayer alloc] init];
                CGFloat lineHeight = (1.f / [UIScreen mainScreen].scale);
                lineLayer.frame = CGRectMake(CGRectGetMinX(bounds) + 10, bounds.size.height - lineHeight, bounds.size.width - 10, lineHeight);
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

- (void)createNewButtonPressed:(UIButton *)button
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Enter Name"
                                                    message:@"  "
                                                   delegate:self
                                          cancelButtonTitle:@"Cancel"
                                          otherButtonTitles:@"OK", nil];
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;
    [alert show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 1)
    {
        NSString *name = [alertView textFieldAtIndex:0].text;
        [[[HPDataManager sharedInstance] currentConfiguration].values writeToFile:[NSString stringWithFormat:@"%@%@", @"/var/mobile/Documents/HomePlus/Loadouts/", [NSString stringWithFormat:@"%@%@", name, @".plist"]] atomically:YES];
        [[HPDataManager sharedInstance] loadListOfSavedConfigurations];

        [[HPDataManager sharedInstance] loadConfigurationWithName:name];
        [kIconModel layout];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"HPUpdateLayoutCache" object:nil];
        [[HPManager sharedInstance] layoutIconViews];
        [[[HPUIManager sharedInstance] editorViewController] reload];
        [self.table reloadData];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [[[HPDataManager sharedInstance] savedConfigurations] count];
}

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView
           editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return UITableViewCellEditingStyleDelete;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle
                                            forRowAtIndexPath:(NSIndexPath *)indexPath
{

    if (editingStyle == UITableViewCellEditingStyleDelete) {

        if (((HPConfiguration *) [[HPDataManager sharedInstance] savedConfigurations][(NSUInteger) indexPath.row]) == [[HPDataManager sharedInstance] currentConfiguration])
        {
            [[HPDataManager sharedInstance] loadConfigurationWithName:@"Default"];
            [kIconModel layout];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"HPUpdateLayoutCache" object:nil];
            [[HPManager sharedInstance] layoutIconViews];
            [[[HPUIManager sharedInstance] editorViewController] reload];
        }
        [((HPConfiguration *) [[HPDataManager sharedInstance] savedConfigurations][(NSUInteger) indexPath.row]) delete];
        [[HPDataManager sharedInstance] loadListOfSavedConfigurations];

        [tableView deleteRowsAtIndexPaths:@[indexPath]
                         withRowAnimation:UITableViewRowAnimationLeft];


    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];

    for (UITableViewCell *acell in tableView.visibleCells)
        acell.accessoryType = 0;

    cell.accessoryType = UITableViewCellAccessoryCheckmark;
    [tableView deselectRowAtIndexPath:indexPath animated:NO];

    [[[HPDataManager sharedInstance] currentConfiguration] saveConfigurationToFile];

    [[HPDataManager sharedInstance] loadConfigurationWithName:((HPConfiguration *) [[HPDataManager sharedInstance] savedConfigurations][(NSUInteger) indexPath.row]).readableName];

    [kIconModel layout];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"HPUpdateLayoutCache" object:nil];
    [[HPManager sharedInstance] layoutIconViews];
    [[[HPUIManager sharedInstance] editorViewController] reload];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithFrame:CGRectZero reuseIdentifier:CellIdentifier];
        cell.textLabel.font = [UIFont systemFontOfSize:16.0];
        cell.textLabel.text = (((HPConfiguration *) [[HPDataManager sharedInstance] savedConfigurations][(NSUInteger) indexPath.row]).readableName);
        if ((((HPConfiguration *) [[HPDataManager sharedInstance] savedConfigurations][(NSUInteger) indexPath.row]).readableName) == [[[HPDataManager sharedInstance] currentConfiguration] readableName]) {
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        } else {
            cell.accessoryType = 0;
        }
    }
    return cell;
}


@end
