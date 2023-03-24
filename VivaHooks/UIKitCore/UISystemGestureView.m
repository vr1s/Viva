#include <UIKit/UIKit.h>


#include "VIVAGestureManager.h"


@hook UISystemGestureView

- (void)movedToSuperview:(UIView*)view
{
    @orig(view);

    [[VIVAGestureManager sharedInstance] setSystemGestureView:self];

    NSLog(@"Viva: Gesture Injected");
}

@end