//
// HPControllerView.m
// HomePlus
// 
// Base to build controller views on. 
// Subclasses of this go in ./ControllerViews
//
// Baseline for everything is sliders. 
// Even if the sliders are hidden, use their handling methods as stubs
//      to update the values. 
// 
// Author: Kritanta
// Created: Oct 2019
//
// TODO: rewrite
//

#include "../../HomePlus.h"
#include "../Utility/HPResources.h"
#include "HPUIManager.h"
#include "HPControllerView.h"
#import "HPLayoutManager.h"
#import "HPUtility.h"
#import "HPPageConfiguration.h"
#import "HPConfigurationManager.h"
#include <AudioToolbox/AudioToolbox.h>


@implementation HPControllerView
{
@private
    HPControllerViewConfiguration _config;
}

@synthesize config = _config;

- (instancetype)initWithFrame:(CGRect)frame config:(HPControllerViewConfiguration)config
{
    self = [super initWithFrame:frame];

    if (self)
    {
        self.config = config;
        [self layoutControllerView];
        [self updateLayoutForConfiguration:config];
    }
    return self;
}

#pragma mark Layout

- (void)layoutControllerView
{
    UIView *backer = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [[UIScreen mainScreen] bounds].size.width, 800)];
    backer.layer.cornerRadius = kDeviceCornerRadius;
    backer.layer.cornerCurve = kCACornerCurveContinuous;
    backer.layer.masksToBounds = YES;
    backer.backgroundColor = [UIColor colorWithWhite:1 alpha:0.02];

    // Top View
    self.topView = [
            [UIView alloc] initWithFrame:CGRectMake(0,
                    kTopContainerTopAnchor * [[UIScreen mainScreen] bounds].size.height,
                    [[UIScreen mainScreen] bounds].size.width,
                    kContainerHeight * [[UIScreen mainScreen] bounds].size.height)];

    // Top Label
    self.topLabel = [[UILabel alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, 0, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height)];
    [self.topLabel setText:@"Top Control"];
    self.topLabel.textColor = [UIColor whiteColor];
    self.topLabel.textAlignment = NSTextAlignmentCenter;

    // Top Text Field. 
    self.topTextField = [[UITextField alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + (0.730) * [[UIScreen mainScreen] bounds].size.width, (0.048) * [[UIScreen mainScreen] bounds].size.height, (0.1333) * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height)];

    [self.topTextField addTarget:self
                          action:@selector(topTextFieldUpdated:)
                forControlEvents:UIControlEventEditingChanged];
    [self.topTextField addTarget:self
                          action:@selector(topTextFieldBeganEditing:)
                forControlEvents:UIControlEventEditingDidBegin];
    self.topTextField.keyboardType = UIKeyboardTypeNumberPad;
    self.topTextField.textColor = [UIColor whiteColor];

    [self.topView addSubview:backer];

    // Top Input Keyboard
    UIToolbar *keyboardToolbar = [[UIToolbar alloc] init];

    [keyboardToolbar sizeToFit];

    UIButton *tminusButton = [[UIButton alloc] initWithFrame:CGRectMake(15, 5, 40, 30)];
    [tminusButton setTitle:@"+/-" forState:UIControlStateNormal];
    [tminusButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [tminusButton addTarget:self action:@selector(invertTopTextField) forControlEvents:UIControlEventTouchUpInside];


    UIBarButtonItem *flexBarButton = [[UIBarButtonItem alloc]
            initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                                 target:nil action:nil];
    UIBarButtonItem *doneBarButton = [[UIBarButtonItem alloc]
            initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                 target:self action:@selector(topTextFieldEndedEditing:)];
    keyboardToolbar.items = @[flexBarButton, doneBarButton];
    self.topTextField.inputAccessoryView = keyboardToolbar;
    [self.topTextField.inputAccessoryView addSubview:tminusButton];

    // Top Slider
    self.topControl = [[OBSlider alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height, (0.7) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height)];
    [self.topControl addTarget:self action:@selector(topSliderUpdated:) forControlEvents:UIControlEventValueChanged];
    [self.topControl setBackgroundColor:[UIColor clearColor]];
    self.topControl.maximumTrackTintColor = [UIColor colorWithWhite:1.0 alpha:0.2];
    self.topControl.minimumTrackTintColor = [UIColor colorWithWhite:1.0 alpha:0.9];
    self.topControl.continuous = YES;

    // Bottom View
    self.bottomView = [[UIView alloc] initWithFrame:CGRectMake(0, (0.862) * [[UIScreen mainScreen] bounds].size.height, (1) * [[UIScreen mainScreen] bounds].size.width, (0.123) * [[UIScreen mainScreen] bounds].size.height)];

    // Bottom Label
    self.bottomLabel = [[UILabel alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, 0, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50)];
    [self.bottomLabel setText:@"Bottom Control"];
    self.bottomLabel.textColor = [UIColor whiteColor];
    self.bottomLabel.textAlignment = NSTextAlignmentCenter;

    // Bottom Text Field
    self.bottomTextField = [[UITextField alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + (0.730) * [[UIScreen mainScreen] bounds].size.width, (0.048) * [[UIScreen mainScreen] bounds].size.height, 50, 30)];
    [self.bottomTextField addTarget:self
                             action:@selector(bottomTextFieldUpdated:)
                   forControlEvents:UIControlEventEditingChanged];

    [self.bottomTextField addTarget:self
                             action:@selector(bottomTextFieldBeganEditing:)
                   forControlEvents:UIControlEventEditingDidBegin];

    // Bottom Text Field Bar
    self.bottomTextField.keyboardType = UIKeyboardTypeNumberPad;
    self.bottomTextField.textColor = [UIColor whiteColor];

    UIToolbar *bkeyboardToolbar = [[UIToolbar alloc] init];

    [bkeyboardToolbar sizeToFit];

    UIButton *minusButton = [[UIButton alloc] initWithFrame:CGRectMake(15, 5, 40, 30)];
    [minusButton setTitle:@"+/-" forState:UIControlStateNormal];
    [minusButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [minusButton addTarget:self action:@selector(invertBottomTextField) forControlEvents:UIControlEventTouchUpInside];

    UIBarButtonItem *bflexBarButton = [[UIBarButtonItem alloc]
            initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                                 target:nil action:nil];
    UIBarButtonItem *bdoneBarButton = [[UIBarButtonItem alloc]
            initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                 target:self action:@selector(bottomTextFieldEndedEditing:)];
    bkeyboardToolbar.items = @[bflexBarButton, bdoneBarButton];
    self.bottomTextField.inputAccessoryView = bkeyboardToolbar;

    [self.bottomTextField.inputAccessoryView addSubview:minusButton];


    self.bottomControl = [[OBSlider alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height, (0.700) * [[UIScreen mainScreen] bounds].size.width, 50)];
    [self.bottomControl addTarget:self action:@selector(bottomSliderUpdated:) forControlEvents:UIControlEventValueChanged];
    [self.bottomControl setBackgroundColor:[UIColor clearColor]];
    self.bottomControl.maximumTrackTintColor = [UIColor colorWithWhite:1.0 alpha:0.2];
    self.bottomControl.minimumTrackTintColor = [UIColor colorWithWhite:1.0 alpha:0.9];
    self.bottomControl.continuous = YES;

    // Assemble Top View
    [self addSubview:self.topView];
    [self.topView addSubview:self.topLabel];
    [self.topView addSubview:self.topControl];
    [self.topView addSubview:self.topTextField];

    // Assemble Bottom View 
    [self addSubview:self.bottomView];
    [self.bottomView addSubview:self.bottomLabel];
    [self.bottomView addSubview:self.bottomControl];
    [self.bottomView addSubview:self.bottomTextField];

    self.topResetButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.topResetButton addTarget:self
                            action:@selector(handleTopResetButtonPress:)
                  forControlEvents:UIControlEventTouchUpInside];
    UIImage *rsImage = [HPResources resetImageToggled:NO];
    [self.topResetButton setImage:rsImage forState:UIControlStateNormal];
    self.topResetButton.frame = CGRectMake(15, (0.0369) * [[UIScreen mainScreen] bounds].size.height, kResetButtonSize, kResetButtonSize);
    self.topResetButton.alpha = 0.8;
    self.topResetButton.center = CGPointMake(self.topResetButton.center.x, self.topControl.center.y);
    [self.topView addSubview:self.topResetButton];

    self.bottomResetButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.bottomResetButton addTarget:self
                               action:@selector(handleBottomResetButtonPress:)
                     forControlEvents:UIControlEventTouchUpInside];
    [self.bottomResetButton setImage:rsImage forState:UIControlStateNormal];
    self.bottomResetButton.frame = CGRectMake(15, (0.0369) * [[UIScreen mainScreen] bounds].size.height, kResetButtonSize, kResetButtonSize);
    self.bottomResetButton.alpha = 0.8;
    self.bottomResetButton.center = CGPointMake(self.bottomResetButton.center.x, self.bottomControl.center.y);
    [self.bottomView addSubview:self.bottomResetButton];

    UILabel *location = [[UILabel alloc] initWithFrame:CGRectMake([[UIScreen mainScreen] bounds].size.width - 300, [[UIScreen mainScreen] bounds].size.height - 60, 280, 60)];
    location.text = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];
    location.textAlignment = NSTextAlignmentRight;
    [location setFont:[UIFont systemFontOfSize:13]];
}

