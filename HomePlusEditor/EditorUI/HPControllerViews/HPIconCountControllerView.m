//
// HPIconCountControllerView.m
// HomePlus
//
// Controller View for Editing Columns/Rows
// This subclass hides the sliders and replaces them with buttons.
// Maybe someday I should make a custom subclass for button controlls and such
//
// Authors: Kritanta
// Created  Dec 2019
//

#include "../HPControllerView.h"
#include "../HPEditorViewController.h"
#include "../../Data/HPConfiguration.h"
#include "../../Data/HPDataManager.h"
#include "../HPUIManager.h"
#include "../../Utility/HPUtility.h"


@implementation HPIconCountControllerView

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

    self.topLabel.text = [HPUtility localizedItem:@"ROWS"];
    self.bottomLabel.text = [HPUtility localizedItem:@"COLUMNS"];

    self.topLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height);
    self.bottomLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50);

    self.topTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+([[UIScreen mainScreen] bounds].size.width / 2) - (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2) - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.048) * [[UIScreen mainScreen] bounds].size.height, (0.1333) * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height);
    self.bottomTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+[[UIScreen mainScreen] bounds].size.width / 2 -  ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.0480) * [[UIScreen mainScreen] bounds].size.height, 50, 30);

    self.topControl.minimumValue = 1;
    self.topControl.maximumValue = 14;

    self.bottomControl.minimumValue = 1;
    self.bottomControl.maximumValue = 14;

    self.topControl.alpha = 0;
    self.bottomControl.alpha = 0;

    UIButton *rowMin = [UIButton buttonWithType:UIButtonTypeCustom];
        
    [rowMin addTarget:self 
            action:@selector(rowMinus)
    forControlEvents:UIControlEventTouchUpInside];
    [rowMin setTitle:@"-" forState:UIControlStateNormal];

    rowMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
    [self.topView addSubview:rowMin];

    UIButton *rowPlu = [UIButton buttonWithType:UIButtonTypeCustom];

    [rowPlu addTarget:self 
            action:@selector(rowPlus)
    forControlEvents:UIControlEventTouchUpInside];
    [rowPlu setTitle:@"+" forState:UIControlStateNormal];

    rowPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
    
    [self.topView addSubview:rowPlu];

    UIButton *colMin = [UIButton buttonWithType:UIButtonTypeCustom];

    [colMin addTarget:self 
            action:@selector(columnMinus)
    forControlEvents:UIControlEventTouchUpInside];
    [colMin setTitle:@"-" forState:UIControlStateNormal];
    colMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) *   [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
    [self.bottomView addSubview:colMin];

    UIButton *colPlu = [UIButton buttonWithType:UIButtonTypeCustom];
    [colPlu addTarget:self 
            action:@selector(columnPlus)
    forControlEvents:UIControlEventTouchUpInside];

    [colPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
    [colMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
    [rowPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
    [rowMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];

    colPlu.layer.cornerRadius = 10;
    colPlu.layer.cornerCurve = kCACornerCurveContinuous;
    colPlu.clipsToBounds = YES;
    colMin.layer.cornerRadius = 10;
    colMin.layer.cornerCurve = kCACornerCurveContinuous;
    colMin.clipsToBounds = YES;
    rowMin.layer.cornerRadius = 10;
    rowMin.layer.cornerCurve = kCACornerCurveContinuous;
    rowMin.clipsToBounds = YES;
    rowPlu.layer.cornerRadius = 10;
    rowPlu.layer.cornerCurve = kCACornerCurveContinuous;
    rowPlu.clipsToBounds = YES;

    [colPlu setTitle:@"+" forState:UIControlStateNormal];
    colPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2), (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
        
    [self.bottomView addSubview:colPlu];

    self.topControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"%@%@%@", @"HPData", x, @"Rows"]];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", self.topControl.value];
    self.bottomControl.value = [[[HPDataManager sharedInstance] currentConfiguration] floatForKey:[NSString stringWithFormat:@"%@%@%@", @"HPData", x, @"Columns"]];
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", self.bottomControl.value];

}

- (void)rowMinus
{
    self.topControl.value -= 1;
    [self topSliderUpdated:self.topControl];
}

- (void)rowPlus
{
    self.topControl.value += 1;
    [self topSliderUpdated:self.topControl];
}

- (void)columnMinus
{
    self.bottomControl.value -= 1;
    [self bottomSliderUpdated:self.bottomControl];
}

- (void)columnPlus 
{
    self.bottomControl.value += 1;
    [self bottomSliderUpdated:self.bottomControl];
}

- (void)topSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setInteger:sender.value
                                                               forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"Rows"]];
     
    [HPManager updateCacheForLocation:[[HPUIManager sharedInstance] editingLocation]];
    [kIconModel layout];
    self.topTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat)((NSInteger)(floor([sender value])))];
}

- (void)bottomSliderUpdated:(UISlider *)sender
{
    NSString *x = [[[HPUIManager sharedInstance] editingLocation] substringFromIndex:14];

    [[[HPDataManager sharedInstance] currentConfiguration] setFloat:sender.value
                                                             forKey:[NSString stringWithFormat:@"HPData%@%@", x, @"Columns"]];
    [[HPManager sharedInstance] layoutIconViewsAnimated];

    [HPManager updateCacheForLocation:[[HPUIManager sharedInstance] editingLocation]];
    [kIconModel layout];
       
    self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat)((NSInteger)(floor([sender value])))];
}

- (void)handleTopResetButtonPress:(UIButton*)sender 
{
    [super handleTopResetButtonPress:sender];
    self.topControl.value = [HPUtility defaultRows];
    [self topSliderUpdated:self.topControl];
}
- (void)handleBottomResetButtonPress:(UIButton*)sender 
{
    [super handleBottomResetButtonPress:sender];
    self.bottomControl.value = 4;
    [self bottomSliderUpdated:self.bottomControl];
}


@end