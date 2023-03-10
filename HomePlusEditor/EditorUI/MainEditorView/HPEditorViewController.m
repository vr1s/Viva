//
// HPEditorViewController.m
// HomePlus
// 
// View controller for the Editor and Home base for anything UI.
// 
// Created Oct 2019 
// Authors: Kritanta
//
// TODO: rewrite or at least heavily optimize this file
// 
#include "HomePlus.h"
#include "HomePlusEditor.h"
#import "HPLayoutManager.h"
#include <AudioToolbox/AudioToolbox.h>

#define kButtonSpacing 10

@interface HPEditorViewController ()

@property (nonatomic, readwrite, strong) HPControllerView *offsetControlView;
@property (nonatomic, readwrite, strong) HPControllerView *spacingControlView;
@property (nonatomic, readwrite, strong) HPControllerView *iconCountControlView;
@property (nonatomic, readwrite, strong) HPControllerView *scaleControlView;
@property (nonatomic, readwrite, strong) HPControllerView *settingsView;

@property (nonatomic, readwrite, strong) HPEditorViewNavigationTabBar *tabBar;

@property (nonatomic, readwrite, strong) HPSettingsTableViewController *tableViewController;

@property (nonatomic, retain) HPControllerView *activeView;
@property (nonatomic, retain) UIButton *activeButton;

@property (nonatomic, retain) UIButton *rootButton;
@property (nonatomic, retain) UIButton *dockButton;

@property (nonatomic, retain) UIButton *settingsDoneButton;

@end

#pragma mark Constants

const CGFloat MENU_BUTTON_TOP_ANCHOR = 0.05541872;
const CGFloat MENU_BUTTON_SIZE = 40.0;

const CGFloat TABLE_HEADER_HEIGHT = 0.458;


@implementation HPEditorViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.homeTabControllerViews = [@[[self offsetControlView], [self spacingControlView],
            [self iconCountControlView], [self scaleControlView],
            [self settingsView]] mutableCopy];


    // Add subviews to self. Any time viewDidLoad is called manually, unload these view beforehand
    if (self.activeExtension == nil)
    {
        [self.view addSubview:[self offsetControlView]];
        [self.view addSubview:[self spacingControlView]];
        [self.view addSubview:[self iconCountControlView]];

        [self.view addSubview:[self scaleControlView]];
        [self.view addSubview:[self settingsView]];

        // Load the view
        [self loadControllerView:[self offsetControlView]];


        self.tabBar = [self defaultTabBar];

        [self handleDefaultBarTabButtonPress:[self.tabBar subviews][0]];
    }
    else
    {
        self.tabBar = [self customExtensionTabBar];
        @try
        {
            [self handleExtensionTabBarButtonPress:[self.tabBar subviews][0]];
        }
        @catch (NSException *ex)
        {
            self.activeExtension = nil;
            [self reload];
            return;
        }
    }

    self.extensionBar = [self anExtensionBar];

    // Set the alpha of the rest to 0

    [self.view addSubview:self.tabBar];
    [self.view addSubview:self.extensionBar];

    [self.view addGestureRecognizer:[[HPGestureManager sharedInstance] inactiveGestureRecognizer]];
}