- (void)updateLayoutForConfiguration:(HPControllerViewConfiguration)config
{

    self.topLabel.text = [HPUtility localizedItem:config.topControl.itemInfo.label];
    self.bottomLabel.text = [HPUtility localizedItem:config.bottomControl.itemInfo.label];

    self.topLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height);
    self.bottomLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50);


    switch (config.topControl.itemType)
    {
        case kHPControllerItemTypeNone:
            _topView.hidden = YES;
            break;
        case kHPControllerItemTypeCounter:
        {
            self.topLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height);
            self.topTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + ([[UIScreen mainScreen] bounds].size.width / 2) - (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2) - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.048) * [[UIScreen mainScreen] bounds].size.height, (0.1333) * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height);
            self.topControl.alpha = 0;

            UIButton *topMin = [UIButton buttonWithType:UIButtonTypeCustom];

            [topMin addTarget:self
                       action:@selector(topMinus)
             forControlEvents:UIControlEventTouchUpInside];
            [topMin setTitle:@"-" forState:UIControlStateNormal];

            topMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, 40.0);
            [self.topView addSubview:topMin];

            UIButton *topPlu = [UIButton buttonWithType:UIButtonTypeCustom];

            [topPlu addTarget:self
                       action:@selector(topPlus)
             forControlEvents:UIControlEventTouchUpInside];
            [topPlu setTitle:@"+" forState:UIControlStateNormal];

            topPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, (0.0369) * [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, 40.0);

            [self.topView addSubview:topPlu];

            [topPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
            [topMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];

            topMin.layer.cornerRadius = 10;
            topMin.layer.cornerCurve = kCACornerCurveContinuous;
            topMin.clipsToBounds = YES;
            topPlu.layer.cornerRadius = 10;
            topPlu.layer.cornerCurve = kCACornerCurveContinuous;
            topPlu.clipsToBounds = YES;

            break;
        }
        default:
            break;
    }

    switch (config.bottomControl.itemType)
    {
        case kHPControllerItemTypeNone:
            _bottomView.hidden = YES;
            break;
        case kHPControllerItemTypeCounter:
        {
            UIButton *bottomMin = [UIButton buttonWithType:UIButtonTypeCustom];

            [bottomMin addTarget:self
                          action:@selector(bottomMinus)
                forControlEvents:UIControlEventTouchUpInside];
            [bottomMin setTitle:@"-" forState:UIControlStateNormal];
            bottomMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, 40.0);
            [self.bottomView addSubview:bottomMin];

            UIButton *bottomPlu = [UIButton buttonWithType:UIButtonTypeCustom];
            [bottomPlu addTarget:self
                          action:@selector(bottomPlus)
                forControlEvents:UIControlEventTouchUpInside];

            [bottomPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
            [bottomMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];

            [bottomPlu setTitle:@"+" forState:UIControlStateNormal];
            bottomPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2), (0.0369) * [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, 40.0);

            [self.bottomView addSubview:bottomPlu];

            self.bottomControl.alpha = 0;

            bottomPlu.layer.cornerRadius = 10;
            bottomPlu.layer.cornerCurve = kCACornerCurveContinuous;
            bottomPlu.clipsToBounds = YES;
            bottomMin.layer.cornerRadius = 10;
            bottomMin.layer.cornerCurve = kCACornerCurveContinuous;
            bottomMin.clipsToBounds = YES;

            self.bottomLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50);

            self.bottomTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + [[UIScreen mainScreen] bounds].size.width / 2 - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.0480) * [[UIScreen mainScreen] bounds].size.height, 50, 30);


            break;
        }
        default:
            break;
    }


    self.topControl.minimumValue = config.topControl.itemInfo.min;
    self.topControl.maximumValue = config.topControl.itemInfo.max;

    self.bottomControl.minimumValue = config.bottomControl.itemInfo.min;
    self.bottomControl.maximumValue = config.bottomControl.itemInfo.max;


    HPPageConfiguration *pageConfig = [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][[[HPUIManager sharedInstance] editingLocation]];
    self.topControl.value = (float) [pageConfig valueForItem:config.topControl.itemInfo.configKey];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", self.topControl.value];
    self.bottomControl.value = (float) [pageConfig valueForItem:config.bottomControl.itemInfo.configKey];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", self.bottomControl.value];
}

