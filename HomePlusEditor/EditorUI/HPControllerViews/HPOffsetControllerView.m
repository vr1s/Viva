//
// HPOffsetControllerView.m
// HomePlus
// 
// Control View for Editing Top/Left Offsets
// This subclass also adds a label for info at the bottom of the screen
//
// Author:  Kritanta
// Created: Dec 2019
//

#include "../HPControllerView.h"
#include "../HPEditorViewController.h"
#include "../../Data/HPConfiguration.h"
#include "../../Data/HPDataManager.h"
#include "../HPUIManager.h"
#include "../../Utility/HPUtility.h"

@implementation HPOffsetControllerView

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

    if (self) 
    {
        [self layoutControllerView];
    }

    return self;
}

-(void)layoutControllerView
{
    [super layoutControllerView];

    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    self.topLabel.text = [HPUtility localizedItem:@"TOP_OFFSET"];
    self.bottomLabel.text = [HPUtility localizedItem:@"LEFT_OFFSET"];


    self.topControl.minimumValue = -100;
    self.topControl.maximumValue = [[UIScreen mainScreen] bounds].size.height;

    self.bottomControl.minimumValue = -400.0;
    self.bottomControl.maximumValue = 400.0;

    self.leftOffsetLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, (0.0369) * [[UIScreen mainScreen] bounds].size.height + 30,[[UIScreen mainScreen] bounds].size.width, 50)];
    [self.leftOffsetLabel setText:[HPUtility localizedItem:@"SET_LEFT_TO_ZERO"]];
    [self.leftOffsetLabel setFont:[UIFont systemFontOfSize:11]];
    self.leftOffsetLabel.numberOfLines = 2;
    self.leftOffsetLabel.textColor=[UIColor whiteColor];
    self.leftOffsetLabel.textAlignment=NSTextAlignmentCenter;
    [self.bottomView addSubview:self.leftOffsetLabel];
    
    
    self.topControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"TopInset"]];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"TopInset"]]];
    self.bottomControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"LeftInset"]];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"LeftInset"]]];
}

- (void)topSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setFloat:sender.value
                                                             forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"TopInset"]];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];

    [super topSliderUpdated:sender];
}

- (void)bottomSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setFloat:sender.value
                                                             forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"LeftInset"]];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];

    [super bottomSliderUpdated:sender];
}

- (void)handleTopResetButtonPress:(UIButton*)sender 
{
    [super handleTopResetButtonPress:sender];
    self.topControl.value = 0;
    [self topSliderUpdated:self.topControl];
}
- (void)handleBottomResetButtonPress:(UIButton*)sender 
{
    [super handleBottomResetButtonPress:sender];
    self.bottomControl.value = 0;
    [self bottomSliderUpdated:self.bottomControl];
}

@end