- (HPEditorViewNavigationTabBar *)anExtensionBar
{
    HPEditorViewNavigationTabBar *extensionBar = [[HPEditorViewNavigationTabBar alloc] initWithFrame:CGRectMake(
            7.5,
            MENU_BUTTON_TOP_ANCHOR * [[UIScreen mainScreen] bounds].size.height + kDeviceCornerRadius / 2,
            MENU_BUTTON_SIZE, ([UIScreen mainScreen].bounds.size.height) * (0.7))];

    UIButton *homeButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *homeImage = [HPResources extensionHomeToggled:NO];
    UIImage *homeImageToggled = [HPResources extensionHomeToggled:YES];
    [homeButton setImage:homeImage forState:UIControlStateNormal];
    [homeButton setImage:homeImageToggled forState:UIControlStateHighlighted];
    homeButton.frame = CGRectMake(0, 0, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);

    [extensionBar addSubview:homeButton toTabBarIndex:0];

    NSUInteger index = 1;

    for (HPExtension *extension in [[HPExtensionManager sharedInstance] extensions])
    {
        UIButton *extensionButton = [UIButton buttonWithType:UIButtonTypeCustom];
        UIImage *extensionImage = extension.extensionIcon;
        [extensionButton setImage:extensionImage forState:UIControlStateNormal];
        extensionButton.frame = CGRectMake(0, MENU_BUTTON_SIZE * index, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
        [extensionBar addSubview:extensionButton toTabBarIndex:index];
        index++;
    }

    for (UIButton *button in [extensionBar subviews])
    {
        [button addTarget:self
                   action:@selector(handleExtensionBarButtonPress:)
         forControlEvents:UIControlEventTouchUpInside];
        [button addTarget:self
                   action:@selector(buttonPressDown:)
         forControlEvents:UIControlEventTouchDown];
    }

    UIButton *loadoutButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *loadoutImage = [HPResources loadoutsToggled:NO];
    UIImage *loadoutImageToggled = [HPResources loadoutsToggled:YES];
    [loadoutButton setImage:loadoutImage forState:UIControlStateNormal];
    [loadoutButton setImage:loadoutImageToggled forState:UIControlStateHighlighted];
    loadoutButton.frame = CGRectMake(0, MENU_BUTTON_SIZE * 2, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);

    [loadoutButton addTarget:self action:@selector(loadLoadouts:) forControlEvents:UIControlEventTouchUpInside];

    [extensionBar addSubview:loadoutButton toBackwardsTabBarIndex:0];

    return extensionBar;
}

- (void)loadLoadouts:(UIButton *)button
{
    HPLoadoutViewController *vc = [[HPLoadoutViewController alloc] initWithNibName:nil bundle:nil];
    //vc.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
    [vc viewDidLoad];
    [self presentViewController:vc animated:YES completion:NULL];
}

- (void)buttonPressDown:(id)arg
{
    AudioServicesPlaySystemSound(1519);
}

- (void)unloadExtensionPanes
{
    if (self.activeExtension != nil)
    {
        [self loadExtension:nil];
    }
}

- (HPEditorViewNavigationTabBar *)customExtensionTabBar
{
    HPEditorViewNavigationTabBar *extensionTabBar = [[HPEditorViewNavigationTabBar alloc] initWithFrame:CGRectMake(
            [[UIScreen mainScreen] bounds].size.width - 47.5,
            MENU_BUTTON_TOP_ANCHOR * [[UIScreen mainScreen] bounds].size.height + kDeviceCornerRadius / 2,
            MENU_BUTTON_SIZE, ([UIScreen mainScreen].bounds.size.height) * (0.7))];

    NSUInteger index = 0;

    for (HPExtensionControllerView *pane in self.activeExtension.extensionControllerViews)
    {
        UIButton *paneButton = [UIButton buttonWithType:UIButtonTypeCustom];
        UIImage *paneImage = pane.paneIcon;
        [paneButton setImage:paneImage forState:UIControlStateNormal];
        paneButton.frame = CGRectMake(0, MENU_BUTTON_SIZE * index, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
        [extensionTabBar addSubview:paneButton];
        index++;
    }

    for (UIButton *button in [extensionTabBar subviews])
    {
        [button addTarget:self
                   action:@selector(handleExtensionTabBarButtonPress:)
         forControlEvents:UIControlEventTouchUpInside];
        [button addTarget:self
                   action:@selector(buttonPressDown:)
         forControlEvents:UIControlEventTouchDown];
    }

    return extensionTabBar;

}

- (HPEditorViewNavigationTabBar *)defaultTabBar
{
    HPEditorViewNavigationTabBar *tabBar = [[HPEditorViewNavigationTabBar alloc] initWithFrame:CGRectMake(
            [[UIScreen mainScreen] bounds].size.width - 47.5,
            MENU_BUTTON_TOP_ANCHOR * [[UIScreen mainScreen] bounds].size.height + kDeviceCornerRadius / 2,
            MENU_BUTTON_SIZE, ([UIScreen mainScreen].bounds.size.height) * (0.7))];

    UIButton *offsetButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *offsetImage = [HPResources offsetImageToggled:NO];
    UIImage *offsetImageToggled = [HPResources offsetImageToggled:YES];
    [offsetButton setImage:offsetImage forState:UIControlStateNormal];
    [offsetButton setImage:offsetImageToggled forState:UIControlStateHighlighted];
    offsetButton.frame = CGRectMake(0, 0 + (kButtonSpacing + MENU_BUTTON_SIZE) * 0, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
    offsetButton.highlighted = YES;

    [tabBar addSubview:offsetButton toBackwardsTabBarIndex:6];
    // Since the offset view will be the first loaded, we dont need to lower alpha
    //      on the button. 

    UIButton *spacerButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *spacerImage = [HPResources spacerImageToggled:NO];
    UIImage *spacerImageToggled = [HPResources spacerImageToggled:YES];
    [spacerButton setImage:spacerImage forState:UIControlStateNormal];
    [spacerButton setImage:spacerImageToggled forState:UIControlStateHighlighted];

    spacerButton.frame = CGRectMake(0, 0 + (kButtonSpacing + MENU_BUTTON_SIZE), MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);

    spacerButton.highlighted = NO;

    [tabBar addSubview:spacerButton toBackwardsTabBarIndex:5];

    UIButton *iconCountButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *iCImage = [HPResources iconCountImageToggled:NO];
    UIImage *iCImageToggled = [HPResources iconCountImageToggled:YES];
    [iconCountButton setImage:iCImage forState:UIControlStateNormal];
    [iconCountButton setImage:iCImageToggled forState:UIControlStateHighlighted];
    iconCountButton.frame = CGRectMake(0, 0 + (kButtonSpacing + MENU_BUTTON_SIZE) * 2, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
    iconCountButton.highlighted = NO;

    [tabBar addSubview:iconCountButton toBackwardsTabBarIndex:4];

    UIButton *scaleButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *sImage = [HPResources scaleImageToggled:NO];
    UIImage *sImageToggled = [HPResources scaleImageToggled:YES];
    [scaleButton setImage:sImage forState:UIControlStateNormal];
    [scaleButton setImage:sImageToggled forState:UIControlStateHighlighted];
    scaleButton.frame = CGRectMake(0, 0 + (kButtonSpacing + MENU_BUTTON_SIZE) * 3, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
    scaleButton.highlighted = NO;

    [tabBar addSubview:scaleButton toBackwardsTabBarIndex:3];

    UIButton *settingsButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *settingsImage = [HPResources settingsImageToggled:NO];
    UIImage *settingsImageToggled = [HPResources settingsImageToggled:YES];
    [settingsButton setImage:settingsImage forState:UIControlStateNormal];
    [settingsButton setImage:settingsImageToggled forState:UIControlStateHighlighted];
    settingsButton.frame = CGRectMake(0, 0 + (kButtonSpacing + MENU_BUTTON_SIZE) * (4), MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
    settingsButton.highlighted = NO;

    [tabBar addSubview:settingsButton toTabBarIndex:0];


    for (UIButton *button in [tabBar subviews])
    {
        [button addTarget:self
                   action:@selector(handleDefaultBarTabButtonPress:)
         forControlEvents:UIControlEventTouchUpInside];
        [button addTarget:self
                   action:@selector(buttonPressDown:)
         forControlEvents:UIControlEventTouchDown];
    }

    if (![[[HPUIManager sharedInstance] editingLocation] isEqualToString:@"SBIconLocationFolder"])
    {

        self.rootButton = [UIButton buttonWithType:UIButtonTypeCustom];
        UIImage *rootImage = [HPResources rootImageToggled:NO];
        UIImage *rootImageToggled = [HPResources rootImageToggled:YES];
        [self.rootButton setImage:rootImage forState:UIControlStateNormal];
        [self.rootButton setImage:rootImageToggled forState:UIControlStateHighlighted];
        self.rootButton.frame = CGRectMake(0, 30 + (kButtonSpacing + MENU_BUTTON_SIZE) * 5, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
        self.rootButton.highlighted = YES;
        [self.rootButton addTarget:self action:@selector(handleRootButtonPress:) forControlEvents:UIControlEventTouchUpInside];
        [tabBar addSubview:self.rootButton toBackwardsTabBarIndex:1];

        self.dockButton = [UIButton buttonWithType:UIButtonTypeCustom];
        UIImage *dockImage = [HPResources dockImageToggled:NO];
        UIImage *dockImageToggled = [HPResources dockImageToggled:YES];
        [self.dockButton setImage:dockImage forState:UIControlStateNormal];
        [self.dockButton setImage:dockImageToggled forState:UIControlStateHighlighted];
        self.dockButton.frame = CGRectMake(0, 30 + (kButtonSpacing + MENU_BUTTON_SIZE) * 6, MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
        self.dockButton.highlighted = NO;
        [self.dockButton addTarget:self action:@selector(handleDockButtonPress:) forControlEvents:UIControlEventTouchUpInside];

        [tabBar addSubview:self.dockButton toBackwardsTabBarIndex:0];
    }
    else
    {
        iconCountButton.enabled = NO;
    }

    self.activeButton = offsetButton;

    return tabBar;
}

- (void)handleExtensionBarButtonPress:(UIButton *)button
{
    NSUInteger index = [self.extensionBar.subviews indexOfObject:button];

    if (index <= 0 || [[[HPExtensionManager sharedInstance] extensions] count] == 0)
    {
        [self loadExtension:nil];
    }
    else
    {
        [self loadExtension:[[HPExtensionManager sharedInstance] extensions][index - 1]];
    }
}

- (void)loadExtension:(HPExtension *)extension
{
    self.activeExtension = extension;
    [self reload];
    [self transitionViewsToActivationPercentage:1];
    int _ = 1;
    for (HPExtensionControllerView *controller in extension.extensionControllerViews)
    {
        controller.alpha = 0;
        if (_ == 1)
        {
            controller.alpha = 1.0;
            _ = 0;
        } // set the first controller to have a 1 alpha
        [self.view addSubview:controller];
    }

    [self.view bringSubviewToFront:self.tabBar];
    [self.view bringSubviewToFront:self.extensionBar];
}

- (void)handleExtensionTabBarButtonPress:(UIButton *)button
{
    NSUInteger index = [self.tabBar.subviews indexOfObject:button];

    [self loadControllerView:self.activeExtension.extensionControllerViews[index]];

    self.activeButton.userInteractionEnabled = YES;

    [UIView animateWithDuration:.2
                     animations:
                             ^
                             {
                                 button.alpha = 1;
                             }
    ];

    self.activeButton = button;
    button.userInteractionEnabled = NO;
}

- (void)handleDefaultBarTabButtonPress:(UIButton *)button
{
    AudioServicesPlaySystemSound(1519);
    NSUInteger index = [self.tabBar.subviews indexOfObject:button];

    if (index < 4)
    {
        [self loadControllerView:self.homeTabControllerViews[index]];
        self.activeButton.userInteractionEnabled = YES;

        [UIView animateWithDuration:.2
                         animations:
                                 ^
                                 {
                                     self.activeButton.highlighted = NO;
                                     button.highlighted = YES;
                                 }
        ];

        self.activeButton = button;
        button.userInteractionEnabled = NO;
    }
    else if (index == 4)
    {
        [self handleSettingsButtonPress:button];
    }
    else if (index == 5)
    {
        [self handleRootButtonPress:button];
    }
    else
    {
        [self handleDockButtonPress:button];
    }

    [self performSelector:@selector(doHighlight:) withObject:button afterDelay:0];
}

- (void)doHighlight:(UIButton *)b
{
    [b setHighlighted:YES];
}

- (void)transitionViewsToActivationPercentage:(CGFloat)amount
{
    CGFloat fullAmt = (([[UIScreen mainScreen] bounds].size.height) * 0.15);
    //CGFloat topTranslation = 0-fullAmt + (amount * fullAmt);
    CGFloat bottomTranslation = fullAmt - (amount * fullAmt);
    bottomTranslation *= 2;
    self.activeView.topView.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, 0, bottomTranslation);
    self.activeView.bottomView.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, 0, bottomTranslation);
    self.tabBar.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, (50 - (50 * amount)), 0);
    self.extensionBar.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, (-50 + (50 * amount)), 0);
}

- (void)transitionViewsToActivationPercentage:(CGFloat)amount withDuration:(CGFloat)duration
{
    [UIView animateWithDuration:duration
                     animations:
                             ^
                             {
                                 CGFloat fullAmt = (([[UIScreen mainScreen] bounds].size.height) * 0.15);
                                 //CGFloat topTranslation = 0-fullAmt + (amount * fullAmt);
                                 CGFloat bottomTranslation = fullAmt - (amount * fullAmt);
                                 bottomTranslation *= 2;
                                 self.activeView.topView.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, 0, bottomTranslation);
                                 self.activeView.bottomView.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, 0, bottomTranslation);
                                 self.tabBar.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, (50 - (50 * amount)), 0);
                                 self.extensionBar.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, (-50 + (50 * amount)), 0);
                             }
    ];
}