- (void)topMinus
{
    self.topControl.value -= 1;
    [self topSliderUpdated:self.topControl];
}

- (void)topPlus
{
    self.topControl.value += 1;
    [self topSliderUpdated:self.topControl];
}

- (void)bottomMinus
{
    self.bottomControl.value -= 1;
    [self bottomSliderUpdated:self.bottomControl];
}

- (void)bottomPlus
{
    self.bottomControl.value += 1;
    [self bottomSliderUpdated:self.bottomControl];
}

#pragma mark Sliders

- (void)topSliderUpdated:(UISlider *)slider
{
    [HPLayoutManager updateConfigItem:_config.topControl.itemInfo.configKey
                          forLocation:[[HPUIManager sharedInstance] editingLocation]
                            withValue:(NSInteger) slider.value];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat) ((NSInteger) (floor([slider value])))];
}

- (void)bottomSliderUpdated:(UISlider *)slider
{
    [HPLayoutManager updateConfigItem:_config.bottomControl.itemInfo.configKey
                          forLocation:[[HPUIManager sharedInstance] editingLocation]
                            withValue:(NSInteger) slider.value];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat) ((NSInteger) (floor([slider value])))];
}

#pragma mark Text Fields

- (void)topTextFieldBeganEditing:(UITextField *)textField
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kFadeFloatingDockNotificationName object:nil];
}

