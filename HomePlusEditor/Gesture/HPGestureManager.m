//
// Created by Kritanta on 6/24/21.
//

#import "HPGestureManager.h"
#import "HPManager.h"
#import "../EditorUI/HPUIManager.h"
#import "HPUtility.h"
#import "UISystemGestureView.h"
#import "HPSystemUIManager.h"
#import <AudioToolbox/AudioToolbox.h>

#include <SpringBoard/SpringBoard.h>


@implementation HPGestureManager
{

@private
    UISystemGestureView *_systemGestureView;
    UIPinchGestureRecognizer *_activeGestureRecognizer;
    UIPinchGestureRecognizer *_inactiveGestureRecognizer;
}


@synthesize systemGestureView = _systemGestureView;
@synthesize activeGestureRecognizer = _activeGestureRecognizer;
@synthesize inactiveGestureRecognizer = _inactiveGestureRecognizer;

+ (instancetype)sharedInstance
{
    static HPGestureManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        sharedInstance = (HPGestureManager *) [[[self class] alloc] init];
    });
    return sharedInstance;
}

- (void)insertGestureRecognizers:(UISystemGestureView *)systemGestureView
{
    _systemGestureView = systemGestureView;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(activationListener:) name:kEditingModeDisabledNotificationName object:nil];

    UIPinchGestureRecognizer *pan = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(handlePinchGesture:)];
    UIPinchGestureRecognizer *pan2 = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(handlePinchGesture:)];

    pan2.enabled = NO;
    _activeGestureRecognizer.delegate = _systemGestureView;
    _activeGestureRecognizer = pan;
    self.panAmount = 1;


    _inactiveGestureRecognizer.delegate = _systemGestureView;
    _inactiveGestureRecognizer = pan2;
    FBSDisplayIdentity *displayIdentity = [[[UIScreen mainScreen] displayConfiguration] identity];
    [[_UISystemGestureManager sharedInstance] addGestureRecognizer:_activeGestureRecognizer toDisplayWithIdentity:displayIdentity];
    [[_UISystemGestureManager sharedInstance] addGestureRecognizer:_inactiveGestureRecognizer toDisplayWithIdentity:displayIdentity];
}