- (void)reload
{
    [[self.view subviews]
            makeObjectsPerformSelector:@selector(removeFromSuperview)];
    _spacingControlView = nil;
    _offsetControlView = nil;
    _settingsView = nil;
    _iconCountControlView = nil;
    _scaleControlView = nil;

    [self viewDidLoad];
}

#pragma mark Editing Location

- (void)handleDockButtonPress:(UIButton *)sender
{
    if ([[[HPUIManager sharedInstance] editingLocation] isEqualToString:@"SBIconLocationDock"])
    {
        return;
    }
    AudioServicesPlaySystemSound(1519);
    [[HPUIManager sharedInstance] setEditingLocation:@"SBIconLocationDock"];

    [[self.view subviews]
            makeObjectsPerformSelector:@selector(removeFromSuperview)];
    _spacingControlView = nil;
    _offsetControlView = nil;
    _settingsView = nil;
    _iconCountControlView = nil;
    _scaleControlView = nil;

    // Reload views
    [self viewDidLoad];

    self.rootButton.highlighted = NO;
    self.dockButton.highlighted = YES;

}

- (void)handleRootButtonPress:(UIButton *)sender
{
    if ([[[HPUIManager sharedInstance] editingLocation] isEqualToString:@"SBIconLocationRoot"])
    {
        return;
    }
    //AudioServicesPlaySystemSound(1519);
    [[HPUIManager sharedInstance] setEditingLocation:@"SBIconLocationRoot"];
    [[self.view subviews]
            makeObjectsPerformSelector:@selector(removeFromSuperview)];
    _spacingControlView = nil;
    _offsetControlView = nil;
    _settingsView = nil;
    _iconCountControlView = nil;
    _scaleControlView = nil;

    // Reload views
    [self viewDidLoad];

    self.rootButton.highlighted = YES;
    self.dockButton.highlighted = NO;

}