- (void)topTextFieldEndedEditing:(UITextField *)textField
{
    [self.topTextField resignFirstResponder];
    [[NSNotificationCenter defaultCenter] postNotificationName:kShowFloatingDockNotificationName object:nil];
}

- (void)topTextFieldUpdated:(UITextField *)textField
{
    self.topControl.value = [[textField text] floatValue];
    [self topSliderUpdated:self.topControl];
}

- (void)invertTopTextField
{
    if ([self.topTextField.text hasPrefix:@"-"])
    {
        self.topTextField.text = [self.topTextField.text substringFromIndex:1];
    }
    else
    {
        self.topTextField.text = [NSString stringWithFormat:@"-%@", self.topTextField.text];
    }
    [self topTextFieldUpdated:self.topTextField];
}

- (void)bottomTextFieldBeganEditing:(UITextField *)textField
{
    CGAffineTransform transform = CGAffineTransformIdentity;
    [UIView animateWithDuration:0.4
                     animations:
                             ^
                             {
                                 self.transform = CGAffineTransformTranslate(transform, 0, (0 - ([[UIScreen mainScreen] bounds].size.height * 0.5)));
                             }
    ];
    [[NSNotificationCenter defaultCenter] postNotificationName:kFadeFloatingDockNotificationName object:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditorKickViewsUp object:nil];
}

- (void)bottomTextFieldEndedEditing:(UITextField *)textField
{
    [self.bottomTextField resignFirstResponder];
    [[NSNotificationCenter defaultCenter] postNotificationName:kShowFloatingDockNotificationName object:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditorKickViewsBack object:nil];
    [UIView animateWithDuration:0.4
                     animations:
                             ^
                             {
                                 self.transform = CGAffineTransformIdentity;
                             }
    ];
}

- (void)bottomTextFieldUpdated:(UITextField *)textField
{
    self.bottomControl.value = [[textField text] floatValue];
    [self bottomSliderUpdated:self.bottomControl];
}

- (void)invertBottomTextField
{
    if ([self.bottomTextField.text hasPrefix:@"-"])
    {
        self.bottomTextField.text = [self.bottomTextField.text substringFromIndex:1];
    }
    else
    {
        self.bottomTextField.text = [NSString stringWithFormat:@"-%@", self.bottomTextField.text];
    }
    [self bottomTextFieldUpdated:self.bottomTextField];
}

#pragma mark Reset Buttons

- (void)handleTopResetButtonPress:(UIButton *)sender
{
    AudioServicesPlaySystemSound(1519);
    self.topControl.value = _config.topControl.itemInfo.defaultValue;
    [self topSliderUpdated:self.topControl];
}

- (void)handleBottomResetButtonPress:(UIButton *)sender
{
    AudioServicesPlaySystemSound(1519);
    self.bottomControl.value = _config.bottomControl.itemInfo.defaultValue;
    [self bottomSliderUpdated:self.bottomControl];
}

@end