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
#include <AudioToolbox/AudioToolbox.h>


@implementation HPControllerView 

/*
Properties: 
    @property (nonatomic, retain) UIView *topView;
    @property (nonatomic, retain) UIView *bottomView;

    @property (nonatomic, retain) UILabel *topLabel;
    @property (nonatomic, retain) OBSlider *topControl;
    @property (nonatomic, retain) UITextField *topTextField;

    @property (nonatomic, retain) UILabel *bottomLabel;
    @property (nonatomic, retain) OBSlider *bottomControl;
    @property (nonatomic, retain) UITextField *bottomTextField;
*/

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];

    if (self) {
        //[self layoutControllerView];
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
            [UIView alloc] initWithFrame: CGRectMake(0,
                                                    kTopContainerTopAnchor * [[UIScreen mainScreen] bounds].size.height, 
                                                    [[UIScreen mainScreen] bounds].size.width, 
                                                    kContainerHeight * [[UIScreen mainScreen] bounds].size.height)];

    // Top Label
    self.topLabel = [[UILabel alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, 0, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height)];
    [self.topLabel setText:@"Top Control"];
    self.topLabel.textColor=[UIColor whiteColor];
    self.topLabel.textAlignment=NSTextAlignmentCenter;
    // Top Text Field. 
    self.topTextField = [[UITextField alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+(0.730) * [[UIScreen mainScreen] bounds].size.width, (0.048) * [[UIScreen mainScreen] bounds].size.height, (0.1333) * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height)];
        
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
    UIToolbar* keyboardToolbar = [[UIToolbar alloc] init];

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
    self.topControl.minimumTrackTintColor = [UIColor colorWithWhite:1.0 alpha: 0.9];
    //self.topControl.minimumValue = -100;
    //self.topControl.maximumValue = [[UIScreen mainScreen] bounds].size.height;
    self.topControl.continuous = YES;
    //self.topControl.value = 0;

    // Bottom View
    self.bottomView = [[UIView alloc] initWithFrame:CGRectMake(0, (0.862) * [[UIScreen mainScreen] bounds].size.height, (1) * [[UIScreen mainScreen] bounds].size.width, (0.123) * [[UIScreen mainScreen] bounds].size.height)];

    // Bottom Label
    self.bottomLabel = [[UILabel alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, 0, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50)];
    [self.bottomLabel setText:@"Bottom Control"];
    self.bottomLabel.textColor=[UIColor whiteColor];
    self.bottomLabel.textAlignment=NSTextAlignmentCenter;

    // Bottom Text Field
    self.bottomTextField = [[UITextField alloc] initWithFrame:CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+(0.730) * [[UIScreen mainScreen] bounds].size.width, (0.048) * [[UIScreen mainScreen] bounds].size.height, 50, 30)];
    [self.bottomTextField addTarget:self
            action:@selector(bottomTextFieldUpdated:)
            forControlEvents:UIControlEventEditingChanged];
    
    [self.bottomTextField addTarget:self
            action:@selector(bottomTextFieldBeganEditing:)
            forControlEvents:UIControlEventEditingDidBegin];

    // Bottom Text Field Bar

    self.bottomTextField.keyboardType = UIKeyboardTypeNumberPad;
    self.bottomTextField.textColor = [UIColor whiteColor];

    UIToolbar* bkeyboardToolbar = [[UIToolbar alloc] init];

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
    self.bottomControl.minimumTrackTintColor = [UIColor colorWithWhite:1.0 alpha: 0.9];
    //self.bottomControl.minimumValue = -400.0;
    //self.bottomControl.maximumValue = 400.0;
    self.bottomControl.continuous = YES;
    //self.bottomControl.value = 0;

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

    UILabel *location = [[UILabel alloc] initWithFrame:CGRectMake([[UIScreen mainScreen] bounds].size.width-300, [[UIScreen mainScreen] bounds].size.height-60, 280, 60)];
    location.text = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];
    location.textAlignment = NSTextAlignmentRight;
    [location setFont:[UIFont systemFontOfSize:13]];
    //[self addSubview:location];
}

#pragma mark Sliders 

- (void)topSliderUpdated:(UISlider *)slider
{
    // Mainly stubs for subclasses. If they need this they can call super (most if not all need it)
    
    [HPManager updateCacheForLocation:[[HPUIManager sharedInstance] editingLocation]];
    [[HPManager sharedInstance] layoutIconViews];
}

- (void)bottomSliderUpdated:(UISlider *)slider
{
    
    [HPManager updateCacheForLocation:[[HPUIManager sharedInstance] editingLocation]];
    [[HPManager sharedInstance] layoutIconViews];
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
        ^{
            self.transform = CGAffineTransformTranslate(transform, 0, (0-([[UIScreen mainScreen] bounds].size.height * 0.5)));
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
        ^{  
            self.transform = CGAffineTransformIdentity;   
        }
    ]; 
}

- (void)bottomTextFieldUpdated:(UITextField *)textField
{
    self.bottomControl.value = [[textField text] floatValue];
    [self bottomSliderUpdated:self.bottomControl];
}

-(void)invertBottomTextField
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

- (void)handleTopResetButtonPress:(UIButton*)sender 
{
    AudioServicesPlaySystemSound(1519);
    // method stub for subclasses
}
- (void)handleBottomResetButtonPress:(UIButton*)sender 
{
    AudioServicesPlaySystemSound(1519);
    // method stub for subclasses
}

@end