#pragma mark Settings View

- (HPControllerView *)settingsView
{
    // settings table controller hacked into the usual hpcontrollerview model we use. 
    // top view is the entire controller, bottom view is the header. 
    if (!_settingsView)
    {
        _settingsView = [[HPControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        UIView *settingsContainerView = self.tableViewController.view;
        _settingsView.topView = [[UIView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        [_settingsView.topView addSubview:settingsContainerView];
        [_settingsView addSubview:_settingsView.topView];

        UIView *tableHeaderView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [[UIScreen mainScreen] bounds].size.width, (([[UIScreen mainScreen] bounds].size.width) / 750) * 300)];
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, [[UIScreen mainScreen] bounds].size.width, (([[UIScreen mainScreen] bounds].size.width) / 750) * 300)];

        imageView.image = [HPUIManager sharedInstance].dynamicallyGeneratedSettingsHeaderImage;
        imageView.contentMode = UIViewContentModeScaleAspectFill;
        imageView.clipsToBounds = YES;
        [tableHeaderView addSubview:imageView];

        UIView *doneButtonContainerView = [[UIView alloc] initWithFrame:CGRectMake([[UIScreen mainScreen] bounds].size.width - 80, ((([[UIScreen mainScreen] bounds].size.width) / 750) * 300) - 40, [[UIScreen mainScreen] bounds].size.width / 2, 40)];

        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        [button addTarget:self
                   action:@selector(handleDoneSettingsButtonPress:)
         forControlEvents:UIControlEventTouchUpInside];
        [button setTitle:@"Done" forState:UIControlStateNormal];
        button.frame = CGRectMake(0, 0, 80, 40);
        [doneButtonContainerView addSubview:button];
        _settingsView.bottomView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [[UIScreen mainScreen] bounds].size.width, (TABLE_HEADER_HEIGHT * [[UIScreen mainScreen] bounds].size.width))];
        [_settingsView.bottomView addSubview:doneButtonContainerView];

        [_settingsView.topView addSubview:tableHeaderView];
        [_settingsView addSubview:_settingsView.bottomView];
    }
    _settingsView.hidden = NO;
    _settingsView.alpha = 0;
    return _settingsView;
}


