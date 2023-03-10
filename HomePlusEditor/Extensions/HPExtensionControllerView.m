//
// HPExtensionControllerView.m
// HomePlus
//
// HPControllerView subclass for extensions
// Supports various interfaces (sliders, buttons, etc)
//
// Also handles interacting with tweak prefs
//
// Authors: vriska
// Created  Dec 2019
//
// TODO: add titles
// TODO: toggles?
// TODO: optimize
//

#include <UIKit/UIKit.h>

#include "HPExtensionControllerView.h"
#include "../EditorUI/HPControllerView.h"
#include "../Utility/HPUtility.h"

@implementation HPExtensionControllerView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];

    if (self) 
    {

    }

    return self;
}

-(void)layoutControllerView
{
    [super layoutControllerView];

    if (self.topControlType == kSlider)
    {
        // Nothing needs to be done
    }
    else if (self.topControlType == kCounter)
    {
        self.topLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, (0.0615) * [[UIScreen mainScreen] bounds].size.height);
        self.topTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+([[UIScreen mainScreen] bounds].size.width / 2) - (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2) - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.048) * [[UIScreen mainScreen] bounds].size.height, (0.1333) * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height);
        self.topControl.alpha = 0;

        UIButton *topMin = [UIButton buttonWithType:UIButtonTypeCustom];
        
        [topMin addTarget:self 
                action:@selector(topMinus)
        forControlEvents:UIControlEventTouchUpInside];
        [topMin setTitle:@"-" forState:UIControlStateNormal];

        topMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
        [self.topView addSubview:topMin];

        UIButton *topPlu = [UIButton buttonWithType:UIButtonTypeCustom];

        [topPlu addTarget:self 
                action:@selector(topPlus)
        forControlEvents:UIControlEventTouchUpInside];
        [topPlu setTitle:@"+" forState:UIControlStateNormal];

        topPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2, (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
        
        [self.topView addSubview:topPlu];

        [topPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
        [topMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];

        topMin.layer.cornerRadius = 10;
        topMin.layer.cornerCurve = kCACornerCurveContinuous;
        topMin.clipsToBounds = YES;
        topPlu.layer.cornerRadius = 10;
        topPlu.layer.cornerCurve = kCACornerCurveContinuous;
        topPlu.clipsToBounds = YES;
    }
    else if (self.topControlType == kNone)//kSwitch
    {
        self.topView.hidden = YES;
    }
    else
    {

    }

    if (self.bottomControlType == kSlider)
    {
        // Nothing needs to be done
    }
    else if (self.bottomControlType == kCounter)
    {
        UIButton *bottomMin = [UIButton buttonWithType:UIButtonTypeCustom];

        [bottomMin addTarget:self 
                action:@selector(bottomMinus)
        forControlEvents:UIControlEventTouchUpInside];
        [bottomMin setTitle:@"-" forState:UIControlStateNormal];
        bottomMin.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, (0.0369) * [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
        [self.bottomView addSubview:bottomMin];

        UIButton *bottomPlu = [UIButton buttonWithType:UIButtonTypeCustom];
        [bottomPlu addTarget:self 
                action:@selector(bottomPlus)
        forControlEvents:UIControlEventTouchUpInside];

        [bottomPlu setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];
        [bottomMin setBackgroundColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.06]];

        [bottomPlu setTitle:@"+" forState:UIControlStateNormal];
        bottomPlu.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) + (((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2), (0.0369) *  [[UIScreen mainScreen] bounds].size.height, ((0.7) * [[UIScreen mainScreen] bounds].size.width / 2) - ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 , 40.0);
        
        [self.bottomView addSubview:bottomPlu];
    
        self.bottomControl.alpha = 0;

        bottomPlu.layer.cornerRadius = 10;
        bottomPlu.layer.cornerCurve = kCACornerCurveContinuous;
        bottomPlu.clipsToBounds = YES;
        bottomMin.layer.cornerRadius = 10;
        bottomMin.layer.cornerCurve = kCACornerCurveContinuous;
        bottomMin.clipsToBounds = YES;

        self.bottomLabel.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width, -10, (0.706) * [[UIScreen mainScreen] bounds].size.width, 50);

        self.bottomTextField.frame = CGRectMake(kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width+[[UIScreen mainScreen] bounds].size.width / 2 -  ((0.0369) * [[UIScreen mainScreen] bounds].size.height) / 2 - kLeftScreenBuffer * [[UIScreen mainScreen] bounds].size.width + 7, (0.0480) * [[UIScreen mainScreen] bounds].size.height, 50, 30);

    }
    else if (self.bottomControlType == kNone)
    {
        self.bottomView.hidden = YES;
    }
    else
    {

    }

}

- (void)configureValuesFromBundle
{
    NSDictionary *prefs = [NSDictionary dictionaryWithContentsOfFile:self.bundleValueLocation];

    self.topControl.value = [[prefs valueForKey:self.topPreferenceLink] floatValue];
    self.bottomControl.value = [[prefs valueForKey:self.bottomPreferenceLink] floatValue];

    [self topSliderUpdated:self.topControl];
    [self bottomSliderUpdated:self.bottomControl];
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
- (void)topSliderUpdated:(UISlider *)sender
{
    //NSMutableDictionary* prefs = [[NSMutableDictionary alloc] initWithContentsOfFile:self.bundleValueLocation];
    //[prefs setValue:[NSNumber numberWithFloat: sender.value] forKey:self.topPreferenceLink];

    //[prefs writeToFile:self.bundleValueLocation atomically: YES];
    [HPUtility writeToBundle:self.bundleID atKey:self.topPreferenceLink withValue:[NSNumber numberWithFloat:sender.value]];
    CFStringRef notif = (__bridge CFStringRef)self.topNotification;
    CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(),
        notif, NULL, NULL, TRUE);
        
    [[NSNotificationCenter defaultCenter] postNotificationName:self.topNotification object:nil];
    if (self.topControlType == kCounter)
    {
        self.topTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat)((NSInteger)(floor([sender value])))];
    }
    else if (self.topControlType == kSlider)
    {
        self.topTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];
    }
}

- (void)bottomSliderUpdated:(UISlider *)sender
{
    [HPUtility writeToBundle:self.bundleID atKey:self.bottomPreferenceLink withValue:[NSNumber numberWithFloat:sender.value]];
    CFStringRef notif = (__bridge CFStringRef)self.bottomNotification;
    CFNotificationCenterPostNotification(
        CFNotificationCenterGetDarwinNotifyCenter(),
        notif, 
        NULL, 
        NULL,
        TRUE);

    [[NSNotificationCenter defaultCenter] postNotificationName:self.bottomNotification object:nil];
    if (self.bottomControlType == kCounter)
    {
        self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", (CGFloat)((NSInteger)(floor([sender value])))];
    }
    else if (self.bottomControlType == kSlider)
    {
        self.bottomTextField.text = [NSString stringWithFormat:@"%.0f", sender.value];
    }

}


@end