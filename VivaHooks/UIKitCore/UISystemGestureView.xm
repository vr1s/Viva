#include <UIKit/UIKit.h>


#include "VIVAGestureManager.h"


%hook UISystemGestureView

- (void)movedToSuperview:(UIView*)view
{
    %orig;

    [[VIVAGestureManager sharedInstance] setSystemGestureView:self];

    NSLog(@"Viva: Gesture Injected");
}

%end