#pragma mark - Controller Views

- (HPControllerView *)offsetControlView
{
    if (!_offsetControlView)
    {
        HPControllerViewConfiguration config = {
                .topControl = {
                        .itemType = {
                                kHPControllerItemTypeSlider
                        },
                        .itemInfo = {
                                .label = @"TOP_OFFSET",
                                .configKey = @"TopInset",
                                .min = -100,
                                .max = (NSInteger) [[UIScreen mainScreen] bounds].size.height,
                                .defaultValue = 0
                        }
                },
                .bottomControl = {
                        .itemType = {
                                kHPControllerItemTypeSlider
                        },
                        .itemInfo = {
                                .label = @"LEFT_OFFSET",
                                .configKey = @"LeftInset",
                                .min = -400,
                                .max = 400,
                                .defaultValue = 0
                        }
                }
        };
        _offsetControlView = [[HPControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds] config:config];
        _offsetControlView.alpha = 0;
    }
    return _offsetControlView;
}

- (HPControllerView *)spacingControlView
{
    if (!_spacingControlView)
    {
        HPControllerViewConfiguration config = {
                .topControl = {
                        .itemType = {
                                kHPControllerItemTypeSlider
                        },
                        .itemInfo = {
                                .label = @"VERTICAL_SPACING",
                                .configKey = @"VerticalSpacing",
                                .min = -400,
                                .max = 400,
                                .defaultValue = 0
                        }
                },
                .bottomControl = {
                        .itemType = {
                                kHPControllerItemTypeSlider
                        },
                        .itemInfo = {
                                .label = @"HORIZONTAL_SPACING",
                                .configKey = @"HorizontalSpacing",
                                .min = -200,
                                .max = 400,
                                .defaultValue = 0
                        }
                }
        };
        _spacingControlView = [[HPControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds] config:config];
        _spacingControlView.alpha = 0;
    }
    return _spacingControlView;
}

