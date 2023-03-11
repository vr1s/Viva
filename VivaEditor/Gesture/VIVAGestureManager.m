//
// Created by vrisk/a on 6/24/21.
//

#import "VIVAGestureManager.h"
#import "VIVAManager.h"
#import "../EditorUI/VIVAUIManager.h"
#import "VIVAUtility.h"
#import "UISystemGestureView.h"
#include "VIVALayoutManager.h"
#import "VIVASystemUIManager.h"
#import <AudioToolbox/AudioToolbox.h>

#include <SpringBoard/SpringBoard.h>


@implementation VIVAGestureManager
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
    static VIVAGestureManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        sharedInstance = (VIVAGestureManager *) [[[self class] alloc] init];
    });
    return sharedInstance;
}

- (void)insertGestureRecognizers:(UISystemGestureView *)systemGestureView
{
    _systemGestureView = systemGestureView;
    NSLog(@"Configured Gesture View");

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
    [VIVASystemUIManager sharedInstance].wallpaperWindow.transform = CGAffineTransformMakeScale(1, 1);
    [VIVASystemUIManager sharedInstance].homeWindow.transform = CGAffineTransformMakeScale(1, 1);

    [VIVASystemUIManager sharedInstance].homeWindow.layer.borderColor = [[UIColor clearColor] CGColor];
    [VIVASystemUIManager sharedInstance].homeWindow.layer.borderWidth = 0;
    [VIVASystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
    [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;

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
        [[VIVAUIManager sharedInstance] showEditorView];
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
            [[[VIVAUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:0 withDuration:0.15];
            [UIView animateWithDuration:0.2
                             animations:^
                             {
                                 [VIVASystemUIManager sharedInstance].wallpaperWindow.transform = CGAffineTransformMakeScale(1, 1);
                                 [VIVASystemUIManager sharedInstance].homeWindow.transform = CGAffineTransformMakeScale(1, 1);
                             }
                             completion:^(BOOL finished)
                             {
                                 [VIVASystemUIManager sharedInstance].homeWindow.layer.borderColor = [[UIColor clearColor] CGColor];
                                 [VIVASystemUIManager sharedInstance].homeWindow.layer.borderWidth = 0;
                                 [VIVASystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
                                 [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;
                                 self.inactiveGestureRecognizer.enabled = NO;

                                 if (self.editorActivated)
                                 {
                                     [[VIVAUIManager sharedInstance] hideEditorView];
                                     self.activeGestureRecognizer.enabled = YES;
                                     self.editorActivated = NO;
                                     self.editorOpened = NO;
                                 }

                                [[VIVALayoutManager sharedInstance] doSharedEditorClosedTasks];
                             }
            ];
        }
        else
        {
            [[[VIVAUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:1 withDuration:0.15];

            [UIView animateWithDuration:0.2
                             animations:^
                             {
                                 CGAffineTransform restState = CGAffineTransformMakeScale(0.7, 0.7);
                                 restState.ty = -kMaxAmt;
                                 [VIVASystemUIManager sharedInstance].wallpaperWindow.transform = restState;
                                 [VIVASystemUIManager sharedInstance].homeWindow.transform = restState;
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
            [[VIVAUIManager sharedInstance] showEditorView];
            self.editorActivated = YES;
        }

        [VIVASystemUIManager sharedInstance].homeWindow.layer.cornerRadius = [VIVAUtility isCurrentDeviceNotched] ? 35 : 0;
        [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = [VIVAUtility isCurrentDeviceNotched] ? 35 : 0;
        [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.masksToBounds = YES;
        [VIVASystemUIManager sharedInstance].homeWindow.layer.masksToBounds = YES;
        [VIVASystemUIManager sharedInstance].homeWindow.layer.cornerCurve = kCACornerCurveContinuous;
        [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.cornerCurve = kCACornerCurveContinuous;
    }
    else
    {
        [VIVASystemUIManager sharedInstance].homeWindow.layer.cornerRadius = 0;
        [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.cornerRadius = 0;
        [VIVASystemUIManager sharedInstance].wallpaperWindow.layer.masksToBounds = NO;
        [VIVASystemUIManager sharedInstance].homeWindow.layer.masksToBounds = NO;
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

    [VIVASystemUIManager sharedInstance].wallpaperWindow.transform = movement;
    [VIVASystemUIManager sharedInstance].homeWindow.transform = movement;
    // [VIVAManager sharedInstance].floatingDockWindow.transform = movement;

    CGFloat pctgOfTotal =
            (
                (
                    (.15 * [UIScreen mainScreen].bounds.size.height)
                    - [VIVASystemUIManager sharedInstance].homeWindow.frame.origin.y
                )
                + [VIVASystemUIManager sharedInstance].homeWindow.frame.size.height
            )
            / [UIScreen mainScreen].bounds.size.height;
    pctgOfTotal = 1 - pctgOfTotal;
    pctgOfTotal *= 5;
    [[[VIVAUIManager sharedInstance] editorViewController] transitionViewsToActivationPercentage:pctgOfTotal];

}

@end