- (void)activationListener:(NSNotification *)notification
{
    [HPSystemUIManager sharedInstance].wallpaperWindow.transform = CGAffineTransformMakeScale(1, 1);
    [HPSystemUIManager sharedInstance].homeWindow.transform = CGAffineTransformMakeScale(1, 1);

    [HPSystemUIManager sharedInstance].homeWindow.layer.borderColor = [[UIColor clearColor] CGColor];
    [HPSystemUIManager sharedInstance].homeWindow.layer.borderWidth = 0;
    [HPSystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
    [HPSystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;

    self.hitboxMaxed = NO;
    self.activeGestureRecognizer.enabled = YES;
    self.inactiveGestureRecognizer.enabled = NO;

    self.editorActivated = NO;
    self.editorOpened = NO;
}

- (void)handlePinchGesture:(UIPinchGestureRecognizer *)gestureRecognizer
{

    if (![(SpringBoard *) [UIApplication sharedApplication] isShowingHomescreen])
    {
        gestureRecognizer.state = UIGestureRecognizerStateCancelled;
        return;
    }

    if (gestureRecognizer.scale > self.panAmount && gestureRecognizer == self.activeGestureRecognizer)
    {
        gestureRecognizer.scale = self.panAmount;
    }

    if (self.activeGestureRecognizer.state >= 1 && gestureRecognizer != self.activeGestureRecognizer && gestureRecognizer.state != UIGestureRecognizerStateEnded)
    {
        return;
    }

    if (self.inactiveGestureRecognizer.state >= 1 && gestureRecognizer == self.activeGestureRecognizer && gestureRecognizer.state != UIGestureRecognizerStateEnded)
    {
        return;
    }

    CGFloat maxAmt = 1;

    if (gestureRecognizer.scale < 0.7)
    {
        gestureRecognizer.scale = 0.7;
    }

    CGFloat scalie = gestureRecognizer.scale;

    if (gestureRecognizer.scale > 1 && gestureRecognizer != self.activeGestureRecognizer)
    {
        scalie *= (self.inactiveGestureRecognizer.enabled ? .7 : 1);
    }

    if (scalie > 1)
    {
        scalie = 1;
    }


    self.panAmount = scalie;

    if (gestureRecognizer.scale < lastAmount && self.inactiveGestureRecognizer.enabled && gestureRecognizer.state != UIGestureRecognizerStateEnded)
    {
        gestureRecognizer.scale = lastAmount;
        return;
    }
    lastAmount = gestureRecognizer.scale;
    if (gestureRecognizer.state == UIGestureRecognizerStateBegan && gestureRecognizer != self.inactiveGestureRecognizer)
    {
        [[HPUIManager sharedInstance] showEditorView];
        self.editorActivated = YES;
    }

    if (gestureRecognizer.state == UIGestureRecognizerStateEnded)
    {
        if (self.panAmount < 0)
        {
            self.panAmount = 0;
        }

        if (self.panAmount > maxAmt)
        {
            self.panAmount = maxAmt;
        }

        if (self.panAmount > maxAmt * 0.90)
        {
            [[[HPUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:0 withDuration:0.15];
            [UIView animateWithDuration:0.2
                             animations:^
                             {
                                 [HPSystemUIManager sharedInstance].wallpaperWindow.transform = CGAffineTransformMakeScale(1, 1);
                                 [HPSystemUIManager sharedInstance].homeWindow.transform = CGAffineTransformMakeScale(1, 1);
                                 //[HPSystemUIManager sharedInstance].floatingDockWindow.transform = CGAffineTransformMakeScale(1, 1);
                             }
                             completion:^(BOOL finished)
                             {
                                 [HPSystemUIManager sharedInstance].homeWindow.layer.borderColor = [[UIColor clearColor] CGColor];
                                 [HPSystemUIManager sharedInstance].homeWindow.layer.borderWidth = 0;
                                 [HPSystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
                                 [HPSystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;
                                 self.inactiveGestureRecognizer.enabled = NO;

                                 if (self.editorActivated)
                                 {
                                     [[HPUIManager sharedInstance] hideEditorView];
                                     //AudioServicesPlaySystemSound(1519);
                                     self.activeGestureRecognizer.enabled = YES;
                                     self.editorActivated = NO;
                                     self.editorOpened = NO;
                                 }
                             }
            ];
        }
        else
        {
            [[[HPUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:1 withDuration:0.15];

            [UIView animateWithDuration:0.2
                             animations:^
                             {
                                 CGAffineTransform restState = CGAffineTransformMakeScale(0.7, 0.7);
                                 restState.ty = -kMaxAmt;
                                 [HPSystemUIManager sharedInstance].wallpaperWindow.transform = restState;
                                 [HPSystemUIManager sharedInstance].homeWindow.transform = restState;
                                 //[HPSystemUIManager sharedInstance].floatingDockWindow.transform = restState;
                             }
                             completion:^(BOOL finished)
                             {
                                 self.editorOpened = YES;
                                 self.inactiveGestureRecognizer.enabled = YES;
                                 self.activeGestureRecognizer.enabled = NO;
                             }
            ];
        }
        return;
    }

    if (self.panAmount < 1)
    {
        if (!self.editorActivated)
        {
            [[HPUIManager sharedInstance] showEditorView];
            self.editorActivated = YES;
        }

        [HPSystemUIManager sharedInstance].homeWindow.layer.cornerRadius = [HPUtility isCurrentDeviceNotched] ? 35 : 0;
        [HPSystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = [HPUtility isCurrentDeviceNotched] ? 35 : 0;
        [HPSystemUIManager sharedInstance].homeWindow.layer.cornerCurve = kCACornerCurveContinuous;
        [HPSystemUIManager sharedInstance].wallpaperWindow.layer.cornerCurve = kCACornerCurveContinuous;
    }
    else
    {
        [HPSystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
        [HPSystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;
    }

    if (self.panAmount >= maxAmt)
    {
        if (!self.hitboxMaxed)
        {
            self.hitboxMaxed = YES;
        }

        if (self.editorOpened)
        {
            self.panAmount = maxAmt;
        }
        else
        {
            self.panAmount = maxAmt;

            self.editorOpened = YES;
        }
    }

    CGAffineTransform movement = CGAffineTransformMakeScale(scalie, scalie);
    // .85 = 0.0
    // .80 = 0.33
    // .75 = 0.66
    // .7  = 1.0
    // x = scale
    // y = outcome
    // .85 - .85 = 0
    // .85 - .7 = .15
    // (.85 - x)*(60/9)
    //

    CGFloat bump = scalie > 0.85 ? 0 : (.85 - scalie) * (6.66666666666666666) * (-kMaxAmt) * 1.42;
    movement = CGAffineTransformTranslate(movement, 0, bump);

    [HPSystemUIManager sharedInstance].wallpaperWindow.transform = movement;
    [HPSystemUIManager sharedInstance].homeWindow.transform = movement;
    // [HPManager sharedInstance].floatingDockWindow.transform = movement;

    CGFloat pctgOfTotal =
            (
                (
                    (.15 * [UIScreen mainScreen].bounds.size.height)
                    - [HPSystemUIManager sharedInstance].homeWindow.frame.origin.y
                )
                + [HPSystemUIManager sharedInstance].homeWindow.frame.size.height
            )
            / [UIScreen mainScreen].bounds.size.height;
    pctgOfTotal = 1 - pctgOfTotal;
    pctgOfTotal *= 5;
    [[[HPUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:pctgOfTotal];

}

@end