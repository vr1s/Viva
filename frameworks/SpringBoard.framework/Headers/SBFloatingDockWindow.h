// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFLOATINGDOCKWINDOW_H
#define SBFLOATINGDOCKWINDOW_H

#include "SBMainScreenActiveInterfaceOrientationWindow.h"

@class SBMainScreenActiveInterfaceOrientationWindow;

@interface SBFloatingDockWindow : SBMainScreenActiveInterfaceOrientationWindow

-(BOOL)_canBecomeKeyWindow;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(id)floatingDockRootViewController;

@end


#endif