- (HPControllerView *)iconCountControlView
{
    if (!_iconCountControlView)
    {
        HPControllerViewConfiguration config = {
                .topControl = {
                        .itemType = {
                                kHPControllerItemTypeCounter
                        },
                        .itemInfo = {
                                .label = @"ROWS",
                                .configKey = @"Rows",
                                .min = 1,
                                .max = 14,
                                .defaultValue = 6
                        }
                },
                .bottomControl = {
                        .itemType = {
                                kHPControllerItemTypeCounter
                        },
                        .itemInfo = {
                                .label = @"COLUMNS",
                                .configKey = @"Columns",
                                .min = 1,
                                .max = 14,
                                .defaultValue = 4
                        }
                }
        };
        _iconCountControlView = [[HPControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds] config:config];
        _iconCountControlView.alpha = 0;
    }
    return _iconCountControlView;
}

- (HPControllerView *)scaleControlView
{
    if (!_scaleControlView)
    {
        HPControllerViewConfiguration config = {
                .topControl = {
                        .itemType = {
                                kHPControllerItemTypeSlider
                        },
                        .itemInfo = {
                                .label = @"ICON_SCALE",
                                .configKey = @"Scale",
                                .min = 1,
                                .max = 200,
                                .defaultValue = 100
                        }
                },
                .bottomControl = {
                        .itemType = {
                                kHPControllerItemTypeNone
                        },
                        .itemInfo = {
                                .label = @"ICON_CORNER",
                                .configKey = @"IconCorner",
                                .min = -400,
                                .max = 400,
                                .defaultValue = 0
                        }
                }
        };
        _scaleControlView = [[HPControllerView alloc] initWithFrame:[[UIScreen mainScreen] bounds] config:config];
        _scaleControlView.alpha = 0;
    }
    return _scaleControlView;
}

- (void)resetAllValuesToDefaults
{

}

#pragma mark Button Handlers

- (void)handleSettingsButtonPress:(UIButton *)sender
{
    HPSettingsTableViewController *vc = [[HPSettingsTableViewController alloc] initWithNibName:nil bundle:nil];
    [vc viewDidLoad];
    [self presentViewController:vc animated:YES completion:NULL];

    [[NSNotificationCenter defaultCenter] postNotificationName:kFadeFloatingDockNotificationName object:nil];

    [vc opened];

    self.activeButton = sender;
}

- (void)handleDoneSettingsButtonPress:(UIButton *)sender
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kShowFloatingDockNotificationName object:nil];
    [[HPLayoutManager sharedInstance] layoutIconViews];
    [[HPLayoutManager sharedInstance] layoutIndividualIcons];
}

- (void)resignAllTextFields
{
    [self.view endEditing:YES];
}

- (void)loadControllerView:(HPControllerView *)arg1
{
    [self resignAllTextFields];

    [UIView animateWithDuration:.2
                     animations:
                             ^
                             {
                                 self.activeView.alpha = 0;
                                 arg1.alpha = 1;
                             }
    ];


    self.activeView = arg1;
    [self transitionViewsToActivationPercentage:1];
}

#pragma mark Springboard Layout Updates

- (void)layoutAllSpringboardIcons
{
    
}

- (void)viewWillTransitionToSize:(CGSize)size
       withTransitionCoordinator:(id <UIViewControllerTransitionCoordinator>)coordinator
{
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
    [self reload];
}

#pragma mark UIViewController overrides

- (BOOL)shouldAutorotate
{
    return [HPUtility deviceRotatable];
}


@end
