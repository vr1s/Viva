#include "VIVAGestureManager.h"

@hook _UISystemGestureManager 

-(_UISystemGestureManager*)init 
{
    id o = @orig();
    
    [[VIVAGestureManager sharedInstance] insertGestureRecognizers:self];

    return o;
}

@end