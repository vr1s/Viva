//
// HPScaleControllerView.m
// HomePlus
//
// Controller View for editing Icon Scale/Alpha
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

@implementation HPScaleControllerView

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

    self.topLabel.text = [HPUtility localizedItem:@"ICON_SCALE"];
    self.bottomLabel.text = [HPUtility localizedItem:@"ICON_CORNER"];

    self.topControl.minimumValue = 1;
    self.topControl.maximumValue = 100;

    self.bottomControl.minimumValue = 0;
    self.bottomControl.maximumValue = 100.0;


    self.topControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"Scale"]];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"Scale"]]];
    self.bottomControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"IconCorner"]];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"HPData%@%@", x, @"IconCorner"]]];
    
    self.bottomControl.hidden = 1;
    self.bottomLabel.hidden = 1;
    [self.bottomView removeFromSuperview];
}

- (void)topSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setFloat:sender.value
                                                             forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"Scale"]];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];

    [[HPManager sharedInstance] layoutIconViews];
}

- (void)bottomSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setFloat:sender.value
                                                             forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"IconCorner"]];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];

    [super bottomSliderUpdated:sender];
    [[HPManager sharedInstance] layoutIconViews];
}


- (void)handleTopResetButtonPress:(UIButton*)sender 
{
    [super handleTopResetButtonPress:sender];
    self.topControl.value = 60;
    [self topSliderUpdated:self.topControl];
}
- (void)handleBottomResetButtonPress:(UIButton*)sender 
{
    [super handleBottomResetButtonPress:sender];
    self.bottomControl.value = 13.5;
    [self bottomSliderUpdated:self.bottomControl];
}


@end