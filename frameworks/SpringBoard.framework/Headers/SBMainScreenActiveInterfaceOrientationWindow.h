// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBMAINSCREENACTIVEINTERFACEORIENTATIONWINDOW_H
#define SBMAINSCREENACTIVEINTERFACEORIENTATIONWINDOW_H


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "SBWindow.h"
@protocol BSDescriptionProviding;
@protocol SBUIActiveOrientationObserver;

@interface SBMainScreenActiveInterfaceOrientationWindow : SBWindow <BSDescriptionProviding, SBUIActiveOrientationObserver>

{
NSCountedSet *_orientationUpdateDisableReasons;
}


@property (readonly, copy, nonatomic) NSString *debugName; // ivar: _debugName
@property (retain, nonatomic) UIViewController *contentViewController; // ivar: _contentViewController
@property (nonatomic) BOOL passesTouchesThrough; // ivar: _passesTouchesThrough
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(void)activeInterfaceOrientationDidChangeToOrientation:(NSInteger)arg0 willAnimateWithDuration:(CGFloat)arg1 fromOrientation:(NSInteger)arg2 ;
-(BOOL)_canBecomeKeyWindow;
-(id)initWithDebugName:(id)arg0 ;
-(void)activeInterfaceOrientationWillChangeToOrientation:(NSInteger)arg0 ;
-(BOOL)isActive;
-(BOOL)passesTouchesThrough;
-(void)setRootViewController:(id)arg0 ;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(id)succinctDescriptionBuilder;
-(void)setHidden:(BOOL)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(BOOL)isDisablingInterfaceOrientationChanges;
-(void)disableInterfaceOrientationChangesForReason:(id)arg0 ;
-(void)enableInterfaceOrientationChangesForReason:(id)arg0 ;
-(void)_updateInterfaceOrientationToCurrentActiveInterfaceOrientationWithDuration:(CGFloat)arg0 ;
-(NSUInteger)effectiveRootViewControllerSupportedInterfaceOrientations;
+(BOOL)layoutContentViewControllerWithConstraints;

@end


#endif

